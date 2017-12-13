#include "camera.h"
//#include <d3d11.h>
//#define _XM_NO_INTRINSICS_
//#define XM_NO_ALIGNMENT
//#include <math.h>
//#include <xnamath.h>
//int (WINAPIV * __vsnprintf_s)(char *, size_t, const char*, va_list) = _vsnprintf;

camera::camera(float x, float y, float z, float camera_rotation)
{
	m_x = x;
	m_y = y;
	m_z = z;
	m_camera_rotation= camera_rotation;

	m_dx = sin(m_camera_rotation *(XM_PI / 180.0));
	m_dz = cos(m_camera_rotation *(XM_PI / 180.0));
}

void camera::Rotate(float degree_nummber)
{
	
	m_camera_rotation += degree_nummber;

	m_dx = sin(m_camera_rotation *(XM_PI / 180.0));
	m_dz = cos(m_camera_rotation *(XM_PI / 180.0));

}

void camera::Forward(float distance)
{
	m_x += m_dx * distance;
	m_z += m_dz * distance;

}

void camera::Up(float heigh)
{
	m_y += heigh;
}

XMMATRIX camera::GetViewMatrix()
{
	m_position = XMVectorSet(m_x, m_y, m_z, 0.0);
	m_lookat = XMVectorSet(m_x+ m_dx, m_y,m_z+m_dz, 0.0);
	m_up = XMVectorSet(0.0, 1.0, 0.0, 0.0);

	XMMATRIX view = XMMatrixLookAtLH(m_position, m_lookat, m_up);

	return view;
}
