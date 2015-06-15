/*
 * singly_linked_list-jq.c
 *
 *  Created on: May 25, 2015
 *      Author: juequ
 */

#include "buffer_global.h"
//#include "singly_linked_list-jq.h"

/*
 * 01. FIFO Buffer Create - Singly linked list Buffer Create.
 *     And initial the buffer created.
 */
BUFP_T *buf_sll_create(const int n)
{
//printf("now, we are in buf_sll_create() !\n");
	int i;
	SLL_T *bp;
	SLL_T *head, *temp;
	head=NULL;
	for(i=0;i<n;i++)
		{
		bp=(SLL_T *) malloc(BULEN);
// printf("When i=%2d, the address of Buffer = 0x %08X, or %%p=%p\n",i,bp,bp);
		if(i==0) head=bp;
		else temp->next=bp;
		temp=bp;

		}
	temp->next=NULL;  //for the end of linked-list
	//BUFP_T buff;   //NOTE: to define: BUFP_T *buff, we should assign memory for it by malloc(); otherwise, it won't work!
	BUFP_T *buff=(BUFP_T *) malloc(sizeof(BUFP_T));
	buff->buf_h=head;  //buffer head
	buff->buf_c=head;  //initial the current pointer to head.
//	buff->buf_e=temp;  //buffer end

//printf("\nIn 01. buf_sll_create(), the HEAD of Buffer created is: 0x %08X,",buff.buf_h);
//printf("and the CUR of Buffer created is: 0x %08X\n",buff.buf_c);

	return buff;
}

/*
 * 02. FIFO Buffer Delete - Singly linked list Buffer Delete.
 */
int buf_sll_del(BUFP_T *buf)
{
	int i=BUFFER_SIZE; //for node count
	SLL_T *pb, *pe;  //pe: end of the list
	pe=buf->buf_h;
if(DEBUG) printf("\nIn 02. buf_sll_del()\n");
	while(pe->next!=NULL)
	{
		while(pe->next!=NULL)
		{
			pb=pe;   //to find out the node before the last one.
			pe=pe->next;
		}
if(DEBUG) printf("node.%2d to be free --> its next point to: %p, and its address is: 0x%08X\n",i--,pe->next,pe);
	//free(pb->next);
	free(pe);
	pb->next=NULL;  //after free the last node, point the node before it to NULL.
	pe=buf->buf_h;  //re-point the *pe to the head to find the end of the list in the next while round.
	}

if(DEBUG) printf("node.%2d to be free --> its next point to: %p, and its address is: 0x%08X. <-- The LAST node.\n",i,pe->next,pe);
	free(pe);  //to free the last one left in the linked-list

if(DEBUG) printf("Finally, free the Buffer Pointers Structure: %p\n",buf);
	free(buf);

	return 0;
}

/*
 * 03. FIFO Buffer Length - Singly linked list Buffer Length.
 * Note: 1. Not like array which counts from 0, buffer length counts from 1.
 * 		 2. Not like strlen() which ignores the '\0', buffer length includes '\0'
 */
int buf_sll_len(const BUFP_T *buf)
{
	int i;
	SLL_T *pb;
	pb=buf->buf_h;

	//Going through the singly linked-list to find out the location of buf->buf_c
	for(i=0;i<BUFFER_SIZE;i++)
	{
		if(pb==buf->buf_c) break;
		pb=pb->next;
	}

	return i;
}

/*
 * 04. FIFO Buffer Clear - Singly linked list Buffer Clear.
 *     Remove all the data stores in Buffer
 */
void buf_sll_clear(BUFP_T *buf)
{
	buf->buf_c=buf->buf_h;   // the current pointer point to the head of the singly linked list
}

/*
 * 05. FIFO Buffer flush - Singly linked list Buffer.
 *     Output all the data from Buffer to a string and print it, then clear the buffer data.
 */
int buf_sll_flush(BUFP_T *buf)
{
	SLL_T *pb=buf->buf_h;
	int i;
	char str[BUFFER_SIZE+1]; // +1 for '\0'
	//Output the content of the linked list
	for(i=0;i<BUFFER_SIZE;i++)
	{
		str[i]=pb->buc;  //output a char from linked list to string
		pb=pb->next;
// printf("\In 05 buf_sll_flush(), when i=%d, char=%c\n", i, str[i]);
	}
	str[BUFFER_SIZE]='\0';  // to finish the string
	printf("In 05 Flush Buffer(), The data output is: %s\n",str);
	buf->buf_c=buf->buf_h;  //to point buf_c to the head of linked list
	return i;
}

/*
// Output all of the content to a FILE *stream, then point buf_c to the head of the linked list
// Note ---> code is NOT tested, and function is NOT used here !!!

int buf_sll_flush(FILE *stream, BUFP_T *buf)
{
	char ch;
	SLL_T *pb;
	int i;
	int len=buf_sll_len(buf);

	//Output the content of the linked list
	for(i=0;i<len;i++)
	{
		pb=buf->buf_h;
		ch=pb->buc;  //get a char from linked list
		fputc(ch,stream);  //output the char to stream
		pb=pb->next;
	}
	buf->buf_c=buf->buf_h;  //to point buf_c to the head of linked list
	return 0;
}

//Output char one by one, renew the linked list on each char pop-up.
int buf_sll_flush2(FILE *stream, BUFP_T *buf)
{
	char ch;
	SLL_T *pb, *pt;
	while(buf->buf_c != buf->buf_h)
	{
		ch=(buf->buf_h)->buc;  //get the char in head
		fputc(ch,stream);  //output a char to stream

		//to move linked list backward
		pb=buf->buf_h;
		while(pb!=buf->buf_c) //to move chars forward
		{
			pb->buc=(pb->next)->buc;  //get char from next unit of linked-list
			pt=pb;   //pt is for updating buf_c after moving linked list backward
			pb=pb->next;
		}
		buf->buf_c=pt;  //update buf_c after moving linked list backward
	}
	return 0;
}
*/


