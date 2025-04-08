
/*

TOPIC: std::future and std::promise in threading.

NOTES:
1. std::promise
	a. Used to set values or exceptions.
2. std::future
	a. Used to get values from promise.
	b. Ask promise if the value is available.
	c. Wait for the promise.

*/

#include<bits/stdc++.h>
#define pp pair<int,int>
#define ll long long
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


void findOddSum(promise<ll>&& oddSum,ll n){
	ll sum=0;
	for(int i=1;i<=n;i+=2){
		sum+=i;
	}

	oddSum.set_value(sum);
}

int main(){
	fast();

	promise<ll>oddSum;
	future<ll>oddSumGet=oddSum.get_future();

	thread t1(findOddSum,move(oddSum),100);

	// Some code
	this_thread::sleep_for(chrono::seconds(2));

	cout<<"Wating For Value"<<endl;
	cout<<oddSumGet.get()<<endl;
	cout<<"Completed"<<endl;

	t1.join();

	return 0;
}