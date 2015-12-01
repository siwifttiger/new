/*************************************************************************
	> File Name: p4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月28日 星期一 14时21分23秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<queue>
using namespace std;

char s[4] = {"012"};
const int MAXN = 12000;

struct Node{
    string s;
    int mod;
};

int n;
string bfs(){
  int num[MAXN*100] = {0};
  //for(int i = 0; i< MAXN *100; i++)
  //	num[i] = 0;
    queue<Node>q;
    Node p;
    p.s="";
    p.mod = 0;
    q.push(p);
    while(!q.empty()){
        Node x = q.front();
        q.pop();
        int len = x.s.length();
        if(len > 30) break;
        for(int i = 1; i<=2; i++){
            Node y;
            y.mod = (x.mod * 10 + i) % n;
           if(num[y.mod]) continue;
            num[y.mod] = 1;
            y.s = x.s+s[i];
            if(y.mod == 0){
               
                            return y.s;
            }
            q.push(y);
        }
    }
    
    return "Impossible";
}

int main(){
    while(cin >> n){
        string c = bfs();
        cout << c << endl;
       
    }
    return 0;
}