/*
Author:- Yashovardhan Siramdas
CED16I028

COM301P
Lab Session:- 04/09/18
To Upper

Child executes "ls" and the output is stored in pipe using dup2. Parent reads from the pipe and converts the data into upper case.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define BS 2048
#define REND 0
#define WEND 1

int main()
{
	char rm[BS];
	int fd[2],nb;

	if(pipe(fd) == -1)
	{
		printf("error while creating pipe\n");
		return -1;
	}

	pid_t pid = fork();

	if(pid>0)
	{
		while((nb=read(fd[REND],rm,BS))>0) //Event 1
		{
			for(int i=0;i<nb;i++) //Event 4
				rm[i] = toupper(rm[i]);
			write(1,rm,nb);  //Event 5
		}
	}

	else if(pid == 0)
	{
		dup2(fd[WEND],1); //Event 2
		execlp("ls","ls","-al",NULL);  //Event 3
	}
}