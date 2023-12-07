#pragma once

#include<iostream>
#include<sstream>
#include<string>
//Класс Вектор
class Vector
{
private:
	int size;         // количество координат вектора
	double* vector;   // координаты вектора
public:
	// Конструкторы
	Vector();
	Vector(int size);
	// Конструктор копирования
	Vector(const Vector& other);
	// setter & getter
	int get_size();
	double& elem(int index);

	// Методы вывода координат вектора
	void print();
	std::string to_string();

	// Проверка в одной ли системе координат находятся векторы
	// (возможны ли операции над данными векторами)
	bool line_vector(const Vector& other); 

	// операции с векторам
	Vector invert();         // Изменение знака вектора 
	
	void increment();        // Инкремент вектора
	Vector prefix_inc();     // Префиксный инкремент
	Vector postfix_inc();    // Постфиксный инкремент
	void decrement();        // Декремент
	Vector prefix_dec();     // Префиксный декремент
	Vector postfix_dec();    // Постфиксный декремент
	
	Vector multiplication(double number);     // Умножение вектора на число
	double module();                          // Модуль вектора	     
	
	Vector sum(Vector& summand);                // Сложение векторов
	Vector difference(Vector& deductaible);     // Разность векторов
	Vector multiplication(Vector& multiplier);  // Умножение векторов
	Vector division(Vector& divider);           // Деление векторов

	bool equals(const Vector& other);      // сравнение векторов по координатам
	int compare(Vector& other);            // сравнеие векторов по модулю

	// Соответствующие перегрузки
	Vector operator+(Vector& summand);	
	Vector operator-(Vector& deductaible);
	Vector operator*(Vector& multiplier);
	Vector operator*(double multiplier);
	Vector operator/(Vector& divider);

	Vector operator++();				// префиксный инкремент
	Vector operator++(int);			    // постфиксный инкремент
	Vector operator--();                // префисный декремент
	Vector operator--(int);             // постфиксный декремент
	
	int operator[](int index);			// координата вектора по индексу

	bool operator==(const Vector& other);
	bool operator!=(const Vector& other);
	bool operator<(Vector& other);
	bool operator>(Vector& other);
	bool operator<=(Vector& other);
	bool operator>=(Vector& other);

	// Деструктор
	~Vector();
};

