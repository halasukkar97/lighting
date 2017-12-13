#include <d3d11.h>
#define _XM_NO_INTRINSICS_
#define XM_NO_ALIGNMENT
#include <math.h>
#include <xnamath.h>

//Create a Camera class
class camera {

	//with private floating
private:
	float m_x;
	float m_y;
	float m_z;
	float m_dx;
	float m_dz;
	float m_camera_rotation;

	XMVECTOR  m_position;
	XMVECTOR  m_lookat;
	XMVECTOR m_up;
public:

	//a constructor that has 4 parameters
	camera(float x,float y,float z,float camera_rotation);
	
	// creating Rotate method with one floating point parameter
	void Rotate(float degree_nummber);

	//Create Forward method that has one floating point parameter  
	void Forward(float distance);

	//Create Up method that has one floating point parameter
	void Up(float heigh);

	//create GetViewMatrix method when it says return XMMATRIX that means use the type insted of void 
	XMMATRIX GetViewMatrix();


};
