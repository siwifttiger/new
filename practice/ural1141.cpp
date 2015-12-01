#include<iostream>
#include<cmath>
using namespace std;

void extendGcd(int a, int b, int& x, int& y){
	if(b == 0){
		x =1;
		y =0;
		return;
	}
	extendGcd(b,a%b,x,y);
	int t = x;
	x = y;
	y = t - a/b*y;
}

bool isPrime(int n){
	for(int i = 2; i*i < n; ++ i){
		if(n%i == 0)
			return false;
	}
	return true;
}


void findPQ(int n, int& p, int& q){
	for(int i = 2; i*i < n; ++i){
		if(n % i == 0 && isPrime(i) and isPrime(n/i)){
			p = i;
			q = n/i;
			return;
		}
	}
}
/*x^y mod N*/
int modExp(int x, int y, int N){
	if(y ==0) return 1;
	int z = modExp(x,y/2,N);
	if(y%2 == 0){
		return z*z%N;
	}
	else return (((x*z)%N)*z)%N;
}

int main(){
	int times,e,c,n,x,y,p,q;
	cin >> times;
	for(int i = 0; i < times; ++i){
		cin >> e >> n >> c;
		findPQ(n,p,q);
		extendGcd(e,(p-1)*(q-1),x,y);
		while(x < 0){
			x += (p-1)*(q-1);
		}
		cout << modExp(c,x,n) << endl;
	}
}