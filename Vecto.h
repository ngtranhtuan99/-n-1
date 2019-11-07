#pragma once
#include<iostream>
using namespace std;
#define max 10 // Số lượng phần tử tối đa của matrix
class Vecto
{
private:
	double vector[max];	
	int n; // sô luong vecto

public:
	
	Vecto(); // hàm khởi tạo một vector
	
	void Input();// hàm nhập một vector
	void Output(); // hàm in ra một vector
	void Plus_Vecto(Vecto a); // hàm tính tổng hai vector
	void Multi_Vecto(float cons); // hàm nhân một vector cho const
	~Vecto(); // hàm hủy vector
};
