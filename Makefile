run: main.o checkValidCommand.o cutCommand.o execute.o
	gcc -o run main.o checkValidCommand.o cutCommand.o execute.o
main.o: main.c function.h
	gcc -c main.c
checkValidCommand.o: checkValidCommand.c function.h
	gcc -c checkValidCommand.c
cutCommand.o: cutCommand.c function.h
	gcc -c cutCommand.c
execute.o: execute.c function.h
	gcc -c execute.c
.PHONY: clean
clean:
	rm -rf *.o run
debug:
	gdb
