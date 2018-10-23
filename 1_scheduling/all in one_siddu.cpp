#include<iostream>
#include<stdlib.h>
#include<queue>

using namespace std;

int n;
int ST;
struct process
{
	int pid, at, bt, ct, tat, wt, p, mark, flag;
}pr[100];

void init()
{
	for (int i = 0; i < 100; i++)
	{
		pr[i].at = pr[i].bt = pr[i].ct = pr[i].tat = pr[i].wt = pr[i].mark = pr[i].p = pr[i].flag = 0;
		pr[i].pid = i;
	}
}

class sch
{
private:
	int choice, next;
	process st[100], rr[100], pp[100], np[100];
public:

	void intit()
	{
		for (int i = 0; i < 100; i++)
			pr[i].ct = pr[i].tat = pr[i].wt = pr[i].mark = pr[i].flag = 0;
	}

	int schmain()
	{
		while (1)
		{
			cout << "\n1.Round Robin\t2.SRT\t3.Prio Pre emptive \n ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				rrmain();
				break;
			case 2:
				srtmain();
				break;
			case 3:
				ppmain();
				break;
			case 4:
				return 0;
			}
		}
	}

	void disp(process temp[])
	{
		cout<<"\n\n\nPID\t"<<"AT\t"<<"BT\t"<<"PRIO\t"<<"CT\n";
		for (int i = 0; i < n; i++)
			cout << pr[i].pid << "\t " << pr[i].at << "\t" << pr[i].bt << "\t" << pr[i].p << "\t" << temp[i].ct << endl;
	}

	int minarr(process temp[],int s)
	{
		int min = temp[0].at, minp = temp[0].p;
		int pn = 0;
		for (int i = 1; i < n; i++)
			if (temp[i].at < min)
			{
				min = temp[i].at;
				pn = i;
			}
		if (s == 1)
		{
			for (int i = 1; i < n; i++)
				if (temp[i].at == min && temp[i].p>minp)
				{
					min = temp[i].at;
					pn = i;
					minp = temp[i].p;
				}
		}
		return pn;
	}

	int nxtarr(int s, process temp[])
	{
		int pn = s, min=0;
		for (int i = 0; i < n; i++)
			if (temp[i].flag == 0 && temp[i].at <= ST && temp[i].bt > 0)
			{
				min = temp[i].bt;
				pn = i;
				break;
			}

		for (int i = 0; i < n; i++)
			if (temp[i].bt < min && ST >= temp[i].at && temp[i].flag == 0 && temp[i].bt>0)
			{
				min = temp[i].bt;
				pn = i;
			}
		return pn;
	}

	void srtmain()
	{
		intit();
		//cout << "Shortest Remaining Time\n";
		ST = 0;
		int end = 0;

		for (int i = 0; i < n; i++)
			st[i] = pr[i];

		ST = st[minarr(st,0)].at;
		int pre = minarr(st,0);

		while (end != 1)
		{
			ST++;
			end = 1;
			if (st[pre].bt > 0)
			{
				st[pre].bt--;
				st[pre].ct = ST;
			}
			if (st[pre].bt <= 0)
				st[pre].flag = 1;
			pre = nxtarr(pre, st);

			for (int i = 0; i < n; i++)
				if (st[i].flag == 0)
					end = 0;
		}
		for (int i = 0; i < n; i++)
		{
			st[i].tat = st[i].ct - st[i].at;
			st[i].wt = st[i].tat - pr[i].bt;
		}
		disp(st);

	}

	int nxtjob(int s, process temp[])
	{
		int pn = s, min;
		for (int i = 0; i < n; i++)
			if (temp[i].flag == 0 && temp[i].at <= ST && temp[i].mark != 1)
			{
				min = temp[i].at;
				pn = i;
				break;
			}

		for (int i = 0; i < n; i++)
			if (temp[i].at < min && ST >= temp[i].at && temp[i].flag == 0 && temp[i].mark != 1)
			{
				min = temp[i].at;
				pn = i;
			}
		return pn;
	}

	void show(queue <int> temp)
	{
		queue <int> te = temp;
		while (!te.empty())
		{
			cout << te.front() << "\t";
			te.pop();
		}
		cout << endl;
	}
	int mcheck(process temp[])
	{
		for (int i = 0; i < n; i++)
			if (temp[i].mark == 0)
				return 0;
		return 1;
	}
	void rrmain()
	{
		intit();
		int tq, np = 0;
		//cout << "Round Robin\n";
		ST = 0;
		cout << "Enter Time Quantum : ";
		cin >> tq;
		int end = 0;
		for (int i = 0; i < n; i++)
			rr[i] = pr[i];

		int pre = minarr(rr,0);
		ST = rr[pre].at;
		rr[pre].mark = 1;
		queue <int> qu;
		qu.push(pre);
		while (end != 1)
		{
			np = 0;
			if (rr[pre].bt > tq)
			{
				rr[pre].bt = rr[pre].bt - tq;
				ST = ST + tq;
				np = 0;
			}
			else
			{
				ST = ST + rr[pre].bt;
				rr[pre].ct = ST;
				rr[pre].bt = 0;
				rr[pre].flag = 1;
				qu.pop();
				np = 1;

			}
			if (mcheck(rr) == 0 && check(rr) == 0 && qu.empty())
				ST = rr[minat(rr)].at;

			for (int i = 0; i < n; i++)
			{
				if (rr[nxtjob(pre, rr)].mark != 1)
				{
					qu.push(nxtjob(pre, rr));
					rr[nxtjob(pre, rr)].mark = 1;
				}
			}
			if (np == 0)
			{
				pre = qu.front();
				qu.pop();
				qu.push(pre);
			}
			pre = qu.front();

			if (qu.empty())
				end = 1;
		}
		for (int i = 0; i < n; i++)
		{
			rr[i].tat = rr[i].ct - rr[i].at;
			rr[i].wt = rr[i].tat - pr[i].bt;
		}
		disp(rr);
	}

	int nxtpr(int s, process temp[])
	{
		int pn = s, min = 0;
		for (int i = 0; i < n; i++)
			if (temp[i].flag == 0 && temp[i].at <= ST)
			{
				min = temp[i].p;
				pn = i;
				break;
			}

		for (int i = 0; i < n; i++)
			if (temp[i].p > min && ST >= temp[i].at && temp[i].flag == 0)
			{
				min = temp[i].p;
				pn = i;
			}
		return pn;
	}

	void ppmain()
	{
		intit();
		intit();
		//cout << "Pre-emptive Priority\n";
		ST = 0;
		int end = 0;

		for (int i = 0; i < n; i++)
			pp[i] = pr[i];

		ST = pp[minarr(pp,1)].at;
		int pre = minarr(pp,1);

		while (end != 1)
		{
			ST++;
			end = 1;
			if (pp[pre].bt > 0)
			{
				pp[pre].bt--;
				pp[pre].ct = ST;
			}
			if (pp[pre].bt <= 0)
				pp[pre].flag = 1;
			pre = nxtpr(pre, pp);

			for (int i = 0; i < n; i++)
				if (pp[i].flag == 0)
					end = 0;
		}
		for (int i = 0; i < n; i++)
		{
			pp[i].tat = pp[i].ct - pp[i].at;
			pp[i].wt = pp[i].tat - pr[i].bt;
		}
		disp(pp);
	}
	int minat(process temp[])
	{
		int min;
		int pn;

		for (int i = 0; i < n; i++)
			if (temp[i].flag == 0 && temp[i].mark == 0)
			{
				min = temp[i].at;
				pn = i;
				break;
			}
		for (int i = 0; i < n; i++)
			if (temp[i].at < min && temp[i].flag == 0 && temp[i].mark == 0)
			{
				min = temp[i].at;
				pn = i;
			}
		return pn;
	}

	int check(process temp[])
	{
		for (int i = 0; i < n; i++)
			if (ST > temp[i].at && temp[i].flag == 0 && temp[i].mark == 0)
				return 1;

		return 0;
	}

	void pnpmain()
	{
		intit();
		//cout << "Non Pre-emptive Priority\n";
		ST = 0;
		int end = 0;
		for (int i = 0; i < n; i++)
			np[i] = pr[i];

		int pre = minarr(np,1);
		ST = ST + np[pre].at + np[pre].bt;
		np[pre].ct = ST;
		np[pre].flag = 1;

		while (end != 1)
		{
			if (check(np) == 0)
				ST = np[minat(np)].at;

			end = 1;
			pre = nxtpr(pre, np);
			if (np[pre].flag == 0)
			{
				ST = ST + np[pre].bt;
				np[pre].ct = ST;
				np[pre].flag = 1;
			}

			for (int i = 0; i < n; i++)
				if (np[i].flag == 0)
					end = 0;
		}
		for (int i = 0; i < n; i++)
		{
			np[i].tat = np[i].ct - np[i].at;
			np[i].wt = np[i].tat - pr[i].bt;
		}
		disp(np);
	}
}sh;


