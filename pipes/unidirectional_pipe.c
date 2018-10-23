/*
Author:- Yashovardhan Siramdas
CED16I028

COM301P
Lab Session:- 04/09/18
Unidirectional Pipe

Parents writes to Pipe from "write end" and child reads the pipe from "read end"
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define BS 50
#define REND 0
#define WEND 1

int main()
{
	char wm[BS]="IIIT",rm[BS];
	int fd[2];

	if(pipe(fd)==-1)
	{
		printf("error while creating pipe\n");
		return -1;
	}

	pid_t pid = fork();

	if(pid>0)
	{
		close(fd[REND]);
		write(fd[WEND],wm,strlen(wm));
		close(fd[WEND]);
	}

	else if(pid == 0)
	{
		close(fd[WEND]);
		read(fd[REND],rm,BS);
		printf("%s\n",rm);
		close(fd[REND]);
	}
}