#include <iostream>
#include <algorithm>

using namespace std;

class fcfs {
public:
	int pid,AT,BT,rBT,CT,WT,TAT,RT;
	int flag,order,visited;
}s[20];

int front=0,rear=0;
int Q[1000],sys_time=0,check=0;

void print(int n) {
	cout<<"PID\t"<<"AT\t"<<"BT\t"<<"rBT\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"order\n\n";
	for(int i=1;i<=n;i++) {
		cout<<s[i].pid<<"\t"<<s[i].AT<<"\t"<<s[i].BT<<"\t"<<s[i].rBT<<"\t"<<s[i].CT<<"\t"<<s[i].TAT<<"\t"<<s[i].WT<<"\t"<<s[i].order<<endl;
	}
}

void input(int n) {
	for(int i=1;i<=n;i++) {
		s[i].pid=i;
		s[i].flag=0;
		s[i].visited=0;
		cout<<"Enter AT & BT for P"<<i<<" :"<<endl;
		cin>>s[i].AT;
		cin>>s[i].BT;
		s[i].rBT= s[i].BT;
	}
}

void update_queue(int n,int t) {
	for(int i=1;i<=n;i++) {
		if(s[i].AT <=sys_time && s[i].visited!=1 && s[i].flag!=1) {
			rear++;
			Q[rear]=s[i].pid;
			s[i].visited=1;
		}
	}

	
}

void schedule(int t) {

while(front<=rear) {
		front++;
		if(s[front].rBT<=t && s[front].rBT!=0 ) {
			sys_time += s[front].rBT;
			s[front].CT=sys_time;
			s[front].rBT=0;
			s[front].flag=1;
			check++;
		}
		else {
			sys_time += t;
			s[front].rBT -= t;
			//s[front].CT=sys_time;
		}
	}

}

void RR_algo(int n,int t) {
	int i=0;
sys_time = s[1].AT;

while(check<=n) {
//i=1;
i++;
//	for(i=1;i<=n;i++) {

		if(s[i].rBT <= t && s[i].rBT !=0) {
			sys_time+=s[i].rBT;
			s[i].CT=sys_time;
			s[i].rBT=0;
			s[i].flag=1;
			check++;
		}
		else {

			sys_time+=t;
			s[i].rBT-=t;
			//s[i].CT+=t;
			update_queue(n,t);
			rear++;
			Q[rear]=s[i].pid;
			schedule(t);
		}
//	}
}



}




int main() {

int x,t;
cout<<"enter TIME_QUANTUM & no. of processes!\n";
cin>>t>>x;
input(x);
RR_algo(x,t);
cout<<"\n\nAfter Scheduling :\n\n";
print(x);


	return 0;

}

