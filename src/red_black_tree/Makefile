all: \
	rbn_alloc.o	\
	rbn_insert.o
	ld -r *.o -o __RedBlackTree.o

%.o: %.c
	gcc -c $(subst .o,.c, $@)
