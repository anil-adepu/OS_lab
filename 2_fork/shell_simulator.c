/*
Author:- Yashovardhan Siramdas
CED16I028

COM301P
Lab Session:- 21/08/18
Shell Simulator

Child takes a command as input and gets killed. Parent executes the command and sends output to shell.
This is repeated in infinite loop till user interrupt(CTRL + Z) is encountered.

At any point in time, there are at max 2 processes in memory (Child gets killed in each iteration)
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	char buffer[1024];
	while(1)
	{
		pid = vfork();

		if(pid == 0)
		{
			printf("Enter the command to be executed: ");
			fgets(buffer,1024,stdin);
			_exit(0);
		}

		else if(pid > 0)
		{
			system(buffer);
		}	
	}
}