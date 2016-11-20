#include <GraphicsEngine/Time.h>
#include "MaterialSphere.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/MathUtils.h"
#include "GraphicsEngine/SceneUtils.h"


MaterialSphere::MaterialSphere()
{
    m_vsFileName = "ShaderSphere";
    m_psFileName = "ShaderSphere";
}
void MaterialSphere::Init(Object * pObject)
{
    Material::Init(pObject);

}

void MaterialSphere::Deinit()
{
    Material::Deinit();
}

void MaterialSphere::SetMaterial()
{
    // Заполняем матрицы World, View, Proj
    const Matrix4x4 & matWorld	= SceneUtils::GetMatrixWorld(m_pObject);
    const Matrix4x4 & matView	= SceneUtils::GetMatrixView();
    const Matrix4x4 & matProj	= SceneUtils::GetMatrixProj();

    const Matrix4x4 matWorldViewProjT = MathUtils::GetMatrixWorldViewProjT(matWorld, matView, matProj);

    double t = (sin(Time::GetTime()) + 1) / 2;

    SetMaterialBegin();
    {
        SetVertexShaderBegin();
        SetVertexShaderMatrix4x4("matrixWorldViewProjT", matWorldViewProjT);
        SetVertexShaderVector4("vect", Vector4(t, 1, 1, 1));
        SetVertexShaderEnd();

        SetPixelShaderBegin();
        SetPixelShaderEnd();
    }
    SetMaterialEnd();
}
