#include <iostream>
#include<stdio.h>
using namespace std;

class fcfs {
public:
	int pid,AT,BT,CT,WT,TAT;
}s[20];

void fcfs_algo(int n) {
	for(int i=1;i<=n;i++) {
		s[i].pid=i;
		cout<<"Enter AT & BT for P"<<i<<" :"<<endl;
		cin>>s[i].AT;
		cin>>s[i].BT;
   
	if(i==1) {
		s[i].CT=s[i].AT + s[i].BT;
	}
	else {
		if(s[i].AT <= s[i-1].CT) 
			s[i].CT = s[i-1].CT + s[i].BT;
		else
			s[i].CT= s[i].AT + s[i].BT;
	}
s[i].TAT= s[i].CT-s[i].AT;
s[i].WT= s[i].TAT-s[i].BT;
   }
}

int main() {
int x;
cout<<"enter no of processes!\n";
scanf("%d",&x);
fcfs_algo(x);
cout<<"PID\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"WT\n\n";
for(int i=1;i<=x;i++) {
	cout<<s[i].pid<<"\t"<<s[i].AT<<"\t"<<s[i].BT<<"\t"<<s[i].CT<<"\t"<<s[i].TAT<<"\t"<<s[i].WT<<endl;
}
	return 0;
}

