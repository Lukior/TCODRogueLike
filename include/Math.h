#pragma once

#include "Global.h"

#pragma warning(disable : 4244) // float to int conversion warning

namespace RogueEngine
{
	namespace Math
	{
		template <typename T>
		class Vector2;

		template <typename T>
		T Clamp(T min, T max, T value)
		{
			T ret = MIN(max, value);
			ret = MAX(min, ret);
			return ret;
		}

		template <typename T>
		Vector2<T> Clamp(Vector2<T> min, Vector2<T> max, Vector2<T> value)
		{
			Vector<T> ret = value;
			ret.x = MAX(min.x, ret.x);
			ret.y = MAX(min.y, ret.y);
			ret.x = MIN(max, ret.x);
			ret.y = MIN(max, ret.y);
			return ret;
		}
	}
}

#include "Classes\Math\Vector2.hpp"
