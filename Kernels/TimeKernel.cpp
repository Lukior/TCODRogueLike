#include "TimeKernel.h"

namespace RogueEngine
{
	TimeKernel::TimeKernel()
	{}

	TimeKernel& TimeKernel::Get()
	{
		static TimeKernel me;
		return me;
	}

	void TimeKernel::Update()
	{
		TimeKernel& me = Get();
		me.m_DeltaTime = TCODSystem::getLastFrameLength();
		me.m_Time = TCODSystem::getElapsedSeconds();
	}

	float TimeKernel::DeltaTime()
	{
		return Get().m_DeltaTime;
	}

	float TimeKernel::Time()
	{
		return Get().m_Time;
	}
}