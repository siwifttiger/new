/*************************************************************************
	> File Name: p3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月24日 星期四 16时49分49秒
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