#include<iostream>
#include<cmath>
#include<gl/glut.h>
using namespace std;

//系数矩阵 
double A[3][3] = { { 2, -1, 2 },
{ 1, 2, 3 },
{ 2, -2, -3 }
};

//初始向量 
double b[3] = { 4, 9, -3 };


void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 2.0, 0.0, 1000.0);
}


int SOR(double w, int size){
	//存放第k次的结果 
	double x[3] = { 0, 0, 0 };
	//存放第k+1次的迭代结果 
	double xx[3] = { 0, 0, 0 };

	//最大迭代次数
	const int MAX = 1000;

	//无穷范数
	double dis = 0.0;
	//两次迭代结果之差
	double dif = 1.0;
	//精度 
	double eps = 1e-5;
	double sum = 0.0;
	double res = 0.0;
	int time = 0;
	for (int k = 1; (k<MAX) && (dif >= eps); k++){
		dif = 0.0;
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				if (j<i){
					sum += A[i][j] * xx[j];
				}
				if (j >= i){
					sum += A[i][j] * x[j];
				}
			}
			xx[i] = x[i] + w*(b[i] - sum) / A[i][i];
			sum = 0.0;
		}
		//计算两次相邻迭代结果之差，2范数 
		res = 0.0;
		for (int m = 0; m < size; ++m){
			res += (xx[m] - x[m])*(xx[m] - x[m]);
		}
		dif = pow(res, 0.5);


		for (int m = 0; m < size; ++m){
			x[m] = xx[m];
		}

		time = k;
	}

	cout << "\n 当w = " << w << ",迭代结果为:\n";
	for (int k = 0; k < size; ++k){
		cout << x[k] << " ";
	}
	cout << "\n迭代次数为" << time << endl;
	return time;

}


void line(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.4, 0.2);
	glBegin(GL_LINE_STRIP);
	double w = 0.1;
	while (w < 2.0){
		int n = SOR(w, 3);
		glVertex2f(w, n);
		w += 0.1;
	}
	glEnd();
	glFlush();
}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(300, 400);
	glutCreateWindow("SOR 松弛因子与迭代次数关系");

	init();
	glutDisplayFunc(line);
	glutMainLoop();
}