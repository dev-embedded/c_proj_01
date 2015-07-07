#ifndef LIB_BUFFER_SINGLY_LINKED_LIST_ST_H_
#define LIB_BUFFER_SINGLY_LINKED_LIST_ST_H_

typedef struct buffer_node *l_buffer_node;

//structure buffer node
struct buffer_node
{
    char data;
    struct buffer_node *next;
}buf_node;


//structure buffer
typedef struct buf
{
	l_buffer_node loc_read;
	l_buffer_node loc_write;
    int size;
}buffer_st;

int buffer_test();

buffer_st *buf_init_st();

void buf_exit_st(buffer_st *buffer);

void buf_clear_st(buffer_st *buffer);

int buf_isempty_st(buffer_st *buffer);

int buf_getlength_st(buffer_st *buffer);

char buf_getdata_st(buffer_st *buffer);

l_buffer_node buf_getread_st(buffer_st *buffer);

l_buffer_node buf_getwrite_st(buffer_st *buffer);

buffer_st *buf_insert_st(buffer_st *buffer, char ch);

buffer_st *buf_del_st(buffer_st *buffer);

int buf_write_st(buffer_st *buffer, const char *str);

buffer_st *buf_read_st(buffer_st *buffer);

#endif /* LIB_BUFFER_SINGLY_LINKED_LIST_ST_H_ */
