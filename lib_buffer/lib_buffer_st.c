#include <stdio.h>
#include <malloc.h>
#include "lib_buffer_st.h"

buffer_st *buf_init_st()
{
	buffer_st *new_buffer = (buffer_st *) malloc(sizeof(buffer_st));
	if (new_buffer != NULL)
	{
		new_buffer->loc_read = NULL;
		new_buffer->loc_write = NULL;
		new_buffer->size = 0;
	}
	return new_buffer;
}

void buf_exit_st(buffer_st *buffer)
{
	if (buffer->size != 0)
	{
		buf_clear_st(buffer);
	}
	free(buffer);
}

void buf_clear_st(buffer_st *buffer)
{

}

int buf_isempty_st(buffer_st *buffer)
{
	if (buffer->loc_read == NULL && buffer->loc_write == NULL
			&& buffer->size == 0)
	{
		return 1;
	}
	return 0;
}

int buf_getlength_st(buffer_st *buffer)
{
	return buffer->size;
}

char buf_getdata_st(buffer_st *buffer)
{
	return buffer->loc_read->data;
}

l_buffer_node buf_getread_st(buffer_st *buffer)
{
	return buffer->loc_read;
}

l_buffer_node buf_getwrite_st(buffer_st *buffer)
{
	return buffer->loc_write;
}

buffer_st *buf_insert_st(buffer_st *buffer, char ch)
{
	l_buffer_node new_node = (l_buffer_node) malloc(sizeof(buf_node));
	if (new_node != NULL)
	{
		new_node->data = ch;
		new_node->next = NULL;

		if (buf_isempty_st(buffer))
		{
			buffer->loc_read = new_node;
		}
		else
		{
			buffer->loc_write->next = new_node;
		}
		buffer->loc_write = new_node;
		buffer->size++;
	}
	return buffer;
}

buffer_st *buf_del_st(buffer_st *buffer)
{
	l_buffer_node temp_node = buffer->loc_read;
	printf("%c", buffer->loc_read->data);
	buffer->loc_read = buffer->loc_read->next;
	free(temp_node);
	if (buffer->size == 0)
	{
		buffer->loc_write = NULL;
	}
	return buffer;
}

buffer_st *buf_write_st(buffer_st *buffer, const char *str)
{
	char *p = str;
	while (*p != '\0')
	{
		buf_insert_st(buffer, *p);
		p++;
	}
	buf_insert_st(buffer, '\0');

	return buffer;
}

buffer_st *buf_read_st(buffer_st *buffer, const char *str)
{
	char *p = str;
	while (*p != '\0')
	{
		buf_insert_st(buffer, *p);
		p++;
	}
	buf_insert_st(buffer, '\0');

	return buffer;
}
