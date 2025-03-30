#include <cmath>

template<typename T>
class Vector2
{
public:
	Vector2(T x, T y) : vx(x), vy(y)
	{};
	Vector2& operator+=(Vector2<T> const& v)
	{
		vx += v.vx; vy += v.vy;
		return *this;
	}
	Vector2& operator-=(Vector2<T> const& v)
	{
		vx -= v.vx; vy -= v.vy;
		return *this;
	}
	template<typename U>
	Vector2& operator*=(U const& u)
	{
		vx *= u; vy *= u;
		return *this;
	}
	template<typename U>
	Vector2& operator/=(U const& u)
	{
		vx /= u; vy /= u;
		return *this;
	}
	T vx, vy;
};

template<typename T>
Vector2<T> operator+(Vector2<T> const& v1, Vector2<T> const& v2)
{
	return Vector2<T>(v1.vx + v2.vx, v1.vy + v2.vy);
}
template<typename T>
Vector2<T> operator-(Vector2<T> const& v1, Vector2<T> const& v2)
{
	return Vector2<T>(v1.vx - v2.vx, v1.vy - v2.vy);
}

template<typename T>
Vector2<T> operator*(Vector2<T> const& v1, T const& u)
{
	return Vector2<T>(v1.vx * u, v1.vy * u);
}

template<typename T>
Vector2<T> operator*(T const& u, Vector2<T> const& v1)
{
	return Vector2<T>(v1.vx * u, v1.vy * u);
}

template<typename T>
Vector2<T> operator/(Vector2<T> const& v1, T const& u)
{
	return Vector2<T>(v1.vx / u, v1.vy / u);
}

template<typename T>
Vector2<T> normalize(Vector2<T> const& v1)
{
	T hossz = length(v1);
	if (hossz != 0)
	{
		return Vector2<T>(v1.vx / hossz, v1.vy / hossz);
	}
	else
	{
		return Vector2<T>(0, 0);
	}
}

template<typename T>
T dot(Vector2<T> const& v1, Vector2<T> const& v2)
{
	return v1.vx * v2.vx + v1.vy * v2.vy;
}

template<typename T>
T area(Vector2<T> const& v1, Vector2<T> const& v2)
{
	return v1.vx * v2.vy - v1.vy * v2.vx;
}

template<typename T>
T length(Vector2<T> const& v1)
{
	return std::sqrt(v1.vx * v1.vx + v1.vy * v1.vy);
}

template<typename T>
T sqlength(Vector2<T> const& v1)
{
	return v1.vx * v1.vx + v1.vy * v1.vy;
}

template<typename T>
std::ostream& operator<<(std::ostream& o, Vector2<T> const& v1)
{
	o << v1.vx << " " << v1.vy;
	return o;
}

template<typename T>
std::istream& operator>>(std::istream& i, Vector2<T> const& v1)
{
	i >> v1.vx;
	i >> v1.vy;
	return i;
}