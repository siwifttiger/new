#include<iostream>
#include<cmath>
using namespace std;

int sumOfDivisor(int num){
	int sum = 0;
	for(int i = 2; i < (sqrt(num) +1); ++i){
		if(num % i == 0){
			sum += i+num/i;
		}
	}
	sum += 1;
	return sum;
}


int main(){
	int left, right;
	cin >> left >> right;
	int minNum = right;
	double minTrivi = right /2 + 0.5;
	double trivi = 0;
	if(left == 1) {cout << 1; return 0;}
	for(int i = right; i >= left; -- i){
		if(sumOfDivisor(i) == 1){
			minNum = i;
			break;
		}
		trivi = ((double)sumOfDivisor(i) / (double)i*1.0);
		if(minTrivi > trivi){
			minTrivi = trivi;
			minNum = i;
			//cout << minNum << ' ' << minTrivi << endl;
		}
	}
	cout << minNum << endl;
}