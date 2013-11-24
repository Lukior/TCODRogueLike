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
		};
	}
}