/*

TOPIC: unique lock In C++ (std::unique_lock_mutex> lock(ml))

NOTES:
1. The class unique_lock is a mutex ownership wrapper.
2. It Allows:
	a. Can Have Different Locking Strategies
	b. time-constrained attempts at locking (try_lock_for, try_lock_until)
	c. recursive locking
	d. transfer of lock ownership (move not copy)
	e. condition variables. (See this in coming videos)

Locking Strategies
    TYPE           EFFECTS(S)
    1. defer_lock   do not acquire ownership of the mutex.
    2. try_to_lock  try to acquire ownership of the mutex without blocking.
    3. adopt_lock   assume the calling thread already has ownership of the mutex.
*/

#include<bits/stdc++.h>
#define pp pair<int,int>
#define ll long long
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


int counter1 = 0;
mutex m;

// Example : 1

void increaseCounter(int n,string s){	
	unique_lock<mutex> lck(m);
	for(int i=0; i<n; i++){
		cout<<i<<" "<<s<<endl;
		counter1++;
	}
}

// Example : 2

timed_mutex m2;

int counter2 = 0;
void increaseCounter2(int n, string s) {
    std::unique_lock<std::timed_mutex> lck(m2,defer_lock);

    if (lck.try_lock_for(std::chrono::milliseconds(1))) {
        for (int i = 0; i < n; i++) {
            std::cout << i << " " << s << std::endl;
            counter2++;
        }

		this_thread::sleep_for(chrono::milliseconds(10));
    } else {
        std::cout << "Could not acquire lock in " << s << std::endl;
    }
}

// Example : 3

int counter3 = 0;
mutex m3;

void increaseCounter3(int n,string s){	
	unique_lock<mutex> lck(m3,try_to_lock);
	if(lck.owns_lock()){
		for(int i=0; i<n; i++){
			cout<<i<<" "<<s<<endl;
			counter3++;
		}
	}else{
		cout<<"Could not acquire lock in "<<s<<endl;
	}
}

int main(){
	fast();

	thread t1(increaseCounter,5,"First Thread");
	thread t2(increaseCounter,5,"Second Thread");

	t1.join();
	t2.join();

	cout<<"Counter 1: "<<counter1<<endl;


	thread t3(increaseCounter2,5,"Third Thread");
	thread t4(increaseCounter2,5,"Fourth Thread");

	t3.join();
	t4.join();

	cout<<"Counter 2: "<<counter2<<endl;


	thread t5(increaseCounter3,5,"Fifth Thread");
	thread t6(increaseCounter3,5,"Sixth Thread");

	t5.join();
	t6.join();

	cout<<"Counter 3: "<<counter3<<endl;

	return 0;
}