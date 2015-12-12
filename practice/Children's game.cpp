#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

string num[100];

bool cmp(string num1, string num2){
	return num1+num2 > num2+num1;
}


int main(){
	
	int n;
	while(true){
		cin >> n;
	
		if(n == 0) break;
		for(int i = 0; i < n; ++ i){
			cin >> num[i];
		}
		sort(num,num+n,cmp);
		for(int i = 0; i < n; ++ i)
		cout << num[i];
		cout << endl;
	}
	
}
