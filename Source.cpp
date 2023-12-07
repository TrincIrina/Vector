#include<iostream>
#include"Vector.h"
using namespace std;

void Test(Vector& vector) {
	for (int i = 0; i < vector.get_size(); i++)
		vector.elem(i) = rand() % 50 - 25;
	cout << " vector = "; vector.print(); cout << endl;
	++vector;
	cout << " ++vector = " << vector.to_string() << endl;
	vector--;
	cout << " --vector = " << vector.to_string() << endl;
	int num = rand() % 10 + 1;	
	cout << " vector * " << num << " = " << (vector * num).to_string() << endl;
	cout << " -vector = " << vector.invert().to_string() << endl;
	cout << " |vector| = " << vector.module() << endl << endl;
}

void Test_operations(Vector& v1, Vector& v2) {
	cout << "v1 = " << v1.to_string() << "; v2 = " << v2.to_string() << endl;
	if (v1.line_vector(v2)) {				
		cout << "v1 + v2 = " << (v1 + v2).to_string() << endl;		
		cout << "v1 - v2 = " << (v1 - v2).to_string() << endl;		
		cout << "v1 * v2 = " << (v1 * v2).to_string() << endl;		
		cout << "v1 / v2 = " << (v1 / v2).to_string() << endl;
		if (v1 == v2) {
			cout << "Векторы равны" << endl;
		}
		else {
			cout << "Векторы не равны" << endl;
		}		
		if (v1 > v2) {
			cout << "|v1| > |v2|" << endl << endl;
		}
		else if (v1 < v2) {
			cout << "|v1| < |v2|" << endl << endl;
		}
		else if (v1 <= v2) {
			cout << "|v1| <= |v2|" << endl << endl;
		}
		else if (v1 >= v2) {
			cout << "|v1| >= |v2|" << endl << endl;
		}
	}
	else
		cout << "Векторы находятся в разных системах координат. Операции над ними невозможны." << endl;
}

void main() {
	setlocale(0, "");
	srand(time(NULL));

	Vector a(2);		
	Test(a);
		
	Vector b(2);	
	Test(b);
	Test_operations(a, b);

	Vector c(4);	
	Test(c);
	Test_operations(b, c);
}
