#include <iostream>
using namespace std;
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
int ch;

cout<<"Enter ur choice!\n1.zombie\t2.orphan\n";
cin>>ch;
switch(ch) {
	case 1 : {
			pid_t child_id=fork();
			if(child_id>0) {
				cout<<"Parent sleeps!\n";
				sleep(5);
				//wait(NULL);
				cout<<"parent woke up!\n";
				exit(1);
			}
			else {
//				sleep(5);
				cout<<"Child dies!\n";
				exit(0);
			}
		break;
	}
	case 2 : {
		pid_t child_id=fork();
		if(child_id>0) {
			//sleep(5);
			//wait(NULL);
			cout<<"parent dies!\n";
			exit(1);
		}
		else {
			cout<<"Child sleeps!\n";
			sleep(5);
			cout<<"Child woke up!\n";

			//exit(0);
		}
		break;
	}
	default : { cout<<"Wrong choice!\n"; break; }

  }

	return 0;
}
