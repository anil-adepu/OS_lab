#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
pid_t pid=vfork();
int n;

if(pid==0) {
	cout<<"Enter n value!\n";
	cin>>n;
	_exit(0);
}
else {
	wait(NULL);
	cout<<"The collatz sequence is :\n";
	cout<<n;
	while(n>1) {
		if(n % 2 ==0) {
			n = n / 2;
			cout<<"  "<<n;
		}
		else {
			n= 3 * n + 1;
			cout<<"  "<<n;
		}
	}
	cout<<endl;
}

	return 0;
}



/*
















int main() {
	pid_t pid;
	pid = vfork();
	int n;
	if(pid == 0) {
		cout<<"Enter n value!\n";
		cin>>n;
		exit(0);
	}
	else if(pid > 0) {
		wait(NULL);
		printf("sequence is\n");
		cout<<n;
		while(n != 1)
		{
			if(n % 2 == 0)
				n = n / 2;
			else
				n = (3 * n) + 1;
			cout<<"  "<<n;
		}
		printf("\n");

	}

return 0;

}
*/
