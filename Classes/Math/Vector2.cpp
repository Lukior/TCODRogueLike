#include "Global.h"

namespace RogueEngine
{
	namespace Math
	{
		Vector2::Vector2(int x, int y)
			: m_X(x), m_Y(y)
		{}

		Vector2::Vector2()
			: Vector2(0, 0)
		{}

		int& Vector2::X()
		{
			return m_X;
		}

		int& Vector2::Y()
		{
			return m_Y;
		}
	}
}