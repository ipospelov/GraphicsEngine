#pragma once

#include <GraphicsEngine/Materials/MaterialSphere.h>
#include <GraphicsEngine/Materials/MaterialCylinder.h>
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

class Task02 : public Task{
public:
    virtual ~Task02(){};
    virtual void Init(){
        Scene & scene = Application::Instance().GetScene();

        // Камера
        {
            Object * pCameraObj = new Object();
            pCameraObj->m_pTransform = new Transform( Vector3(0, 1, -4), Vector3(10.0f, 0.0f, 0.0f));
            Camera * pCamera = new Camera();
            pCamera->SetFovY(90);
            pCamera->SetNearPlane(0.01f);
            pCamera->SetFarPlane(100);
            pCameraObj->AddComponent( pCamera );

            scene.SetCamera( pCamera );
        }

        {
            Object * pObject = new Object();
            pObject->m_pMesh = new MeshCube(10);
            pObject->m_pTransform	= new Transform(-2, 0, 0, 0, 0, 0, 1, 1, 1);
            pObject->m_pMaterial = new MaterialSphere();

            scene.AddObject(pObject);


        }

        {
            Object * pObject = new Object();
            pObject->m_pMesh = new MeshCylinder(20);
            pObject->m_pTransform	= new Transform(2, 0, 0, 0, 0, 0, 1, 1, 1);
            pObject->m_pMaterial = new MaterialCylinder();

            scene.AddObject(pObject);


        }


    }
    virtual void Update()
    {

    }
};