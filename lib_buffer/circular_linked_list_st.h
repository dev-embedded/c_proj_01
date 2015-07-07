/*
 * circular_linked_list_st.h
 *
 *  Created on: 2015年7月6日
 *      Author: suntao
 */

#ifndef LIB_BUFFER_CIRCULAR_LINKED_LIST_ST_H_
#define LIB_BUFFER_CIRCULAR_LINKED_LIST_ST_H_
typedef struct cll_buffer_node *cl_buffer_node;

//structure buffer node
struct cll_buffer_node
{
    char data;
    struct cll_buffer_node *next;
}cll_buf_node;


//structure buffer
typedef struct cll_buf
{
	cl_buffer_node loc_read;
	cl_buffer_node loc_write;
  int size;
}cll_buffer_st;

int cll_buffer_test();

cll_buffer_st *cll_buf_init_st();

void cll_buf_exit_st(cll_buffer_st *buffer);

void cll_buf_clear_st(cll_buffer_st *buffer);

int cll_buf_isempty_st(cll_buffer_st *buffer);

int cll_buf_getlength_st(cll_buffer_st *buffer);

char cll_buf_getdata_st(cll_buffer_st *buffer);

cl_buffer_node cll_buf_getread_st(cll_buffer_st *buffer);

cl_buffer_node cll_buf_getwrite_st(cll_buffer_st *buffer);

cll_buffer_st *cll_buf_insert_st(cll_buffer_st *buffer, char ch);

cll_buffer_st *cll_buf_del_st(cll_buffer_st *buffer);

int cll_buf_write_st(cll_buffer_st *buffer, const char *str);

cll_buffer_st *cll_buf_read_st(cll_buffer_st *buffer);


#endif /* LIB_BUFFER_CIRCULAR_LINKED_LIST_ST_H_ */
