/**
 思路：ret用来存放前n-1个素数，若当前奇整数不能被ret里的任何一个素数整除，则该
 数也是素数，继续存入到ret中，直到ret的大小等于n
**/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int MAXN = 170000;
long long prime[MAXN];

void solve(){
	
	prime[1] = 2;
	prime[2] = 3;
	int count = 3;
	bool flag = true;
	for(int i= 4; i < MAXN; ++i){
		for(int j = 2; j <= sqrt(i); ++j){
			if(i%j == 0){
				flag = false;
			}
		}
		if(flag){
			prime[count] = i;
			count++;
		}
		flag = true;
	}
}

int main(){
	solve();
	int n;
	cin >> n;
	int temp;
	for(int i = 0; i < n; ++ i){
		cin >> temp;
		cout << prime[temp] << endl;
	}
}