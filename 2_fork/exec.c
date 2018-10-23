#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
	pid_t pid;

	char *cmd[] = {"ls","-al",NULL};

	pid = fork();

	if(pid == 0)
	{
		//execl("/bin/ls","ls","-al",NULL);
		//execlp("ls","ls","-al",NULL);
		//execv("/bin/ls",cmd);
		execvp("ls",cmd);
		
	}

}