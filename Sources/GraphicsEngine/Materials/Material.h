#pragma once
#include "GraphicsEngine/GraphicsApi/MaterialImpl.h"
#include "GraphicsEngine/Texture2D.h"
#include <string>


class Object;
//#define NULL 0

class Material
{
public:

	virtual void	Init(Object * pObject);
	virtual void	Deinit();
	bool			IsInited();

	virtual void SetMaterial() = 0;

	void ResetMaterial();

protected:
	void SetMaterialBegin();

	void SetVertexShaderBegin();
	void SetVertexShaderMatrix4x4	(const char * propertyName, const Matrix4x4 & matrix);
	void SetVertexShaderVector4		(const char * propertyName, const Vector4 & vector);
	void SetVertexShaderEnd();

	void SetPixelShaderBegin();
	void SetPixelShaderMatrix4x4	(const char * propertyName, const Matrix4x4 & matrix);
	void SetPixelShaderVector4		(const char * propertyName, const Vector4 & vector);
	void SetPixelShaderTexture2d	(const char * propertyName, const Texture2D * pTexture);
	void SetPixelShaderEnd();
	
	void SetMaterialEnd();

	Object *		m_pObject;
	std::string		m_vsFileName;
	std::string		m_psFileName;

private:
	MaterialImpl *	m_pImpl;
};
