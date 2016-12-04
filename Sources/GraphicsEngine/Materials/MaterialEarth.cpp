//
// Created by posiv on 04.12.16.
//

#include "MaterialEarth.h"
#include "MaterialDiffuse.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/Light.h"
#include "GraphicsEngine/MathUtils.h"
#include "GraphicsEngine/SceneUtils.h"


MaterialEarth::MaterialEarth()
{
    m_vsFileName = "ShaderEarth";
    m_psFileName = "ShaderEarth";

    m_pTexture1 = NULL;
}

void MaterialEarth::Init(Object * pObject)
{
    Material::Init(pObject);

    m_pTexture1 = new Texture2D("Earth_Albedo.jpg");

}

void MaterialEarth::Deinit()
{
    Material::Deinit();
}

void MaterialEarth::SetMaterial()
{
    // Заполняем матрицы World, View, Proj
    const Matrix4x4 & matWorld	= SceneUtils::GetMatrixWorld(m_pObject);
    const Matrix4x4 & matView	= SceneUtils::GetMatrixView();
    const Matrix4x4 & matProj	= SceneUtils::GetMatrixProj();

    const Matrix4x4 matWorldViewProjT	= MathUtils::GetMatrixWorldViewProjT(matWorld, matView, matProj);

    // Получили список всех источников света в сцене
    std::list<const Light *> lights = SceneUtils::GetLights();
    const size_t count = lights.size() < 3 ? lights.size() : 3;

    Matrix4x4 viewModel = matView.Inverse();

    SetMaterialBegin();
    {
        const Matrix4x4 & matWorld	= SceneUtils::GetMatrixWorld(m_pObject);
        const Matrix4x4 & matView	= SceneUtils::GetMatrixView();
        const Matrix4x4 & matProj	= SceneUtils::GetMatrixProj();

        const Matrix4x4 matWorldViewProjT = MathUtils::GetMatrixWorldViewProjT(matWorld, matView, matProj);

        SetMaterialBegin();
        {
            SetVertexShaderBegin();
            SetVertexShaderMatrix4x4("matrixWorldViewProjT", matWorldViewProjT);
            SetVertexShaderVector4("constColor", Vector4(1, 1, 1, 1));
            SetVertexShaderEnd();

            SetPixelShaderBegin();
            SetPixelShaderTexture2d("texture1", m_pTexture1);
            SetPixelShaderEnd();
        }
        SetMaterialEnd();
    }
    SetMaterialEnd();
}

