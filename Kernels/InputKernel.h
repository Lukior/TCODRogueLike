#pragma once

#include "Global.h"
#include "include\Math.h"

namespace RogueEngine
{
	enum InputState
	{
		RELEASED,
		PRESSED
	};

	enum MouseInput
	{
		LEFT_BUTTON,
		RIGHT_BUTTON,
		MIDDLE_BUTTON,
		WHEEL_UP,
		WHEEL_DOWN
	};

	class InputKernel
	{
	public:
		static void Update();

		static bool							IsPressed(TCOD_keycode_t key);
		static bool							IsPressed(MouseInput button);

		static map<TCOD_keycode_t, bool>&	Keys();
		static map<MouseInput, bool>&		MouseButtons();

		static const Math::Vector2<float>&	MousePosition();
		static const Math::Vector2<float>&	MouseCellPosition();
		static const Math::Vector2<float>&	MouseMovement();
		static const Math::Vector2<float>&	MouseCellMovement();
		static const Math::Vector2<float>&	KeyboardAxis();
	private:
		InputKernel();
		static InputKernel&					Get();

		Math::Vector2<float>				m_MousePosition;
		Math::Vector2<float>				m_MouseCellPosition;
		Math::Vector2<float>				m_MouseMovement;
		Math::Vector2<float>				m_MouseCellMovement;
		Math::Vector2<float>				m_KeyboardAxis;

		map<TCOD_keycode_t, bool>			m_KeyboardStates;
		map<MouseInput, bool>				m_MouseStates;
	};
}