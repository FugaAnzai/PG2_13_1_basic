#pragma once
#include "Vec2.h"

struct Matrix2x2
{
	float m[2][2];

	/// <summary>
	/// sρΜa
	/// </summary>
	/// <param name="matrix1">sρ1</param>
	/// <param name="matrix2">sρ2</param>
	/// <returns>Matrix2x2^</returns>
	Matrix2x2 Add(Matrix2x2 matrix1, Matrix2x2 matrix2);

	/// <summary>
	/// sρΜ·
	/// </summary>
	/// <param name="matrix1">sρ1</param>
	/// <param name="matrix2">sρ2</param>
	/// <returns>Matrix2x2^</returns>
	Matrix2x2 Subtract(Matrix2x2 matrix1, Matrix2x2 matrix2);

	/// <summary>
	/// sρΜΟ
	/// </summary>
	/// <param name="matrix1">sρ1</param>
	/// <param name="matrix2">sρ2</param>
	/// <returns>Matrix2x2^</returns>
	Matrix2x2 Multiply(Matrix2x2 matrix1, Matrix2x2 matrix2);

	/// <summary>
	/// ρ]sρΜμ¬(t[thetaXV)
	/// </summary>
	/// <param name="matrix1">sρ1</param>
	/// <param name="matrix2">sρ2</param>
	/// <returns>Matrix2x2^</returns>
	Matrix2x2 MakeRotateMatrix(float theta);

	Matrix2x2 Inverse();

	static Matrix2x2 Transpose(const Matrix2x2 m);

};