#include "Matrix.h"

Matrix::Matrix()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void Matrix::Input()
{
	cout << "Enter number N: "; cin >> n; cout << endl;
	cout << "Enter number M: "; cin >> m; cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "Enter matrix[" << i << "]""[" << j << "]:";
			cin >> matrix[i][j];
		}
	}
}

void Matrix::Output()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{			
			cout<< matrix[i][j]<<" ";
		}
		cout << endl;
	}
}

double Matrix::Del_Matrix(Matrix A, int size)
{
	int k; // Chỉ số Hi. k=(-1)^h
	double Sum = 0;
	// Không phải ma trận vuông
	if (n != m)
	{
		cout << "Error: Input incorrect, Sorry :( Only find Del matrix NxN. Please Enter  matrix NxN !!!" << endl;
		return VC;
	}
	//  ma trận vuông
	while (n == m)
	{
		// Ma trận 1x1
		if (size == 1) return A.matrix[0][0];
		// Ma trận 2x2
		if (size == 2) return A.matrix[0][0] * A.matrix[1][1] - A.matrix[0][1] * A.matrix[1][0];
		//Xét ma trận h hàng
		for (int h = 0; h < size; h++)
		{
			// Tạo một matrix temp để chưa các ma trận phân nhỏ của matrix A
			Matrix temp;
			for (int i = 0; i < size; i++)
			{
				for (int j = 1; j < size; j++)
				{
					// bỏ đi hàng h
					if (i < h) temp.matrix[i][j - 1] = A.matrix[i][j];
					else if (i > h) temp.matrix[i - 1][j - 1] = A.matrix[i][j];
				}
			}
			if (h % 2 == 0) k = 1;
			else k = -1;
			Sum += k * A.matrix[h][0] * Del_Matrix(temp, size - 1);
		}
		return Sum;
	}
}

void Matrix::Matrix_thutu()
{
	// dòng nào có phần từ đầu tiên là 1 thì ưu tiên đưa lên đầu dòng cho dễ 
	for (int i = 0; i < n; i++)
	{
		if (matrix[i][0] == 1)
		{
			int temp = matrix[0][0];
			matrix[0][0] = matrix[i][0];
			matrix[i][0] = matrix[0][0];
		}
	}
}

void Matrix::Matrix_bacthang()
{
	// Sắp xếp lại thứ tự các dòng dữ liệu cho dễ dàng thực hiện biến đổi bậc thang
	Matrix::Matrix_thutu();
	// Dùng thuật toán Gausse
	for (int i = 0; i < n-1; i++)
	{
		for (int k = i + 1; k < n; k++)
		{
			if (matrix[k][i] != 0)
			{
				double t = matrix[k][i] / matrix[i][i];
				for (int j = 0; j < m; j++)
				{
					matrix[k][j] = matrix[k][j] - t * matrix[i][j];
				}
			}
		}
	}
}

Matrix Matrix::Matrix_xoabo(int ha, int co)
{
	Matrix Result;

	// xóa bỏ hàng i=ha
	for (int i = ha; i < n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = matrix[i + 1][j];
		}		
	}
	// xóa bỏ cột j=co
	for (int j = co; j < m - 1; j++)
	{
		for (int i = 0; i < n; i++)
		{
			matrix[i][j] = matrix[i][j + 1];
		}
	}
	
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < m-1; j++)
		{
			Result.matrix[i][j] = matrix[i][j];
		}
	}
	return Result;
}

void Matrix::Matrix_nghichdao(Matrix a)
{
	// ma trận b là phụ hợp của a
	Matrix b;
	// định thức của ma trận A
	double Del = a.Del_Matrix(a, n);
	if (Del == 0)
	{
		cout << " Don't have inverse matrix A because Del(A)= 0 \n";
		return;
	}
	
	// Không phải ma trận vuông
	if (n != m)
	{
		cout << "Error: Input incorrect, Sorry :( Only find Del matrix NxN. Please Enter  matrix NxN !!!" << endl;
		return;
	}
	//  ma trận vuông
	else
	{
		for (int rows = 0; rows < n; rows++)
		{
			for (int col = 0; col < m; col++)
			{
				//Tạo ma trận temp1 phụ cho là ma trận a lúc đầu
				Matrix temp1 = a;
				// ma trận temp2 là ma trận temp1 sau khi bỏ đi hàng rows và cột col
				Matrix temp2 = temp1.Matrix_xoabo(rows, col);
				// ma trận b 
				b.matrix[rows][col] = pow(-1, rows + col)*temp2.Del_Matrix(temp2, n - 1);

			}
		}

		cout << "Result inverse matrix A: " << endl;
		// Del(A)
		double re = 1 / Del;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << b.matrix[i][j] * re << " ";
			}
			cout << endl;
		}
	}
}

void Matrix::Mul_matrix(Matrix temp)
{
	Matrix Result;
	if (m != temp.GetN())
	{
		cout << "Error: input incorrect, Please Enter number N of matrix B is equal the number M of matrix A !!!" << endl;
		return;
	}
	cout << "Result matrix A x matrix B : \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < temp.n; k++)
			{
				sum = sum + matrix[i][k] * temp.matrix[k][j];				
			}
			Result.matrix[i][j] = sum;
		}
	}
	// in ma trận Result
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < temp.GetM(); j++)
		{
			cout << Result.matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;	
}

