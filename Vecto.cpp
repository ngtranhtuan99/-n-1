#include "Vecto.h"
Vecto::Vecto()
{
	for (int i = 1; i <= n; i++)
	{
		vector[i] = 0;
	}
}


void Vecto::Input()
{
	cout << "Enter number N: "; cin >> n; cout << endl;	
	for (int i = 1; i <= n; i++)
	{
		cout << "matrix[" << i << "]: ";
		cin >> vector[i];
	}	
}

void Vecto::Output()
{
	for (int i = 1; i <= n; i++)
	{
		cout << vector[i] << " ";
	}
	cout << endl;
}

void  Vecto::Plus_Vecto(Vecto a)
{
	if (this->n != a.n)
	{
		cout << "Error: Input incorrect, please Enter number of two Vector is the same !!!" << endl;
		return;
	}
	do
	{
		Vecto Result;
		cout << "Result A + B : ";
		for (int i = 1; i <= n; i++) {
			Result.vector[i] = vector[i] + a.vector[i];
			cout << Result.vector[i] << " ";
		}
		cout << endl;
	} while (this->n != a.n);
}

void Vecto::Multi_Vecto(float cons)
{
	Vecto Result;
	cout << "Result A*cons: ";
	for (int i = 1; i <= n; i++)
	{
		Result.vector[i] = vector[i] * cons;
		cout << Result.vector[i] << " ";
	}
	cout << endl;
}


Vecto::~Vecto()
{
}
