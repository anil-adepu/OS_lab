/*
Author:- Yashovardhan Siramdas
CED16I028

COM301P
Lab Session:- 04/09/18
Executes "ps" command and the output is sent to grep which will search for a process name(process name is hardcoded).

Child executes "ps" and the output is stored in pipe using dup2(child duplicates fd's WEND).
Parent executes "grep" and input for "grep" is taken from pipe(parent duplicates fd's REND).
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
		close(fd[WEND]); //Event 1
		dup2(fd[REND],0); //Event 2
		execlp("grep","grep","Firefox",NULL); //Event 3
	}

	else if(pid == 0)
	{
		dup2(fd[WEND],1); //Event 4
		execlp("ps","ps","-A",NULL);  //Event 5
	}
}