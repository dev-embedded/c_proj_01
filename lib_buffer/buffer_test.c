#include "buffer_global.h"
//#include "buffer_test.h"
//#include "singly_linked_list-jq.h"
//#include <stdio.h>

int buffer_test()
{
	int n=BUFFER_SIZE;
	char sw[STR_SIZE];  //string write to buffer
	strcpy(sw, _S1);    //we can use _S1, _S2 to test the short string, or _SL for long sting
	char *br=(char *)malloc(STR_SIZE);  //string for buffer read
	int i, ret;


if(DCSB_ST)
{
	//DCSN_T *np;
	DCSP_T *bp;
printf("Single Thread - Dynamic Circular linked-list Stream Buffer(FIFO) test ==>>> \n");

	//01 buffer create: buf_cll_create()
printf("111111  -  In main(), now create buffer!\n");
		bp=buf_dcs_create();

		//to list the buffer length & the node address
		printf("\n(in main) After created, the buffer length is: %d\n",buf_dcs_len(bp));
		if(DEBUG) buf_dcs_nlist_a(bp);

	//to test buffer node add function
	if(0)
	{
		for(i=1;i<=(BUFFER_SIZE+2);i++)
		{
			printf("\n-------> Add node %d, !move the rare next!\n",i);
			ret=buf_dcs_na(bp);
			if(ret==BUFFER_FULL){ printf("when i=%d, BUFFER_FULL!\n",i); break; }
			bp->buf_r=bp->buf_r->next;  //to move rare forward.
			printf("\n(in main) After add node %d, move the RARE to: %p, then the buffer length is: %d\n",i,bp->buf_r,buf_dcs_len(bp));
			if(DEBUG) buf_dcs_nlist_a(bp);
		}
	}

		ret=buf_dcs_len(bp);
		printf("\n(in main) After add one node without move the rare pointer forward, the buffer length is: %d\n",ret);

}


if(CLLB)
{
	CBP_T *cbuf;
	CBN_T *cnode;

	//01 buffer create: buf_cll_create()
		cbuf=buf_cll_create(n);
		if(DEBUG) buf_cll_list_node_a(cbuf);
		printf("\n(in main) After created, the buffer usage situation is:");
		buf_cll_len(cbuf);

	//06 buffer write: buf_cll_w(), it will test the 05 buf_cll_flush() for long strings
		ret=buf_cll_w(cbuf,sw);
		printf("\n(in main) After calling 06 buf_cll_w(), the return is: %d\n", ret);
		if(DEBUG) buf_cll_list_node_c(cbuf);

	//03 buffer length: buf_cll_len()
		printf("\n(in main) After writing, the buffer usage situation is:");
		ret=buf_cll_len(cbuf);

	//07 buffer read: buf_cll_r(), it also tests 04 buf_cll_clear()
		ret=buf_cll_r(br, cbuf);
		printf("\n(in main) After calling 07 buf_cll_r(), the return is: %d, the output ===> %s\n", ret, br);
		printf("\n(in main) After reading, the buffer usage situation is: (it should be 0) ");
		buf_cll_len(cbuf);
		if(DEBUG) buf_cll_list_node_c(cbuf);

	//02 buffer delete
		buf_cll_del(cbuf);
}


if(SLLB)
{
	BUFP_T *buff;   //=(BUFP_T *) malloc(BPLEN);
	SLL_T *node;

//	printf("This is in buffer_test, and the buffer size is: %d\n",n);

	int l=BULEN;
	printf("--- The length of buffer node is:%d, & the (sizeof)node is ---\n",l);

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

//---08. to test node usage method
buf_sll_node_list(buff);


//03. to test buffer length
	ret=buf_sll_len(buff);
	printf("\nCall 03 buf_sll_len() successfully, the buffer length is: %d.(including '\\0')\n", ret);

//07. to test buffer read
	ret=buf_sll_r(br,buff);
	printf("\nCall 07 buf_sll_r() successfully, read %d nodes(including '\\0'), and get the string: %s\n", ret, br);

//	ret=buf_sll_r2(br,buff);
//	printf("\nCall 07.2 buf_sll_r2() successfully, read %d nodes(including '\\0'), and get the string: %s\n", ret, br);

//buf_sll_w(buff,"123456789");
//buf_sll_node_list(buff);


//02. to test buffer delete: buf_sll_del()
	ret=buf_sll_del(buff);
	printf("\nIn main buffer_test(), after call 02. Buffer delete function, the return is: %d. Buffer delete Successfully !!!\n",ret);
}   //end of if(SLLB)

	return 0;
}


