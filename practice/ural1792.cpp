#include<iostream>
using namespace std;
int a[7];

bool isCorrect(){
	if(a[6] == (a[0] + a[1] + a[3])%2 
	&& a[5] == (a[0] + a[2] + a[3]) %2
	&& a[4] == (a[1] + a[2] + a[3]) %2) return true;
	return false;
}

int main(){
for(int i = 0; i < 7; ++ i) cin >> a[i];

for(int i = 0; i < 7; ++ i){
	if(isCorrect()){
		for(int j = 0; j < 7; ++ j)
			cout << a[j] << ' ';
			return 0;
	}
	else{
		int temp = a[i];
		a[i] = 1-a[i];
		if(isCorrect()){
			for(int j = 0; j < 7; ++ j)
			cout << a[j] << ' ';
			return 0;
		}
		a[i] = temp;
	}
}
}