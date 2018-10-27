all:
	arm-linux-gcc -fPIC -c -o my_add.o my_add.c
	arm-linux-gcc -shared -o libmy_add.so my_add.o
	arm-linux-gcc main.c -o main -L./ -lmy_add
clean:
	rm -rf *.o  *.so main
