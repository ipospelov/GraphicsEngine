#include "GL20Input.h"
#include "GraphicsEngine/GraphicsApi/OpenGL20/GL20.h"
#include "GraphicsEngine/Internal/InternalInput.h"

#ifdef CAN_USE_OPEN_GL


unsigned int GL20Input::m_translationTable1[256];
unsigned int GL20Input::m_translationTable2[256];
const unsigned int GL20Input::KEY_A_UPPER_CASE = 'A';
const unsigned int GL20Input::KEY_Z_UPPER_CASE = 'Z';
const unsigned int GL20Input::KEY_A_LOWER_CASE = 'a';
const unsigned int GL20Input::KEY_Z_LOWER_CASE = 'z';

void GL20Input::Init()
{
	for (int i = 0; i < 256; ++i)
	{
		m_translationTable1[i] = KEY_CODE_NONE;
		m_translationTable2[i] = KEY_CODE_NONE;
	}

	int n = KEY_Z_UPPER_CASE - KEY_A_UPPER_CASE + 1;
	for (int i = 0; i < n; ++i)
	{
		m_translationTable1[KEY_A_UPPER_CASE + i] = KEY_CODE_A + i;
		m_translationTable1[KEY_A_LOWER_CASE + i] = KEY_CODE_A + i;
	}

	m_translationTable2[GLUT_KEY_LEFT]	= KEY_CODE_LEFT_ARROW;
	m_translationTable2[GLUT_KEY_UP]	= KEY_CODE_UP_ARROW;
	m_translationTable2[GLUT_KEY_RIGHT]	= KEY_CODE_RIGHT_ARROW;
	m_translationTable2[GLUT_KEY_DOWN]	= KEY_CODE_DOWN_ARROW;

	m_translationTable2[112] = KEY_CODE_LEFT_SHIFT;
	m_translationTable2[113] = KEY_CODE_RIGHT_SHIFT;
}

void GL20Input::Clear()
{
	InternalInput::Clear();
}

void GL20Input::SetLetterKeyDown(unsigned char key)
{
	InternalInput::SetKeyDown( m_translationTable1[key] );
}

void GL20Input::SetLetterKeyUp(unsigned char key)
{
	InternalInput::SetKeyUp( m_translationTable1[key] );
}

void GL20Input::SetSpecialKeyDown(unsigned char key)
{
	//int mod = glutGetModifiers();
	//if (mod == GLUT_ACTIVE_SHIFT)
	//{
	//	int i = 0;
	//}

	InternalInput::SetKeyDown( m_translationTable2[key] );
}

void GL20Input::SetSpecialKeyUp(unsigned char key)
{
	InternalInput::SetKeyUp( m_translationTable2[key] );
}

void GL20Input::SetMouseButtonsEvent(int button, int state, int x, int y)
{
	if (state != GLUT_DOWN && 
		state != GLUT_UP) return;

	if (button != GLUT_LEFT_BUTTON && 
		button != GLUT_RIGHT_BUTTON && 
		button != GLUT_MIDDLE_BUTTON) return;
	
	bool pressed = (state == GLUT_DOWN);
	int buttonNum = (button == GLUT_LEFT_BUTTON) ? 0 : (button == GLUT_RIGHT_BUTTON) ? 1 : 2;
	
	InternalInput::SetMouseButton(buttonNum, pressed);	
}

void GL20Input::SetMouseMotionEvent(int x, int y)
{
	InternalInput::SetMousePosition(x, y);
}

#endif