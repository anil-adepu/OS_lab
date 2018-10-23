#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define null (char *)0
int main()
{
	pid_t pid;

	char *cmd[] = {"ls","-al",NULL};

	pid = fork();

	if(pid == 0)
	{
//		execl("/bin/ls","ls","-al",null);
            execl("/bin/cat","cat","bsort_template.cpp",null);
//		execlp("ls","ls","-al",(char *)0);
//            execlp("./pno","./pno",NULL);
		//execv("/bin/ls",cmd);
		//execvp("ls",cmd);

	}

}
//orphan
/*int main() {
   int pid;
   system("ps -f");
   pid = fork();
   if (pid == 0) {
      printf("Child: pid is %d and ppid is %d\n",getpid(),getppid());
      sleep(5);
      printf("\nChild: pid is %d and ppid is %d\n",getpid(),getppid());
      system("ps -f");
//      abort();
//      return 0;
//      _exit(0);
   } else {
      printf("Parent: pid is %d and ppid is %d\n",getpid(),getppid());
      //sleep(2);
      _exit(0);
   }
   return 0;
}*/

//zombie
/*int main() {
   int pid;
   pid = fork();
   if (pid == 0) {
      system("ps au");
      printf("Child: pid is %d and ppid is %d\n",getpid(),getppid());
//      sleep(5);
//      printf("Child: pid is %d and ppid is %d\n",getpid(),getppid());
      //system("ps -ef");
      _exit(0);
   } else {
      printf("Parent: pid is %d and ppid is %d\n",getpid(),getppid());
      sleep(5);
      system("ps -aux | grep a.out");
//      _exit(0);
   }
   return 0;
}*/

//perfect no
/*int perfectno(int n) {
      int sum=0;
      for(int i=1;i<n;i++) {
            if(n % i ==0)
                  sum += i;
      }
if(sum ==n)
      return 1;
else
      return 0;
}

int main(int argc, char const *argv[]) {
pid_t pid;
int UL , LL, c;
pid = vfork();

if(pid > 0) {
      wait(NULL);
      for(int i = LL ; i<=UL ; i++) {
            if((c=perfectno(i)) !=0)
                  printf("%d  ",i);
      }

} else {
      printf("enter LL  &  UL\n");
      scanf("%d%d", &LL,&UL);
      _exit(0);
}
      return 0;
}*/

//shell simulator
/*int main() {
int pid, status;
char buffer[100];
while(1) {
pid = vfork();
if(pid > 0  )
      system(buffer);
else {
      printf("enter a command !\n");
      fgets(buffer,100,stdin);
      _exit(0);
   }
}
      return 0;
}*/
