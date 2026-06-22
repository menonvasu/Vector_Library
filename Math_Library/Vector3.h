#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>

template <typename T>
struct Vector3 {
	T x{ };
	T y{ };
	T z{ };

	Vector3& operator+=(const Vector3& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vector3& operator*= (T scalarValue) {
		x *= scalarValue;
		y *= scalarValue;
		z *= scalarValue;
		return *this;
	}

	Vector3& operator /= (T scalarValue) {
		if (scalarValue == 0) return *this;

		x /= scalarValue;
		y /= scalarValue;
		z /= scalarValue;
		return *this;
	}

	T length() const {
		return std::sqrt(x * x + y * y + z * z);
	}

	Vector3<T> normalized() const {
		if (x == 0 && y == 0 && z == 0) {
			return Vector3{ 0, 0, 0 };
		}
		return *this / length();
	}
};

template <typename T>
Vector3<T> operator+(Vector3<T> lhs, const Vector3<T>& rhs) {
	return lhs += rhs;
}

template <typename T>
Vector3<T> operator*(Vector3<T> current, T scalar) {
	return current *= scalar;
}

template <typename T>
Vector3<T> operator*(T scalar, Vector3<T> current) {
	return current *= scalar;
}

template <typename T>
Vector3<T> operator/(Vector3<T> current, T scalar) {
	return  current /= scalar;
}

template <typename T>
T dot(const Vector3<T>& lhs, const Vector3<T>& rhs) {
	return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z);
}

template <typename T>
Vector3<T> cross(const Vector3<T>& lhs, const Vector3<T>& rhs) {
	Vector3<T> result{};

	result.x = (lhs.y * rhs.z) - (lhs.z * rhs.y);
	result.y = (lhs.z * rhs.x) - (lhs.x * rhs.z);
	result.z = (lhs.x * rhs.y) - (lhs.y * rhs.x);
	return result;
}

#endif 
