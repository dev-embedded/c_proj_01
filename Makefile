CC = gcc
CFLAGS += -Wall -std=c99 -g
CPPFLAGS += -MMD -I"./lib_string" "lib_buffer"

OBJS := main.o ./lib_string/str_test.o ./lib_string/lib_str.o ./lib_buffer/buffer_test.o ./lib_buffer/singly_linked_list_st.o
DEPS := main.d str_test.d lib_str.d buffer_test.d singly_linked_list_st.d

EXEC := main

$(EXEC): $(OBJS)
	gcc -o$@ $^

-include $(DEPS)

.PHONY : clean distclean

clean:
	@echo clean
	@rm -f *.o
	@rm -f *.d

distclean: clean
	@rm -f $(EXEC)
