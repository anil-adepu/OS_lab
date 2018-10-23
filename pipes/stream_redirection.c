/*
Author:- Yashovardhan Siramdas
CED16I028

COM301P
Lab Session:- 04/09/18
Stream Redirection (To user created file)

Child writes an integer to pipe.
Parent reads the integer from pipe; uses dup2 for pointing stdout to user created file descriptor; computes factorial of the integer and prints it to user created file descriptor
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BS 50
#define REND 0
#define WEND 1

int factorial(int n)
{
	if(n==0 || n==1)
		return 1;
	return n * factorial(n-1);
}

int main()
{
	char wm[BS]="5",rm[BS];
	int fd[2];

	if(pipe(fd) == -1)
	{
		printf("error while creating pipe\n");
		return -1;
	}

	int fileOpen = open("stream_redirection.txt",  O_WRONLY | O_APPEND | O_CREAT,00700);

	if(fileOpen == -1)
	{
	    printf("Opening of output file failed\n");
	    exit(1);
	}


	pid_t pid = fork();

	if(pid>0)
	{
		close(fd[WEND]);
		read(fd[REND],rm,BS); //Event 1
		dup2(fileOpen,1); //Event 3
		printf("%d\n",factorial(atoi(rm))); //Event 4
	}

	else if(pid == 0)
	{
		close(fd[REND]);
		write(fd[WEND],wm,strlen(wm)); //Event 2
	}
}