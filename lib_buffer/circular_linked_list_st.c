#include <stdio.h>
#include <malloc.h>
#include "buffer_global.h"
#include "circular_linked_list_st.h"

cll_buffer_st *cll_buf_init_st()
{
	cll_buffer_st *new_cll_buffer = (cll_buffer_st *) malloc(
			sizeof(cll_buffer_st));
	if (new_cll_buffer != NULL)
	{
		new_cll_buffer->loc_read = NULL;
		new_cll_buffer->loc_write = NULL;
		new_cll_buffer->size = 0;
		int i;
		for (i = 0; i < BUFFER_SIZE; i++)
		{
			cl_buffer_node new_cl_node = (cl_buffer_node) malloc(
					sizeof(cll_buf_node));
			if (new_cl_node != NULL)
			{
				new_cl_node->next = NULL;
				new_cl_node->data = NULL;

				if (buf_isempty_st(new_cll_buffer))
				{
					new_cll_buffer->loc_read = new_cl_node;
				}
				else
				{
					new_cll_buffer->loc_write->next = new_cl_node;
				}
				new_cll_buffer->loc_write = new_cl_node;
			}
		}
		new_cll_buffer->loc_write->next = new_cll_buffer->loc_read;
	}
	return new_cll_buffer;
}

void cll_buf_exit_st(cll_buffer_st *buffer)
{
	if (buffer->size > 0)
	{
			cll_buf_clear_st(buffer);
	}
		free(buffer);
}

void cll_buf_clear_st(cll_buffer_st *buffer)
{
		while (!cll_buf_isempty_st(buffer))
		{
			cll_buf_del_st(buffer);
		}
}

int cll_buf_isempty_st(cll_buffer_st *buffer)
{
	if (buffer->loc_read == buffer->loc_write && buffer->size == 0)
		{
			return 1;
		}
		return 0;
}

int cll_buf_isfull_st(cll_buffer_st *buffer)
{
	if (buffer->size == BUFFER_SIZE)
		{
			return 1;
		}
		return 0;
}

int cll_buf_getlength_st(cll_buffer_st *buffer)
{
	return buffer->size;
}

char cll_buf_getdata_st(cll_buffer_st *buffer)
{
	return buffer->loc_read->data;
}

cl_buffer_node cll_buf_getread_st(cll_buffer_st *buffer)
{
	return buffer->loc_read;
}

cl_buffer_node cll_buf_getwrite_st(cll_buffer_st *buffer)
{
	return buffer->loc_write;
}

cll_buffer_st *cll_buf_insert_st(cll_buffer_st *buffer, char ch)
{
	buffer->loc_write->data = ch;
	buffer->size++;

	return buffer;
}

cll_buffer_st *cll_buf_del_st(cll_buffer_st *buffer)
{
	buffer->loc_read->data = NULL;
	buffer->size--;

	return buffer;
}

int cll_buf_write_st(cll_buffer_st *buffer, const char *str)
{
	int cnt = 0;


	return cnt;
}

cll_buffer_st *cll_buf_read_st(cll_buffer_st *buffer)
{


	return buffer;
}

