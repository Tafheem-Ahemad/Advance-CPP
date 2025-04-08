

/*

STD::Lock() (For locking multiple mutexes at a timeto avoid deadlock)

It is used to lock multiple mutex at the same time.

IMPORTANT:

syntax-> std::lock(m1, m2, m3, m4);
1. All arguments are locked via a sequence of calls to lock(), try_lock(), or unlock() on each 		argument.
2. Order of locking is not defined (it will try to lock provided mutex in any order and ensure that   there is no deadlock).It is a blocking call.
3. If any of the mutexes is already locked, then it will release all the mutexes that were locked
4. It is a blocking call.


*/

/*


Example: 1 --> No Deadlock

	Thread 1      Thread 2

	lock(m1,m2);	lock(m2,m1);

Example: 2 --> No Deadlock

	Thread 1      Thread 2

	lock(m1,m2);	lock(m2,m1);

Example: 3 --> No Deadlock

	Thread 1      Thread 2

	lock(m1,m2,m3,m4);	lock(m1,m2);
						lock(m3,m4);


						
Example: 4 --> may be Deadlock

	Thread 1      Thread 2

	lock(m3,m4);	lock(m1,m2);
	lock(m1,m2);	lock(m3,m4);



*/

#include<bits/stdc++.h>
#define pp pair<int,int>
#define ll long long
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

mutex m1,m2;

void threadAword(){
	lock(m1,m2); 
	this_thread::sleep_for(chrono::milliseconds(100));
	cout<<"Thread A working Start"<<endl;
	m1.unlock();
	m2.unlock();
}
void threadBword(){
	lock(m1,m2);
	this_thread::sleep_for(chrono::milliseconds(100));
	cout<<"Thread B working Start"<<endl;
	m1.unlock();
	m2.unlock();
}
void threadCword(){
	scoped_lock lock(m1,m2); // scoped_lock is used ,so no need to unlock the mutexes explicitly.
	this_thread::sleep_for(chrono::milliseconds(100));
	cout<<"Thread C working Start"<<endl;
}

int main(){
	fast();

	thread t1(threadAword);
	thread t2(threadBword);
	thread t3(threadCword);


	t1.join();
	t2.join();
	t3.join();

	

	return 0;
}