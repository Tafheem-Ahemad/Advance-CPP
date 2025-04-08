/*


TOPICS: Condition Variable in C++ Threading

IMPORTANT POINT: CV are used for two purpose
	A. Notify other threads
	B. Waiting for some conditions

1. Condition Variable allows running threads to wait on some conditions and once those conditions are met the waiting thread is notified using:
		a. notify_one();
		b. notify_all();
2. You need mutex to use condition variable.
3. If some thread want to wait on some condition then it has to do these things:
	a. Acquire the mutex lock using std::unique_lock<std::mutex> lock(m);
	b. Execute wait, wait_for, or wait_until. The wait operations atomically release the mutex and suspend the execution of the thread.
	c. When the condition variable is notified, the thread is awakened, and the mutex is atomically reacquired.The thread should then check the condition and resume waiting if the wake up was spurious.means after get notification condition_variable will recheck the condition , because ,may be some false or unnessesery notification can be called from other threads

NOTE:
1. Condition variables are used to "synchronize" two or more threads.
2. Best use case of condition variable is Producer/Consumer problem.

*/


#include<bits/stdc++.h>
#define pp pair<int,int>
#define ll long long
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int balance=0;
condition_variable cv;
mutex mtx;

void addMoney(ll money){
	lock_guard<mutex> lock(mtx);
	cout<<"Thread A is Enterned"<<endl;
	balance+=money;
	cv.notify_all();
}


void withdrawMoney(int money){
	unique_lock<mutex> lock(mtx);
	cv.wait(lock,[&]{
		return balance > money;
	});

	if(balance>=money){
		balance-=money;
		cout<<"Balance is withdraw"<<endl;
	}else{
		cout<<"Balance can not be withdraw"<<endl;
	}

	cv.notify_all();
}

int main(){
	fast();

	thread t1(addMoney,5000);
	thread t2(withdrawMoney,1000);

	t1.join();
	t2.join();

	cout<<balance<<endl;


	return 0;
}