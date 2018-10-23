#include <iostream>
using namespace std;

class HRRN {
	public:
	int pid,AT,BT,CT,WT,TAT;
	int flag,order;
}s[20];

int sys_clock=0,ind=-1;
float hratio=0;
void print(int n) {
	cout<<"PID\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"order\n\n";
	for(int i=1;i<=n;i++) {
		cout<<s[i].pid<<"\t"<<s[i].AT<<"\t"<<s[i].BT<<"\t"<<s[i].CT<<"\t"<<s[i].TAT<<"\t"<<s[i].WT<<"\t"<<s[i].order<<endl;
	}
}

void input(int n) {
	for(int i=1;i<=n;i++) {
		s[i].pid=i;
		s[i].flag=0;
		cout<<"Enter AT & BT for P"<<i<<" :"<<endl;
		cin>>s[i].AT;
		cin>>s[i].BT;
	}
}

int find_hrrn(int n) {
 for(int c=1;c<=n;c++) {
	if(s[c].AT<=sys_clock && s[c].flag==0 &&  ( ( sys_clock - s[c].AT)*1.0000 / s[c].BT*1.0000 ) > hratio )
	{
		ind=c;
		hratio= ( sys_clock - s[c].AT)*1.0000 / s[c].BT*1.0000 ;
	}
}
return ind;
}

void HRRN_algo(int n) {
int counter=0,hrrn_index,temp;

//sys_clock = s[1].AT;
for(int i=1;i<=n;i++) {
	counter++;

/*	if(i==1) {
		sys_clock+= s[i].BT;
		s[i].CT= s[i].AT+s[i].BT;
		s[i].TAT = s[i].CT - s[i].AT;
		s[i].WT = s[i].TAT - s[i].BT;
		s[i].flag=1;
		s[i].order = counter;
	}*/
//	else {
		temp=find_hrrn(n);
		hratio=0;
		ind=-1;

		if(temp!=-1) {
			hrrn_index=temp;
			sys_clock+= s[hrrn_index].BT; 
		}
		else {
			hrrn_index= i;
			sys_clock = s[hrrn_index].AT + s[hrrn_index].BT;
		}

		s[hrrn_index].flag=1;
		s[hrrn_index].order=counter;
		s[hrrn_index].CT = sys_clock;
		s[hrrn_index].TAT = s[hrrn_index].CT - s[hrrn_index].AT;
		s[hrrn_index].WT = s[hrrn_index].TAT - s[hrrn_index].BT;
	//}
}
//	cout<<"\ntest!\n";
}

int main() {
int x;
cout<<"enter no of processes!\n";
scanf("%d",&x);
input(x);
HRRN_algo(x);
cout<<"\n\nAfter Scheduling :\n\n";
print(x);
//print_after(x);
	return 0;
}




#include <iostream>
using namespace std;

class HRRN {
	public:
	int pid,AT,BT,CT,WT,TAT;
	int flag,order;
}s[20];

int sys_clock=0,ind=-1;
float hratio=0;
void print(int n) {
	cout<<"PID\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"order\n\n";
	for(int i=1;i<=n;i++) {
		cout<<s[i].pid<<"\t"<<s[i].AT<<"\t"<<s[i].BT<<"\t"<<s[i].CT<<"\t"<<s[i].TAT<<"\t"<<s[i].WT<<"\t"<<s[i].order<<endl;
	}
}

void input(int n) {
	for(int i=1;i<=n;i++) {
		s[i].pid=i;
		s[i].flag=0;
		cout<<"Enter AT & BT for P"<<i<<" :"<<endl;
		cin>>s[i].AT;
		cin>>s[i].BT;
	}
}

int find_hrrn(int n) {
 for(int c=1;c<=n;c++) {
	if(s[c].AT<=sys_clock && s[c].flag==0 &&  ( ( sys_clock - s[c].AT)*1.0000 / s[c].BT*1.0000 ) > hratio )
	{
		ind=c;
		hratio= ( sys_clock - s[c].AT)*1.0000 / s[c].BT*1.0000 ;
	}
}
return ind;
}

void HRRN_algo(int n) {
int counter=0,hrrn_index,temp;

//sys_clock = s[1].AT;
for(int i=1;i<=n;i++) {
	counter++;

/*	if(i==1) {
		sys_clock+= s[i].BT;
		s[i].CT= s[i].AT+s[i].BT;
		s[i].TAT = s[i].CT - s[i].AT;
		s[i].WT = s[i].TAT - s[i].BT;
		s[i].flag=1;
		s[i].order = counter;
	}*/
//	else {
		temp=find_hrrn(n);
		hratio=0;
		ind=-1;

		if(temp!=-1) {
			hrrn_index=temp;
			sys_clock+= s[hrrn_index].BT; 
		}
		else {
			hrrn_index= i;
			sys_clock = s[hrrn_index].AT + s[hrrn_index].BT;
		}

		s[hrrn_index].flag=1;
		s[hrrn_index].order=counter;
		s[hrrn_index].CT = sys_clock;
		s[hrrn_index].TAT = s[hrrn_index].CT - s[hrrn_index].AT;
		s[hrrn_index].WT = s[hrrn_index].TAT - s[hrrn_index].BT;
	//}
}
//	cout<<"\ntest!\n";
}

int main() {
int x;
cout<<"enter no of processes!\n";
scanf("%d",&x);
input(x);
HRRN_algo(x);
cout<<"\n\nAfter Scheduling :\n\n";
print(x);
//print_after(x);
	return 0;
}




