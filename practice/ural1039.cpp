#include<iostream>
#include<vector>
using namespace std;

int dp[6005][2];
vector<int> tree[6005];
int value[6005];
int isRoot[6005];

void dfs(int root){
	dp[root][1] = value[root];
	int len = tree[root].size();
	for(int i = 0; i < len; ++ i)
		dfs(tree[root][i]);
	for(int i = 0; i < len; ++ i){
		dp[root][0] += max(dp[tree[root][i]][0],dp[tree[root][i]][1]);
		dp[root][1] += dp[tree[root][i]][0];
	}
}

int main(){
	int n;
	int l,k;
	cin >> n;
	for(int i = 1; i <= n; ++ i){
		cin >> value[i];
		dp[i][0]= dp[i][1] = 0;
		isRoot[i] = -1; //  根节点标识 
	}
	
	while(true){
		cin >> l >> k;
		if(l==0 && k == 0) break;
		isRoot[l]=k; // 第k个节点是第l个节点的父节点 
		tree[k].push_back(l); // 将l加入以k为根节点的树中 
	}
	//找出根节点
	int root = 1;
	while(isRoot[root] != -1) root = isRoot[root];
	dfs(root);
	cout << max(dp[root][1],dp[root][0]); 
}
