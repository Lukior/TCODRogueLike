#pragma once

#include "Global.h"
#include "include\Math.h"

namespace RogueEngine
{
	namespace Math
	{
		template <typename T>
		class Vector2
		{
		public:
			Vector2(T x, T y)
				: x(x), y(y)
			{}
			Vector2()
				: x(0), y(0)
			{}

			T x;
			T y;

			Vector2<T>& operator=(const Vector2<T>& rhs)
			{
				x = rhs.x;
				y = rhs.y;

				return *this;
			}
		};

		template <typename T>
		ostream& operator<<(ostream& lhs, const Vector2<T>& rhs)
		{
			lhs << "x = " << rhs.x << ", y = " << rhs.y;
			return lhs;
		}

		template <typename T>
		Vector2<T> operator*(const Vector2<T>& lhs, float rhs)
		{
			Vector2<T> ret;

			ret.x = lhs.x * rhs;
			ret.y = lhs.y * rhs;

			return ret;
		}

		template <typename T>
		Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs)
		{
			Vector2<T> ret;

			ret.x = lhs.x + rhs.x;
			ret.y = lhs.y + rhs.y;

			return ret;
		}
	}
}