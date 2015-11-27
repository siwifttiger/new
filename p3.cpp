#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Line{
	int left;
	int right;
	Line();
	Line(int left, int right){
		this->left = left;
		this->right = right;
	}
};
vector<Line> lines;
vector<Line> ans;

bool cmp(Line l1, Line l2){
	if(l1.left < l2.left) return true;
	return false;
}

void output(const vector<Line>& line){
	for(int i = 0; i < line.size(); ++ i){
		cout << line[i].left << ' ' << line[i].right << endl;
	}
}

void findMaxRight(const vector<Line>& line, int right, int maxR){
	int len = line.size();
	int maxIndex = 0;
	Line tmp(0,0);
	for(int i = 0; i < len; ++ i){
		if(line[i].left <= right){
			if(line[i].right >= maxR){
				tmp = line[i];
				maxR = tmp.right;
				maxIndex = i;
			}
		}
	}
//	if(tmp.left != 0 || tmp.right != 0)
		ans.push_back(tmp);
	
}

int main(){
	int left, right,M;
	cin >> M;
	for(;;){
		cin >> left >> right;
		if(left == 0 && right == 0) break;
		Line tmp1(left,right);
		lines.push_back(tmp1);
	}
	sort(lines.begin(),lines.end(),cmp);
	
	int maskRight = 0;
	int count = 0;
	int len = lines.size();
	int maxRight = -100000;
	for(int i = 0; i < len; ++ i){
		findMaxRight(lines,maskRight,maxRight);
		if(ans[ans.size()-1].right >= M){
			cout << ans.size() << endl;
			for(int j = 0; j < ans.size(); ++ j){
				cout << ans[j].left << ' ' << ans[j].right << endl;
			}
			return 0;
		}
		else{
			maskRight = ans[ans.size()-1].right;
			maxRight = maskRight;
		}
	}
	cout << "No solution" << endl;
}
