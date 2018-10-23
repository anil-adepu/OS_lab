#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define size 50

int main()
{
	char wm1[size]="HELLO",wm2[size]="WORLD",rm1[size],rm2[size];
	int fd1[2],fd2[2];

	if(pipe(fd1) == -1)
	{
		printf("error while creating pipe1\n");
		return -1;
	}

	if(pipe(fd2) == -1)
	{
		printf("error while creating pipe2\n");
		return -1;
	}

	pid_t pid = fork();

	if(pid>0)
	{
		close(fd1[0]);
		close(fd2[1]);
		write(fd1[1],wm1,strlen(wm1)); //Event 1
		read(fd2[0],rm2,size); //Event 4
		printf("%s\n",rm2);
	}

	else if(pid == 0)
	{
		close(fd1[1]);
		close(fd2[0]);
		read(fd1[0],rm1,size); //Event 2
		printf("%s\n",rm1);
		write(fd2[1],wm2,strlen(wm2)); //Event 3
	}
}
