#include "MyMatrix3D.h"

//patryk wysocki
//15/01/2017

//default constructor
MyMatrix3::MyMatrix3():
	m_a11{0.0},
	m_a12{ 0.0 },
	m_a13{ 0.0 },

	m_a21{ 0.0 },
	m_a22{ 0.0 },
	m_a23{ 0.0 },

	m_a31{ 0.0 },
	m_a32{ 0.0 },
	m_a33{ 0.0 }
{
}
//overload constructos that takes 3 vecotrs
MyMatrix3::MyMatrix3(MyVector3D row1, MyVector3D row2, MyVector3D row3):
	m_a11{ row1.getX() },
	m_a12{ row1.getY() },
	m_a13{ row1.getZ() },

	m_a21{ row2.getX() },
	m_a22{ row2.getY() },
	m_a23{ row2.getZ() },

	m_a31{ row3.getX() },
	m_a32{ row3.getY() },
	m_a33{ row3.getZ() }
{
}
//overload constructos that takes doubles
MyMatrix3::MyMatrix3(double a11, double a12, double a13, 
	double a21, double a22, double a23, 
	double a31, double a32, double a33):
	m_a11{ a11 },
	m_a12{ a12 },
	m_a13{ a13 },

	m_a21{ a21 },
	m_a22{ a22 },
	m_a23{ a23 },

	m_a31{ a31 },
	m_a32{ a32 },
	m_a33{ a33 }
{
}
//operator overload for multiplication of  matrix by vector
MyVector3D MyMatrix3::operator*(const MyVector3D v2) const
{
	return MyVector3D((m_a11 * v2.getX() + m_a12 * v2.getY() + m_a13* v2.getZ()),
		(m_a21 * v2.getX() + m_a22 * v2.getY() + m_a23* v2.getZ()),
		(m_a31 * v2.getX() + m_a32 * v2.getY() + m_a33* v2.getZ()));
}
//operator overload for additoin of matrix by matrix
MyMatrix3 MyMatrix3::operator+(const MyMatrix3 m2) const
{
	return MyMatrix3(m_a11 + m2.m_a11, m_a12 + m2.m_a12, m_a13 + m2.m_a13,
		m_a21 + m2.m_a21, m_a22 + m2.m_a22, m_a23 + m2.m_a23,
		m_a31 + m2.m_a31, m_a32 + m2.m_a32, m_a33 + m2.m_a33);
}
//operator overload for subtraction of matrix minus matrix
MyMatrix3 MyMatrix3::operator-(const MyMatrix3 m2) const
{
	return MyMatrix3(m_a11 - m2.m_a11, m_a12 - m2.m_a12, m_a13 - m2.m_a13,
		m_a21 - m2.m_a21, m_a22 - m2.m_a22, m_a23 - m2.m_a23,
		m_a31 - m2.m_a31, m_a32 - m2.m_a32, m_a33 - m2.m_a33);
}
//operator overload for multiplication of matrix by a number
MyMatrix3 MyMatrix3::operator*(const double x) const
{
	return MyMatrix3((m_a11 * x), (m_a12 * x), (m_a13 * x),
		(m_a21 * x), (m_a22 * x), (m_a23 * x),
		(m_a31 * x), (m_a32* x), (m_a33 * x));
}
//operator overload for multip[lication of matrix by matrix
MyMatrix3 MyMatrix3::operator*(const MyMatrix3 m2) const
{
	MyVector3D row1 = MyVector3D(m_a11 * m2.m_a11 + m_a12 * m2.m_a21 + m_a13 * m2.m_a31, m_a11 * m2.m_a12 + m_a12 * m2.m_a22 + m_a13 * m2.m_a32, m_a11 * m2.m_a13 + m_a12 * m2.m_a23 + m_a13 * m2.m_a33);
	MyVector3D row2 = MyVector3D(m_a21 * m2.m_a11 + m_a22 * m2.m_a21 + m_a23 * m2.m_a31, m_a21 * m2.m_a12 + m_a22 * m2.m_a22 + m_a23 * m2.m_a32, m_a21 * m2.m_a13 + m_a22 * m2.m_a23 + m_a23 * m2.m_a33);
	MyVector3D row3 = MyVector3D(m_a31 * m2.m_a11 + m_a32 * m2.m_a21 + m_a33 * m2.m_a31, m_a31 * m2.m_a12 + m_a32 * m2.m_a22 + m_a33 * m2.m_a32, m_a31 * m2.m_a13 + m_a32 * m2.m_a23 + m_a33 * m2.m_a33);
	return MyMatrix3(row1, row2, row3);
}
// a method to return as Row as vector3 0 == first row, default == last row
MyVector3D MyMatrix3::row(int i) const
{
	switch (i)
	{
	case 0:
		return MyVector3D(m_a11, m_a12, m_a13);
	case 1:
		return MyVector3D(m_a21, m_a22, m_a23);
	case 2:
	default:
		return MyVector3D(m_a31, m_a32, m_a33);
	}
}
// a method to return as column as vector3 0 == first column, default == last column
MyVector3D MyMatrix3::column(int i) const
{
	switch (i)
	{
	case 0:
		return MyVector3D(m_a11, m_a21, m_a31);
	case 1:
		return MyVector3D(m_a12, m_a22, m_a32);
	case 2:
	default:
		return MyVector3D(m_a13, m_a23, m_a33);
	}
}
// method to return the determinant of a 3x3 matrix
double MyMatrix3::determinant() const
{
	return  m_a11 * m_a22 * m_a33 - m_a11 * m_a32 * m_a23 + m_a21 * m_a32 * m_a13 - m_a31 * m_a22 * m_a13 + m_a31 * m_a12 * m_a23 - m_a21 * m_a12 * m_a33;
}
// method to return the inverse of a matrix if exists else zero vector
MyMatrix3 MyMatrix3::inverse() const
{
	if (determinant() == 0)
	{
		return MyMatrix3();
	}
	else
	{
		return MyMatrix3(1 / determinant() * (m_a33*m_a22) - (m_a32*m_a23), 1 / determinant() * (m_a32*m_a13) - (m_a33*m_a12), 1 / determinant() * (m_a23*m_a12) - (m_a22*m_a13),
			1 / determinant() * (m_a31*m_a23) - (m_a33*m_a21), 1 / determinant() * (m_a33*m_a11) - (m_a31*m_a13), 1 / determinant() * (m_a21*m_a13) - (m_a23*m_a11),
			1 / determinant() * (m_a32*m_a21) - (m_a31*m_a22), 1 / determinant() * (m_a31*m_a12) - (m_a32*m_a11), 1 / determinant() * (m_a22*m_a11) - (m_a21*m_a12));
	}
}
//transpose the matrix
MyMatrix3 MyMatrix3::transpose() const
{
	return  MyMatrix3(m_a11, m_a21, m_a31,
		m_a12, m_a22,m_a32,
		m_a13, m_a23, m_a33);
}
//operator overload with minus sign
//return -matrix
MyMatrix3 MyMatrix3::operator-()
{
	return MyMatrix3(-m_a11, -m_a12, -m_a13, 
		-m_a21, -m_a22, -m_a23, 
		-m_a31, -m_a32, -m_a33);
}

