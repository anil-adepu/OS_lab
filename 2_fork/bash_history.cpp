#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void bh(FILE * fd,int n) {
int count = 0;
int pos;
//unsigned long long pos;
char str[1024];
	 if (fseek(fd, 0, SEEK_END))
	      perror("fseek() failed");
	  else {
	        pos = ftell(fd);
	        while (pos)
	        {
	            if (!fseek(fd, --pos, SEEK_SET))
	            {
	                if (fgetc(fd) == '\n')
	                    if (count++ == n)
	                        break;
	            }
	            else
	                perror("fseek() failed");
	        }
	        printf("\n\nPrinting last %d lines -\n", n);
	        while (fgets(str, sizeof(str), fd))
	            printf("%s", str);
	    }
}

int main()
{
	pid_t pid;
	char buffer[1024];
	char c;

	while(1)
	{
		pid = vfork();

		if(pid == 0)
		{
			printf("Enter the command to be executed!\n ");
			fgets(buffer,1024,stdin);
			_exit(0);
		}

		else if(pid > 0)
		{
			FILE *fd = fopen("log.txt","a+");

			if(buffer[0]==33)
			{
				if(buffer[1] != 33)
				{
					bh(fd,atoi(buffer+1));
				}
				else
				{
					fseek(fd, 0, SEEK_SET);
					printf("\n\nComplete log file :\n");
					c = fgetc(fd);
					while (c != EOF)
					{
					    printf ("%c", c);
					    c = fgetc(fd);
					}
				}

			}
			else
			{
				system(buffer);
			}

			fprintf(fd,"%s",buffer);
			fclose(fd);
		}
	}
}
