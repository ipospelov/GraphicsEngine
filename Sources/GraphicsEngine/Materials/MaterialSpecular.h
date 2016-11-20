#pragma once
#include "GraphicsEngine/Materials/Material.h"


// Рассчитывает только компоненту diffuse от всех источников света
class MaterialSpecular : public Material
{
public:
    MaterialSpecular();

    virtual void Init(Object * pObject);
    virtual void Deinit();

    virtual void SetMaterial();
};
