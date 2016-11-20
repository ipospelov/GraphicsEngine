#pragma once
#include "GraphicsEngine/GraphicsApi/OpenGL20/GL20.h"
#include "GraphicsEngine/GraphicsApi/Texture2DImpl.h"


class GL20Texture2D : public Texture2DImpl
{
public:
	GL20Texture2D(const char * filepath);
	~GL20Texture2D();

	void SetFilterMode(TextureFilterMode filterMode);
	void SetTexture(int textureRegister) const;

private:
	GLuint		m_texture;
	FIBITMAP * bitmap;
	FIBITMAP * pImage;
	int nWidth;
	int nHeight;

	GLint m_minFilterMode;
	GLint m_magFilterMode;

	bool m_useAniso;
};
