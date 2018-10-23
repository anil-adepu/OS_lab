#include <iostream>
#include <time.h>
using namespace std;

double cir_p=0, tot_p=0;

void *monte_carlo(void *param) {
int n = *(int *)param;
double x,y,dist;
x = double(rand() % (n+1)) / n;
y = double(rand() % (n+1)) / n;

dist = x * x + y * y;
if(dist <= 1)
      cir_p++;
tot_p++;
pthread_exit(0);
}

int main() {
      clock_t t1,t2;
      double pi;
      srand(time(NULL));
int iterations;
cout<<"Enter the no. of iterations!\n";
cin>>iterations;
t1=clock();
      pthread_t tid[iterations * iterations];
for(int i=1;i<=iterations * iterations;i++) {
      pthread_attr_t attr;

      pthread_attr_init(&attr);
      pthread_create(&tid,&attr,monte_carlo,&iterations);

      pthread_join(tid,NULL);
}
t2=clock();
pi = 4 * cir_p / tot_p;
cout<<"\nThe estimated Pi value is :\t";
      cout<<pi<<endl;

//      cout<<endl<<t2-t1;
cout<<"  \n\nTotal time taken  :"<<(t2-t1)/(double)CLOCKS_PER_SEC<<" SEC\n";

return 0;
}
