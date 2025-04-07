
/*

Mutex: Mutual Exclusion

RACE CONDITION:
0. Race condition is a situation where two or more threads/process happen to change a common data at the same time. if two or more threads just read the data , the no race condition
1. If there is a race condition then we have to protect it and the protected setion is called critical section/region.

MUTEX:
0. Mutex is used to avoid race condition.
1. We use lock(), unlock() on mutex to avoid race condition.

*/


#include<bits/stdc++.h>
#define pp pair<int,int>
#define ll long long
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

// using mutex

mutex m1;
int amount=0;

void add(string s){
	m1.lock();
	cout<<s<<endl;
	amount++;
	this_thread::sleep_for(chrono::milliseconds(200));
	m1.unlock();
}

int main(){
	fast();

	thread t1(add,"First Thread");
	thread t2(add,"second Thread");

	this_thread::sleep_for(chrono::milliseconds(100));
	cout<<amount<<endl;

	t1.join();
	t2.join();


	return 0;
}