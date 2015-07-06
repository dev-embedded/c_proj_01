/*
 * circular_linked_list_buffer-jq.c
 *
 *  Created on: Jun 24, 2015
 *      Author: juequ
 */

#include "buffer_global.h"

/*
 * 01. FIFO Buffer Create - Circular linked list Buffer Create.
 *     And initial the buffer created.
 */
CBP_T * buf_cll_create(const int n)
{
	printf("This is in fun: 01 buf_cll_create()\n");
	CBN_T *node, *head, *t;  //for node
	CBP_T *buf=(CBP_T *)malloc(PLEN);
	int i;
	for(i=0;i<n;i++)
	{
		node=(CBN_T *)malloc(NLEN);
		if(i==0) head=node;
		else
		{
			t->next=node;
			node->prev=t;
		}
		t=node;
		t->bch='Z';   //initial the node char
	}
	t->next=head;   //Circular linked-list
	head->prev=t;	//Circular linked-list

	buf->cllb_h=buf->cllb_e=head;  //Initial the Buffer after creating
	buf->blen=0;

	return buf;
}


/*
 * 02. FIFO Buffer Delete - Circular linked list Buffer Delete.
 */
int buf_cll_del(CBP_T *buf)
{
	printf("\nThis is in fun 02 buf_cll_del()\n");
	CBN_T *node=buf->cllb_h;
	CBN_T *next=node->next;
	while(next!=buf->cllb_h)
	{
if(DEBUG)	printf("The node address to be free is: %p\n", node);
		node->next=node->prev=NULL;  //to prevent the future access through node pointers by mistake, after node free
		free(node);
		node=next;
		next=next->next;
	}
	printf("The node address to be free is: %p.  <-- the last node (02)\n", node);
	node->next=node->prev=NULL;  //to prevent the future access through node pointers by mistake, after node free
	free(node);  //free the last node of buffer

	printf("Finally, The Buffer Pointer structure to be free is: %p. <===== The End !!!\n", buf);
	buf->cllb_h=buf->cllb_e=NULL;  //to prevent the future access through these pointers by mistake, after buffer free
	free(buf);   //free the Buffer Pointer structure
	return 0;
}


/*
 * 03. FIFO Buffer Length - Circular linked list Buffer.
 */
int buf_cll_len(const CBP_T *buf)
{
printf("\nThis is in fun 03 buf_cll_len()! ");
	CBN_T *node;
	int i;
	for(i=0,node=buf->cllb_h;i!=buf->blen||node!=buf->cllb_e;i++,node=node->next);
	// this for expression equals the following code:
	// node=buf->cllb_h;
	// if(buf->blen==0 && buf->cllb_h==buf->cllb_e) return 0;   // Buffer is empty!
	// else
	// 		for(i=1;;i++)
	// 		{
	//			node=node->next;
	//			if(node==buf->cllb_e) break;
	// 		}
printf("The length checked by the end pointer is: %d, and the buffer->blen is: %d\n",i,buf->blen);
	return i;
}


/*
 * 04. FIFO Buffer Clear - Circular linked list Buffer.
 *     Remove all the data stores in Buffer, without any output
 */
void buf_cll_clear(CBP_T *buf)
{
printf("\nThis is in fun 04 buf_cll_clear()\n");
	buf->cllb_h=buf->cllb_e;
	buf->blen=0;
	return;
}


/*
 * 05. FIFO Buffer flush - Circular linked list Buffer.
 *     Output all the data from Buffer to a file, then clear the buffer data.
 */
int buf_cll_flush(CBP_T *buf)
{
	CBN_T *node;
	int i;
	printf("\nThis is in fun 05 buf_cll_fulsh(), the output is: ");
	for(i=0,node=buf->cllb_h;i!=buf->blen||node!=buf->cllb_e;i++,node=node->next)
		printf(" %c |",node->bch);
	printf(" <=== \n");
	buf->cllb_h=buf->cllb_e;  //initial buffer after flush
	buf->blen=0;			  //initial buffer after flush
	return i;
}
//int buf_cll_flush2(FILE *stream, CBP_T *buf);


/*
 * 06. FIFO Buffer Writing- Circular linked list Buffer Write.
 *
 */
