#include<iostream>
#include<cmath>
using namespace std;

void extendGcd(int a, int b, int& x, int& y){
	if(b == 0){
		x = 1;
		y = 0;
		return;
	}
	extendGcd(b,a%b,x,y);
	int t = x;
	x = y;
	y = t - a/b*y;
}

bool isPrime(int num){
	for(int i = 2; i*i < num; i++){
		if(num %i == 0)
			return false;
	}
	return true;
}

int main(){
	int times,p,q,x,y,n;
	cin >> times;
	for(int i = 0; i < times; ++i){
		cin >> n;
		for(int j = 2; j*j < n; ++j){
			if((n%j == 0) && isPrime(j) && isPrime(n/j)){
				p = j;
				q = n/j;
				break;
			}

		}
			extendGcd(p,q,x,y);
			if(x<0) x = x+q;
			int ans1 = p*x;
			extendGcd(q,p,x,y);
			if(x < 0) x = x+p;
			int ans2 = q*x;
			cout << 0 << ' ' << 1 << ' ' << min(ans1,ans2) << ' ' << max(ans1,ans2) << endl; 
	}
}