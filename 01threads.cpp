#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define ll long long
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

/*-

NOTE :-
1. Thread is a lightweight process. It is a separate flow of execution. It is a sequence of instructions that can be executed independently of other code.
2. If you create multiple threads, Then which will compile first, it is not guaranteed. It depends on the OS and the CPU. So, the output may be different for different runs.

*/

// Creating a "Thread"

// Method 1 (using normal function)
void solve(ll n){
	while(n--){
		cout<<n<<endl;
	}
}
int main(){
	fast();

	std::thread t1(solve,10);
	t1.join();

	return 0;
}

// Method 2 (using Lambda function)
// lambda function is a function without a name, it is an anonymous function
int main(){

	auto solve=[&](ll n)->void{
		while(n--){
			cout<<n<<endl;
		}
	};

	std::thread t1(solve,10);
	t1.join();
	return 0;
}


// methiod 3 (using Class object)
class Bus{
public:

	void solve(ll n){
		while(n--){
			cout<<n<<endl;
		}
	}
};

int main(){

	Bus b;
	std::thread t1(Bus::solve,&b,10);
	t1.join();

	return 0;
}

// methiod 4 (using Static class metohod)
class Bus{
public:

	static void solve(ll n){
		while(n--){
			cout<<n<<endl;
		}
	}
};

int main(){

	std::thread t1(Bus::solve,10);
	t1.join();

	return 0;
}
