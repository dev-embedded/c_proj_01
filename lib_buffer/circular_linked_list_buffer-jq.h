/*
 * circular_linked_list_buffer-jq.h
 *
 *  Created on: Jun 24, 2015
 *      Author: juequ
 */

#ifndef CIRCULAR_LINKED_LIST_BUFFER_JQ_H_
#define CIRCULAR_LINKED_LIST_BUFFER_JQ_H_


typedef struct  cll //Circular Linked List BUFFER Node Structure
{
	char bch;   //buffer node char
	struct cll *prev;
	struct cll *next;
}CBN_T;       //Circular linked-list Buffer Node Type

typedef struct cll_buf_pt    //Pointers of a Circular Linked List Buffer
{
	int blen;		//Buffer used length (the amount of nodes which contain useful information)
	CBN_T * cllb_h; //Buffer head (circular linked list)
	CBN_T * cllb_e; //Buffer end (circular linked list);
					//if(buf_e==buf_h && blen==0), the Buffer is empty;
					//if(buf_e==buf_h && blen>0), the Buffer is full.
}CBP_T;      //Circular linked-list Buffer Pointer Type


#define NLEN sizeof(CBN_T)  //Buffer Node Structure Length
#define PLEN sizeof(CBP_T)  //Buffer Pointers Structure Length


/*
 * 01. FIFO Buffer Create - Circular linked list Buffer Create.
 *     And initial the buffer created.
 */
CBP_T * buf_cll_create(const int n);

/*
 * 02. FIFO Buffer Delete - Circular linked list Buffer Delete.
 */
int buf_cll_del(CBP_T *buf);

/*
 * 03. FIFO Buffer Length - Circular linked list Buffer.
 */
int buf_cll_len(const CBP_T *buf);

/*
 * 04. FIFO Buffer Clear - Circular linked list Buffer.
 *     Remove all the data stores in Buffer, without any output
 */
void buf_cll_clear(CBP_T *buf);

/*
 * 05. FIFO Buffer flush - Circular linked list Buffer.
 *     Output all the data from Buffer to a file, then clear the buffer data.
 */
int buf_cll_flush(CBP_T *buf);
//int buf_cll_flush2(FILE *stream, CBP_T *buf);

/*
 * 06. FIFO Buffer Writing- Circular linked list Buffer Write.
 *
 */
int buf_cll_w(CBP_T *buf, char *txt);

/*
 * 07. FIFO Buffer Reading - Circular linked list Buffer Read.
 *     output data based bufmod
 */
//int buf_cll_r(FILE *stream, CBP_T *buf, int bufmod);
int buf_cll_r(char *c, CBP_T *buf);
//int buf_cll_r2(char *c, CBP_T *buf);

/*
 * 08. cll node test
 */
int buf_cll_list_node_a(CBP_T *buf);  // list node address info
int buf_cll_list_node_c(CBP_T *buf);  // list node char info
int buf_cll_list_node_f(CBP_T *buf);  // list node full info


#endif /* CIRCULAR_LINKED_LIST_BUFFER_JQ_H_ */
