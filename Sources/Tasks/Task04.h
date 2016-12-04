#pragma once

#include <GraphicsEngine/Materials/MaterialSpecular.h>
#include "GraphicsEngine/Application.h"
#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/Light.h"
#include "GraphicsEngine/Materials/MaterialTask01.h"
#include "GraphicsEngine/Materials/MaterialUnlit.h"
#include "GraphicsEngine/Materials/MaterialDiffuse.h"
#include "GraphicsEngine/Meshes/MeshTriangle.h"
#include "GraphicsEngine/Meshes/MeshQuad.h"
#include "GraphicsEngine/Meshes/MeshSphere.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Scene.h"
#include "GraphicsEngine/Transform.h"
#include "Tasks/Task.h"
#include "Tasks/ObjectRotator.h"


class Task04: public Task
{
public:
	virtual ~Task04() { }

	virtual void Init()
	{
		Scene & scene = Application::Instance().GetScene();
		
		// Камера
		{
			Object * pCameraObj = new Object();
			pCameraObj->m_pTransform = new Transform( Vector3(0.0f, 0.0f,-7.0f), Vector3(0.0f, 0.0f, 0.0f));
			Camera * pCamera = new Camera();
			pCameraObj->AddComponent( pCamera );

			scene.SetCamera( pCamera );
		}

		// объект #1 - Сфера
		{
			Object * pObject1 = new Object();

			pObject1->m_pTransform	= new Transform(0,0,0, 0,0,0, 3,3,3);
			pObject1->m_pMesh		= new MeshSphere(20);

			//pObject1->m_pMaterial   = new MaterialSpecular();
            pObject1->m_pMaterial	= new MaterialDiffuse();
			pObject1->AddComponent( new ObjectRotator(0,10,0) );

			scene.AddObject( pObject1 );
		}

		// Источник света #1
		{
			Light * pLight = new Light(LightType::LIGHT_DIRECTIONAL);
			pLight->SetColor(1,1,0);
			pLight->SetIntensity(1);

			Object * pLightObject = new Object();
			pLightObject->m_pTransform	= new Transform(1,0,0, 0,90,0, 1,1,1);
			pLightObject->AddComponent(pLight);

			scene.AddLight(pLight);
		}

		// Источник света #2
        {
			Light * pLight = new Light(LightType::LIGHT_POINT);
			pLight->SetColor(1,1,1);
			pLight->SetIntensity(1.3);

			Object * pLightObject = new Object();
			pLightObject->m_pTransform	= new Transform(2,0,-1, 0,0,0, 1,1,1);
			pLightObject->AddComponent(pLight);

			scene.AddLight(pLight);
		}
        // Источник света #3
        {
            Light * pLight = new Light(LightType::LIGHT_SPOT);
            pLight->SetColor(1,0,1);
            pLight->SetIntensity(2);

            Object * pLightObject = new Object();
            pLightObject->m_pTransform	= new Transform(1,1,-2, 0,0,0, 1,1,1);
            pLightObject->AddComponent(pLight);

            scene.AddLight(pLight);
        }
	}

	virtual void Update()
	{
		
	}
};
