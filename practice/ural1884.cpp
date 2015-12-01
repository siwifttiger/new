/*
ural 1884
Ҫ����ͨ������������������ľ�������Ϊ8
�ұ������������ľ�������Ϊ16

*/


#include<iostream>
#include<iomanip>
using namespace std;

int markLeft[10005],markRight[10005];

int main(){
	int n,m;
	//Ϊ��߳����ľ������ñ�־
	cin >> n;
	for(int i = 0; i < n; ++ i){
		int distanceL;
		cin >> distanceL;
		for(int j = 0; j < 5; ++ j){
			markLeft[distanceL + j] = 1;
		}
		
	}
	//Ϊ�ұ߳����ľ������ñ�־
	cin >> m;
	for(int i = 0; i < m; ++ i){
		int distanceR;
		cin >> distanceR;
		for(int j = 0; j < 5; ++ j){
			markRight[distanceR + j] = 1;
		}
	}
	for(int i = 0; i < 10005; ++i){
		bool flag = true;
		for(int j = 0; j < 8; ++ j){
			if(markLeft[i+j] || markRight[i+j+8]){
				flag = false;
				break;
			}
		}
		if(flag){
			cout.setf(ios::showpoint); 
			cout.precision(6);
			cout.setf(ios::fixed); 
			double temp = i*3.6/20;
			cout <<  temp;
			return 0;
		}
	}
	return 0;
}