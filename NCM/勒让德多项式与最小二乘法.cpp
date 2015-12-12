#include<iostream>
#include<GL/glut.h>
#include<vector>
#include<cmath>
#include<string>
#include<sstream>
#include<fstream>
#include"armadillo"
using namespace arma;
using namespace std;

vector<double>x;
vector<double>y;
const double EPS = 1e-10;
mat A(100,100);
vec v1(100);
mat ans1;

//把数字转化成字符串
string num2str(double i){
	stringstream ss;
	string s;
	ss << i;
	ss >> s;
	return s;
}
//初始化节点值
void inintialXY(){
	for (double i = -1.0; i <= 1.0; i += 0.1){
		x.push_back(i);
		y.push_back(exp(i));
	}
	
}
//假设基函数是{1，x,x^2...},n 表示节点个数,计算出对应位置的值
double computex(int a1, int a2, int n){
	double sum = 0;
	for (int i = 0; i <= n; ++i){
		sum += pow(x[i], a1)*pow(x[i], a2);
	}
	if (sum < EPS)
		sum = 0.0;
	return sum;

}
//计算出B中对应位置的值
double computey(int a, int n){
	double sum = 0;
	for (int i = 0; i <= n; i++){
		sum += y[i] * pow(x[i], a);
	}
	if (sum < EPS)
		sum = 0.0;
	return sum;
}
//初始化系数矩阵
void inintMatrix(int n,int l){
	A.set_size(l + 1, l + 1);
	for (int i = 0; i <= l; ++i){
		for (int j = 0; j <= l; ++j){
			A(i, j) = computex(i, j, n);
			
			
		}
		
	}
}
//初始化答案矩阵
void initAns(int n, int l){
	v1.set_size(l + 1);// v1用来存放函数矩阵。
	for (int i = 0; i <= l; ++i){
		v1(i) = computey(i, n);
		 
	}
}



// 对于给定的l，计算ln(cond(A))
double lCondA(int l){
	inintialXY();
	
	
	inintMatrix(20, l); //初始化A
	initAns(20, l);//初始化v1


	ans1.set_size(l + 1,1);
	ans1 = solve(A, v1); //ans1 中存放的就是l次的最小二乘解。
	double c = cond(A);
	return log(c);
}
//计算n阶勒让德多项式
double P(int n, double x){
	if (n == 0) return 1;
	else if (n == 1) return x;
	else if (n > 1) return ((2 * n - 1)*x*P(n - 1, x) - (n - 1)*P(n - 2, x)) / n;
}
//计算出A中对应位置的值（基函数为勒让德多项式）
double computeXP(int a1, int a2, int n){
	double sum = 0;
	for (int i = 0; i <= 20; ++i){
		sum += P(a1, x[i])*P(a2, x[i]);
	}
	if (sum < EPS)
		sum = 0;
	return sum;
}
//计算出B中对应位置的值（基函数为勒让德多项式）
double computeYP(int a, int n){
	double sum = 0;
	for (int i = 0; i <= n; ++i){
		sum += P(a, x[i])*y[i];
	}
	if (sum < EPS)
		sum = 0;
	return sum;
}
//初始化系数矩阵A
void initialMatrixP(int n, int l){
	A.set_size(l + 1,l+1);
	for (int i = 0; i <= l; ++i){
		for (int j = 0; j <= l; ++j){
			A(i, j) = computeXP(i, j, n);
		}
	}
}
//初始化B
void initialAnsP(int n, int l){
	v1.set_size(l + 1);
	for (int i = 0; i <= l; ++i){
		v1(i) = computeYP(i, n);
	}
}
//计算出l次的ln(cond(A))（基函数为勒让德多项式）
double lnCondAP(int l){
	inintialXY();
	initialMatrixP(20, l);
	initialAnsP(20,l);
	ans1.set_size(l + 1, 1);
	ans1 = solve(A, v1); //ans1里面存放的是基函数为勒让德多项式的最小二乘解
	double c = cond(A);
	return log(c);

}
//算出最终多项式对应的y值
double finalExp(mat conff,double x){
	double sum = 0;
	for (int i = 0; i < conff.size(); ++i){
		sum += pow(x, i)*conff(i, 0);
	}
	return sum;
}
//算出最小偏差
double computeCancha(mat conff){
	double sum = 0;
	for (int i = 0; i <= 20; ++i){
		sum += pow(finalExp(conff, x[i]) - y[i],2);
	}
	return sum;
}


//得出多项式的形式
string outputP(mat conff, int l){
	string s;
	for (int i = 0; i <= l; ++i){
		s += (num2str(conff(i, 0)) + " * x^" + num2str(i) + '+');
	}
	s += '0';
	return s;
}

//初始化窗口的一些设置，背景色为白色，横坐标[0,20],纵坐标[0,30].
void init(void){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 20.0, 0, 30.0);

}

//次数从1到15，在同一个坐标系中画出正常基函数下l 和 ln(cond(A))的曲线 
//以及勒让德多项式为基函数的情况下 l 和 ln(cond(A))的曲线。
void lieSegment1(void){
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 0.0);
	//画出x轴，y轴
	glBegin(GL_LINES);
	glVertex2i(1, 1);
	glVertex2i(1, 30);
	glVertex2i(1, 1);
	glVertex2i(20, 1);
	glEnd();
	ofstream out;
	out.open("result.txt");
	glBegin(GL_LINE_STRIP);
	for (int i = 1; i <= 15; ++i){
		glVertex2f(i, lCondA(i));
		out << "对于正常基函数，次数 " << i << "对应的最小偏差为：" << computeCancha(ans1) << endl << "多项式的形式为：\n";
		out << outputP(ans1, i) << endl;


	}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	for (int i = 1; i <= 15; ++i){
		glVertex2f(i, lnCondAP(i));
		out << "对于勒让德多项式的基函数，次数 " << i << "对应的最小偏差为：" << computeCancha(ans1) << endl << "多项式的形式为：\n";
		out << outputP(ans1, i) << endl;
	}
	out.close();
	glEnd();
	glFlush();
}

//画出勒让德多项式为基函数情况下的曲线图。
void lieSegment2(void){
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 0.0);
	//画出x轴，y轴
	glBegin(GL_LINES);
	glVertex2i(1, 1);
	glVertex2i(1, 30);
	glVertex2i(1, 1);
	glVertex2i(20, 1);
	glEnd();
	ofstream out;
	out.open("result.txt");
	glBegin(GL_LINE_STRIP);
	for (int i = 1; i <= 15; ++i){
		glVertex2f(i, lnCondAP(i));
		out << "对于勒让德多项式的基函数，次数 " << i << "对应的最小偏差为：" << computeCancha(ans1) << endl << "多项式的形式为：\n";
		out << outputP(ans1, i) << endl;
	}
	out.close();
	glEnd();
	glFlush();
}


void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 300);
	glutCreateWindow("次数l和ln(cond(A))的关系图");

	init();
	/*int choose;
		cout << "请选择\n1.正常基函数：\n2.勒让德多项式:\n";
		cin >> choose;
		switch (choose){
		case 1:
			glutDisplayFunc(lieSegment1);
		
			break;
		case 2:
			glutDisplayFunc(lieSegment2);
			
			break;
		default:
			cout << "错误选择" << endl;
			break;


		}*/
		glutDisplayFunc(lieSegment1);
		glutMainLoop();
	
}