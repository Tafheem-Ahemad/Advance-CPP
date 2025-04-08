
/*

TOPIC: Lock_guard In C++ (std::Lock_guard<mutex> Lock(m1))

NOTES:
0. It is very light weight wrapper for owning mutex on scoped basis.
1. It aquires mutex lock the moment you create the object of lock_guard.
2. It automatically removes the lock while goes out of scope.
3. You can not explicitly unlock the lock_guard.
4. You can not copy lock_guard.

*/

#include<bits/stdc++.h>
#define pp pair<int,int>
#define ll long long
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

mutex m1; 
void print(int n,string s){
	
	lock_guard<mutex> lck(m1); 
	for(int i=0; i<n; i++){
		cout<<i<<" "<<s<<endl;
	}
}

int main(){
	fast();

	thread t1(print,5,"First Thread");
	thread t2(print,5,"Second Thread");

	t1.join();
	t2.join();

	return 0;
}