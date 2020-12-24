all:
	gcc *.c  -Wall -o test.exe
clean:
	del test.exe