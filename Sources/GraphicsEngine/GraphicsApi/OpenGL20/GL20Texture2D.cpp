#include "GL20Texture2D.h"
#include "GraphicsEngine/Application.h"
//#include "GraphicsEngine/GraphicsApi/OpenGL20/GL20GraphicsEngineContext.h"


GL20Texture2D::GL20Texture2D(const char * filepath)
{
	bitmap = FreeImage_Load( FreeImage_GetFileType(filepath, 0), filepath);
	pImage = FreeImage_ConvertTo32Bits(bitmap);
	FreeImage_FlipVertical(pImage); // OpenGL flips texture upside-down, so we should flip too.
	nWidth = FreeImage_GetWidth(pImage);
	nHeight = FreeImage_GetHeight(pImage);
		
	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);
	{
		void * pPixels = (void*)FreeImage_GetBits(pImage);		
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, pPixels);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	glBindTexture(GL_TEXTURE_2D, 0);

	FreeImage_Unload(pImage);

	m_useAniso = false;

	SetFilterMode(TEXTURE_FILTER_MODE_TRILINEAR);

	// TODO: Release resources at destructor
}

GL20Texture2D::~GL20Texture2D()
{
	glDeleteBuffers(1, &m_texture);
}

void GL20Texture2D::SetFilterMode(TextureFilterMode filterMode)
{
	// http://www.learnopengles.com/android-lesson-six-an-introduction-to-texture-filtering/
	// https://www.opengl.org/wiki/Sampler_Object
	// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/
	// http://opengl-master.ru/view_post.php?id=78
	// http://www.araku.ac.ir/~d_comp_engineering/88892/1323108/OpenGL%20Game%20Development.pdf

	if (filterMode == TEXTURE_FILTER_MODE_POINT)
	{
		m_minFilterMode = GL_NEAREST;
		m_magFilterMode = GL_NEAREST;
		m_useAniso = false;
	}
	else if (filterMode == TEXTURE_FILTER_MODE_BILINEAR)
	{
		// TODO: Task05
		//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,m_magFilterMode);
		m_minFilterMode = GL_LINEAR;
		m_magFilterMode = GL_LINEAR;
		m_useAniso = false;
	}
	else if (filterMode == TEXTURE_FILTER_MODE_TRILINEAR)
	{
		// TODO: Task05
		m_minFilterMode = GL_LINEAR_MIPMAP_LINEAR;
		m_magFilterMode = GL_LINEAR;
		m_useAniso = false;
	}
	else if (filterMode == TEXTURE_FILTER_MODE_ANISOTROPIC)
	{
		// TODO: Task05
/*		GLint g_nMaxAnisotropy;
		glGetIntegerv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &g_nMaxAnisotropy);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAX_ANISOTROPY_EXT,g_nMaxAnisotropy - 0.1);*/
		m_minFilterMode = GL_LINEAR_MIPMAP_LINEAR;
		m_magFilterMode = GL_LINEAR;
/*		gluBuild2DMipmaps(GL_TEXTURE_2D,3,nHeight,nWidth,
						  GL_RGB,GL_UNSIGNED_BYTE,pImage);*/
		m_useAniso = true;
	}
}

void GL20Texture2D::SetTexture(int textureRegister) const
{
	glActiveTexture(GL_TEXTURE0 + textureRegister);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_minFilterMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_magFilterMode);
	if(m_useAniso){
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 3);
	} else{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 0);
	}
}
