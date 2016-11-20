#pragma once
#include <list>
#include "Object.h"


class Camera;
class Light;


class Scene
{
public:

	void Init();
	void Deinit();

	void AddObject	(Object * pObject);
	void AddLight	(Light * pLight);
	
	void SetCamera	(Camera * pCamera);	
	Camera &		GetCamera() const;
	
	const std::list<const Light *> & GetLights() const;
	
	void Update();
	void Render();

private:
	std::list<const Object *>	m_objects;
	std::list<const Light *>	m_lights;
	Camera *					m_pCamera;
};
