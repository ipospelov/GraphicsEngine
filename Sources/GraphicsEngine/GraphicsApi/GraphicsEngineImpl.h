#pragma once
#include "GraphicsEngine/Rect.h"


class GraphicsEngineImpl
{
public:
	virtual void Init() = 0;
	virtual void Deinit() = 0;

	virtual void Render() = 0;
	virtual bool IsRunning() = 0;

	virtual void SetViewport(Rect rect) = 0;
	virtual void SetResolution(int width, int height) = 0;
};
