#ifndef MYVECTOR3D
#define MYVECTOR3D

//patryk wysocki
//15/01/2017

#include <string>
#include <math.h>
class MyVector3D
{
public:
	MyVector3D();
	MyVector3D(double x1, double y1, double z1);
	double getX() const;
	double getY()const;
	double getZ() const;
	double length();
	double lengthSquared();
	void normalise();
	MyVector3D operator+(const MyVector3D v2)const;

	MyVector3D operator-(const MyVector3D v2)const;
	MyVector3D operator-();

	MyVector3D operator*(const MyVector3D v2)const;
	MyVector3D operator*(const double v2)const;
	MyVector3D operator*(const float v2)const;
	MyVector3D operator*(const int v2)const;

	MyVector3D operator^(const MyVector3D v2)const;
	//static MyVector3D operator -(MyVector3D V);
	std::string toString();

private:
	double m_x;
	double m_y;
	double m_z;
};


#endif // !MYVECTOR3D

