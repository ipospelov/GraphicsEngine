#pragma once
#include "GraphicsEngine/Materials/Material.h"

class MaterialSphere : public Material
{
public:
    MaterialSphere();

    virtual void Init(Object * pObject);
    virtual void Deinit();

    virtual void SetMaterial();
};
