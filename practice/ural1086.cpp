/**
 ˼·��ret�������ǰn-1������������ǰ���������ܱ�ret����κ�һ���������������
 ��Ҳ���������������뵽ret�У�ֱ��ret�Ĵ�С����n
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