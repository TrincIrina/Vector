#include "Vector.h"

Vector::Vector()
	: Vector(0)
{
}

Vector::Vector(int size)
	: size{ size }
{
	vector = new double[size];
}

Vector::Vector(const Vector& other)
	: size{ other.size }
{
	vector = new double[size];
	for (int i = 0; i < size; i++)
		vector[i] = other.vector[i];
}

int Vector::get_size()
{
	return size;
}

double& Vector::elem(int index)
{
	return vector[index];
}

void Vector::print()
{
	for (int i = 0; i < size; i++)
		std::cout << vector[i] << " ";
}

std::string Vector::to_string()
{
	std::ostringstream out;
	out << "( ";
	for (int i = 0; i < size - 1; i++)
		out << vector[i] << ", ";
	out << vector[size - 1] << " )";
	return out.str();
}

bool Vector::line_vector(const Vector& other)
{
	return size == other.size;
}

Vector Vector::invert()
{
	for (int i = 0; i < size; i++)
		vector[i] *= -1;
	return *this;
}

Vector Vector::multiplication(double number)
{
	for (int i = 0; i < size; i++)
		vector[i] *= number;
	return *this;
}

void Vector::increment()
{
	for (int i = 0; i < size; i++)
		vector[i]++;	            // Увеличиваем каждую координату
}

Vector Vector::prefix_inc()
{
	increment();    // Увеличиваем вектор
	return *this;   // Возрращаем копию
}

Vector Vector::postfix_inc()
{
	Vector old = *this;  // Сохранить старое значение 
	increment();         // Сделать инкремент
	return old;          // Вернуть старое значение
}

void Vector::decrement()
{
	for (int i = 0; i < size; i++)
		vector[i]--;                  // Уменьшаем каждую координату
}

Vector Vector::prefix_dec()
{
	decrement();       // Уменьшаем вектор
	return *this;      // Возрращаем копию
}

Vector Vector::postfix_dec()
{
	Vector old = *this;   // Сохранить старое значение
	decrement();          // Сделать декремент
	return old;           // Вернуть старое значение
}

double Vector::module()
{
	double S = 0;
	for (int i = 0; i < size; i++)
		S += vector[i] * vector[i];
	return sqrt(S);
}

Vector Vector::sum(Vector& summand)
{	
	Vector a(size);
	for (int i = 0; i < size; i++)
		a.elem(i) = vector[i] + summand.vector[i];
	return a;
}

Vector Vector::difference(Vector& deductaible)
{
	Vector a(size);
	for (int i = 0; i < size; i++)
		a.elem(i) = vector[i] - deductaible.vector[i];
	return a;
}

Vector Vector::multiplication(Vector& multiplier)
{
	Vector a(size);
	for (int i = 0; i < size; i++)
		a.elem(i) = vector[i] * multiplier.vector[i];
	return a;
}

Vector Vector::division(Vector& divider)
{
	Vector a(size);
	for (int i = 0; i < size; i++)
		a.elem(i) = vector[i] / divider.vector[i];
	return a;
}

bool Vector::equals(const Vector& other)
{
	int f = 0;
	for (int i = 0; i < size; i++) {
		if (vector[i] == other.vector[i]) {
			f++;
		}
	}
	if(f==size)
		return true; 
	else
		return false;
}

int Vector::compare(Vector& other)
{
	double mod_1 = module();
	double mod_2 = other.module();
	if (mod_1 == mod_2)
		return 0;
	if (mod_1 > mod_2)
		return 1;
	if (mod_1 < mod_2)
		return -1;
}

Vector Vector::operator+(Vector& summand)
{
	return sum(summand);
}

Vector Vector::operator-(Vector& deductaible)
{
	return difference(deductaible);
}

Vector Vector::operator*(Vector& multiplier)
{
	return multiplication(multiplier);
}

Vector Vector::operator*(double multiplier)
{
	return multiplication(multiplier);
}

Vector Vector::operator/(Vector& divider)
{
	return division(divider);
}

Vector Vector::operator++()
{
	return prefix_inc();
}

Vector Vector::operator++(int)
{
	return postfix_inc();
}

Vector Vector::operator--()
{
	return prefix_dec();
}

Vector Vector::operator--(int)
{
	return postfix_dec();
}

int Vector::operator[](int index)
{
	return vector[index];
}

bool Vector::operator==(const Vector& other)
{
	return equals(other);
}

bool Vector::operator!=(const Vector& other)
{
	return !equals(other);
}

bool Vector::operator<(Vector& other)
{
	return compare(other) < 0;
}

bool Vector::operator>(Vector& other)
{
	return compare(other) > 0;
}

bool Vector::operator<=(Vector& other)
{
	return compare(other) <= 0;
}

bool Vector::operator>=(Vector& other)
{
	return compare(other) >= 0;
}

Vector::~Vector()
{
	delete[] vector;
}