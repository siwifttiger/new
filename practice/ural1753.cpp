#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double bookHeight,bookShelfHeight,bookShelfLen;
const double eps = 1e-9;
const double PI = acos(-1.0);
//angle 表示书本和书架的夹角
double distance(double angle){
	return bookHeight*0.5*cos(angle)-bookShelfHeight/tan(angle);
}

double maxDistance(double left, double right){
	double m1,m2,m1_value,m2_value;
	while(fabs(right-left)>eps){
		m1 = left +(right-left)/3;
		m2 = right - (right-left)/3;
		m1_value = distance(m1);
		m2_value = distance(m2);
		if(m1_value >= m2_value)
			right = m2;
		else left = m1;
	}
	return m1_value;
}

int main(){
	cin >> bookShelfHeight >> bookHeight >> bookShelfLen;
	double leftAngle = 0.0;
	double rightAngle = PI*0.5;
	cout << fixed << maxDistance(leftAngle,rightAngle);
}