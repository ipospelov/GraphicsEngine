#pragma once
#include "GraphicsEngine/Materials/Material.h"


// Рассчитывает только компоненту diffuse от всех источников света
class MaterialEarth : public Material
{
public:
    MaterialEarth();

    virtual void Init(Object * pObject);
    virtual void Deinit();

    virtual void SetMaterial();
private:
    Texture2D *	m_pTexture1;
    Texture2D *	m_pTexture2;
};