/*
 * 06. FIFO Buffer Writing- Singly linked list Buffer Write.
 * NOTE: 1. Here, we assume the buffer is always empty before writing.
 *       2. This function returns the length of Buffer used. (including '\0')
 */
int buf_sll_w(BUFP_T *buf, char *c)
{
	int i=1;
//	SLL_T *pb=(SLL_T *)malloc(BULEN);
	buf_sll_clear(buf);  //to make sure the buffer is empty for writing, we assume it should always be empty before writing
	SLL_T *pb=buf->buf_h;
	printf("\nIn 06. buf_sll_w(), the string to be input to buffer is: %s, & its strlen()==%d\n", c, strlen(c));
	while(*c!='\0')
	{
		if(i>1 && (i-1)%BUFFER_SIZE==0) //greater than length, do buffer reader first, then buffer writer.
		{
			printf("buffer writer full, call buf_sll_flush ... \n");
			buf_sll_flush(buf);
			pb=buf->buf_h;   //reset the pb to the head of buffer
		}

		pb->buc=*c;  //write the current char to buffer
if(DEBUG) printf("node=%2d, the address is: 0x%08X, the char input is: %c\n",i,pb,pb->buc);
		buf->buf_c=pb->next;  //re-mark the buf_c pointer after writing a char
		pb=pb->next;
		c++;
		i++;
	}

	//for the last char '\0'
	if(i>1 && (i-1)%BUFFER_SIZE==0) //if buffer full, do buffer reader first, then buffer writer.
	{
		printf("buffer writer full, call buf_sll_flush ... \n");
		buf_sll_flush(buf);
		pb=buf->buf_h;   //reset the pb to the head of buffer
	}
	pb->buc=*c;  //write the last char '\0' to buffer
if(DEBUG)
	{
	if(pb->buc=='\0')
		printf("node=%2d, the address is: 0x%08X, the char input is:\\0. <-- Buffer Write complete!\n",i,pb);
	else
		printf("Err! string not finish with \\0 !!!\n");
	}
	buf->buf_c=pb->next;  //re-mark to the last node of the buffer.

//	free(pb);  //free temporary variable

	return i;
}

/*
 * 07. FIFO Buffer Reading - Singly linked list Buffer Read.
 * NOte: 1. Each time, output one piece of message --- here is a string !
 *       2. This function returns the length of Buffer read. (including '\0')
 */
// 07 Output all of the content first, then point buf_c to the head of the linked list
int buf_sll_r(char *c, BUFP_T *buf)
{
	SLL_T *pb=buf->buf_h;
	int i;
	int len=buf_sll_len(buf);

	//Output the content of the linked list
	for(i=0;i<len;i++)
	{
		*c=pb->buc;  //output a char from linked list to string
		c++;
		pb=pb->next;
	}
	buf->buf_c=buf->buf_h;  //to point buf_c to the head of linked list

	return i;
}

// 07.2 Output char one by one, renew the linked list on each char pop-up.
int buf_sll_r2(char *c, BUFP_T *buf)
{
//	char ch;
	SLL_T *pb, *pt;
	int i=0;
	while(buf->buf_c != buf->buf_h)
	{
		*c=(buf->buf_h)->buc;  //output one char from buffer to string
		c++;
		i++;
		//to move linked list backward
		pb=buf->buf_h;
		while(pb!=buf->buf_c) //to move chars forward
		{
			pb->buc=(pb->next)->buc;  //get char from next unit of linked-list
			pt=pb;   //pt is for updating buf_c after moving linked list backward
			pb=pb->next;
		}
		buf->buf_c=pt;  //update buf_c after moving linked list backward
	}

	return i;
}


/*
//the following code is for buffer output to a FILE *stream based on bufmod, & is NOT tested !!!

int buf_sll_r(FILE *stream, BUFP_T *buf, int bufmod)
{
	if(bufmod==_IOFBF) buf_sll_flush(stream,buf);
	else
	{
		char ch;
		SLL_T *pb, *pt;
		while(buf->buf_c != buf->buf_h && buf->buf_h->buc != '\n')
		{
			ch=(buf->buf_h)->buc;  //get the char in head
			fputc(ch,stream);  //output a char to stream

			//to move linked list backward
			pb=buf->buf_h;
			while(pb!=buf->buf_c) //to move chars forward
			{
				pb->buc=(pb->next)->buc;  //get char from next unit of linked-list
				pt=pb;   //pt is for updating buf_c after moving linked list backward
				pb=pb->next;
			}
			buf->buf_c=pt;  //update buf_c after moving linked list backward
		}

		//to output the '\n'
		while(buf->buf_h->buc == '\n')
		{
			fputc('\n',stream);  //output to stream

			//to move linked list backward
			pb=buf->buf_h;
			while(pb!=buf->buf_c) //to move chars forward
			{
				pb->buc=(pb->next)->buc;  //get char from next unit of linked-list
				pt=pb;   //pt is for updating buf_c after moving linked list backward
				pb=pb->next;
			}
			buf->buf_c=pt;  //update buf_c after moving linked list backward
		}

	}
	return 0;
}
*/

