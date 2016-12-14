#pragma once

#include "GraphicsEngine/PlatformApi/Platform.h"
#ifdef CAN_USE_DIRECT_X

#include <Windows.h>
#include <Windowsx.h>


class WinInput
{
public:
	static void Init();
	static void Clear();
	static void Dispatch(MSG & msg);

private:

	static void DispatchKeyDown(int winKey, int winKeyValue, int virtualKey, int keyCode);
	static void DispatchKeyUp(int winKey, int winKeyValue, int virtualKey, int keyCode);

	static void DispatchMousePosition(int winEvent, LPARAM lParam);
	static void DispatchMouseButton(int winEvent, int winEventValue, int mouseButton, bool pressed);

	// Translates a key in Windows OS to a key in Graphics Engine
	static unsigned int m_translationTable[];

	static const WPARAM VK_A; // a key 'A' in Windows OS
	static const WPARAM VK_Z; // a key 'Z' in Windows OS
};

#endif