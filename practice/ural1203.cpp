/*************************************************************************
	> File Name: p1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月26日 星期四 07时52分51秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


struct Data {
    int start;
    int finish;
    Data();
    Data(int s,int f){
        start = s;
        finish = f;
    }
};

vector<Data> data;

bool cmp(const Data& d1, const Data& d2){
    if(d1.finish < d2.finish)
    return true;
    return false;
}

int greedySelect(const vector<Data>& d){
    int count = 1;
    int n = d.size();
    int i = 0;
    for(int m = 1; m < n; ++ m){
        if(d[m].start > d[i].finish){
            ++count;
            i = m;
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    int s, f;
    for(int i = 0; i < n; ++ i ){
        cin >> s >> f;
        Data tmpData(s,f);
        data.push_back(tmpData);
    }
    sort(data.begin(),data.end(),cmp);
    cout << greedySelect(data);

}