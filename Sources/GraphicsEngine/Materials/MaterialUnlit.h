#pragma once
#include "GraphicsEngine/Materials/Material.h"


// Unlit значит "неосвещаемый",
// т.е. этот материал не освещается источниками света
class MaterialUnlit : public Material
{
public:
	MaterialUnlit();

	virtual void Init(Object * pObject);
	virtual void Deinit();
	
	virtual void SetMaterial();
};
