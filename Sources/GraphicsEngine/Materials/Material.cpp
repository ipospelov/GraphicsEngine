#include "Material.h"
#include "GraphicsEngine/GraphicsEngineFabric.h"


void Material::Init(Object * pObject)
{
	m_pObject = pObject;

	m_pImpl = GraphicsEngineFabric::CreateMaterial(m_vsFileName.c_str(), m_psFileName.c_str());
}

void Material::Deinit()
{
	delete m_pImpl;
	m_pImpl = NULL;
	
	m_pObject = NULL;	
}

bool Material::IsInited()
{
	return m_pImpl->IsInited();
}


void Material::SetMaterialBegin()
{
	m_pImpl->SetMaterialBegin();
}

void Material::SetVertexShaderBegin()
{
	m_pImpl->SetVertexShaderBegin();
}

void Material::SetVertexShaderMatrix4x4(const char * propertyName, const Matrix4x4 & matrix)
{
	m_pImpl->SetVertexShaderMatrix4x4(propertyName, matrix);
}

void Material::SetVertexShaderVector4(const char * propertyName, const Vector4 & vector)
{
	m_pImpl->SetVertexShaderVector4(propertyName, vector);
}

void Material::SetVertexShaderEnd()
{
	m_pImpl->SetVertexShaderEnd();
}


void Material::SetPixelShaderBegin()
{
	m_pImpl->SetPixelShaderBegin();
}

void Material::SetPixelShaderMatrix4x4(const char * propertyName, const Matrix4x4 & matrix)
{
	m_pImpl->SetPixelShaderMatrix4x4(propertyName, matrix);
}

void Material::SetPixelShaderVector4(const char * propertyName, const Vector4 & vector)
{
	m_pImpl->SetPixelShaderVector4(propertyName, vector);
}

void Material::SetPixelShaderTexture2d(const char * propertyName, const Texture2D * pTexture)
{
	m_pImpl->SetPixelShaderTexture2d(propertyName, pTexture);
}

void Material::SetPixelShaderEnd()
{
	m_pImpl->SetPixelShaderEnd();
}


void Material::SetMaterialEnd()
{
	m_pImpl->SetMaterialEnd();
}

void Material::ResetMaterial()
{
	m_pImpl->ResetMaterial();
}
