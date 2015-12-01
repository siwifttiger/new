/*************************************************************************
	> File Name: p4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月05日 星期一 10时02分28秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
    int a,b,n;
    while(cin >> a >> b >> n){
        long long ans = 0;
        for(int i = 0; i < n; i+=a){
            int iInB = i/b, countForJ = 0, currentPage = 0;
            bool flag = 0;
            for(int j = i + 1; j < i+a && j<n; ++j){
                int jInB = j/b;
                if(jInB == iInB) continue;
                if(!flag){
                    currentPage = jInB;
                    countForJ = j - i;
                    flag = 1;
                }
                if(currentPage != jInB){
                    currentPage = jInB;
                    countForJ = j - i;
                }
                ans += countForJ;
            }
        }
        cout << ans << endl;
    }
}