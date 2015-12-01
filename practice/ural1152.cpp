#include <iostream>
#include <vector>
using namespace std;

vector<int>dp(1<<20,-1);
int n;
int posDam[30];

int addOn(int num,int pos){
	return num = (num | (1<<pos));
}

int deleteOff(int num, int pos){
	return num = (num & ~(1<<pos));
}

bool check(int num, int pos){
	return (bool)(num & (1<<pos));
}



int solve(int mask){  //�ӿ�״̬��ʼ����Ѱ��
	if(mask == (1<<n)-1) return 0; // ȫ��������
	if(dp[mask] != -1) return dp[mask];
	int ans = 1 << 28; //�ܴ����
	for(int i = 0; i < n; ++ i){
		if(!check(mask,i)){  //���λ�ò��ڵ�ǰ״̬�����У������Լ����������ӽ���
			int x = i+1;
			int y = i+2;
			int dam = 0;
			int temp = mask;
			if(x >= n ) x-=n;
			if(y>= n) y -=n;
			temp = addOn(temp,i);
			temp = addOn(temp,x);
			temp = addOn(temp,y);
			for(int j = 0; j < n; j++){
				if(!check(temp,j)) //��������λ�ò��ڵ�ǰ�����У��ͻ��������˺�
					dam += posDam[j];
			}
			ans = min(ans, solve(temp)+dam);
		} 
		
	}
	return dp[mask]=ans;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; ++ i){
		cin >> posDam[i];
	}
	cout << solve(0) << endl;
}