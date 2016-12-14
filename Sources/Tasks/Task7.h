#pragma once

#include <GraphicsEngine/Meshes/MeshObjFile.h>
#include "GraphicsEngine/Application.h"
#include "GraphicsEngine/Camera.h"
#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/Light.h"
#include "GraphicsEngine/Materials/MaterialUnlit.h"
#include "GraphicsEngine/Meshes/MeshCube.h"
#include "GraphicsEngine/Meshes/MeshCylinder.h"
#include "GraphicsEngine/Meshes/MeshTriangle.h"
#include "GraphicsEngine/Meshes/MeshQuad.h"
#include "GraphicsEngine/Meshes/MeshSphere.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Scene.h"
#include "GraphicsEngine/Transform.h"
#include "Tasks/Task.h"
#include "Tasks/ObjectRotator.h"


class Task07: public Task
{
public:
    virtual ~Task07() { }

    virtual void Init()
    {
        Scene & scene = Application::Instance().GetScene();

        // Камера
        {
            Object * pCameraObj = new Object();
            pCameraObj->m_pTransform = new Transform( Vector3(0, 2, -15), Vector3(0.0f, 0.0f, 0.0f));
            Camera * pCamera = new Camera();
            pCamera->SetFovY(90);
            pCamera->SetNearPlane(0.01f);
            pCamera->SetFarPlane(100);
            pCameraObj->AddComponent( pCamera );

            scene.SetCamera( pCamera );
        }

        // Объект - Куб #1
        Object * pObj1 = NULL;
        {
            Object * pObject = new Object();
            pObject->m_pMesh		= new MeshObjFile("/home/posiv/НГУ/ПСВизуализации/GraphicsEngine/Data/MeshHouse.obj");
            pObject->m_pTransform	= new Transform();
            pObject->m_pMaterial	= new MaterialDiffuse();
            pObject->AddComponent( new ObjectRotator(0, 45, 0) );

            scene.AddObject( pObject );

            pObj1 = pObject;
        }

        // Источник света #1
/*        {
            Light * pLight = new Light(LightType::LIGHT_DIRECTIONAL);
            pLight->SetColor(1,1,1);
            pLight->SetIntensity(1);

            Object * pLightObject = new Object();
            pLightObject->m_pTransform	= new Transform(1,0,0, 0,90,0, 1,1,1);
            pLightObject->AddComponent(pLight);

            scene.AddLight(pLight);
        }*/

        {
            Light * pLight = new Light(LightType::LIGHT_DIRECTIONAL);
            pLight->SetColor(1,1,1);
            pLight->SetIntensity(1);

            Object * pLightObject = new Object();
            pLightObject->m_pTransform	= new Transform(1,-5,0, 20,0,0, 1,1,1);
            pLightObject->AddComponent(pLight);

            scene.AddLight(pLight);
        }
    }

    virtual void Update()
    {

    }
};
