#pragma once

#include <iostream>
#include "GraphicsEngine/Component.h"
#include "GraphicsEngine/Input.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/Time.h"
#include "GraphicsEngine/Vector3.h"


class CameraController : public Component
{
    Vector3 mousePos;
    double speed = 300.0;

public:
    CameraController()
    {
        mousePos = Vector3::Zero();
    }

    virtual ~CameraController() {}

    virtual void Update()
    {
        Transform * pTransform = m_pObject->m_pTransform;

        // Camera Translation
        {
            Vector3 forward	= pTransform->GetForward();
            Vector3 right	= pTransform->GetRight();
            double dt = Time::GetDeltaTime();


            Vector3 direction;

            if (Input::GetKey(KEY_CODE_W) || Input::GetKey(KEY_CODE_UP_ARROW))
            {
                pTransform->SetPosition(pTransform->GetPosition() + (pTransform->GetForward())/speed);
                //pTransform->Transform();
                // TODO: Task08
                // Move forward
            }
            else if (Input::GetKey(KEY_CODE_S) || Input::GetKey(KEY_CODE_DOWN_ARROW))
            {
                // TODO: Task08
                // Move backward
                pTransform->SetPosition(pTransform->GetPosition() - (pTransform->GetForward())/speed);
            }

            if (Input::GetKey(KEY_CODE_D) || Input::GetKey(KEY_CODE_RIGHT_ARROW))
            {
                // TODO: Task08
                // Move right
                pTransform->SetPosition(pTransform->GetPosition() + (pTransform->GetRight())/speed);
            }
            else if (Input::GetKey(KEY_CODE_A) || Input::GetKey(KEY_CODE_LEFT_ARROW))
            {
                // TODO: Task08
                // Move left
                pTransform->SetPosition(pTransform->GetPosition() - (pTransform->GetRight())/speed);
            }

            if (Input::GetKey(KEY_CODE_LEFT_SHIFT) || Input::GetKey(KEY_CODE_RIGHT_SHIFT))
            {
                // TODO: Task08
                // Move speed up (multiply speed by 10)
                speed = 100;
            }
            if (!Input::GetKey(KEY_CODE_LEFT_SHIFT) && !Input::GetKey(KEY_CODE_RIGHT_SHIFT))
            {
                // TODO: Task08
                // Move speed up (multiply speed by 10)
                speed = 300;
            }

            pTransform->Translate( speed * dt * direction );
        }

        // Camera Rotation
        {


            const double speedAngle = 0.3;
            if (Input::GetMouseButton(1))
            {
                // TODO: Task08
                // Rotate pTransform
                pTransform->Rotate(0.1 * (mousePos.y - Input::GetMousePosition().y),0.1 * (mousePos.x - Input::GetMousePosition().x),0);
                //std::cout<<mousePos.x <<" "<<mousePos.y<<" "<<mousePos.z<<std::endl;
                //std::cout<<Input::GetMousePosition().x <<" "<<Input::GetMousePosition().y<<" "<<mousePos.z<<std::endl;
            }

            if (Input::GetMouseButtonDown(1))
            {
                // TODO: Task08
                // Rotate pTransform
                //mousePos = Input::GetMousePosition();
                //std::cout<<"Yep"<<std::endl;

            }
            if (Input::GetMouseButtonUp(1))
            {
                // TODO: Task08
                // Rotate pTransform
               // mousePos = Input::GetMousePosition();
                //std::cout<<"Yep"<<std::endl;

            }
            mousePos = Input::GetMousePosition();
        }
    }
};