#include <iostream>

//矩阵为4行5列
#define row 4
#define col 5
using namespace std;

//初始化矩阵，读入数据
void iniMat(int** pA) {
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			cin >> pA[i][j];
}

//输出4*5矩阵
void outMat(int** pA) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			cout << pA[i][j] << "\t";
		cout << "\n";
	}
}

//矩阵相加，A3=A1+A2
void addMat(int** pA3, int** pA1, int** pA2) {
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) 
			pA3[i][j] = pA1[i][j] + pA2[i][j];
}

//矩阵相减，A3=A1-A2
void subMat(int** pA3, int** pA1, int** pA2) {
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			pA3[i][j] = pA1[i][j] - pA2[i][j];

}

int main()
{
	//申请高一级的动态数组
	int** pA1 = new int* [row];
	int** pA2 = new int* [row];
	int** pA3 = new int* [row];
	//申请低一级的动态数组
	for (int i = 0; i < row; ++i) {
		pA1[i] = new int [col];
		pA2[i] = new int [col];
		pA3[i] = new int [col];
	}

	cout << "输入矩阵A1（4*5）" << endl;
	iniMat(pA1);
	cout << "输入矩阵A2（4*5）" << endl;
	iniMat(pA2);

	addMat(pA3, pA1, pA2);
	cout << "A3 = A1 + A2 =" << endl;
	outMat(pA3);

	subMat(pA3, pA1, pA2);
	cout << "A3 = A1 - A2 =" << endl;
	outMat(pA3);


	//释放低一级的动态数组
	for (int i = 0; i < row; ++i) {
		delete[] pA1[i];
		delete[] pA2[i];
		delete[] pA3[i];
	}
	//释放高一级的动态数组
	delete[] pA1;
	delete[] pA2;
	delete[] pA3;

	return 0;
}

