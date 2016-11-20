#pragma once
#include "GraphicsEngine/Materials/Material.h"

class MaterialCylinder : public Material
{
public:
    MaterialCylinder();

    virtual void Init(Object * pObject);
    virtual void Deinit();

    virtual void SetMaterial();
};