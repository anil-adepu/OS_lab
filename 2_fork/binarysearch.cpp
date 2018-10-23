

#include <iostream>
using namespace std;
#include <unistd.h>
#include <sys/types.h>
#include <algorithm>

int binary_search(int n,int a[], int b, int e, int x) {
cout<<b<<e<<x;
for(int i=0;i<5;i++)
		cout<<a[i]<<"  ";

while(b<=e) {
	int mid = (b+e)/2;
	if(a[mid]==x) 
		return mid;

	else if(a[mid]<x ){
			e=mid-1;
		//return binary_search(a,b,mid-1,x);
	}
	else 
		b = mid+1;
	//	return binary_search(a,mid+1,e,x);
}

return -1;
}


int main() {
int n,x,a[100];

pid_t pid=vfork();

if(pid==0) {
cout<<"Enter array size!\n";
cin>>n;

cout<<"Enter array elements!\n";
for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
		for(int i=0;i<n;i++)
		cout<<a[i]<<"  ";
	cout<<endl;
	_exit(0);
}
else {
//int x;
cout<<"Enter search element!\n";
cin>>x;
int flag=binary_search(n,a,0,n-1,x);
cout<<"test"<<flag;
if(flag>0)
	cout<<"Found at "<<flag <<"position!\n";

	//for(int i=0;i<n;i++)
	//	cout<<a[i];
	//exit(0);
}

	return 0;
}