std::string MyMatrix3::toString()
{
	return std::string("(" + std::to_string(m_a11) + "," + std::to_string(m_a12) + "," + std::to_string(m_a13)
		+ std::to_string(m_a21) + "," + std::to_string(m_a22) + "," + std::to_string(m_a23) + ","
		+ std::to_string(m_a31) + "," + std::to_string(m_a32) + "," + std::to_string(m_a33));


}

//returns matrix to multiply by to rotate a vector
MyMatrix3 MyMatrix3::rotation(double angle) const
{
	double radians = (acos(-1) / 180) * angle;  // converting to radians
	return MyMatrix3(cos(radians), sin(radians), 0,
		-sin(radians), cos(radians), 0,
		0, 0, 1);
}


//returns matrix to multiply by to rotate a vector
MyMatrix3 MyMatrix3::rotationX(double angle) const
{
	double radians = (acos(-1) / 180) * angle;  // converting to radians
	return MyMatrix3(1, 0, 0,
		0, cos(radians), -sin(radians),
		0, sin(radians), cos(radians));
}

//returns matrix to multiply by to rotate a vector
MyMatrix3 MyMatrix3::rotationY(double angle) const
{
	double radians = (acos(-1) / 180) * angle;  // converting to radians
	return MyMatrix3(cos(radians), 0, -sin(radians),
		0, 1, 0,
		sin(radians), 0, cos(radians));
}

