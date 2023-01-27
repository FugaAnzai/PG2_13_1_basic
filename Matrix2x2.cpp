#include "Matrix2x2.h"

Matrix2x2 Matrix2x2::Add(Matrix2x2 matrix1, Matrix2x2 matrix2) {
	m[0][0] = matrix1.m[0][0] + matrix2.m[0][0];
	m[0][1] = matrix1.m[0][1] + matrix2.m[0][1];
	m[1][0] = matrix1.m[1][0] + matrix2.m[1][0];
	m[1][1] = matrix1.m[1][1] + matrix2.m[1][1];

	return{ m[0][0] ,m[0][1],m[1][0],m[1][1] };

}

Matrix2x2 Matrix2x2::Subtract(Matrix2x2 matrix1, Matrix2x2 matrix2) {
	m[0][0] = matrix1.m[0][0] - matrix2.m[0][0];
	m[0][1] = matrix1.m[0][1] - matrix2.m[0][1];
	m[1][0] = matrix1.m[1][0] - matrix2.m[1][0];
	m[1][1] = matrix1.m[1][1] - matrix2.m[1][1];

	return{ m[0][0] ,m[0][1],m[1][0],m[1][1] };

}

Matrix2x2 Matrix2x2::Multiply(Matrix2x2 matrix1, Matrix2x2 matrix2) {
	m[0][0] = matrix1.m[0][0] * matrix2.m[0][0] + matrix1.m[0][1] * matrix2.m[1][0];
	m[0][1] = matrix1.m[0][0] * matrix2.m[0][1] + matrix1.m[0][1] * matrix2.m[1][1];
	m[1][0] = matrix1.m[1][0] * matrix2.m[0][0] + matrix1.m[1][1] * matrix2.m[1][0];
	m[1][1] = matrix1.m[1][0] * matrix2.m[0][1] + matrix1.m[1][1] * matrix2.m[1][1];

	return{ m[0][0] ,m[0][1],m[1][0],m[1][1] };

}

Matrix2x2 Matrix2x2::MakeRotateMatrix(float theta) {
	m[0][0] = cosf(theta);
	m[0][1] = sinf(theta);
	m[1][0] = -sinf(theta);
	m[1][1] = cosf(theta);

	return{ m[0][0] ,m[0][1],m[1][0],m[1][1] };

}

Matrix2x2 Matrix2x2::Inverse() {

	Matrix2x2 result;

	result.m[0][0] = m[1][1] * (1 / ((m[0][0] * m[1][1]) - (m[0][1] * m[1][0])));
	result.m[0][1] = -m[0][1] * (1 / ((m[0][0] * m[1][1]) - (m[0][1] * m[1][0])));
	result.m[1][0] = -m[1][0] * (1 / ((m[0][0] * m[1][1]) - (m[0][1] * m[1][0])));
	result.m[1][1] = m[0][0] * (1 / ((m[0][0] * m[1][1]) - (m[0][1] * m[1][0])));

	return result;
}

Matrix2x2 Matrix2x2::Transpose(const Matrix2x2 m) {

	Matrix2x2 result;

	result.m[0][0] = m.m[0][0];
	result.m[0][1] = m.m[1][0];
	result.m[1][0] = m.m[0][1];
	result.m[1][1] = m.m[1][1];

	return result;

}