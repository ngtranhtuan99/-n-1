#pragma once
#include<iostream>
using namespace std;
#define max 5 // cấp lớn nhất của ma trận
#define VC -10000// kết quả cho là sai
class Matrix
{
private:
	double matrix[max][max];
	int n; // Số hàng
	int m; // Số cột
public:
	Matrix();
	void Input(); // Hàm nhập ma trân 
	void Output(); // Hàm xuất ma trận
	int GetN() { return this->n; } // hàm lấy ra só hàng N của ma trận 
	int GetM() { return this->m; } // hàm lấy ra só hàng M của ma trận 
	double Del_Matrix(Matrix A, int size); // Hàm tính định thức ma trận
	Matrix Matrix_xoabo(int ha, int co); //ma trân sau khi xóa đi hàng ha cột co
	void Matrix_nghichdao(Matrix a); // Tìm ma trận nghịch đảo
	void Mul_matrix(Matrix temp); // Tích hai ma trận 
	void Matrix_thutu();// Sắp xếp thứ tự các dòng trong ma trận
	void Matrix_bacthang(); // Tìm matrix bậc thang
	void Matrix_hang(Matrix a); // Tìm hạng của ma trận
	void Matrix_HPT(); // hàm giải hệ phương trình tuyến tính
	
	~Matrix();

};
