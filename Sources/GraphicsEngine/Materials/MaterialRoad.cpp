#include "MaterialRoad.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/MathUtils.h"
#include "GraphicsEngine/SceneUtils.h"


MaterialRoad::MaterialRoad(TextureFilterMode filterMode)
{
    m_vsFileName = "ShaderRoad";
    m_psFileName = "ShaderRoad";

    m_pTexture1 = NULL;
    m_filterMode = filterMode;
}

void MaterialRoad::Init(Object * pObject)
{
    Material::Init(pObject);

    m_pTexture1 = new Texture2D("road_1.jpg");
    m_pTexture2 = new Texture2D("road_2.jpg");
    m_pTexture3 = new Texture2D("road_3.jpg");
    m_pTexture1->SetFilterMode(m_filterMode);
    m_pTexture2->SetFilterMode(m_filterMode);
    m_pTexture3->SetFilterMode(m_filterMode);
}

void MaterialRoad::Deinit()
{
    delete m_pTexture1;
    m_pTexture1 = NULL;

    Material::Deinit();
}

void MaterialRoad::SetMaterial()
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
        SetPixelShaderTexture2d("texture2", m_pTexture2);
        SetPixelShaderTexture2d("texture3", m_pTexture3);
        SetPixelShaderEnd();
    }
    SetMaterialEnd();
}
