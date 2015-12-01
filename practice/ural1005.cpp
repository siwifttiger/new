#include<iostream>
#include<bitset>
#include<cmath>
using namespace std;

int main(){
	 int n;
	cin >> n;
	int *stone = new int[n];
	int sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> stone[i];
		sum += stone[i];
	}
	
	int min = sum;
	for(int i = 0; i < (1 << n); ++ i){
		int temp = sum;
		bitset<20> b(i);
		for(size_t j = 0; j < n; ++ j){
			if(b.test(j)){
				temp = abs(temp-stone[j]);
				
			}
		}
		temp = abs(2*temp - sum);
		if(min > temp){
			min = temp;
		}
	}
	cout << min;
}