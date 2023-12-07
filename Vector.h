#pragma once

#include<iostream>
#include<sstream>
#include<string>
//����� ������
class Vector
{
private:
	int size;         // ���������� ��������� �������
	double* vector;   // ���������� �������
public:
	// ������������
	Vector();
	Vector(int size);
	// ����������� �����������
	Vector(const Vector& other);
	// setter & getter
	int get_size();
	double& elem(int index);

	// ������ ������ ��������� �������
	void print();
	std::string to_string();

	// �������� � ����� �� ������� ��������� ��������� �������
	// (�������� �� �������� ��� ������� ���������)
	bool line_vector(const Vector& other); 

	// �������� � ��������
	Vector invert();         // ��������� ����� ������� 
	
	void increment();        // ��������� �������
	Vector prefix_inc();     // ���������� ���������
	Vector postfix_inc();    // ����������� ���������
	void decrement();        // ���������
	Vector prefix_dec();     // ���������� ���������
	Vector postfix_dec();    // ����������� ���������
	
	Vector multiplication(double number);     // ��������� ������� �� �����
	double module();                          // ������ �������	     
	
	Vector sum(Vector& summand);                // �������� ��������
	Vector difference(Vector& deductaible);     // �������� ��������
	Vector multiplication(Vector& multiplier);  // ��������� ��������
	Vector division(Vector& divider);           // ������� ��������

	bool equals(const Vector& other);      // ��������� �������� �� �����������
	int compare(Vector& other);            // �������� �������� �� ������

	// ��������������� ����������
	Vector operator+(Vector& summand);	
	Vector operator-(Vector& deductaible);
	Vector operator*(Vector& multiplier);
	Vector operator*(double multiplier);
	Vector operator/(Vector& divider);

	Vector operator++();				// ���������� ���������
	Vector operator++(int);			    // ����������� ���������
	Vector operator--();                // ��������� ���������
	Vector operator--(int);             // ����������� ���������
	
	int operator[](int index);			// ���������� ������� �� �������

	bool operator==(const Vector& other);
	bool operator!=(const Vector& other);
	bool operator<(Vector& other);
	bool operator>(Vector& other);
	bool operator<=(Vector& other);
	bool operator>=(Vector& other);

	// ����������
	~Vector();
};

