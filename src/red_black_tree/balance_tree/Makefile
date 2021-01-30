all: \
	balance_tree.o \
	identify_family.o \
	rotation_cases.o \
	rotations.o \
	make_rotations.o \
	getSide.o
	ld -r *.o -o __BalanceTree.o

%.o: %.c
	gcc -c $(subst .o,.c, $@)
