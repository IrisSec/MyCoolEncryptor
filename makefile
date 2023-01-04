all: coolencrypt

coolencrypt: coolsdk/cool.c program.c
	$(CC) coolsdk/cool.c program.c -o coolencrypt