void Matrix::Matrix_hang(Matrix a)
{
	// Không phải ma trận vuông
	if (n != m)
	{
		cout << "Error: Input incorrect, Sorry :( Only find rank matrix NxN. Please Enter  matrix NxN !!!" << endl;
		return;
	}
	// nếu đinh thức của ma trận A!=0 thì rank(A)=n
	if (a.Del_Matrix(a, a.GetN()) != 0)  cout << "Rank(A)= " << a.GetN();
	else
	{
		// Tìm hàng ma trận bằng chuyển về ma trận bậc thang. Tìm xem còn bao nhiêu dòng khác 0 thì đó là hạng của ma trận
		Matrix::Matrix_bacthang();
		cout << endl;
		Matrix::Output();
		int hang = n;
		for (int i = 0; i < n; i++)
		{
			int dem = 0;
			for (int j = 0; j < m; j++)
			{
				if (matrix[i][j] == 0)	dem++;
			}
			// Nguyên dòng đó là 0
			if (dem == m) hang--;
		}
		cout << "Rank(A)= " << hang << endl;
	}
}

void Matrix::Matrix_HPT()
{
	// Giải hệ phương trình bậc 2
	if (n == 2)
	{
		if (m == 3)
		{
			double x, y;
			Matrix Dx, Dy, D;
			Matrix temp1, temp2;

			// gán temp1 là matrix
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					temp1.matrix[i][j] = matrix[i][j];
				}
			}
			// gán temp2 là matrix
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					temp2.matrix[i][j] = matrix[i][j];
				}
			}

			//tìm ma trận D
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m - 1; j++)
				{
					D.matrix[i][j] = matrix[i][j];
				}
			}


			// Tìm ma trận Dx
			for (int i = 0; i < n; i++)
			{
				int temp = temp1.matrix[i][0];
				temp1.matrix[i][0] = temp1.matrix[i][2];
				temp1.matrix[i][2] = temp1.matrix[i][0];
				for (int k = 0; k < n; k++)
				{
					for (int t = 0; t < m - 1; t++)
					{
						Dx.matrix[k][t] = temp1.matrix[k][t];
					}
				}
			}
			// Tìm ma trận Dy
			for (int i = 0; i < n; i++)
			{
				int temp = temp2.matrix[i][1];
				temp2.matrix[i][1] = temp2.matrix[i][2];
				temp2.matrix[i][2] = temp2.matrix[i][1];
				for (int k = 0; k < n; k++)
				{
					for (int t = 0; t < m - 1; t++)
					{
						Dy.matrix[k][t] = temp2.matrix[k][t];
					}
				}
			}
			cout << "Result nghiem cua he phuong trinh bac 2:" << endl;
			// Nghiem x:
			x = Dx.Del_Matrix(Dx, n) / D.Del_Matrix(D, n);
			cout << "X= " << x << endl;
			// Nghiem y:
			y = Dy.Del_Matrix(Dy, n) / D.Del_Matrix(D, n);
			cout << "Y= " << y << endl;
		}
		else
		{
			cout << "Error: input incorrect, Please Enter number M=3 to solve HPT bac 2 !!!" << endl;
			return;
		}
	}

	// giải hệ phương trình bậc 3
	if (n == 3)
	{
		if (m == 4)
		{
			double x, y, z;
			Matrix Dx, Dy, Dz, D;
			Matrix temp1, temp2, temp3;

			// gán temp1 là matrix
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					temp1.matrix[i][j] = matrix[i][j];
				}
			}
			// gán temp2 là matrix
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					temp2.matrix[i][j] = matrix[i][j];
				}
			}
			// Gán temp3 là matrix
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					temp3.matrix[i][j] = matrix[i][j];
				}
			}

			//tìm ma trận D
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m - 1; j++)
				{
					D.matrix[i][j] = matrix[i][j];
				}
			}


			// Tìm ma trận Dx
			for (int i = 0; i < n; i++)
			{
				int temp = temp1.matrix[i][0];
				temp1.matrix[i][0] = temp1.matrix[i][3];
				temp1.matrix[i][3] = temp1.matrix[i][0];
				for (int k = 0; k < n; k++)
				{
					for (int t = 0; t < m - 1; t++)
					{
						Dx.matrix[k][t] = temp1.matrix[k][t];
					}
				}
			}
			// Tìm ma trận Dy
			for (int i = 0; i < n; i++)
			{
				int temp = temp2.matrix[i][1];
				temp2.matrix[i][1] = temp2.matrix[i][3];
				temp2.matrix[i][3] = temp2.matrix[i][1];
				for (int k = 0; k < n; k++)
				{
					for (int t = 0; t < m - 1; t++)
					{
						Dy.matrix[k][t] = temp2.matrix[k][t];
					}
				}
			}
			// Tìm ma trận Dz
			for (int i = 0; i < n; i++)
			{
				int temp = temp3.matrix[i][2];
				temp3.matrix[i][2] = temp3.matrix[i][3];
				temp3.matrix[i][3] = temp3.matrix[i][2];
				for (int k = 0; k < n; k++)
				{
					for (int t = 0; t < m - 1; t++)
					{
						Dz.matrix[k][t] = temp3.matrix[k][t];
					}
				}
			}
			cout << "Result nghiem cua he phuong trinh bac 3:" << endl;
			// Nghiem x:
			x = Dx.Del_Matrix(Dx, n) / D.Del_Matrix(D, n);
			cout << "X= " << x << endl;
			// Nghiem y:
			y = Dy.Del_Matrix(Dy, n) / D.Del_Matrix(D, n);
			cout << "Y= " << y << endl;
			// Nghiem z:
			z = Dz.Del_Matrix(Dz, n) / D.Del_Matrix(D, n);
			cout << "Z= " << z << endl;


		}
		else
		{
			cout << "Error: input incorrect, Please Enter number M=4 to solve HPT bac 3 !!!" << endl;
			return;
		}
	}
	if((n!=2) && (n!=3))
	{
		cout << "Error: Input incorrect, please enter number n=2 or n=3. Sorry :( Program is only supports solve HPT bac2 and bac 3!!!" << endl;
		return;
	}
}

Matrix::~Matrix()
{

}
