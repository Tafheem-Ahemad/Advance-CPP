

/*

Recursive Mutex


NOTES:
0. It is same as mutex but, Same thread can lock one mutex multiple times using recursive mutex.
1. If thread T1 first call lock/try_lock on recursive mutex ml, then ml is locked by T1, no as T1 is running in recursion T1 can call lock/try_lock any number of times there is no issue.
2. But if T1 have aquired 10 times lock/try_lock on mutex ml then thread T1 will have to unloc it 10 times otherwise no other thread will be able to lock mutex ml It means recursive mutex keeps count how many times it was locked so that many times it should be unlocked.
3. How many time we can lock recursive mutex is not defined but when that number reaches and if we were callin lock() it will return std::system_error OR if we were calling try_lock() then it will return fals


BOTTOM LINE:
0. It is similar to mutex but have extra factility that it can be locked multiple time by same thread.
1. If we can avoid recursive mutex then we should because it brings overhead to the system.
2. It can be used in loops also.


*/

#include<bits/stdc++.h>
#define pp pair<int,int>
#define ll long long
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){
	fast();



	return 0;
}
