#pragma once
#include "GraphicsEngine/Scene.h"
#include "GraphicsEngine/Application.h"
#include "GraphicsEngine/Camera.h"

class SceneUtils
{
public:

	static const Matrix4x4 GetMatrixWorld(const Object * pObject)
	{
		const Matrix4x4 matWorld = pObject->m_pTransform->GetMatWorld();
		
		return matWorld;
	}

	static const Matrix4x4 GetMatrixView()
	{
		Scene &	scene = Application::Instance().GetScene();
		Camera & camera = scene.GetCamera();

		const Matrix4x4 matView = camera.GetMatrixView();
		
		return matView;
	}

	static const Matrix4x4 GetMatrixProj()
	{
		Scene &	scene = Application::Instance().GetScene();
		Camera & camera = scene.GetCamera();

		const Matrix4x4 matProj = camera.GetMatrixProj();

		return matProj;
	}
	
	static const Vector3 GetEyePosition()
	{
		// TODO: Нужно поставить проверки, что не работает с нулевыми указателями
		const Scene &	scene = Application::Instance().GetScene();
		Vector3 eyePos = scene.GetCamera().GetObjectPtr()->m_pTransform->GetPosition();
		return eyePos;
	}

	static const std::list<const Light *> GetLights()
	{
		const Scene & scene = Application::Instance().GetScene();
		return scene.GetLights();
	}
};
