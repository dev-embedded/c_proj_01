/*
 * STBuf_DCllS.h
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

#ifndef STBUF_DCLLS_H_
#define STBUF_DCLLS_H_


typedef struct  dclls_node //Dynamic Circular linked-list Stream Buffer NODE Structure
{
	char *nmsg;	//pointer to the message node where it stores
	int nlen;	//message node length
	struct dclls_node *prev;
	struct dclls_node *next;
}DCSN_T;       //Dynamic Circular linked-list Stream Buffer NODE Type

typedef struct dclls_buf_pt    //Pointers of a Dynamic Circular linked-list Stream Buffer Structure
{
	DCSN_T * buf_h; //Buffer head (Dynamic circular linked list)
	DCSN_T * buf_r; //Buffer rare (Dynamic circular linked list);
					//if(dcs_h==dcs_r), the Buffer is empty; if(dcs_r->next==dcs_h), the Buffer is full.
					//Since this is Dynamic CLL, the nodes added on demand, there is no empty node in the buffer, actually
}DCSP_T;      //Dynamic Circular linked-list Stream Buffer POINTER Type


#define DNLEN sizeof(DCSN_T)  //Dynamic Buffer Node Structure Length
#define DPLEN sizeof(DCSP_T)  //Dynamic Buffer Pointers Structure Length
#define IS_EMPTY(buf) (((buf)->dcs_h)==((buf)->dcs_r))
#define IS_FULL(buf)  (((buf)->dcs_h)==(((buf)->dcs_r)->next))

/*
 * 01. FIFO Buffer Create - Dynamic Circular linked-list Stream Buffer Create.
 *     And initial the buffer created.
 */
DCSP_T * buf_dcs_create();

/*
 * 09. FIFO Buffer Create - Dynamic Circular linked-list Stream Buffer
 *     Node add, always add at the rare (because FIFO)
 */
int buf_dcs_na(DCSP_T *buf);

/*
 * 10. FIFO Buffer Create - Dynamic Circular linked-list Stream Buffer
 *     Node remove, always remove the head node (because FIFO)
 */
int buf_dcs_nr(DCSP_T *buf);

/*
 * 02. FIFO Buffer Delete - Dynamic Circular linked list Stream Buffer Delete.
 */
int buf_dcs_del(DCSP_T *buf);

/*
 * 03. FIFO Buffer Length - Dynamic Circular linked list Buffer.
 */
int buf_dcs_len(const DCSP_T *buf);

/*
 * 04. FIFO Buffer Clear - Dynamic Circular linked list Buffer.
 *     Initial buffer: remove nodes, free the used space, without any output
 */
void buf_dcs_clear(DCSP_T *buf);
void buf_dcs_clear2(DCSP_T *buf);

/*
 * 05. FIFO Buffer flush - Dynamic Circular linked list Buffer.
 *     Output all the data from Buffer to an output file, then initial the buffer: remove nodes, free space.
 */
int buf_dcs_flush(DCSP_T *buf, FILE *fp);
//int buf_cll_flush2(FILE *stream, DCSP_T *buf);

/*
 * 06. FIFO Buffer Writing- Dynamic Circular linked list Buffer Write.
 *	   Add a node in the rare of buffer, then write a piece of message into that node.
 */
int buf_dcs_w(DCSP_T *buf, FILE *fp);

/*
 * 07. FIFO Buffer Reading - Dynamic Circular linked list Buffer Read.
 *     Read data from the buffer head node to an output file, then remove that node.
 */
//int buf_cll_r(FILE *stream, DCSP_T *buf, int bufmod);
int buf_dcs_r(FILE *fp, DCSP_T *buf);


/*
 * 08. DCll node data list for Debug
 */
int buf_dcs_nlist_a(DCSP_T *buf);  // list node address info
int buf_dcs_nlist_m(DCSP_T *buf);  // list node message info
int buf_dcs_nlist_f(DCSP_T *buf);  // list node full info

#endif /* STBUF_DCLLS_H_ */
