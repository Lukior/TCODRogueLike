#pragma once

#include "Global.h"

namespace RogueEngine
{
	class TimeKernel
	{
	public:
		static void Update();
		static float DeltaTime();
		static float Time();

	private:
		TimeKernel();
		static TimeKernel& Get();

		float m_DeltaTime;
		float m_Time;
	};
}