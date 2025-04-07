
/*

// Mutex try_lock

// 0. try_lock() tries to lock the mutex. Returns immediately.On successful lock acquisition, returns true; otherwise, returns false.

// 1. If try_lock() is not able to lock mutex, then it doesn't get blocked that's why it is called non-blocking.

// 2. If try_lock is called again by the same thread which owns the mutex, the behavior is undefined. It is a deadlock situation with undefined behaviour. (If you want to be able to lock the same mutex by the same thread more than one time, then go for `recursive_mutex`)


*/

#include<bits/stdc++.h>
#define pp pair<int,int>
#define ll long long
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


mutex m;

int counter=0;
void increaseTheCounter(){

	// Here we are trying to lock the mutex using try_lock() function. when try_lock() is not able to lock the mutex, it will return false and we will not go to that block. So, we can not increase the counter in that iteration. so in that iteration we will not increase the counter.
	
	// in some iteration conter will increase and in some iteration it will not increase. So, we are not getting the desire output.

	//The normal lock will block the thread until the mutex is unlocked and wait for it.But try_lock() will not block or wait for the mutex to be unlocked. it just go to the next iteration.

	for(int i=0;i<10;i++){
		if(m.try_lock()){
			counter++;
			m.unlock();
		}
	}
}

int main(){
	fast();

	thread t1(increaseTheCounter);
	thread t2(increaseTheCounter);

	t1.join();
	t2.join();

	cout<<counter<<endl;

	return 0;
}