#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <string>
using namespace std;

#define PI 3.14159265

class ComplexNumber
{
public:
	double real;
	double imag;
	ComplexNumber(double, double);
	ComplexNumber operator+(const ComplexNumber &);
	ComplexNumber operator-(const ComplexNumber &);
	ComplexNumber operator*(const ComplexNumber &);
	ComplexNumber operator/(const ComplexNumber &);
	bool operator==(const ComplexNumber &);
	double abs();
	double angle();
};

ComplexNumber::ComplexNumber(double x = 0, double y = 0)
{
	real = x;
	imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c)
{
	return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c)
{
	return ComplexNumber(real - c.real, imag - c.imag);
}

ComplexNumber operator+(double num, const ComplexNumber &c)
{
	return ComplexNumber(num + c.real, c.imag);
}

ComplexNumber operator-(double num, const ComplexNumber &c)
{
	return ComplexNumber(num - c.real, -c.imag);
}

ostream &operator<<(ostream &os, const ComplexNumber &c)
{
	if (c.real == 0 && c.imag == 0)
		return os << 0;
	else if (c.real == 0)
		return os << c.imag << "i";
	else if (c.imag == 0)
		return os << c.real;
	else
	{
		if (c.imag < 0)
			return os << c.real << c.imag << "i";
		else
			return os << c.real << "+" << c.imag << "i";
	}
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c)
{
	double result_r = (real * c.real) - (imag * c.imag);
	double result_i = (real * c.imag) + (imag * c.real);
	return ComplexNumber(result_r, result_i);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c)
{
	double result_r = ((real * c.real) + (imag * c.imag)) / ((pow(c.real, 2) + pow(c.imag, 2)));
	double result_i = ((imag * c.real) - (real * c.imag)) / ((pow(c.real, 2) + pow(c.imag, 2)));
	return ComplexNumber(result_r, result_i);
}

ComplexNumber operator*(double num, const ComplexNumber &c)
{
	ComplexNumber cn(num);
	return cn * c;
}

ComplexNumber operator/(double num, const ComplexNumber &c)
{
	ComplexNumber cn(num);
	return cn / c;
}

bool ComplexNumber::operator==(const ComplexNumber &c)
{
	if (real == c.real && imag == c.imag)
		return true;
	return false;
}

bool operator==(double num, const ComplexNumber &c)
{
	if (num == c.real && num == c.imag)
		return true;
	return false;
}

double ComplexNumber::abs()
{
	return sqrt(pow(real, 2) + pow(imag, 2));
}

double ComplexNumber::angle()
{
	return atan2(imag, real) * 180 / PI;
	;
}

// Write your code here
ComplexNumber convert(string str,ComplexNumber A,ComplexNumber B,ComplexNumber C,ComplexNumber D,ComplexNumber ANS)
{
	if(str == "A" || str == "B" || str == "C" || str == "D" || str == "ANS"){
		if(str == "A")
			return A;
		else if(str == "B")
			return B;
		else if(str == "C")
			return C;
		else if(str == "D")
			return D;
		else if(str == "ANS")
			return ANS;
	}else{
		string number = "";
		for (int i = 0; i < str.size(); i++)
		{
			//if ((str[i] > 47 && str[i] < 58) || str[i] == 46 || str[i] == '-')
			//{
				number += str[i];
			//}
		}
		ComplexNumber result(stod(number));
		return result;
	}
	return 0;
}

void mainComplex()
{
	ComplexNumber *A = new ComplexNumber;
	ComplexNumber *B = new ComplexNumber;
	ComplexNumber *C = new ComplexNumber;
	ComplexNumber *D = new ComplexNumber;
	ComplexNumber *ANS = new ComplexNumber;
	while (true)
	{
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "                               COMPLEX NUMBER                              " << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		char num;
		cout << "1. ComplexNumber A" << "  ( " << *A << " )" << "\t2. ComplexNumber B" << "  ( " << *B << " )" << "\n3. ComplexNumber C" << "  ( " << *C << " )" << "\t4. ComplexNumber D" << "  ( " << *D << " )" << "\n5. Calculate" << "\n6. Back";
		cout << "\t\t\t\t ANS ( " << *ANS << " )\n";
		cout << "\nSelect ComplexNumber that you want: ";
		cin >> num;
		if (num == '1')
		{
			cout << "A = " << *A << endl;
			double real, imag;
			cout << "Input real number of A: ";
			cin >> real;
			cout << "Input imagine number of A: ";
			cin >> imag;
			A->real = real;
			A->imag = imag;
			cout << "A = " << *A << endl;
		}
		else if (num == '2')
		{
			cout << "B = " << *B << endl;
			double real, imag;
			cout << "Input real number of B: ";
			cin >> real;
			cout << "Input imagine number of B: ";
			cin >> imag;
			B->real = real;
			B->imag = imag;
			cout << "B = " << *B << endl;
		}
		else if (num == '3')
		{
			cout << "C = " << *C << endl;
			double real, imag;
			cout << "Input real number of C: ";
			cin >> real;
			cout << "Input imagine number of C: ";
			cin >> imag;
			C->real = real;
			C->imag = imag;
			cout << "C = " << *C << endl;
		}
		else if (num == '4')
		{
			cout << "D = " << *D << endl;
			double real, imag;
			cout << "Input real number of D: ";
			cin >> real;
			cout << "Input imagine number of D: ";
			cin >> imag;
			D->real = real;
			D->imag = imag;
			cout << "D = " << *D << endl;
		}
		else if (num == '5')
		{
			char sign;
			string cn1;
			string cn2;
			ComplexNumber num1,num2;
			cout << "Input your equation | + | - | * | / | >> ";
			cin >> sign;
			cout << "Input First ComplexNumber: ";
			cin >> cn1;
			num1 = convert(cn1,*A,*B,*C,*D,*ANS);
			cout << "Input Second ComplexNumber: ";
			cin >> cn2;
			num2 = convert(cn2,*A,*B,*C,*D,*ANS);
			cout << "---------------------------------------------------------------------------\n";
			cout << "RESULT >> ";
			switch (sign)
			{
			case '+':
				*ANS =  num1 + num2;
				cout << *ANS;
				break;
			case '-':
				*ANS =  num1 - num2;
				cout << *ANS;
				break;
			case '*':
				*ANS =  num1 * num2;
				cout << *ANS;
				break;
			case '/':
				*ANS =  num1 / num2;
				cout << *ANS;
				break;
			}
			cout << endl;
		}
		else if (num == '6')
		{
			break;
		}else{
			cout << "Invalid input!!" << endl;
		}
	}
	delete A;
	delete B;
	delete C;
	delete D;
}
