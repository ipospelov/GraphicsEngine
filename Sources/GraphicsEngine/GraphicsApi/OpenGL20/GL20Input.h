#pragma once

#include "GraphicsEngine/PlatformApi/Platform.h"
#ifdef CAN_USE_OPEN_GL


class GL20Input
{
public:
    static void Init();

    static void Clear();

    static void SetLetterKeyDown	(unsigned char key);
    static void SetLetterKeyUp		(unsigned char key);
    static void SetSpecialKeyDown	(unsigned char key);
    static void SetSpecialKeyUp		(unsigned char key);

    static void SetMouseButtonsEvent(int button, int state, int x, int y);
    static void SetMouseMotionEvent(int x, int y);

private:

    // Translates a key in OS to a key in Graphics Engine
    static unsigned int m_translationTable1[];
    static unsigned int m_translationTable2[];

    static const unsigned int KEY_A_UPPER_CASE; // a key 'A' in OS
    static const unsigned int KEY_Z_UPPER_CASE; // a key 'Z' in OS
    static const unsigned int KEY_A_LOWER_CASE; // a key 'a' in OS
    static const unsigned int KEY_Z_LOWER_CASE; // a key 'z' in OS
};

#endif
