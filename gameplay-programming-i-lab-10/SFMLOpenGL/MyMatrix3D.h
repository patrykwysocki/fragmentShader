#ifndef MYMATRIX3D
#define MYMATRIX3D
#include "MyVector3D.h"

//patryk wysocki
//15/01/2017

class MyMatrix3
{
public:
	enum class Axis{X,Y,Z};
	MyMatrix3();
	MyMatrix3(MyVector3D row1,MyVector3D row2,MyVector3D row3);
	MyMatrix3(double a11, double a12, double a13,
		double a21, double a22, double a23,
		double a31, double a32, double a33);

	MyVector3D operator*(const MyVector3D v2)const;
	MyMatrix3 operator+(const MyMatrix3 m2)const;
	MyMatrix3 operator-(const MyMatrix3 m2)const;
	MyMatrix3 operator*(const double x)const;
	MyMatrix3 operator*(const MyMatrix3 m2)const;
	MyVector3D row(int i)const;
	MyVector3D column(int i)const;

	double determinant()const;
	MyMatrix3 inverse()const;
	MyMatrix3 transpose()const;
	MyMatrix3 rotation(double angle)const;
	MyMatrix3 translate(double dx, double dy)const;
	MyMatrix3 scale(double dx, double dy, double dz)const;
	MyMatrix3 operator-();
	static MyVector3D translation(MyVector3D & vector, double translateBy, const Axis &);

	MyMatrix3 rotationX(double angle)const;
	MyMatrix3 rotationY(double angle)const;
	MyMatrix3 rotationZ(double angle)const;

	MyMatrix3 scale3D(double dx) const;

	std::string toString();




	


private:
	double m_a11;
	double m_a12;
	double m_a13;
	double m_a21;
	double m_a22;
	double m_a23;
	double m_a31;
	double m_a32;
	double m_a33;
};
#endif // !MYMATRIX3D

