#include<iostream>
#include<algorithm>
using namespace std;

int money[100000];
int binary(int low, int high,int m,int n){
	int mid;
	while(low <= high){
		int sum = 0,count = 1;
		mid = (low+high)/2;
		for(int i = 0; i < n; ++ i){
			if(sum + money[i] <= mid){
				sum += money[i];
			}else{
				sum = money[i];
				++count;
			}
		}
		if(count > m){
			low = mid +1;
		}else{
			high = mid -1;
		}
	}
	return low;
}


int main(){
	int n;int m;
	cin >> n >> m;
	int sum = 0;
	int maxmum = 0;
	for(int i = 0; i < n; ++ i){
		cin >> money[i];
		sum += money[i];
		maxmum = max(maxmum,money[i]);
	}
	cout << binary(maxmum,sum,m,n);
}