int buf_cll_w(CBP_T *buf, char *txt)
{
printf("\nThis is in fun 06 buf_cll_w(), the string is: %s, strlen is: %d.  <--('\\0' is not included in!)\n",txt,strlen(txt));
	CBN_T *node;
	int i;
	if(*txt=='\0') return 0;  //if txt is null, nothing will be write to buffer, return 0
	for(i=0,node=buf->cllb_h;*txt!='\0';txt++)
	{

		node->bch=*txt;   // put a char from string to a buffer node
		node=node->next;
		buf->cllb_e=node;
		i++;
		buf->blen = ((i%BUFFER_SIZE)==0) ? BUFFER_SIZE : i%BUFFER_SIZE;

		if(i%BUFFER_SIZE==0)
			buf_cll_flush(buf);  //BUFFER full, call 05 buf_cll_flush()
	}
	node->bch='\0';   //for the last char '\0'
	i++;
	buf->cllb_e=node->next;
	buf->blen = ((i%BUFFER_SIZE)==0) ? BUFFER_SIZE : i%BUFFER_SIZE;  //buffer nodes used to store data
	return i;					//total chars written to buffer
}


/*
 * 07. FIFO Buffer Reading - Circular linked list Buffer Read.
 *     output data based bufmod
 */
//int buf_cll_r(FILE *stream, CBP_T *buf, int bufmod);
int buf_cll_r(char *c, CBP_T *buf)
{
	printf("\nThis is in fun 07 buf_cll_r()\n");
	CBN_T *node;
	int i;
	for(i=0,node=buf->cllb_h;(i!=buf->blen)||(node!=buf->cllb_e);i++,node=node->next,c++)
		*c=node->bch;
	printf("In 07 buf_cll_r(), after reading the buffer, call 04 buff clear!");
	buf_cll_clear(buf);
	return i;
}


/*
 * 08. cll node test --- for debug!
 */
int buf_cll_list_node_a(CBP_T *buf)  //to print the nodes addresses
{
	printf("\nIn 08 node address list:     <--(to list the linked-list nodes' address)\n");
	printf("BUffer Pointer add is: %p; head add is: %p, end add is: %p, & blen is: %d; then the node info ... :\n",buf,buf->cllb_h,buf->cllb_e,buf->blen);
	CBN_T *node;
	node=buf->cllb_h;
	int i;
	for(i=1;i<=BUFFER_SIZE;i++)
	{
//to list the node address info
		printf("node %d; address: %p; node prev: %p, node next: %p\n",i,node,node->prev,node->next);
		node=node->next;
	}

	return i;
}

int buf_cll_list_node_c(CBP_T *buf)  //to print the nodes char
{
	printf("\nIn 08 node char list:     <--(to list the linked-list nodes' char)\n");
	printf("BUffer Pointer add is: %p; head add is: %p, end add is: %p, & blen is: %d; then the node info ... :\n",buf,buf->cllb_h,buf->cllb_e,buf->blen);
	CBN_T *node;
	node=buf->cllb_h;
	int i;
	for(i=1;i<=BUFFER_SIZE;i++)
	{
//to print the node char info
		printf("node %d; char address: %p, char: (ASCII %2d) %c ;\n",i,&node->bch,node->bch,node->bch);
		node=node->next;
	}

	return i;
}

int buf_cll_list_node_f(CBP_T *buf)  //to print the full information
{
	printf("\nIn 08 node details list:     <--(to list the linked-list nodes in details!) <--\n");
	printf("BUffer Pointer add is: %p; head add is: %p, end add is: %p, & blen is: %d; then the node info ... :\n",buf,buf->cllb_h,buf->cllb_e,buf->blen);
	CBN_T *node;
	node=buf->cllb_h;
	int i;
	for(i=1;i<=BUFFER_SIZE;i++)
	{
//to print the node info in more details
		printf("node %d; address: %p, char address: %p, char: (ASCII %2d) %c ;\n",i,node,node->bch,&node->bch,node->bch);
		printf("\t& node prev: %p, node prev address: %p; vs. node next: %p, node next address: %p\n",node->prev,&node->prev,node->next,&node->next);
		node=node->next;
	}

	return i;
}
