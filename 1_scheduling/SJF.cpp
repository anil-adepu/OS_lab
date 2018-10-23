#include <iostream>
#include <algorithm>
using namespace std;

class fcfs {
public:
	int pid,AT,BT,CT,WT,TAT;
	int flag,order;
}s[20];

int runtime=0,ind=-1,minBT=10000;
//int min_order=1000;

void print(int n) {
	cout<<"PID\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"order\n\n";
	for(int i=1;i<=n;i++) {
		cout<<s[i].pid<<"\t"<<s[i].AT<<"\t"<<s[i].BT<<"\t"<<s[i].CT<<"\t"<<s[i].TAT<<"\t"<<s[i].WT<<"\t"<<s[i].order<<endl;
	}
}

/*
int get_min(int n) {
	for (int i = 1; i <= n; ++i)
	{
		if(s[i].order < min_order && s[i].flag!=0)
			min_order=s[i].order;
	}
return min_order;
}


void print_after(int x) {
	int i;
	for(int t=1;t<=x;t++) {
		i=get_min(x);
		min_order=1000;
		s[i].flag=0;
		cout<<s[i].pid<<"\t"<<s[i].AT<<"\t"<<s[i].BT<<"\t"<<s[i].CT<<"\t"<<s[i].TAT<<"\t"<<s[i].WT<<"\t"<<s[i].order<<endl;
   	}
}*/

void input(int n) {
	for(int i=1;i<=n;i++) {
		s[i].pid=i;
		s[i].flag=0;
		cout<<"Enter AT & BT for P"<<i<<" :"<<endl;
		cin>>s[i].AT;
		cin>>s[i].BT;
	}
}

int findmin(int n) {
	for(int c=1;c<=n;c++) {
		if(s[c].AT <= runtime && s[c].flag!=1 && s[c].BT < minBT) {
			ind=c;
			minBT=s[c].BT;
		}
	}
return ind;
}

void sjf_algo(int n) {
int minindex, c;
int counter=0;
runtime= s[1].AT;

//sort(s,s+n,comparator);
for(int i=1;i<=n;i++) {
	c=findmin(n);
	minBT=10000;
	ind=-1;

	if(c!=-1) {
		minindex=c;
		runtime+= s[minindex].BT;
	}
	else {
		minindex=i;
		runtime = s[minindex].AT+ s[minindex].BT;
	}
	s[minindex].flag=1;
	counter++;
	s[minindex].order=counter;
	s[minindex].CT= runtime;
	s[minindex].TAT= s[minindex].CT - s[minindex].AT;
	s[minindex].WT = s[minindex].TAT - s[minindex].BT;
}
}

int main() {
int x;
cout<<"enter no of processes!\n";
scanf("%d",&x);
input(x);
sjf_algo(x);
cout<<"\n\nAfter Scheduling :\n\n";
print(x);

//print_after(x);
	return 0;
}







/*
void comparator(fcfs a, fcfs b) {

	if(a.AT < b.AT)
		return a;
	else 
		return b;
}*/