//returns matrix to multiply by to rotate a vector
MyMatrix3 MyMatrix3::rotationZ(double angle) const
{
	double radians = (acos(-1) / 180) * angle;  // converting to radians
	return MyMatrix3(cos(radians), sin(radians), 0,
		-sin(radians), cos(radians), 0,
		0, 0, 1);
}

//returns the matrix to multiply by to translate a vector
MyMatrix3 MyMatrix3::translate(double dx, double dy) const
{
	return MyMatrix3(1, 0, dx,
		0, 1, dy,
		0, 0, 1);

}

//f returns the matrix to multiply by to scale a vector
MyMatrix3 MyMatrix3::scale(double dx, double dy,double dz) const
{
	return MyMatrix3(static_cast<double>(dx / 100), 0, 0,
		0, static_cast<double>(dy / 100), 0,
		0, 0, static_cast<double>(dz/100));
}

//returns the matrix to multiply by to scale a vector in 3D
MyMatrix3 MyMatrix3::scale3D(double dx) const
{
	return MyMatrix3(static_cast<double>(dx), 0, 0,
		0, static_cast<double>(dx), 0,
		0, 0, static_cast<double>(dx));
}
MyVector3D MyMatrix3::translation(MyVector3D & vector, double translateBy, const Axis &t_axis)
{
	double row1[4];
	double row2[4];
	double row3[4];
	double row4[4];
	double answer[4];
	switch (t_axis)
	{
	case Axis::X:
		row1[0] = 1; row1[1] = 0; row1[2] = 0; row1[3] = translateBy;
		row2[0] = 0; row2[1] = 1; row2[2] = 0; row2[3] = 0;
		row3[0] = 0; row3[1] = 0; row3[2] = 1; row3[3] = 0;
		row4[0] = 0; row4[1] = 0; row4[2] = 0; row4[3] = 1;
		break;
	case Axis::Y:
		row1[0] = 1; row1[1] = 0; row1[2] = 0; row1[3] = 0;
		row2[0] = 0; row2[1] = 1; row2[2] = 0; row2[3] = translateBy;
		row3[0] = 0; row3[1] = 0; row3[2] = 1; row3[3] = 0;
		row4[0] = 0; row4[1] = 0; row4[2] = 0; row4[3] = 1;
		break;
	case Axis::Z:
		row1[0] = 1; row1[1] = 0; row1[2] = 0; row1[3] = 0;
		row2[0] = 0; row2[1] = 1; row2[2] = 0; row2[3] = 0;
		row3[0] = 0; row3[1] = 0; row3[2] = 1; row3[3] = translateBy;
		row4[0] = 0; row4[1] = 0; row4[2] = 0; row4[3] = 1;
		break;

	default:
		row1[0] = 1; row1[1] = 0; row1[2] = 0; row1[3] = 0;
		row2[0] = 0; row2[1] = 1; row2[2] = 0; row2[3] = 0;
		row3[0] = 0; row3[1] = 0; row3[2] = 1; row3[3] = 0;
		row4[0] = 0; row4[1] = 0; row4[2] = 0; row4[3] = 1;
		break;
	}
	answer[0] = ((row1[0] * vector.getX()) + (row1[1] * vector.getY()) + (row1[2] * vector.getZ()) + (row1[3] * 1));
	answer[1] = ((row2[0] * vector.getX()) + (row2[1] * vector.getY()) + (row2[2] * vector.getZ()) + (row2[3] * 1));
	answer[2] = ((row3[0] * vector.getX()) + (row3[1] * vector.getY()) + (row3[2] * vector.getZ()) + (row3[3] * 1));
	answer[3] = ((row4[0] * vector.getX()) + (row4[1] * vector.getY()) + (row4[2] * vector.getZ()) + (row4[3] * 1));
	return MyVector3D(answer[0],answer[1],answer[2]);
}