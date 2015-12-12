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

//������ת�����ַ���
string num2str(double i){
	stringstream ss;
	string s;
	ss << i;
	ss >> s;
	return s;
}
//��ʼ���ڵ�ֵ
void inintialXY(){
	for (double i = -1.0; i <= 1.0; i += 0.1){
		x.push_back(i);
		y.push_back(exp(i));
	}
	
}
//�����������{1��x,x^2...},n ��ʾ�ڵ����,�������Ӧλ�õ�ֵ
double computex(int a1, int a2, int n){
	double sum = 0;
	for (int i = 0; i <= n; ++i){
		sum += pow(x[i], a1)*pow(x[i], a2);
	}
	if (sum < EPS)
		sum = 0.0;
	return sum;

}
//�����B�ж�Ӧλ�õ�ֵ
double computey(int a, int n){
	double sum = 0;
	for (int i = 0; i <= n; i++){
		sum += y[i] * pow(x[i], a);
	}
	if (sum < EPS)
		sum = 0.0;
	return sum;
}
//��ʼ��ϵ������
void inintMatrix(int n,int l){
	A.set_size(l + 1, l + 1);
	for (int i = 0; i <= l; ++i){
		for (int j = 0; j <= l; ++j){
			A(i, j) = computex(i, j, n);
			
			
		}
		
	}
}
//��ʼ���𰸾���
void initAns(int n, int l){
	v1.set_size(l + 1);// v1������ź�������
	for (int i = 0; i <= l; ++i){
		v1(i) = computey(i, n);
		 
	}
}



// ���ڸ�����l������ln(cond(A))
double lCondA(int l){
	inintialXY();
	
	
	inintMatrix(20, l); //��ʼ��A
	initAns(20, l);//��ʼ��v1


	ans1.set_size(l + 1,1);
	ans1 = solve(A, v1); //ans1 �д�ŵľ���l�ε���С���˽⡣
	double c = cond(A);
	return log(c);
}
//����n�����õ¶���ʽ
double P(int n, double x){
	if (n == 0) return 1;
	else if (n == 1) return x;
	else if (n > 1) return ((2 * n - 1)*x*P(n - 1, x) - (n - 1)*P(n - 2, x)) / n;
}
//�����A�ж�Ӧλ�õ�ֵ��������Ϊ���õ¶���ʽ��
double computeXP(int a1, int a2, int n){
	double sum = 0;
	for (int i = 0; i <= 20; ++i){
		sum += P(a1, x[i])*P(a2, x[i]);
	}
	if (sum < EPS)
		sum = 0;
	return sum;
}
//�����B�ж�Ӧλ�õ�ֵ��������Ϊ���õ¶���ʽ��
double computeYP(int a, int n){
	double sum = 0;
	for (int i = 0; i <= n; ++i){
		sum += P(a, x[i])*y[i];
	}
	if (sum < EPS)
		sum = 0;
	return sum;
}
//��ʼ��ϵ������A
void initialMatrixP(int n, int l){
	A.set_size(l + 1,l+1);
	for (int i = 0; i <= l; ++i){
		for (int j = 0; j <= l; ++j){
			A(i, j) = computeXP(i, j, n);
		}
	}
}
//��ʼ��B
void initialAnsP(int n, int l){
	v1.set_size(l + 1);
	for (int i = 0; i <= l; ++i){
		v1(i) = computeYP(i, n);
	}
}
//�����l�ε�ln(cond(A))��������Ϊ���õ¶���ʽ��
double lnCondAP(int l){
	inintialXY();
	initialMatrixP(20, l);
	initialAnsP(20,l);
	ans1.set_size(l + 1, 1);
	ans1 = solve(A, v1); //ans1�����ŵ��ǻ�����Ϊ���õ¶���ʽ����С���˽�
	double c = cond(A);
	return log(c);

}
//������ն���ʽ��Ӧ��yֵ
double finalExp(mat conff,double x){
	double sum = 0;
	for (int i = 0; i < conff.size(); ++i){
		sum += pow(x, i)*conff(i, 0);
	}
	return sum;
}
//�����Сƫ��
double computeCancha(mat conff){
	double sum = 0;
	for (int i = 0; i <= 20; ++i){
		sum += pow(finalExp(conff, x[i]) - y[i],2);
	}
	return sum;
}


//�ó�����ʽ����ʽ
string outputP(mat conff, int l){
	string s;
	for (int i = 0; i <= l; ++i){
		s += (num2str(conff(i, 0)) + " * x^" + num2str(i) + '+');
	}
	s += '0';
	return s;
}

//��ʼ�����ڵ�һЩ���ã�����ɫΪ��ɫ��������[0,20],������[0,30].
void init(void){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 20.0, 0, 30.0);

}

//������1��15����ͬһ������ϵ�л���������������l �� ln(cond(A))������ 
//�Լ����õ¶���ʽΪ������������� l �� ln(cond(A))�����ߡ�
void lieSegment1(void){
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 0.0);
	//����x�ᣬy��
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
		out << "�������������������� " << i << "��Ӧ����Сƫ��Ϊ��" << computeCancha(ans1) << endl << "����ʽ����ʽΪ��\n";
		out << outputP(ans1, i) << endl;


	}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	for (int i = 1; i <= 15; ++i){
		glVertex2f(i, lnCondAP(i));
		out << "�������õ¶���ʽ�Ļ����������� " << i << "��Ӧ����Сƫ��Ϊ��" << computeCancha(ans1) << endl << "����ʽ����ʽΪ��\n";
		out << outputP(ans1, i) << endl;
	}
	out.close();
	glEnd();
	glFlush();
}

//�������õ¶���ʽΪ����������µ�����ͼ��
void lieSegment2(void){
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 0.0);
	//����x�ᣬy��
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
		out << "�������õ¶���ʽ�Ļ����������� " << i << "��Ӧ����Сƫ��Ϊ��" << computeCancha(ans1) << endl << "����ʽ����ʽΪ��\n";
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
	glutCreateWindow("����l��ln(cond(A))�Ĺ�ϵͼ");

	init();
	/*int choose;
		cout << "��ѡ��\n1.������������\n2.���õ¶���ʽ:\n";
		cin >> choose;
		switch (choose){
		case 1:
			glutDisplayFunc(lieSegment1);
		
			break;
		case 2:
			glutDisplayFunc(lieSegment2);
			
			break;
		default:
			cout << "����ѡ��" << endl;
			break;


		}*/
		glutDisplayFunc(lieSegment1);
		glutMainLoop();
	
}