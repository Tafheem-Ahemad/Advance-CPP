
/*


// Deadlock in C++ Multithreading
// A deadlock is a situation in which two or more threads are unable to proceed because each thread is waiting for the other to release a resource.
// Here thread A is waiting for thread B to release the lock on mutex m2, and thread B is waiting for thread A to release the lock on mutex m1. As a result, both threads are blocked and cannot proceed.

*/


#include<bits/stdc++.h>
#define pp pair<int,int>
#define ll long long
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

mutex m1,m2;

void threadAword(){
	m1.lock();
	this_thread::sleep_for(chrono::milliseconds(100));
	m2.lock();
	cout<<"Thread A working Start"<<endl;
	m1.unlock();
	m2.unlock();
}
void threadBword(){
	m2.lock();
	this_thread::sleep_for(chrono::milliseconds(100));
	m1.lock();
	cout<<"Thread B working Start"<<endl;
	m1.unlock();
	m2.unlock();
}

int main(){
	fast();

	thread t1(threadAword);
	thread t2(threadBword);


	t1.join();
	t2.join();

	

	return 0;
}