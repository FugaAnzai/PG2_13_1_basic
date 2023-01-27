#pragma once
#include "Vec2.h"

struct Matrix2x2
{
	float m[2][2];

	/// <summary>
	/// 行列の和
	/// </summary>
	/// <param name="matrix1">行列1</param>
	/// <param name="matrix2">行列2</param>
	/// <returns>Matrix2x2型</returns>
	Matrix2x2 Add(Matrix2x2 matrix1, Matrix2x2 matrix2);

	/// <summary>
	/// 行列の差
	/// </summary>
	/// <param name="matrix1">行列1</param>
	/// <param name="matrix2">行列2</param>
	/// <returns>Matrix2x2型</returns>
	Matrix2x2 Subtract(Matrix2x2 matrix1, Matrix2x2 matrix2);

	/// <summary>
	/// 行列の積
	/// </summary>
	/// <param name="matrix1">行列1</param>
	/// <param name="matrix2">行列2</param>
	/// <returns>Matrix2x2型</returns>
	Matrix2x2 Multiply(Matrix2x2 matrix1, Matrix2x2 matrix2);

	/// <summary>
	/// 回転行列の作成(毎フレームtheta更新)
	/// </summary>
	/// <param name="matrix1">行列1</param>
	/// <param name="matrix2">行列2</param>
	/// <returns>Matrix2x2型</returns>
	Matrix2x2 MakeRotateMatrix(float theta);

	Matrix2x2 Inverse();

	static Matrix2x2 Transpose(const Matrix2x2 m);

};