#pragma once
#include "GraphicsEngine/Component.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/Math.h"


enum LightType
{
	LIGHT_DIRECTIONAL,
	LIGHT_POINT,
	LIGHT_SPOT,
};

class Light : public Component
{
public:
	Light(LightType type)
	{
		switch (type)
		{
			case LIGHT_DIRECTIONAL:
				m_type = 1;
				break;
			case LIGHT_POINT:
				m_type = 2;
				break;
			case LIGHT_SPOT:
				m_type = 3;
				break;
			
			default:
				m_type = 1;
				break;
		}
	}
	virtual ~Light() {}
	
	virtual Vector4 GetType() const
	{
		return Vector4(m_type,0,0,0);
	}

	virtual Vector4 GetColor() const
	{
		return Vector4(m_color, m_intensity);
	}
	
	virtual Vector3 GetPosition() const
	{
		Vector3 position = m_pObject->m_pTransform->GetPosition();
		return position;
	}

	virtual Vector3 GetDirection() const
	{
		Vector3 direction = m_pObject->m_pTransform->GetForward();
		return direction;
	}

	virtual void SetColor(Vector3 color)
	{
		// Clamp color by interval [0,1]
		m_color = Vector3::Clamp01(color);
	}

	virtual void SetColor(float r, float g, float b)
	{
		// Clamp r, g, b by interval [0,1]
		m_color = Vector3::Clamp01( Vector3(r, g, b) );
	}

	virtual void SetIntensity(float intensity)
	{
		// Clamp intensity by interval [0, +infinity]
		m_intensity = (intensity >= 0) ? intensity : 0;
	}
	
protected:
	int		m_type;
	Vector3	m_color;
	float	m_intensity;

private:
	Light();
};
