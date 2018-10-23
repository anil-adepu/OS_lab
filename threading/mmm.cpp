#include <iostream>
#include <pthread.h>
#include <math.h>
#include <bits/stdc++.h>
//#include <climitss>
using namespace std;

struct mmm {
      int n;
      int a[100];
};

void *mean(void *param) {
struct mmm *data = (struct mmm *)param;
int sum=0;
for(int i=0; i < data->n; i++)
      sum+= data->a[i];
cout<<"\nMean is \t:\t"<<(sum*1.0/data->n);
pthread_exit(0);
}

void *median(void *param) {
struct mmm *data = (struct mmm *)param;
float median,x;
sort(data->a, data->a + data->n);
if( (data -> n)%2!=0 ) {
      median = data -> a[((data -> n) /2)];
      cout<<"\n\nMedian is \t:\t"<<median;
}
else {
      x = (data -> a[((data -> n) /2)-1] + data -> a[((data -> n) /2)]);
      median = x/2;
      cout<<"\n\nMedian is \t:\t"<<median<<"  (avg of "<<data->a[((data -> n) /2)-1]<<" , "<<data->a[((data -> n) /2)]<<" )\n";
   }
pthread_exit(0);
}

void *mode(void *param) {
      struct mmm *data = (struct mmm *)param;
int i, max=0;
for( i=0; i < data->n ; i++ ) {
      if( data -> a[i] > max)
            max = data -> a[i];
}
int N=max;
int arr[N+1]={0};
//for( i=0; i <= N ; i++ )
//      arr[i]=0;
for( i=0; i < data->n ; i++ )
      arr[data -> a[i]]++;
max=0;
for( i=0; i <= N ; i++ )
      if( arr[i] > max)
            max = arr[i];

cout<<"\n\nThe mode is/are :\t";
for( i=0; i <= N ; i++ )
      if( arr[i] == max)
            cout<<i<<"  ";
cout<<endl;
pthread_exit(0);
}

int main() {

struct mmm *data = new mmm;
cout<<"Enter array size!\n";
      cin>>data->n;
cout<<"Enter array elements!\n";
      for(int c=0; c < data->n; c++)
            cin>>data->a[c];

      pthread_t tid[3];
      pthread_attr_t attr;
      pthread_attr_init(&attr);

      pthread_create(&tid[0],&attr,mean,data);
      pthread_join(tid[0],NULL);
      pthread_create(&tid[1],&attr,median,data);
      pthread_join(tid[1],NULL);
      pthread_create(&tid[2],&attr,mode,data);
//      pthread_join(tid[0],NULL);
//      pthread_join(tid[1],NULL);
      pthread_join(tid[2],NULL);
return 0;
}
