#include "InputKernel.h"


namespace RogueEngine
{
	InputKernel::InputKernel()
	{}

	InputKernel& InputKernel::Get()
	{
		static InputKernel me;
		return me;
	}

	void InputKernel::Update()
	{
		InputKernel& me = Get();

		TCOD_key_t key;
		TCOD_mouse_t mouse;
		TCOD_event_t event;
		while (event = TCODSystem::checkForEvent(TCOD_EVENT_ANY, &key, &mouse))
		{
			switch (event)
			{
			case TCOD_EVENT_KEY_PRESS:
				me.m_KeyboardStates[key.vk] = true;
				break;
			case TCOD_EVENT_KEY_RELEASE:
				me.m_KeyboardStates[key.vk] = false;
				break;
			}

			me.m_MouseStates[MouseInput::LEFT_BUTTON] = mouse.lbutton != 0;
			me.m_MouseStates[MouseInput::RIGHT_BUTTON] = mouse.rbutton != 0;
			me.m_MouseStates[MouseInput::MIDDLE_BUTTON] = mouse.mbutton != 0;

			me.m_MouseStates[MouseInput::WHEEL_UP] = mouse.wheel_up != 0;
			me.m_MouseStates[MouseInput::WHEEL_DOWN] = mouse.wheel_down != 0;

			me.m_MousePosition.x = mouse.x;
			me.m_MousePosition.y = mouse.y;

			me.m_MouseCellPosition.x = mouse.cx;
			me.m_MouseCellPosition.y = mouse.cy;

			me.m_MouseMovement.x = mouse.dx;
			me.m_MouseMovement.y = mouse.dy;

			me.m_MouseCellMovement.x = mouse.dcx;
			me.m_MouseCellMovement.y = mouse.dcy;
		}
	}

	bool InputKernel::IsPressed(TCOD_keycode_t key)
	{
		return Get().m_KeyboardStates[key];
	}

	bool InputKernel::IsPressed(MouseInput button)
	{
		return Get().m_MouseStates[button];
	}

	map<TCOD_keycode_t, bool>& InputKernel::Keys()
	{
		return Get().m_KeyboardStates;
	}

	map<MouseInput, bool>& InputKernel::MouseButtons()
	{
		return Get().m_MouseStates;
	}

	const Math::Vector2<float>& InputKernel::MousePosition()
	{
		return Get().m_MousePosition;
	}

	const Math::Vector2<float>& InputKernel::MouseCellPosition()
	{
		return Get().m_MouseCellPosition;
	}
	
	const Math::Vector2<float>& InputKernel::MouseMovement()
	{
		return Get().m_MouseMovement;
	}
	
	const Math::Vector2<float>& InputKernel::MouseCellMovement()
	{
		return Get().m_MouseCellMovement;
	}
}