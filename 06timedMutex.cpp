

/*

TOPIC: Timed Mutex in C++ Threading (std::timed_mutex)

/ NOTES:
0. std::timed_mutex is blocked till timeout_time or the lock is aquired and returns true if success 
   otherwise false.
1. Member Function:
    a. lock
    b. try_lock
    c. try_lock_for     ---\ These two functions makes it different from mutex.
    d. try_lock_until   ---/
    e. unlock

/ EXAMPLE: try_lock_for();
Waits until specified timeout duration has elapsed or the lock is acquired, whichever comes first.
On successful lock acquisition returns true, otherwise returns false.


--> Simply means, let thread A lock the mutex and thread B is trying to lock the mutex. If thread A is not able to unlock the mutex within the specified time, then thread B will not be able to lock the mutex and it will return false. If thread A is able to unlock the mutex within the specified time, then thread B will be able to lock the mutex and it will return true.

*/



#include<bits/stdc++.h>
#define pp pair<int,int>
#define ll long long
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

timed_mutex m;

int counter=0;
void increaseTheCounter(int i){
	
	if(m.try_lock_for(chrono::milliseconds(1000))){
		counter++;
		cout<<"Thread "<<i<<" is able to lock the mutex"<<endl;
		this_thread::sleep_for(chrono::milliseconds(1001)); // simulating some work
		m.unlock();
	}else{
		cout<<"Thread "<<i<<" is not able to lock the mutex"<<endl;
	}
}

int main(){
	fast();

	thread t1(increaseTheCounter,1);
	thread t2(increaseTheCounter,2);

	t1.join();
	t2.join();

	cout<<counter<<endl;

	return 0;
}