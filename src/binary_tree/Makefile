all: \
	bn_alloc.o \
	bn_insert.o \
	tree_depth.o \
	traversals.o \
	locate_parent.o \
	locate_sibling.o \
	tree_trace.o

%.o: %.c
	gcc -c $(subst .o,.c, $@)
