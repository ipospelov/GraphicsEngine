#include "WinInput.h"
#include "GraphicsEngine/Internal/InternalInput.h"

#ifdef CAN_USE_DIRECT_X


unsigned int WinInput::m_translationTable[512];
const WPARAM WinInput::VK_A = 'A';
const WPARAM WinInput::VK_Z = 'Z';

void WinInput::Init()
{
	for (int i = 0; i < 512; ++i)
	{
		m_translationTable[i] = KEY_CODE_NONE;
	}

	int n = VK_Z - VK_A + 1;
	for (int i = 0; i < n; ++i)
	{
		m_translationTable[VK_A + i] = KEY_CODE_A + i;
	}

	m_translationTable[VK_LEFT]		= KEY_CODE_LEFT_ARROW;
	m_translationTable[VK_UP]		= KEY_CODE_UP_ARROW;
	m_translationTable[VK_RIGHT]	= KEY_CODE_RIGHT_ARROW;
	m_translationTable[VK_DOWN]		= KEY_CODE_DOWN_ARROW;

	m_translationTable[VK_SHIFT]	= KEY_CODE_LEFT_SHIFT;
}

void WinInput::Clear()
{
	InternalInput::Clear();
}

void WinInput::Dispatch(MSG & msg)
{
	// If a key event
	if (msg.message >= WM_KEYFIRST && msg.message <= WM_KEYLAST)
	{
		// https://msdn.microsoft.com/en-us/library/windows/desktop/gg153546(v=vs.85).aspx

		UINT winEvent = msg.message;

		// A key in Windows OS
		WPARAM winKey = msg.wParam;

		// If a key is pressed down
		if (winEvent == WM_KEYDOWN)
		{
			// Process keys: Shift, Control, Alt
			if (winKey >= VK_SHIFT && winKey <= VK_MENU)
			{
				DispatchKeyDown(winKey, VK_SHIFT, VK_LSHIFT, KEY_CODE_LEFT_SHIFT);
				DispatchKeyDown(winKey, VK_SHIFT, VK_RSHIFT, KEY_CODE_RIGHT_SHIFT);
			}
			// Process other keys
			else
			{
				InternalInput::SetKeyDown( m_translationTable[winKey] );
			}
		}

		// If a key is pressed up
		if (winEvent == WM_KEYUP)
		{
			// Process keys: Shift, Control, Alt
			if (winKey == VK_SHIFT)
			{
				DispatchKeyUp(winKey, VK_SHIFT, VK_LSHIFT, KEY_CODE_LEFT_SHIFT);
				DispatchKeyUp(winKey, VK_SHIFT, VK_RSHIFT, KEY_CODE_RIGHT_SHIFT);
			}
			// Process other keys
			else
			{
				InternalInput::SetKeyUp( m_translationTable[winKey] );
			}
		}
	}

	// If a mouse event
	if (msg.message >= WM_MOUSEFIRST && msg.message <= WM_MOUSELAST)
	{
		// https://msdn.microsoft.com/en-us/library/windows/desktop/gg153550(v=vs.85).aspx
		// https://msdn.microsoft.com/en-us/library/windows/desktop/ms645533(v=vs.85).aspx

		UINT winEvent = msg.message;

		DispatchMousePosition(winEvent, msg.lParam);

		DispatchMouseButton(winEvent, WM_LBUTTONDOWN, 0, true);
		DispatchMouseButton(winEvent, WM_RBUTTONDOWN, 1, true);
		DispatchMouseButton(winEvent, WM_MBUTTONDOWN, 2, true);

		DispatchMouseButton(winEvent, WM_LBUTTONUP, 0, false);
		DispatchMouseButton(winEvent, WM_RBUTTONUP, 1, false);
		DispatchMouseButton(winEvent, WM_MBUTTONUP, 2, false);
	}
}

void WinInput::DispatchKeyDown(int winKey, int winKeyValue, int virtualKey, int keyCode)
{
	// https://msdn.microsoft.com/en-us/library/windows/desktop/ms646301(v=vs.85).aspx
	if ( (winKey == winKeyValue) && (GetKeyState(virtualKey) & 0x8000) )
	{
		InternalInput::SetKeyDown(keyCode);
	}
}

void WinInput::DispatchKeyUp(int winKey, int winKeyValue, int virtualKey, int keyCode)
{
	// https://msdn.microsoft.com/en-us/library/windows/desktop/ms646301(v=vs.85).aspx
	short pressed = GetKeyState(VK_LSHIFT) & 0x0001;
	if ( (winKey == winKeyValue) && (pressed == 0x0000 || pressed == 0x0001) )
	{
		InternalInput::SetKeyUp(keyCode);
	}
}

void WinInput::DispatchMousePosition(int winEvent, LPARAM lParam)
{
	if (winEvent == WM_MOUSEMOVE)
	{
		int x = GET_X_LPARAM(lParam);
		int y = GET_Y_LPARAM(lParam);

		InternalInput::SetMousePosition(x, y);
	}
}

void WinInput::DispatchMouseButton(int winEvent, int winEventValue, int mouseButton, bool pressed)
{
	if (winEvent == winEventValue)
	{
		InternalInput::SetMouseButton(mouseButton, pressed);
	}
}

#endif