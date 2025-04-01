#include <cmath>
#include <array>

template<typename T>
class Vector2
{
public:
	Vector2(T x, T y) : data{ {x, y} } {}; // Ennek az osztálynak 1 konstruktora van 2 ugyanolyan típusú paraméterrel
	Vector2& operator+=(Vector2<T> const& v) // Következnek a 4. pdf-ben leírt, osztályon belül definiált mûveletek
	{
		data[0] += v[0]; data[1] += v[1];
		return *this;
	}
	Vector2& operator-=(Vector2<T> const& v)
	{
		data[0] -= v[0]; data[1] -= v[1];
		return *this;
	}
	Vector2& operator*=(T const& u)
	{
		data[0] *= u; data[1] *= u;
		return *this;
	}
	Vector2& operator/=(T const& u)
	{
		data[0] /= u; data[1] /= u;
		return *this;
	}
	T const& operator[](int i) const { return data[i]; } // A koordinátákat a példányosítás után kézzel nem lehet
	                                                     // megváltoztatni, csak olvasni lehet
private:
	std::array<T, 2> data; // Ebben a privát array-ben tárolom a vektorok koordinátáit
};

template<typename T>// Következnek a 4. pdf-ben leírt, osztályon kívül definiált mûveletek
Vector2<T> operator+(Vector2<T> const& v1, Vector2<T> const& v2)
{
	return Vector2<T>(v1[0] + v2[0], v1[1] + v2[1]);
}
template<typename T>
Vector2<T> operator-(Vector2<T> const& v1, Vector2<T> const& v2)
{
	return Vector2<T>(v1[0] - v2[0], v1[1] - v2[1]);
}

template<typename T>
Vector2<T> operator*(Vector2<T> const& v1, T const& u)
{
	return Vector2<T>(v1[0] * u, v1[1] * u);
}

template<typename T>
Vector2<T> operator*(T const& u, Vector2<T> const& v1)
{
	return Vector2<T>(v1[0] * u, v1[1] * u);
}

template<typename T>
Vector2<T> operator/(Vector2<T> const& v1, T const& u)
{
	return Vector2<T>(v1[0] / u, v1[1] / u);
}

template<typename T>
Vector2<T> normalize(Vector2<T> const& v1)
{
	T hossz = length(v1);
	if (hossz != 0) 
	{
		return Vector2<T>(v1[0] / hossz, v1[1] / hossz);
	}
	else // ha a hossz 0, akkor sem oszt 0-val
	{
		return Vector2<T>(0, 0);
	}
}

template<typename T>
T dot(Vector2<T> const& v1, Vector2<T> const& v2)
{
	return v1[0] * v2[0] + v1[1] * v2[1];
}

template<typename T>
T area(Vector2<T> const& v1, Vector2<T> const& v2) // Vektorok által meghatározott paralelogramma elõjel nélküli 
												   // területe, mint a keresztszorzásnál
{
	return std::abs(v1[0] * v2[1] - v1[1] * v2[0]);
}

template<typename T>
T length(Vector2<T> const& v1)
{
	return std::sqrt(v1[0] * v1[0] + v1[1] * v1[1]);
}

template<typename T>
T sqlength(Vector2<T> const& v1)
{
	return v1[0] * v1[0] + v1[1] * v1[1];
}

template<typename T>
std::ostream& operator<<(std::ostream& o, Vector2<T> const& v1)
{
	o << v1[0] << " " << v1[1];
	return o;
}

template<typename T>
std::istream& operator>>(std::istream& i, Vector2<T> const& v1)
{
	i >> v1[0];
	i >> v1[1];
	return i;
}