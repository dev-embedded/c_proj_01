/*
 * STBuf_DCllS.c
 *
 *  Created on: Jul 6, 2015
 *      Author: juequ
 */

//Single Thread Buffer (FIFO), Dynamic Circular linked-list for Stream
//Note:
//	1.	Dynamic means that the nodes amount of the Buffer is unsure (but we have a Max length limit);
//		and for each node, the message length is unsure (but we have a Max length limit).
//	2.	We use FILE for Stream storage.
//	3.	For the Circular linked-list, it's empty when head==rare, & it's full when rare->next==head;
//		which means we will not use the last node for storage, it indicates the buffer empty or full status.

#include "buffer_global.h"

/* tested
 * 01. FIFO Buffer Create - Dynamic Circular linked-list Stream Buffer Create.
 *     And initial the buffer created.
 */
DCSP_T * buf_dcs_create()
{
	DCSP_T *buf=(DCSP_T *)malloc(DPLEN);	//create buffer
	DCSN_T *node=(DCSN_T *)malloc(DNLEN);	//create the 1st node

	//initial the first node
	node->nmsg=NULL;
	node->nlen=0;
	node->next=node->prev=node;

	//initial the buffer pointers
	buf->buf_h=buf->buf_r=node;
//printf("\nIn buf_dcs_create(), Buffer address is %p, buf_f is %p, buf_r is %p\n",buf, buf->buf_h,buf->buf_r);

	return buf;
}

/* tested
 * 09. FIFO Buffer Create - Dynamic Circular linked-list Stream Buffer
 *     Node add, always add one node at the Buffer rare (because FIFO), without move the buffer rare pointer,
 *          the rare will be moved forward after buffer writing!
 *     This function is a preparation for write buffer, & should only be called in the buffer_writer()!
 */
int buf_dcs_na(DCSP_T *buf)
{
	if(buf_dcs_len(buf)==BUFFER_SIZE) return BUFFER_FULL;  //reach the limit of buffer size

	DCSN_T *node=(DCSN_T *)malloc(DNLEN);
//	DCSN_T *bn=buf->buf_r;

	//initial the first node
	node->nmsg=NULL;
	node->nlen=0;

	//add this node into the Circular linked-list
	buf->buf_r->next=node;
	buf->buf_h->prev=node;
	node->next=buf->buf_h;
	node->prev=buf->buf_r;

if(0)
{
printf("<----In node add, the new node address is: %p, node prev is: %p, node next is: %p.\n", node,node->prev,node->next);
printf("<----             the buffer head is: %p, the buffer rare is: %p. <<< Note: rare has NOT moved forward yet!\n",buf->buf_h,buf->buf_r);
}
	//buf->buf_r=node;  //move rare forward, it should be done after calling the buffer write function!
	return 0;
}


/*
 * 10. FIFO Buffer Create - Dynamic Circular linked-list Stream Buffer
 *     Buffer head pointer has been moved forward after buffer reading (because FIFO);
 *            so, just remove the node before the head, and free its space.
 *     This function should only be called in the buffer_read function & buffer_flush function!
 */
int buf_dcs_nr(DCSP_T *buf)
{
	DCSN_T *node=buf->buf_h->prev;  //the node to be remove from Buffer, then free the space

	buf->buf_h->prev=buf->buf_r;
	buf->buf_r->next=buf->buf_h;

	//node->nmsg calls malloc() to get space in the buffer_write function, but its space is free here
	node->next=node->prev=NULL;
	free (node->nmsg);  //free message space
	node->nlen=0;
	free (node);

	return 0;
}


/*
 * 02. FIFO Buffer Delete - Dynamic Circular linked list Stream Buffer Delete.
 *     Free the last buffer node space in the buffer, then free the Buffer pointers structure space.
 *     buf_dcs_clear() will free all the other node except the last one.
 */
int buf_dcs_del(DCSP_T *buf)
{
	if(buf_dcs_len(buf)!=0)
		buf_dcs_clear(buf);

	//to free the last buffer node
	DCSN_T *node=buf->buf_h;
	node->prev=node->next=NULL;
	free(node);

	//to free the buffer pointer structure
	buf->buf_h=buf->buf_r=NULL;
	free(buf);

	return 0;
}


/* tested
 * 03. FIFO Buffer Length - Dynamic Circular linked list Buffer.
 */
int buf_dcs_len(const DCSP_T *buf)
{
	int len;
	DCSN_T *node;
	for(len=0,node=buf->buf_h;node!=buf->buf_r;len++,node=node->next);
	return len;
}


/*
 * 04. FIFO Buffer Clear - Dynamic Circular linked list Buffer.
 *     Initial buffer: remove nodes, free the used space, without any output
 */
