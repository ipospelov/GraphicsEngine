#pragma once
#include "GraphicsEngine/Component.h"
#include "GraphicsEngine/Matrix4x4.h"
#include "GraphicsEngine/Rect.h"


class Camera : public Component
{
public:
	Camera();
	
	// Установка вертикального угла обзора (в градусах)
	void SetFovY		(float fovY);
	// Установка ближней отсекающей плоскости
	void SetNearPlane	(float nearPlane);
	// Установка дальней отсекающей плоскости
	void SetFarPlane	(float farPlane);

	/**
	* @brief Where on the screen is the camera rendered in normalized coordinates
	* http://www.gamedev.net/page/resources/_/technical/game-programming/a-room-with-a-view-r3901.
	*/
	void SetViewport	(Rect rect = Rect(0.0f, 0.0f, 1.0f, 1.0f));
	Rect GetViewport	();
		
	const Matrix4x4 & GetMatrixView();
	const Matrix4x4 & GetMatrixProj();

private:

	void RecalculateMatrixProj();

	// Вертикальный угол обзора в градусах
	float m_fovY;
	float m_nearPlane;
	float m_farPlane;

	Matrix4x4 m_matProj;

	Rect viewport;
};
