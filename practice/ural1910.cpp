#include<iostream>
using namespace std;

int main(){
  int sum = 0;
  int max = 0;
  int index = 0;
  int n;
  cin >> n;
  int * num = new int[n];
  for(int i = 0; i < n; ++ i){
    cin >>num[i];
   
  }
  for(int i = 0; i < n - 2; ++ i){
    sum = num[i]+num[i+1]+num[i+2];
    if(max < sum){
      max = sum;
      index = i;
    }
  }
  cout << max << ' ' << index +2;
}