void buf_dcs_clear(DCSP_T *buf)
{
	DCSN_T *node, *np=buf->buf_r;
	for(node=buf->buf_h;node!=buf->buf_r;node=node->next)
	{
		//to remove node from linked-list
		node->prev->next=node->next;
		node->next->prev=node->prev;
		buf->buf_h=node->next;   //move the buffer head forward

		//to free node
		free(node->nmsg);
		node->nlen=0;
		node->prev=node->next=NULL;
		free(node);
	}
}

void buf_dcs_clear2(DCSP_T *buf)
{
	while(buf_dcs_len(buf)!=0)
	{
		buf->buf_h=buf->buf_h->next;
		buf_dcs_nr(buf);
	}
}

/*
 * 05. FIFO Buffer flush - Dynamic Circular linked list Buffer.
 *     Output all the data from Buffer to an output file, then initial the buffer: remove nodes, free space.
 */
int buf_dcs_flush(DCSP_T *buf, FILE *fp)
{
	int i=buf_dcs_len(buf);
	while(buf_dcs_len(buf)!=0) buf_dcs_r(fp,buf);
	return i;
}


/*
 * 06. FIFO Buffer Writing- Dynamic Circular linked list Buffer Write.
 *	   Call buf_dcs_na() to add ONE node in the rare of buffer,
 *	   then write ONE piece of message into that node, and then move the rare pointer forward.
 */
int buf_dcs_w(DCSP_T *buf, FILE *fp)
{
	if(buf_dcs_len(buf)==BUFFER_SIZE) return -1;  //return -1 if Buffer is FULL

	char ch;
	int len=0;
	int loc=ftell(fp); //the current Read position of file
	int i;

	//to get the length of the message to be write into buffer
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch=='\n') break;
		len++;  //EOF or '\n' is not included in
	}

	if(len==0) return 0; //return 0 if the message is blank
	else if(len > MSG_SIZE-1) len=MSG_SIZE-1; //only write the message with the length less than or equal to MSG_SIZE;

	fseek(fp,loc,0);  //set the file read pointer back

	buf_dcs_na(buf);  // add a node for the new data

	DCSN_T *node=buf->buf_r;  //add data at rare
	node->nmsg=(char *)malloc(len+1); //create space for storage the new data
	node->nlen=len+1;

	//to write data into buffer
	char *cp;
	for(i=0,cp=node->nmsg;i<len;i++,cp++)
	{
		*cp=fgetc(fp);
	}
	*cp=BUF_MODE;  //set the last char of the message to BUF_MODE

	buf->buf_r=node->next;  //move the rare pointer forward after writing data

	return len+1;  //return the amount of char written into Buffer
}


/*
 * 07. FIFO Buffer Reading - Dynamic Circular linked list Buffer Read.
 *     Read data from the buffer head node to an output file, move the head pointer forward,
 *     then call buf_dcs_nr() to remove that previous head node.
 */
int buf_dcs_r(FILE *fp, DCSP_T *buf)
{
	if(buf_dcs_len(buf)==0)  return -1; //return -1, if Buffer is EMPTY

	DCSN_T *node=buf->buf_h;  //read buffer from head
	if(node->nlen==0) return 0; //return 0 if the message is blank

	int i;
	char *cp=node->nmsg;
	for(i=0;i<node->nlen;i++,cp++) fputc(cp,fp); //output the message to file

	buf->buf_h=node->next;  //move the Buffer head forward after reading
	buf_dcs_nr(buf);  //remove the node after Buffer reading, and the message space free is in this function.

	return node->nlen; //retrun the amount of char read from Buffer
}





/*
 * 08. DCll node data list for Debug
 */
int buf_dcs_nlist_a(DCSP_T *buf)  // list node address info
{
	printf("\nIn 08 node address list:     <--(to list the linked-list nodes' addresses)\n");
	printf("BUffer Addresses are: Buffer: %p; head: %p, rear is: %p; then the node info ... :\n",buf,buf->buf_h,buf->buf_r);
	int i=0;
	DCSN_T *node=buf->buf_r;

	//print the rare node for buffer rare pointer.
	printf("Node RARE: node address: %p, node prev: %p, node next: %p\n",node,node->prev,node->next);

	if(buf->buf_h==buf->buf_r) printf("--> in 08, buf head == buf rare, the Buffer is empty !\n");
	for(i=1,node=node->next;node!=buf->buf_r;i++,node=node->next)
		{
//to list the node address info
			printf("node %2d; node address: %p, node prev: %p, node next: %p\n",i,node,node->prev,node->next);
		}

	return i;
}
