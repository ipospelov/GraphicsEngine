#pragma once
#include "GraphicsEngine/Materials/Material.h"
#include "GraphicsEngine/Texture2D.h"


class MaterialSand : public Material
{
public:
	MaterialSand(TextureFilterMode filterMode);

	virtual void Init(Object * pObject);
	virtual void Deinit();
	
	virtual void SetMaterial();

private:
	Texture2D *	m_pTexture1;
	TextureFilterMode m_filterMode;
};
