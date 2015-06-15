// 0. This is the main function.
// 1. 1st aim is to test the other functions in the sub-folders.
// 2. The functions (libs) are put in their own sub-folders; we can
// 	  call them with adding "#include xxx/yyy.h" declaration here.

//#include "lib_string/lib_string.h"
#include "lib_buffer/buffer_global.h"

int main()
{
// to test string functions in the ./lib_string sub-folder
// str_test();

// to test buffer functions in the ./lib_buffer sub-folder
buffer_test();

return 0;
}
