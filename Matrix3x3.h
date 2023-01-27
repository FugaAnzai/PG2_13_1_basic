#pragma once
#include "Vec2.h"

struct Matrix3x3
{
	float m[3][3];

	Matrix3x3() {
		m[0][0] = 1;
		m[0][1] = 0;
		m[0][2] = 0;
		m[1][0] = 0;
		m[1][1] = 1;
		m[1][2] = 0;
		m[2][0] = 0;
		m[2][1] = 0;
		m[2][2] = 1;
	}

	Matrix3x3(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22) {

		m[0][0] = m00;
		m[0][1] = m01;
		m[0][2] = m02;
		m[1][0] = m10;
		m[1][1] = m11;
		m[1][2] = m12;
		m[2][0] = m20;
		m[2][1] = m21;
		m[2][2] = m22;

	}
	
public:

	Matrix3x3 operator*(const Matrix3x3& m);
	Matrix3x3& operator*=(const Matrix3x3& m);
	friend Vec2 operator*(const Vec2& v,const Matrix3x3& m);
	static Matrix3x3 MakeIdentityMatrix();
	static Matrix3x3 MakeScalingMatrix(float magX, float magY);
	static Matrix3x3 MakeRotateMatrix(float theta);
	static Matrix3x3 MakeTranslateMatrix(const Vec2& translate);
	static Matrix3x3 Inverse(const Matrix3x3& m);
	static Matrix3x3 Transpose(const Matrix3x3& m);
	static Matrix3x3 MakeWorldMatrix(float magX,float magY,float theta,const Vec2& translate);
	static Matrix3x3 MakeOrthoGraphicMatrix(Vec2 leftTop, Vec2 rightBottom);
	static Matrix3x3 MakeViewportMatrix(Vec2 leftTop, float width, float height);

};