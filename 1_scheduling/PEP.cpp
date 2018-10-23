#include <iostream>
#include <algorithm>
using namespace std;

class fcfs {
public:
	int pid,P,AT,BT,rBT,CT,WT,TAT;
	int flag,order;
}s[20];

int sys_time=0,ind=-1;
int maxprio=0;

int compute(int n) {
	for(int j=1;j<=n;j++) {
		s[j].TAT=s[j].CT-s[j].AT;
		s[j].WT = s[j].TAT - s[j].BT;
	}

}

void print(int n) {
	cout<<"PID\t"<<"PRIO"<<"\t"<<"AT\t"<<"BT\t"<<"rBT\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"order\n\n";
	for(int i=1;i<=n;i++) {
		cout<<s[i].pid<<"\t"<<s[i].P<<"\t"<<s[i].AT<<"\t"<<s[i].BT<<"\t"<<s[i].rBT<<"\t"<<s[i].CT<<"\t"<<s[i].TAT<<"\t"<<s[i].WT<<"\t"<<s[i].order<<endl;
	}
}


void input(int n) {
	for(int i=1;i<=n;i++) {
		s[i].pid=i;
		s[i].flag=0;
		cout<<"Enter Prio, AT & BT for P"<<i<<" :"<<endl;
		cin>>s[i].P;
		cin>>s[i].AT;
		cin>>s[i].BT;
		s[i].rBT= s[i].BT;
	}
}

int find_initial(int n) {
int a;
	for(int c=1;c<=n;c++) {
		if(s[c].AT == sys_time && s[c].P > maxprio) {
				a=c;
				maxprio=s[c].P;
			}
	}
return a;
}

int find_maxprio(int n,int t) {
	for(int k=1;k<=n;k++) {
		if(s[k].AT <= sys_time && s[k].flag!=1 && s[k].P > maxprio) {
			ind=k;
			maxprio=s[k].P;
		}
	}
return ind;
}

void PEP_algo(int n,int t) {

int index, c;
int counter=0;
sys_time= s[1].AT;

c=find_initial(n);
//cout<<"!!!"<<c;
	maxprio=0;
	//s[c].flag=1;

if(s[c].rBT <= t && s[c].rBT !=0) {
		sys_time+= s[c].rBT;
		s[c].CT = sys_time;
		//s[c].TAT=s[c].CT-s[c].AT;
		//s[c].WT = s[c].TAT - s[c].BT;

		s[c].rBT=0;
		counter++;
		s[c].flag=1;
		//s[c].order=counter;
	}
	else {
		sys_time+=t;
		s[c].rBT-=t;
	}


while(counter<=n) {
	//counter++;
	//index=find_maxprio(n,t);
	c=find_maxprio(n,t);
	//cout<<c<<"#####";
		maxprio=0;
		ind=-1;

	if(c==-1) {
		for(int q=1;q<=n;q++) {
			if(s[q].flag!=1) {
				c=q;
				break;
			}
		}
	//cout<<c<<"  ";	
	}
	//else{
	//	c=index;
	//}
	if(s[c].rBT <= t && s[c].rBT !=0) {
		sys_time+= s[c].rBT;
		s[c].CT = sys_time;
		//s[c].TAT=s[c].CT-s[c].AT;
		//s[c].WT = s[c].TAT - s[c].BT;
		//s[c].order=counter;
		s[c].rBT=0;
		counter++;
		s[c].flag=1;
	}
	else {
		sys_time+=t;
		s[c].rBT-=t;
	}

	index=c;
}
}

int main() {
int x,t;
cout<<"enter TIME_QUANTUM & no. of processes!\n";
cin>>t>>x;
input(x);
PEP_algo(x,t);
//compute(x);
cout<<"\n\nAfter Scheduling :\n\n";
print(x);

//print_after(x);
	return 0;
}

