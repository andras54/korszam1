#include <iostream>
#include "vector2.h"

int main()
{
	Vector2<int> vector1i(2, 3);
	Vector2<int> vector2i(4, 5);
	Vector2<double> vector1d(2, 3);
	Vector2<double> vector2d(4, 5);


	Vector2<int> vector3i = vector1i + vector2i;
	std::cout << vector3i << std::endl;
	return 0;
}