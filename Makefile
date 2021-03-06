all:
	gcc -g testLL.c -o testLL.o
	gcc -g removeDuplicate.c -o removeDuplicate.o
	gcc -g  mergeLL.c -o mergeLL.o
	gcc -g  swapLL.c -o swapLL.o
	gcc -g  palindromeLL.c -o palindromeLL.o
	gcc -g  splitLL.c -o splitLL.o
	gcc -g  addtwoLL.c -o addtwoLL.o
	chmod 777 *.o
clean:
	rm -rf *.o
	rm -rf *.dSYM
cleanall:
	rm -rf *.o
	rm -rf core.*
	rm -rf *.dSYM
