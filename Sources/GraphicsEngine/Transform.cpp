#include "Transform.h"
#include <stddef.h>

Transform::Transform()
:	m_pParent		(NULL),
	m_position		(0, 0, 0),
	m_eulerAngles	(0, 0, 0),
	m_scale			(1, 1, 1)
{
	m_shouldRecalc = true;
}

Transform::Transform(float x, float y, float z)
:	m_pParent		(NULL),
	m_position		(x, y, z),
	m_eulerAngles	(0, 0, 0),
	m_scale			(1, 1, 1)
{
	m_shouldRecalc = true;
}

// position (px, py, pz), rotation (rx, ry, rz), scale (sx, sy, sz)
Transform::Transform(float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz)
:	m_pParent		(NULL),
	m_position		(px, py, pz),
	m_eulerAngles	(rx, ry, rz),
	m_scale			(sx, sy, sz)
{
	m_shouldRecalc = true;
}

Transform::Transform(Vector3 position, Vector3 eulerAngles, Vector3 scale)
:	m_pParent		(NULL),
	m_position		( position ),
	m_eulerAngles	( eulerAngles ),
	m_scale			( scale )
{
	m_shouldRecalc = true;
}


void Transform::SetParent(Transform * const pParent)
{
	m_pParent = pParent;
	m_shouldRecalc = true;
}

const Vector3 & Transform::GetForward()
{
	if (m_shouldRecalc)
	{
		Recalc();
	}

	return m_forward;
}

const Vector3 & Transform::GetRight()
{
	if (m_shouldRecalc)
	{
		Recalc();
	}

	return m_right;
}

const Vector3 & Transform::GetUp()
{
	if (m_shouldRecalc)
	{
		Recalc();
	}

	return m_up;
}


void Transform::SetPosition( Vector3 position )
{
	m_position = position;
	m_shouldRecalc = true;
}

void Transform::SetEulerAngles( Vector3 eulerAngles )
{
	m_eulerAngles = eulerAngles;
	m_shouldRecalc = true;
}

void Transform::SetScale( Vector3 scale )
{
	m_scale = scale;
	m_shouldRecalc = true;
}

void Transform::Translate( Vector3 vec )
{
	m_position += vec;
	m_shouldRecalc = true;
}


void Transform::Translate( float x, float y, float z )
{
	m_position += Vector3(x, y, z);
	m_shouldRecalc = true;
}


void Transform::Rotate(const Vector3 & euler)
{
	m_eulerAngles += euler;
	m_shouldRecalc = true;
}

void Transform::Rotate( float x, float y, float z )
{
	m_eulerAngles += Vector3(x,y,z);
	//m_eulerAngles.y = fmod(m_eulerAngles.y, 360);
	m_shouldRecalc = true;
}


const Vector3 & Transform::GetPosition() const
{
	return m_position;
}

const Vector3 & Transform::GetEulerAngles() const
{
	return m_eulerAngles;
}

const Vector3 & Transform::GetScale() const
{
	return m_scale;
}

const Matrix4x4 & Transform::GetMatWorld()
{
	//if (m_shouldRecalc)
	{
		Recalc();
	}

	return m_matWorld;
}

const Matrix4x4 & Transform::GetMatView()
{
	if (m_shouldRecalc)
	{
		Recalc();
	}

	return m_matView;
}

void Transform::Recalc()
{
	// ѕересчитаем матрицу World
	{
		Matrix4x4 matTrans	= Matrix4x4::Translation(m_position);
		Matrix4x4 matRot	= Matrix4x4::Rotation(m_eulerAngles);
		Matrix4x4 matScale	= Matrix4x4::Scaling(m_scale);

		m_matWorld = matScale * matRot * matTrans;
		
		// If has parent then use parent matrix
		if (NULL != m_pParent)
		{
			Matrix4x4 matWorldParent = m_pParent->GetMatWorld();
			m_matWorld = m_matWorld * matWorldParent;
		}
	}

	// ѕересчитаем вектора m_forward, m_right, m_up
	{
		Vector4 forward4 = m_matWorld * Vector4(0, 0, 1, 0);
		m_forward = forward4.ToVector3();
		m_forward.Normalize();

		Vector4 right4 = m_matWorld * Vector4(1, 0, 0, 0);
		m_right = right4.ToVector3();
		m_right.Normalize();

		Vector4 up4 = m_matWorld * Vector4(0, 1, 0, 0);
		m_up = up4.ToVector3();
		m_up.Normalize();
	}

	// ѕересчитываем матрицу View
	{
		m_matView = Matrix4x4::LookAtLH(m_position, m_position + m_forward, m_up);
	}

	m_shouldRecalc = false;
}
