#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int factorial(int n)
{
	if(n==0 || n==1)
		return 1;
	return n * factorial(n-1);
}

int main()
{
	char wm[50],rm[50];
	int fd[2];

	if(pipe(fd) == -1)
	{
		printf("error while creating pipe\n");
		return -1;
	}

	int fileOpen = open("stream_indirection.txt",  O_RDONLY);

	if(fileOpen == -1)
	{
	    printf("Opening of input file failed\n");
	    exit(1);
	}


	pid_t pid = fork();

	if(pid>0)
	{
		close(fd[1]);
		read(fd[0],rm,50);
		printf("%d\n",factorial(atoi(rm)));
	}

	else if(pid == 0)
	{
		close(fd[0]);
		dup2(fileOpen,0);
		scanf("%s",wm);
		write(fd[1],wm,strlen(wm));
	}
}
