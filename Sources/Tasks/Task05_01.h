#pragma once
#include "Tasks/Task.h"
#include "GraphicsEngine/Application.h"
#include "GraphicsEngine/Meshes/MeshQuad.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Scene.h"
#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/Materials/MaterialSand.h"
#include "GraphicsEngine/Light.h"


class Task05_01: public Task
{
public:
	virtual ~Task05_01() { }

	virtual void Init()
	{
		Scene & scene = Application::Instance().GetScene();
	
		// Camera
		{
			Object * pCameraObj = new Object();
			Camera * pCamera = new Camera();
			pCameraObj->m_pTransform = new Transform( Vector3(0.0f, 1.0f,-7.0f), Vector3(25.0f, 0.0f, 0.0f) );			
			pCameraObj->AddComponent( pCamera );

			scene.SetCamera( pCamera );
		}

		// Object #1 - Plane with sand texture (Point filter)
		{
			Object * pObject1 = new Object();

			pObject1->m_pTransform	= new Transform( -0.675,0,0, 90,0,0, 0.2,10,1 );
			pObject1->m_pMesh		= new MeshQuad();			
			pObject1->m_pMaterial	= new MaterialSand(TEXTURE_FILTER_MODE_POINT);
						
			scene.AddObject( pObject1 );
		}
	}

	virtual void Update()
	{
		
	}
};
