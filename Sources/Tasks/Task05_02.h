#pragma once

#include <GraphicsEngine/Materials/MaterialRoad.h>
#include "Tasks/Task.h"
#include "GraphicsEngine/Application.h"
#include "GraphicsEngine/Meshes/MeshQuad.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Scene.h"
#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/Materials/MaterialSand.h"
#include "GraphicsEngine/Light.h"


class Task05_02: public Task
{
public:
    virtual ~Task05_02() { }

    virtual void Init()
    {
        Scene & scene = Application::Instance().GetScene();

        // Camera
        {
            Object * pCameraObj = new Object();
            Camera * pCamera = new Camera();
            pCameraObj->m_pTransform = new Transform( Vector3(0.0f, 1.0f,-7.0f), Vector3(25.0f, 0.0f, 0.0f) );
            pCameraObj->AddComponent((Component *) pCamera);

            scene.SetCamera( pCamera );
        }

        // Object #1 - Plane with sand texture (Point filter)
        {
            Object * pObject1 = new Object();

            pObject1->m_pTransform	= new Transform( 0.0,0,0, 93,0,0, 0.6,10,5 );
            pObject1->m_pMesh		= new MeshQuad();
            pObject1->m_pMaterial	= new MaterialRoad(TEXTURE_FILTER_MODE_ANISOTROPIC);

            scene.AddObject( pObject1 );
        }
    }

    virtual void Update()
    {

    }
};
