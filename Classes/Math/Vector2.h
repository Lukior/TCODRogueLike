#pragma once

#include "Global.h"

namespace RogueEngine
{
	namespace Math
	{
		class Vector2
		{
		public:
			Vector2(int x, int y);
			Vector2();

			int& X();
			int& Y();

		private:
			int m_X;
			int m_Y;
		};
	}
}