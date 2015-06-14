#include "buffer_global.h"
//#include "buffer_test.h"
//#include "singly_linked_list-jq.h"
//#include <stdio.h>

int buffer_test()
{
	BUFP_T *buff=(BUFP_T *) malloc(BPLEN);
	SLL_T *node=(SLL_T *) malloc(BULEN);
	int n=BUFFER_SIZE;
	int i, ret;
	char sw[STR_SIZE];  //string write to buffer
	strcpy(sw, _S1);    //we can use _S1, _S2 to test the short string, or _SL for long sting
	char *br=(char *)malloc(STR_SIZE);  //string for buffer read

//	printf("This is in buffer_test, and the buffer size is: %d\n",n);

//01, to test buffer create: buf_sll_create()
	buff=buf_sll_create(n);
printf("Call 01. Buffer Create function successfully! The buffer head is: 0x%08X\n",buff->buf_h);

if(DEBUG)
{
	//to print the pointers to the Buffer Created
	printf("\nIn main buffer_test, 01. Buffer create, the buffer pointer structure address is %p\nand the head of Buffer created is: %p\n",buff,buff->buf_h);

	//to print the nodes of Buffer Created in details
	node=buff->buf_h;  //assign the head of buffer to the 1st linked-list node
	printf("the nodes of the Buffer created are:\n");
	for(i=1;i<=n;i++)  //doesn't like string array which counts from 0, the buffer node counts from 1
	{
		printf("Node.%2d created! --> the node address is: 0x%08X, and node->next is: 0x%08X\n",i, node, node->next);
		node=node->next;
	}
}


//06, to test buffer write: buf_sll_w(), it returns the amount of char written.
	ret=buf_sll_w(buff,sw);
	printf("\nCall 06 buf_sll_w() successfully, write string: %s , %d nodes written.(including '\\0')\n",sw,ret);

if(DEBUG)
{
	//to print the nodes of Buffer data after write in details
	node=buff->buf_h;  //assign the head of buffer to the 1st linked-list node
	printf("\nIn main buffer_test(), calling 06. Buffer write, it wrote %d nodes data as following:\n",ret);
	for(i=1;i<=n;i++)  //doesn't like string array which counts from 0, the buffer node counts from 1
	{
		if(node->buc=='\0') break;
		printf("Node.%2d, the char stores in node: %c, and the node address is: 0x%08X\n",i, node->buc, node);
		node=node->next;
	}
	printf("Node.%2d, the char stores in node:\\0. and the node address is: 0x%08X. <-- the last written one, stop print data!\n",i,node);
}

//03. to test buffer length
	ret=buf_sll_len(buff);
	printf("\nCall 03 buf_sll_len() successfully, the buffer length is: %d.(including '\\0')\n", ret);

//07. to test buffer read
	ret=buf_sll_r(br,buff);
	printf("\nCall 07 buf_sll_r() successfully, read %d nodes(including '\\0'), and get the string: %s\n", ret, br);

//	ret=buf_sll_r2(br,buff);
//	printf("\nCall 07.2 buf_sll_r2() successfully, read %d nodes(including '\\0'), and get the string: %s\n", ret, br);



//02. to test buffer delete: buf_sll_del()
	ret=buf_sll_del(buff);

printf("\nIn main buffer_test(), after call 02. Buffer delete function, the return is: %d. Buffer delete Successfully !!!\n",ret);


	return 0;
}


