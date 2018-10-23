#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
T bubble_sort(int size, T a[] ) {
	for(int i=0;i<size-1;i++)
		for(int j=0;j<size-1-i;j++)
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);

cout<<"\n\nThe sorted array is :\n";
for(int i=0;i<size;i++)
	cout<<a[i]<<"  ";
cout<<endl;
}

int main() {
int choice,size;
cout<<"\n1.int\t2.float\t3.char\n";
while(1) {
cout<<"\nEnter your choice!\n";
cin>>choice;
cout<<"Enter array size!\n";
cin>>size;
switch(choice) {
	case 1 : {
				int a[size];
				cout<<"Enter array elements!\n";
				for(int i=0;i<size;i++)
					cin>>a[i];
				bubble_sort<int>(size,a);
				break;
			 }
	case 2 : {
				float a[size];
				cout<<"Enter array elements!\n";
				for(int i=0;i<size;i++)
					cin>>a[i];
				bubble_sort<float>(size,a);
				break;
			 }
	case 3 : {
				char a[size];
				cout<<"Enter array elements!\n";
				for(int i=0;i<size;i++)
					cin>>a[i];
				bubble_sort<char>(size,a);
				break;
			 }
	default : { cout<<"Wrong choice!\n"; return 0;}
}
}
	return 0;
}
