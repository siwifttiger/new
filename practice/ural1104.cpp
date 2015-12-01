/*************************************************************************
	> File Name: p1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月25日 星期日 16时05分18秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;



/*long digit2num(int a[], int length,int k){
    long sum = 0;
    for(int i = 0; i < length; ++ i){
        sum += a[i] * pow(k,length-i-1);
    }
    return sum;
}*/

int str2num(string str, int& k){
    int length = str.size();
    int sum = 0;
    int a;
    for(int i = 0; i < length; ++i){
        if(isdigit(str[i])){
            a = str[i] - '0';
        }
        else{
            a = str[i] - 'A' +10;
        }
        k = max(k,a);
        sum += a;
    }
    return sum;
}

int main(){
    string str;
    cin >> str;
   // int length = str.size();
    int k = 0;
   long ans = str2num(str,k);
   if(k==0) k++;
    for(; k <= 36; ++k){
        
        if(ans % (k) == 0){
            cout << k +1<< endl;
            //cout << ans << endl;
            return 0;
        }
    }
    cout << "No solution.";
    return 0;

}