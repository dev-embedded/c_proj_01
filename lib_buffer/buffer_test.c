#include <stdio.h>
#include "lib_buffer_st.h"

int buffer_test()
{

	char *str = "BC";
 buffer_st *buffer = buf_init_st();
	printf("created a new buffer!\n");

	buf_insert_st(buffer, 'A');
	buf_write_st(buffer, str);

	printf("first element is : %c\n",buf_getdata_st(buffer));


	printf("second element is : %c\n",buffer->loc_read->next->next->data);

	buf_exit_st(buffer);
	printf("destroy the buffer !\n");
	return 0;
}


