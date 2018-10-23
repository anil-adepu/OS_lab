#include <iostream>
#include <pthread.h>
//#include <math.h>
#include <bits/stdc++.h>
using namespace std;
#include <time.h>
struct mmm {
      int n;
      int a[100];
};

void merge(int a[],int beg,int end) {
int mid=(beg+end)/2, i=beg, j=mid+1, k=0;
int b[100];
while(i<=mid && j<=end) {
      if(a[i]<a[j]) {
            b[k]=a[i];
            i++;
            k++;
      }
      else {
            b[k]=a[j];
            j++;
            k++;
      }
}
while(i<=mid) {
      b[k]=a[i];
      k++;
      i++;
}
while(j<=end) {
      b[k]=a[j];
      k++;
      j++;
}

for(i=beg;i<=end;i++)
      a[i]=b[i-beg];
}

void merge_sort(int a[], int beg, int end) {
int mid = ( beg + end ) /2;
if(beg < end) {
      merge_sort(a, beg, mid);
      merge_sort(a, mid + 1, end);
      merge(a,beg,end);
  }
}

int partition (int a[], int low, int high) {
int pivot = a[high];
int i = (low - 1);
for(int j = low; j <= high- 1; j++) {
      if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
   }
      swap(a[i + 1], a[high]);
      return (i + 1);
}

void quick_sort(int a[], int low, int high) {
if(low < high) {
      int pi = partition(a,low,high);
      quick_sort(a, low, pi-1);
      quick_sort(a, pi + 1, high);
   }
}

void *merge(void *param) {
struct mmm *data = (struct mmm *)param;

merge_sort(data->a,0,(data -> n)-1);
cout<<"\n\nAfter sorting ( Merge Sort ) :\n";
for( int i=0; i<data->n;i++)
      cout<<data->a[i]<<"  ";
cout<<endl;
pthread_exit(0);
}

void *quick(void *param) {
struct mmm *data1 = (struct mmm *)param;

quick_sort(data1->a,0,(data1 -> n)-1);
cout<<"\n\nAfter sorting ( Quick Sort ) :\n";
for( int i=0; i<data1->n;i++)
      cout<<data1->a[i]<<"  ";
cout<<endl;
pthread_exit(0);
}

int main() {
      clock_t t1,t2;
struct mmm *data = new mmm;
cout<<"Enter array size!\n";
      cin>>data->n;
cout<<"Enter array elements!\n";
for(int c=0; c < data->n ; c++)
      cin>>data->a[c];

struct mmm temp= *data;
struct mmm *data1 = &temp;
t1 = clock();
      pthread_t tid[2];
//      pthread_t tid;
      pthread_attr_t attr;
      pthread_attr_init(&attr);

      pthread_create(&tid[0],&attr,merge,data);
      pthread_create(&tid[1],&attr,quick,data);

//      pthread_create(&tid,&attr,merge,data);
//      pthread_join(tid,NULL);

//     pthread_create(&tid,&attr,quick,data);
 //   pthread_join(tid,NULL);

      pthread_join(tid[0],NULL);
      pthread_join(tid[1],NULL);
t2=clock();
cout<<endl<<t2-t1;
cout<<"  \n\nTotal time taken  :"<<(t2-t1)/(double)CLOCKS_PER_SEC<<" SEC\n";
return 0;
}
