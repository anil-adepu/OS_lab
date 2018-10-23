#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int size,min,max;
float q1,q2,q3;

void *Q1(void *arg)
{
	int *val_p = (int *) arg;
	if(size/2 %2 ==0)
	{
		q1 = (float)(val_p[((size / 2)-1)/2]+val_p[((size / 2))/2])/2;
	}
	else
	{
		q1 = val_p[((size / 2)-1)/2];
	}
	pthread_exit(0);
}

void *Q2(void *arg)
{
	int *val_p = (int *) arg;

	if(size%2 == 0)
		q2 = (float)(val_p[size / 2] + val_p[(size / 2)-1]) / 2;
	else
		q2 = val_p[size / 2];

	pthread_exit(0);
}


void *Q3(void *arg)
{
	int *val_p = (int *) arg;
	if(size/2 %2 ==0)
	{
		q3 = (float)(val_p[((size / 2)+(size-1))/2]+val_p[(((size / 2)+(size-1))/2)+1])/2;
	}
	else
	{
		q3 = val_p[((size / 2)+(size))/2];
	}
	pthread_exit(0);
}

void *compute_min(void *arg)
{
	int *val_p = (int *) arg;
	min = val_p[0];
	pthread_exit(0);
}

void *compute_max(void *arg)
{
	int *val_p = (int *) arg;
	max = val_p[size-1];
	pthread_exit(0);
}


int comparator (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main(int argc,char* argv[])
{
	size = argc - 1;

	int *array = (int *)malloc((size)*sizeof(int));

	for(int i = 0; i < size ; i++)
	{
	  array[i] = atoi(argv[i+1]);
	}
	qsort(array,size,sizeof(int),comparator);

	pthread_t tid[5];
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_create(&tid[0],&attr,compute_min,(void *)array);

	pthread_attr_init(&attr);
	pthread_create(&tid[1],&attr,Q1,(void *)array);

	pthread_attr_init(&attr);
	pthread_create(&tid[2],&attr,Q2,(void *)array);

	pthread_attr_init(&attr);
	pthread_create(&tid[3],&attr,Q3,(void *)array);

	pthread_attr_init(&attr);
	pthread_create(&tid[4],&attr,compute_max,(void *)array);


	for(int i=0;i<5;i++)
		pthread_join(tid[i],NULL);

	printf("Minimum \t= %d\n",min);
	printf("First Quartile  = %f\n",q1);
	printf("Median \t\t= %f\n",q2);
	printf("Third Quartile  = %f\n",q3);
	printf("Maximum \t= %d\n",max);

	free(array);
}
