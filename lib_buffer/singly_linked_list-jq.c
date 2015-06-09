/*
 * singly_linked_list-jq.c
 *
 *  Created on: May 25, 2015
 *      Author: juequ
 */

#include "singly_linked_list-jq.h"

/*
 * 01. FIFO Buffer Create - Singly linked list Buffer Create.
 *     And initial the buffer created.
 */
BUFP_T *buf_sll_create(const int n)
{
	int i;
	SLL_T *head, *bp, *temp;
	head=NULL;
	for(i=0;i<n;i++)
		{
		bp=(SLL_T*)malloc(BULEN);
		if(i==0) head=bp;
		else temp->next=bp;
		temp=bp;
		}
	temp->next=NULL;  //for the end of linked-list

	BUFP_T *buff;
	buff->buf_h=head;  //buffer head
	buff->buf_c=head;  //initial the current pointer to head.
//	buff->buf_e=temp;  //buffer end
	return buff;
}

/*
 * 02. FIFO Buffer Delete - Singly linked list Buffer Delete.
 */
int buf_sll_del(BUFP_T *buf)
{
	SLL_T *pb, *pe;  //pe: end of the list
	pe=buf->buf_h;
	while(pe->next!=NULL)
	{
		while(pe->next!=NULL)
		{
			pb=pe;
			pe=pe->next;
		}
	free(pb->next);
	pb->next=NULL;
	pe=buf->buf_h;
	}
	free(buf);
	buf->buf_h=buf->buf_c=NULL;
	return 0;
}

/*
 * 03. FIFO Buffer Length - Singly linked list Buffer Length.
 */
int buf_sll_len(const BUFP_T *buf)
{
	int i;
	SLL_T *pb=buf->buf_h;
	for(i=0;;i++)
	{
		if(pb==buf->buf_c) break;
		pb=pb->next;
	}
	return i;
}

/*
 * 04. FIFO Buffer Clear - Singly linked list Buffer Length.
 *     Remove all the data stores in Buffer
 */
void buf_sll_clear(BUFP_T *buf)
{
	buf->buf_c=buf->buf_h;   // the current pointer point to the head of the singly linked list
}

/*
 * 05. FIFO Buffer flush - Singly linked list Buffer Length.
 *     Output the data from Buffer to a file, then clear the buffer data.
 */

// Output all of the content first, then point buf_c to the head of the linked list
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

/*
 * 06. FIFO Buffer Writing- Singly linked list Buffer Write.
 */
int buf_sll_w(BUFP_T *buf, char *txt)
{
	return _NA; //NOT Available
}

/*
 * 07. FIFO Buffer Reading - Singly linked list Buffer Read.
 */
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

