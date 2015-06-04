#include <stdio.h>
#include "lib_buffer_st.h"

int buffer_test()
{

	char *str = "ABCDEFGHJKL0123456789";
	int cnt = 0;
	char *tmp = str;
 buffer_st *buffer = buf_init_st();
	printf("created a new buffer!\n");

	buf_insert_st(buffer, 'A');

	cnt = buf_write_st(buffer, str);
	if(cnt == -1)
	{
		buf_read_st(buffer);
	}else{
		while(cnt != -1)
		{
			tmp = tmp + cnt;
			buf_read_st(buffer);
			buf_clear_st(buffer);
			cnt = buf_write_st(buffer, tmp);
		}
		buf_read_st(buffer);
	}

	//printf("first element is : %c\n",buf_getdata_st(buffer));


	//printf("second element is : %c\n",buffer->loc_read->next->next->data);



	buf_exit_st(buffer);
	printf("\ndestroy the buffer !\n");
	return 0;
}


