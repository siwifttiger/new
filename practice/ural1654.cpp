/*************************************************************************
	> File Name: p3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015��09��24�� ������ 16ʱ49��49��
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main(){
    string s;
    vector<char>container;
    cin >> s;
    container.push_back(s[0]);
    for(int i = 1; i < s.length();++i){
        if(container.empty())
            container.push_back(s[i]);
        else{
            if(s[i] == container.back()){
                container.pop_back();
            }
            else{
                container.push_back(s[i]);
            }
        }
    }
    for(int i = 0; i < container.size(); ++ i)
        cout << container[i];
}