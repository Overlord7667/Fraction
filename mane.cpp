#include<iostream>
using namespace std;

class Fraction
{
	int integer;       //Целая часть
	int numerator;	   //Числитель
	int denominator;   //Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		//Single-argument constructor - Конструктор с одним параметром
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;

	}
	~Fraction()
	{
		cout << "Destructor\t" << this << endl;
	}

	//Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}

	//Method
	void to_proper()
	{
		//Переводит дробь в правильную - выделяет уелую часть:
		integer += numerator / denominator;
		numerator %= denominator;
	}
	void to_improper()
	{
		//Переводит дробь в НЕправильную - интегрирует целую часть в числитель
		numerator += integer * denominator;
		integer = 0;
	}
	void reduce()
	{
		//Сокращает дробь:
	}
	void print()
	{
		//5;
		//1/2;
		//2(3/4);
		if (integer)cout << integer;// Если есть целая часть выводим её на экран
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
	

};
//#define CONSTRUCTORS_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;//Default Constructor
	A.print();
	Fraction B = 5;//Single-argument constructor(Конструктор с одним параметром)
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();

#endif // CONSTRUCTORS_CHECK

	Fraction A(14, 4);
	A.to_proper();
	A.print();
	A.to_improper();
	A.print();
}