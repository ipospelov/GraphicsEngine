#include <GraphicsEngine/Time.h>
#include "MaterialCylinder.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/MathUtils.h"
#include "GraphicsEngine/SceneUtils.h"


MaterialCylinder::MaterialCylinder()
{
    m_vsFileName = "ShaderCylinder";
    m_psFileName = "ShaderCylinder";
}
void MaterialCylinder::Init(Object * pObject)
{
    Material::Init(pObject);

}

void MaterialCylinder::Deinit()
{
    Material::Deinit();
}

void MaterialCylinder::SetMaterial()
{
    // Заполняем матрицы World, View, Proj
    const Matrix4x4 & matWorld	= SceneUtils::GetMatrixWorld(m_pObject);
    const Matrix4x4 & matView	= SceneUtils::GetMatrixView();
    const Matrix4x4 & matProj	= SceneUtils::GetMatrixProj();

    const Matrix4x4 matWorldViewProjT = MathUtils::GetMatrixWorldViewProjT(matWorld, matView, matProj);

    double t = (sin(Time::GetTime())) / 2;

    SetMaterialBegin();
    {
        SetVertexShaderBegin();
        SetVertexShaderMatrix4x4("matrixWorldViewProjT", matWorldViewProjT * matWorldViewProjT.RotationY(150 * t));
        SetVertexShaderMatrix4x4("matrixWorldViewProjT2", matWorldViewProjT * matWorldViewProjT.RotationY(-150 * t));
        SetVertexShaderEnd();

        SetPixelShaderBegin();
        SetPixelShaderEnd();
    }
    SetMaterialEnd();
}


