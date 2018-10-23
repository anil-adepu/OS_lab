#include <iostream>

using namespace std;

int N,deter=0;

void * determinant(void * param) {
int a[N][N] = *(int *)param;


      pthread_exit(0);
}

void * cofactor(void * param) {
int a[N][N] = *(int *)param;


      pthread_exit(0);
}

int main() {
std::cout << "Enter order of the matrix!" << '\n';
cin>>N;
int arr[N][N];
std::cout << "Enter the matrix!" << '\n';
for(int i=0;i < N; i++)
      for(int j=0; j < N ; j++)
            cin>>arr[i][j];

pthread_t tid[2];
pthread_attr_t attr;
pthread_attr_init(&attr);

pthread_create(&tid[0],&attr,determinant,&a);
pthread_join(tid[0],NULL);
if(!deter) {
      cout<<"Determinant is zero => No inverse!\n";
      return 0;
}
pthread_create(&tid[1],&attr,cofactor,&a);
pthread_join(tid[1],NULL);
      return 0;
}