int main()
{
	init();
	cout << "Enter n value !\n";
	cin >> n;
	//cout << "Input the Data\n";
	cout << "ENTER AT, BT and PRIO\n";
	for (int i = 0; i < n; i++)
		cin >> pr[i].at >> pr[i].bt >> pr[i].p;

	sh.schmain();
	return 0;
}




























































/*

#include <iostream>
#include <algorithm>

using namespace std;

class fcfs {
public:
	int pid,AT,BT,rBT,CT,WT,TAT,RT;
	int flag,order;
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
		cout<<"Enter AT & BT for P"<<i<<" :"<<endl;
		cin>>s[i].AT;
		cin>>s[i].BT;
		s[i].rBT= s[i].BT;
	}
}

void update_queue(int n,int t,int index) {
	for(int i=index+1;i<=n;i++) {
		if(s[i].AT <=sys_time) {
			rear++;
			Q[rear]=s[i].pid;
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
sys_time = s[0].AT;

//while(check<=n) {
//i=1;
//i++;
//	for(i=1;i<=n;i++) {

		if(s[0].rBT <= t && s[0].rBT !=0) {
			sys_time+=s[0].rBT;
			s[0].CT=sys_time;
			s[0].rBT=0;
			s[0].flag=1;
			check++;
		}
		else {

			sys_time+=t;
			s[0].rBT-=t;
			//s[i].CT+=t;
			update_queue(n,t,0);
			rear++;
			Q[rear]=s[0].pid;
			schedule(t);
		}
//	}
//}


while(check<=n) {


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

/*
for(int q=1;q<=x;q++) 
	cout<<Q[q]<<"\t";
cout<<endl;*/

//print_after(x);
/*
sys_time = s[0].AT;

	if(s[0].rBT <= t) {
		sys_time+=s[0].BT;
		s[0].CT=sys_time;
		s[0].rBT=0;
		s[0].flag=1;
		check++;
	}

	else {

		sys_time+=t;
		s[0].rBT-=t;
		s[0].CT+=t;
		update_queue(n,t);
		rear++;
		Q[rear]=s[0].pid;

	}
*/

