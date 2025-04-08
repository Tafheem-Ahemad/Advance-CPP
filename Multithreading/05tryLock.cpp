
/*

STD::Try_lock()

--> is work smae as mutex::try_lock() function.
--> only difference is that it can lock multiple mutexes at a time.
--> If any one of the mutexes is not able to lock, then it will not lock any of the mutexes that previously locked.
--> on successful lock acquisition, returns -1 , otherwise returns the index of the mutex that was not able to lock.(0 based index)


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