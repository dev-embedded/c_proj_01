/*
 * singly_linked_list-jq.h
 *
 *  Created on: May 25, 2015
 *      Author: juequ
 */

#ifndef SINGLY_LINKED_LIST_JQ_H_
#define SINGLY_LINKED_LIST_JQ_H_

#define NULL 0
#define _NA -999  //Not Available

//buffer mode:
#define _IOFBF 1  //Full Buffer
#define _IOLBF 2  //Line Buffer
#define _IONBF 3  //No Buffer

typedef struct  sll//singly linked list buffer
{
	char buc;   //buffer list unit char
	struct sll *next;
}SLL_T;

#define BULEN sizeof(SLL_T)  //Buffer List Unit Length

typedef struct buf_pt    //Buffer pointers
{
	SLL_T * buf_h;   //Buffer head (singly linked list)
//	SLL_T * buf_e;   //Buffer end (singly linked list)
	SLL_T * buf_c;   //Buffer current position (singly linked list). It equals to buf_h when the buffer
					//is empty, and it equals to NULL when the buffer is full.
}BUFP_T;

/*
 * 01. FIFO Buffer Create - Singly linked list Buffer Create.
 *     And initial the buffer created.
 */
BUFP_T * buf_sll_create(const int n);

/*
 * 02. FIFO Buffer Delete - Singly linked list Buffer Delete.
 */
int buf_sll_del(BUFP_T *buf);

/*
 * 03. FIFO Buffer Length - Singly linked list Buffer Length.
 */
int buf_sll_len(const BUFP_T *buf);

/*
 * 04. FIFO Buffer Clear - Singly linked list Buffer Length.
 *     Remove all the data stores in Buffer
 */
void buf_sll_clear(BUFP_T *buf);

/*
 * 05. FIFO Buffer flush - Singly linked list Buffer Length.
 *     Output the data from Buffer to a file, then clear the buffer data.
 */
int buf_sll_flush(FILE *stream, BUFP_T *buf);
int buf_sll_flush2(FILE *stream, BUFP_T *buf);

/*
 * 06. FIFO Buffer Writing- Singly linked list Buffer Write.
 */
int buf_sll_w(BUFP_T *buf, char *txt);

/*
 * 07. FIFO Buffer Reading - Singly linked list Buffer Read.
 */
int buf_sll_r(FILE *stream, BUFP_T *buf, int bufmod);


#endif /* SINGLY_LINKED_LIST_JQ_H_ */
