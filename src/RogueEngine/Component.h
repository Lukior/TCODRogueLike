#pragma once

namespace RogueEngine
{
	class Component
	{
	public:
		Component();
		virtual ~Component();

#pragma region FACULTATIVE OVERLOAD
		virtual void LateUpdate();
		virtual void Awake();
#pragma endregion
#pragma region MANDATORY OVERLOAD
		virtual void Init() = 0;
		virtual void Start() = 0;
		virtual void Update() = 0;
#pragma endregion
	};
}
