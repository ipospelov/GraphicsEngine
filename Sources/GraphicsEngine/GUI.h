#pragma once
#include "GraphicsEngine/GraphicsApi/GUIImpl.h"
#include <string>
#include <vector>


struct GUIElement
{
public:
	int x, y, w, h;
	std::string text;
};


class GUI
{
public:
	static void Label(int x, int y, int w, int h, const std::string & text);
	static void Label(int x, int y, int w, int h, double number);

	static void Update();

private:
    static std::vector<GUIElement> elements;
	static GUIImpl * pImpl;
};
