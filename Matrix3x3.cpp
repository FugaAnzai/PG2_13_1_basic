#include "Matrix3x3.h"

Matrix3x3 Matrix3x3::operator*(const Matrix3x3& m) {
	Matrix3x3 result;
	
	result.m[0][0] = this->m[0][0] * m.m[0][0] + this->m[0][1] * m.m[1][0] + this->m[0][2] * m.m[2][0];
	result.m[0][1] = this->m[0][0] * m.m[0][1] + this->m[0][1] * m.m[1][1] + this->m[0][2] * m.m[2][1];
	result.m[0][2] = this->m[0][0] * m.m[0][2] + this->m[0][1] * m.m[1][2] + this->m[0][2] * m.m[2][2];
	result.m[1][0] = this->m[1][0] * m.m[0][0] + this->m[1][1] * m.m[1][0] + this->m[1][2] * m.m[2][0];
	result.m[1][1] = this->m[1][0] * m.m[0][1] + this->m[1][1] * m.m[1][1] + this->m[1][2] * m.m[2][1];
	result.m[1][2] = this->m[1][0] * m.m[0][2] + this->m[1][1] * m.m[1][2] + this->m[1][2] * m.m[2][2];
	result.m[2][0] = this->m[2][0] * m.m[0][0] + this->m[2][1] * m.m[1][0] + this->m[2][2] * m.m[2][0];
	result.m[2][1] = this->m[2][0] * m.m[0][1] + this->m[2][1] * m.m[1][1] + this->m[2][2] * m.m[2][1];
	result.m[2][2] = this->m[2][0] * m.m[0][2] + this->m[2][1] * m.m[1][2] + this->m[2][2] * m.m[2][2];

	return result;
}

Matrix3x3& Matrix3x3::operator*=(const Matrix3x3& m) {
	
	*this = *this * m;

	return *this;
}

Vec2 operator*(const Vec2& v, const Matrix3x3& m) {

	Vec2 result;

	result.x = m.m[0][0] * v.x + m.m[1][0] * v.y + m.m[2][0];
	result.y = m.m[0][1] * v.x + m.m[1][1] * v.y + m.m[2][1];

	return result;

}

Matrix3x3 Matrix3x3::MakeIdentityMatrix() {

	Matrix3x3 result;

	result.m[0][0] = 1; result.m[0][1] = 0; result.m[0][2] = 0;
	result.m[1][0] = 0; result.m[1][1] = 1; result.m[1][2] = 0;
	result.m[2][0] = 0; result.m[2][1] = 0; result.m[2][2] = 1;

	return result;
}

Matrix3x3 Matrix3x3::MakeScalingMatrix(float magX, float magY) {

	Matrix3x3 result;

	result.m[0][0] = magX;
	result.m[1][1] = magY;

	return result;
}

Matrix3x3 Matrix3x3::MakeRotateMatrix(float theta) {
	Matrix3x3 result;
	float cos = cosf(theta);
	float sin = sinf(theta);
	result.m[0][0] = cos; result.m[0][1] = sin;
	result.m[1][0] = -sin; result.m[1][1] = cos;

	return result;
}

Matrix3x3 Matrix3x3::MakeTranslateMatrix(const Vec2& translate) {
	Matrix3x3 result;
	result.m[2][0] = translate.x;
	result.m[2][1] = translate.y;

	return result;

}

Matrix3x3 Matrix3x3::Inverse(const Matrix3x3& m) {
	Matrix3x3 result;

	float A = (m.m[0][0] * m.m[1][1] * m.m[2][2]) + (m.m[0][1] * m.m[1][2] * m.m[2][0]) + (m.m[0][2] * m.m[1][0] * m.m[2][1]) - (m.m[0][2] * m.m[1][1] * m.m[2][0]) - (m.m[0][1] * m.m[1][0] * m.m[2][2]) - (m.m[0][0] * m.m[1][2] * m.m[2][1]);

	result.m[0][0] = ((m.m[1][1] * m.m[2][2]) - (m.m[1][2] * m.m[2][1])) * 1 / A;
	result.m[0][1] = -((m.m[0][1] * m.m[2][2]) - (m.m[0][2] * m.m[2][1])) * 1 / A;
	result.m[0][2] = ((m.m[0][1] * m.m[1][2]) - (m.m[0][2] * m.m[1][1])) * 1 / A;
	result.m[1][0] = -((m.m[1][0] * m.m[2][2]) - (m.m[1][2] * m.m[2][0])) * 1 / A;
	result.m[1][1] = ((m.m[0][0] * m.m[2][2]) - (m.m[0][2] * m.m[2][0])) * 1 / A;
	result.m[1][2] = -((m.m[0][0] * m.m[1][2]) - (m.m[0][2] * m.m[1][0])) * 1 / A;
	result.m[2][0] = ((m.m[1][0] * m.m[2][1]) - (m.m[1][1] * m.m[2][0])) * 1 / A;
	result.m[2][1] = -((m.m[0][0] * m.m[2][1]) - (m.m[0][1] * m.m[2][0])) * 1 / A;
	result.m[2][2] = ((m.m[0][0] * m.m[1][1]) - (m.m[0][1] * m.m[1][0])) * 1 / A;

	return result;
}

Matrix3x3 Matrix3x3::Transpose(const Matrix3x3& m) {

	Matrix3x3 result;

	result.m[0][0] = m.m[0][0];
	result.m[0][1] = m.m[1][0];
	result.m[0][2] = m.m[2][0];
	result.m[1][0] = m.m[0][1];
	result.m[1][1] = m.m[1][1];
	result.m[1][2] = m.m[2][1];
	result.m[2][0] = m.m[0][2];
	result.m[2][1] = m.m[1][2];
	result.m[2][2] = m.m[2][2];

	return result;

}

Matrix3x3 Matrix3x3::MakeWorldMatrix(float magX, float magY, float theta, const Vec2& translate) {

	Matrix3x3 result;

	result = Matrix3x3::MakeIdentityMatrix();
	result *= Matrix3x3::MakeScalingMatrix(magX, magY);
	result *= Matrix3x3::MakeRotateMatrix(theta);
	result *= Matrix3x3::MakeTranslateMatrix(translate);

	return result;

}

Matrix3x3 Matrix3x3::MakeOrthoGraphicMatrix(Vec2 leftTop, Vec2 rightBottom) {

	Matrix3x3 result;

	result.m[0][0] = 2.0f / (rightBottom.x - leftTop.x);
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[1][0] = 0;
	result.m[1][1] = 2.0f / (leftTop.y - rightBottom.y);
	result.m[1][2] = 0;
	result.m[2][0] = (leftTop.x + rightBottom.x) / (leftTop.x - rightBottom.x);
	result.m[2][1] = (leftTop.y + rightBottom.y) / (rightBottom.y - leftTop.y);
	result.m[2][2] = 1;

	return result;

}

Matrix3x3 Matrix3x3::MakeViewportMatrix(Vec2 leftTop, float width, float height) {

	Matrix3x3 result;

	result.m[0][0] = width / 2.0f;
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[1][0] = 0;
	result.m[1][1] = -(height / 2.0f);
	result.m[1][2] = 0;
	result.m[2][0] = leftTop.x + (width / 2.0f);
	result.m[2][1] = leftTop.y + (height / 2.0f);
	result.m[2][2] = 1;

	return result;

}