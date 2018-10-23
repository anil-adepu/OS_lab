#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[])
{
    int fd[2];

    char readBuff[50000];
    int readCounter;
    pipe(fd);

    int fileOpen = open(argv[1], O_RDONLY);
    if(fileOpen == -1)
    {
        printf("Opening of Source file failed\n");
        exit(1);
    }

    int targetFile =  open(argv[2],O_WRONLY | O_CREAT,00700);

    if(targetFile  == -1)
    {
        printf("Opening of Destination file failed\n");
        exit(1);
    }

    pid_t pid = fork();

    if(pid > 0)
    {
        close(fd[0]);

        while((readCounter = read(fileOpen, readBuff, sizeof(readBuff)) > 0))
            write(fd[1], readBuff, sizeof(readBuff));

        close(fd[1]);
    }
    else if(pid == 0)
    {
        close(fd[1]);
        read(fd[0], readBuff, sizeof(readBuff));
        write(targetFile, readBuff, strlen(readBuff) + 1);
        printf("File successfully copied to Destination\n");
    }
}
