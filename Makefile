
main: src_make
	find ./src/ -name '*.o' -exec cp -uv '{}' . ';'; \
	gcc src/main.c *.o -g -o Final.out

src_make:
	find ./src/* -type d -exec make -C '{}' ';'

#__________________________

clean:
	rm -f *.out *.o; \
	find . -name '*.o' -delete
