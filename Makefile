.PHONY: default
default: test ;

test: test.c
	gcc -fopenacc -o test test.c
	./test
