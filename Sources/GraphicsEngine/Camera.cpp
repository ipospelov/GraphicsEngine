#include "Camera.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/Math.h"
#include "GraphicsEngine/Screen.h"


Camera::Camera()
{
	m_fovY		= 45.0f;
	m_nearPlane	= 0.1f;
	m_farPlane	= 1000.0f;
}


// Установка вертикального угла обзора (в градусах)
void Camera::SetFovY( float fovY )
{
	m_fovY = Math::Clamp(fovY, 1, 179);
}

// Установка ближней отсекающей плоскости
void Camera::SetNearPlane( float nearPlane )
{
	//TODO: Добавить проверку на положительность и far > near
	m_nearPlane = nearPlane;
}

// Установка дальней отсекающей плоскости
void Camera::SetFarPlane( float farPlane )
{
	//TODO: Добавить проверку на положительность и far > near
	m_farPlane = farPlane;
}

void Camera::SetViewport(Rect rect)
{
	viewport = rect;
}

Rect Camera::GetViewport()
{
	return viewport;
}

const Matrix4x4 & Camera::GetMatrixView()
{
	return m_pObject->m_pTransform->GetMatView();
}

const Matrix4x4 & Camera::GetMatrixProj()
{
	RecalculateMatrixProj();	

	return m_matProj;
}

void Camera::RecalculateMatrixProj()
{
	float sw = Screen::GetWidth();
	float sh = Screen::GetHeight();

	float vw = viewport.w;
	float vh = viewport.h;

	float aspect = (sw * vw) / (sh * vh);
	
	m_matProj = Matrix4x4::PerspectiveFovLH( m_fovY, aspect, m_nearPlane, m_farPlane );
}
