#include <iostream>
#include <iomanip>
#include "vector2.h"

int main()
{
	Vector2<double> vector1(2., 3.);
	Vector2<double> vector2(4., 5.);
	double constant = 1.5;

	std::cout << "the test vectors are:" << std::endl;
	std::cout << "vector1: " << vector1 << std::endl;
	std::cout << "vector2: " << vector2 << std::endl;
	std::cout << std::endl;

	vector1 += vector2;

	std::cout << "sum of vectors using += operator:" << std::endl;
	std::cout << vector1 << std::endl;
	std::cout << std::endl;

	vector1 -= vector2;

	std::cout << "subtract vector2 from the sum of vectors using -= operator:" << std::endl;
	std::cout << vector1 << std::endl;
	std::cout << std::endl;

	vector1 *= constant;

	std::cout << "multiply vector1 by 1.5 using *= operator:" << std::endl;
	std::cout << vector1 << std::endl;
	std::cout << std::endl;

	vector1 /= constant;

	std::cout << "divide the previous vector by 1.5 using /= operator:" << std::endl; // magyar karaktereket nem könnyû kiíratni
	std::cout << vector1 << std::endl;
	std::cout << std::endl;

	std::cout << "sum of vectors using + operator:" << std::endl;
	std::cout << vector1 + vector2 << std::endl;
	std::cout << std::endl;

	std::cout << "subtract vector2 from vector1 using - operator:" << std::endl;
	std::cout << vector1 - vector2 << std::endl;
	std::cout << std::endl;

	std::cout << "multiply vector1 by 1.5 from right using * operator:" << std::endl;
	std::cout << vector1 * constant << std::endl;
	std::cout << std::endl;

	std::cout << "multiply vector1 by 1.5 from left using * operator:" << std::endl;
	std::cout << constant * vector1 << std::endl;
	std::cout << std::endl;

	std::cout << "divide vector1 by 1.5 using / operator:" << std::endl;
	std::cout << std::setprecision(15) << vector1/constant << std::endl;
	std::cout << std::endl;

	std::cout << "vector1's length:" << std::endl;
	std::cout << "program: " << std::setprecision(15) << length(vector1) << std::endl;
	std::cout << "analytical: " << "3.60555127546398929" << std::endl;
	std::cout << std::endl;

	std::cout << "square of vector1's length:" << std::endl;
	std::cout << "program: " << sqlength(vector1) << std::endl;
	std::cout << "analytical: " << "13" << std::endl;
	std::cout << std::endl;

	std::cout << "vector1 normalized:" << std::endl;
	std::cout << "program: " << std::setprecision(15) << normalize(vector1) << std::endl;
	std::cout << "analytical: " << "0.55470019622522912 0.83205029433784368" << std::endl;
	std::cout << std::endl;

	std::cout << "scalar product of vector1 and vector2:" << std::endl;
	std::cout << "program: " << dot(vector1,vector2) << std::endl;
	std::cout << "analytical: " << "23" << std::endl;
	std::cout << std::endl;

	std::cout << "the absolute area of the parallelogram defined by vector1 and vector2:" << std::endl;
	std::cout << "program: " << area(vector1, vector2) << std::endl;
	std::cout << "analytical: " << "2" << std::endl;
	std::cout << std::endl;

	return 0;
}