#include "MyVector3D.h"

//patryk wysocki
//15/01/2017

/// <summary>
/// default contructor x,y,z values=0
/// </summary>
MyVector3D::MyVector3D():
	m_x{0.0},
	m_y{0.0},
	m_z{0.0}
{
}
/// <summary>
/// default constructor allowing to declare values for x,y,z
/// </summary>
/// <param name="x1"></param>
/// <param name="y1"></param>
/// <param name="z1"></param>
MyVector3D::MyVector3D(double x1, double y1, double z1):
	m_x{x1},
	m_y{y1},
	m_z{z1}
{
}
/// <summary>
/// return x value
/// </summary>
/// <returns></returns>
double MyVector3D::getX() const
{
	return m_x;
}
/// <summary>
/// return y value
/// </summary>
/// <returns></returns>
double MyVector3D::getY() const
{
	return m_y;
}
/// <summary>
/// return z value
/// </summary>
/// <returns></returns>
double MyVector3D::getZ() const
{
	return m_z;
}
/// <summary>
/// return length of vector
/// </summary>
/// <returns></returns>
double MyVector3D::length()
{
	return (double)std::sqrt((m_x*m_x) + (m_y*m_y) + (m_z*m_z));
}
/// <summary>
/// return length squared of the vector
/// </summary>
/// <returns></returns>
double MyVector3D::lengthSquared()
{
	return ((m_x*m_x) + (m_y*m_y) + (m_z*m_z));
}

//normalise vector to magnitude one
void MyVector3D::normalise()
{
	if (length() > 0.0)
	{
		double magnitude = length();
		m_x /= magnitude;
		m_y /= magnitude;
		m_z /= magnitude;
	}
}
//overload for addition operator
MyVector3D MyVector3D::operator+(const MyVector3D v2) const
{
	return MyVector3D(m_x + v2.getX(), m_y + v2.getY(), m_z + v2.getZ());
}
//overload for subtraction operator
MyVector3D MyVector3D::operator-(const MyVector3D v2) const
{
	return MyVector3D(m_x - v2.getX(), m_y - v2.getY(), m_z - v2.getZ());
}
//operator overload for minus
//change current vector 
MyVector3D MyVector3D::operator-()
{
	return MyVector3D(-m_x, -m_y, -m_z);
}
//operator overload for multiplication of vectors
MyVector3D MyVector3D::operator*(const MyVector3D v2) const
{
	return MyVector3D(m_x * v2.getX(), m_y * v2.getY(), m_z * v2.getZ());
}
//opeartor overload for multiplication by a double
MyVector3D MyVector3D::operator*(const double v2) const
{
	return MyVector3D(m_x * (float)v2, m_y * (float)v2, m_z * (float)v2);
}
//opeartor overload for multiplication by a flaot
MyVector3D MyVector3D::operator*(const float v2) const
{
	return MyVector3D(m_x * v2, m_y * v2, m_z * v2);
}
//opeartor overload for multiplication by a integer
MyVector3D MyVector3D::operator*(const int v2) const
{
	return MyVector3D(m_x * v2, m_y * v2, m_z * v2);
}
//opeartor overload for power
MyVector3D MyVector3D::operator^(const MyVector3D v2) const
{
	return  MyVector3D(m_y * v2.getZ() - m_z * v2.getY(), m_z * v2.getX() - m_x * v2.getZ(), m_x * v2.getY() - m_y * v2.getX());
}
//to string operator
std::string MyVector3D::toString()
{
	return std::string("("+std::to_string(m_x) +"," + std::to_string(m_y) + "," + std::to_string(m_z));
}
