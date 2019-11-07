#include "Vecto.h"
#include"Matrix.h"

int main()
{
	int select;
	do {
		cout << "\n================CHUONG TRINH MENU CAC CHUC NANG DO AN 1================\n";
		cout << "\n-----------------------------------------------------------------------\n";
		cout << "* Developer: Nguyen Truong Anh Tuan - 1712197 \n";
		cout << "             Nguyen Van Dien        - 1712342 \n";
		cout << "* Contect me: 1712197@student.hcmus.edu.vn \n";
		cout << "\n-----------------------------------------------------------------------\n";
		cout << endl;
		cout << "1. Tim cong thuc phu toi tieu cua ma tran ham Bool\n";
		cout << "2. Phep toan cong hai Vecto.\n";
		cout << "3. Phep toan nhan vecto voi so anpha.\n";
		cout << "4. Tim dinh thuc ma tran vuong nxn.\n";
		cout << "5. Nghich dao ma tran vuong nxn.\n";
		cout << "6. Tich hai ma tran.\n";
		cout << "7. Tim hang cua ma tran.\n";
		cout << "8. He phuong trinh tuyen tinh.\n";
		cout << "\n-----------------------------------------------------------------------\n";
		cout << "Enter Select with (0 < Select < 8) - Select: ";		cin >> select;
		switch (select)
		{
		case 1:
		{
			cout << "Sorry :(. Now, the system don't support. Update is as the soon !!!";
			break;
		}
		case 2:
		{
			cout << "\n==========Thuc hien cong hai vector (vector A + vector B)===========\n";		
			Vecto a, b;
			cout << "Enter vector A :\n";	a.Input();
			cout << "Enter vector B :\n";	b.Input();
			cout << "\nVector A:\n";	a.Output();
			cout << "\nVector B:\n";	b.Output();
			
		    a.Plus_Vecto(b);
			break;

		}
		case 3:
		{
			cout << "\n==========Thuc hien pheo toan nhan vector A voi so anpha( A x anpha)===========\n";
			Vecto a;					   
			cout << "Enter vector A :\n";	a.Input();
			cout << "Vector A:\n";	a.Output();
			double cons;
			cout << "Enter cons :"; cin >> cons;
			a.Multi_Vecto(cons);
			break;
		}
		case 4:
		{
			cout << "\n===========Thuc hien chuong trinh tim dinh thuc cua ma tran vuong nxn===============\n";
			Matrix a;

			cout << "Enter Matrix A:\n"; a.Input();			
			cout << "Matrix A:\n"; a.Output();			
		    double Result = a.Del_Matrix(a, a.GetN());
			cout << "Del(A): " << Result;
			cout << endl;
			break;					
		}
		case 5:
		{
			cout << "\n============Thuc hien chuong trinh tim ma tran nghich dao=======================\n";
			Matrix a;
			cout << "Enter Matrix A:\n"; a.Input();
			cout << "Matrix A:\n"; a.Output();
			cout << endl;
			a.Matrix_nghichdao(a);
			break;
		}
		case 6:
		{
			cout << "\n============= Thuc hien chuong trinh tinh tich hai matrix ( A x B) =====================\n";
			Matrix a, b;
			cout << "Enter Matrix A:\n"; a.Input();
			cout << "Enter Matrix B:\n"; b.Input();
			cout << "Matrix A:\n"; a.Output();
			cout << "Matrix B:\n"; b.Output();
			a.Mul_matrix(b);
			break;
		}
		case 7:
		{
			cout << "\n============= Thuc hien chuong trinh tim hang cua ma tran ===================\n";
			Matrix a;
			cout << "Enter Matrix A:\n"; a.Input();
			cout << "Matrix A:\n"; a.Output();
			a.Matrix_hang(a);
			break;
		}
		case 8:
		{
			cout << "=============== Thuc hien chuong trinh giai he phuong trinh tuyen tinh=================\n";
			Matrix a;
			cout << "Enter Matrix A:\n"; a.Input();
			cout << "Matrix A:\n"; a.Output();
			a.Matrix_HPT();
			break;

		}
		default:
			cout << "Error: Input incorrect, Enter SelectChon with ( 0 < Select < 8)" << endl;
			break;
		}
	} while (select!=9);
	return 0;
}
