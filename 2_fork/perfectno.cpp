#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int isPerfectNumber(int n)
{
	int sum = 0;
	for(int i=1;i<=n-1;i++)
	{
		if(n%i==0)
			sum += i;
	}
	if(sum==n)
		return 1;
	return 0;
}

int main()
{
	pid_t pid;
	pid = vfork();
	int lowerLimit,upperLimit;

	if(pid>0)
	{
		wait(NULL);
		printf("Per nos. in the ange %d-%d are:\n",lowerLimit,upperLimit);
		for(int i=lowerLimit;i<=upperLimit;i++)
			if(isPerfectNumber(i))
				printf("%d ",i);
		printf("\n");
		
	}

	else if(pid==0)
	{
		printf("Enter LL : ");
		scanf("%d",&lowerLimit);
		printf("Enter UL : ");
		scanf("%d",&upperLimit);

		_exit(0);
	}
}