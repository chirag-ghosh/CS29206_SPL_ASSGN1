LIBNAME = libchirag.so
LIBDIR = /usr/local/lib
INCLUDEDIR = /usr/include
INCLUDESUBDIR = $(INCLUDEDIR)/basic
CFLAGS = -fPIC -g -I.
OBJFILES = queue.o stack.o heap.o union.o llist.o

library: queue.o stack.o heap.o union.o llist.o
	gcc -shared -o $(LIBNAME) queue.o stack.o heap.o union.o llist.o
stack.o: node.h stack.h llist.h
queue.o: node.h queue.h llist.h
heap.o: heap.h
union.o: union.h
llist.o: node.h llist.h
install: library
	cp $(LIBNAME) $(LIBDIR)
	-mkdir $(INCLUDESUBDIR)
	cp node.h stack.h queue.h llist.h heap.h union.h $(INCLUDESUBDIR)
	cp basic.h $(INCLUDEDIR)
RM = rm -f
clean:
	-$(RM) $(OBJFILES)
distclean:
	-$(RM) $(OBJFILES) $(LIBNAME)
