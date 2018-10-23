#include <iostream>
#include <pthread.h>
#include <math.h>
using namespace std;

int a[100],index=-1;

struct prime {
      int x;
};

void *primality(void *param) {
      pthread_t id;
      id = pthread_self();
      //cout<<id<<endl;
      struct prime *temp = (struct prime *)param;
      int i,flag=0;
      for(int i=2;i<=sqrt(temp->x); i++) {
            if((temp->x)%i==0)
                  flag=1;
      }
if(flag==0) {
      index++;
      a[index]=temp->x;
   }
pthread_exit(0);
}

int main(int argc, char *argv[]) {
      //void *retval;
if(atoi(argv[1]) == 0 || atoi(argv[1])==1 ) {
      std::cout << "Wrong input!" << '\n';
      return 0;
}

for(int i=2;i<=atoi(argv[1]);i++) {

//      struct prime *temp = (struct prime *)malloc(sizeof(struct prime));
      struct prime *temp = new prime;
      temp->x=i;
      pthread_t tid;
      pthread_attr_t attr;

      pthread_attr_init(&attr);

      int x=pthread_create(&tid,&attr,primality,temp);
      //cout<<"\n"<<tid<<"\n\n";
      pthread_join(tid,NULL);
}
cout<<"The prime numbers in the range are :\n";
for(int k=0;k<=index;k++)
      cout<<a[k]<<"  ";
cout<<endl;
//cout<<retval;
      return 0;
}
