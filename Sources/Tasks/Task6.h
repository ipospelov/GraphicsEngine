#pragma once

#include <GraphicsEngine/Materials/MaterialRoad.h>
#include <GraphicsEngine/Materials/MaterialDiffuse.h>
#include <GraphicsEngine/Materials/MaterialEarth.h>
#include <GraphicsEngine/Meshes/MeshSphere.h>
#include "Tasks/Task.h"
#include "GraphicsEngine/Application.h"
#include "GraphicsEngine/Meshes/MeshQuad.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Scene.h"
#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/Materials/MaterialSand.h"
#include "GraphicsEngine/Light.h"
#include "ObjectRotator.h"


class Task6: public Task
{
public:
    virtual ~Task6() { }

    virtual void Init()
    {
        Scene & scene = Application::Instance().GetScene();

        // Camera
        {
            Object * pCameraObj = new Object();
            Camera * pCamera = new Camera();
            pCameraObj->m_pTransform = new Transform( Vector3(0.0f, 0.0f,-7.0f), Vector3(0.0f, 0.0f, 0.0f));
            pCameraObj->AddComponent((Component *) pCamera);

            scene.SetCamera( pCamera );
        }


        // Object #1 - Plane with sand texture (Point filter)
        {
            Object * pObject1 = new Object();

            pObject1->m_pTransform	= new Transform(0,0,0, 0,0,0, 3,3,3);
            pObject1->m_pMesh		= new MeshSphere(20);
            pObject1->m_pMaterial	= new MaterialEarth();
            pObject1->AddComponent( new ObjectRotator(0,20,0) );
            //pObject1->m_pMesh		= new MeshQuad();
            //pObject1->m_pMaterial	= new MaterialRoad(TEXTURE_FILTER_MODE_ANISOTROPIC);

            scene.AddObject( pObject1 );
        }

        // Источник света #1
        {
            Light * pLight = new Light(LightType::LIGHT_DIRECTIONAL);
            pLight->SetColor(1,1,1);
            pLight->SetIntensity(0.3);

            Object * pLightObject = new Object();
            pLightObject->m_pTransform	= new Transform(1,0,0, 0,-90,30, 1,1,1);
            pLightObject->AddComponent(pLight);

            scene.AddLight(pLight);
        }

    }

    virtual void Update()
    {

    }
};
