#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define size 1024

int main()
{
	char wm1[size],rm1[size],rm2[size];
	int fd1[2],fd2[2];

pipe(fd1);
pipe(fd2);
	pid_t pid = fork();
	if(pid>0)
	{
		close(fd1[0]);
		close(fd2[1]);

		printf("\n\nEnter a string :\n");
		fgets(wm1,size,stdin);

		write(fd1[1],wm1,strlen(wm1));
		read(fd2[0],rm2,size);
		printf("\n\nThe new string is :\n");
		printf("%s\n\n",rm2);
	}
	else if(pid == 0)
	{
		close(fd1[1]);
		close(fd2[0]);

		read(fd1[0],rm1,size);
		for(int i=0;i<strlen(rm1)-1;i++)
		{
			if(rm1[i]>=97 && rm1[i]<=122)
			{
				rm1[i] = rm1[i] - 32;
			}
			else if(rm1[i]>=65 && rm1[i]<=90)
			{
				rm1[i] = rm1[i] + 32;
			}
			else
				rm1[i]=rm1[i];
		}
		write(fd2[1],rm1,strlen(rm1));
	}

}
