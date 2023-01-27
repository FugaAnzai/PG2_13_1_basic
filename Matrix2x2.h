#pragma once
#include "Vec2.h"

struct Matrix2x2
{
	float m[2][2];

	/// <summary>
	/// �s��̘a
	/// </summary>
	/// <param name="matrix1">�s��1</param>
	/// <param name="matrix2">�s��2</param>
	/// <returns>Matrix2x2�^</returns>
	Matrix2x2 Add(Matrix2x2 matrix1, Matrix2x2 matrix2);

	/// <summary>
	/// �s��̍�
	/// </summary>
	/// <param name="matrix1">�s��1</param>
	/// <param name="matrix2">�s��2</param>
	/// <returns>Matrix2x2�^</returns>
	Matrix2x2 Subtract(Matrix2x2 matrix1, Matrix2x2 matrix2);

	/// <summary>
	/// �s��̐�
	/// </summary>
	/// <param name="matrix1">�s��1</param>
	/// <param name="matrix2">�s��2</param>
	/// <returns>Matrix2x2�^</returns>
	Matrix2x2 Multiply(Matrix2x2 matrix1, Matrix2x2 matrix2);

	/// <summary>
	/// ��]�s��̍쐬(���t���[��theta�X�V)
	/// </summary>
	/// <param name="matrix1">�s��1</param>
	/// <param name="matrix2">�s��2</param>
	/// <returns>Matrix2x2�^</returns>
	Matrix2x2 MakeRotateMatrix(float theta);

	Matrix2x2 Inverse();

	static Matrix2x2 Transpose(const Matrix2x2 m);

};