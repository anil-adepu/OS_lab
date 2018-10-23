#include <iostream>
#include <cstdarg>
#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int count, ...) {

va_list (list);
va_start(list,count);

int a[100];
for(int argc=0;argc < count;argc++) {
	a[argc]=va_arg(list,int);
	
		//if(va_arg(list,int) > va_arg(list,int))
		//swap(va_arg(list,int) ,va_arg(list,int));
		//cout<<va_arg(list,int)<<"    ";
}

for(int i=0;i < count-1;i++)
	for(int j=0;j<=count-i-1;j++)
		if( a[j] > a[j+1] )
		//if((strcmp(argv[j],argv[j+1]) >0 )  
			swap(a[j],a[j+1]);

for(int i=0;i<count;i++)
	cout<<a[i]<<"  ";
cout<<endl;


va_end(list);

}

int main() {

bubble_sort(6,3,0,9,1,8,7);

	return 0;
}

