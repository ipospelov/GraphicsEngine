#pragma once
#include "GraphicsEngine/GraphicsApi/Texture2DImpl.h"



class Texture2D
{
public:
	Texture2D(const char * filepath);
	~Texture2D();

	void SetFilterMode(TextureFilterMode filterMode);
	const Texture2DImpl * GetImplPointer() const;

private:
	Texture2DImpl * pImpl;
};
