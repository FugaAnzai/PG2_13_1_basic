#pragma once
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "Vec2.h"
#include <Novice.h>

static const int kRowHeight = 20;
static const int kColumnWidth = 60;

namespace Function {
	int clamp(int value, int min, int max);
	void LoadCSV(const char* path, int* array);
	void MatrixScreenPrintf(int x, int y, Matrix2x2 matrix);
	void MatrixScreenPrintf(int x, int y, Matrix3x3 matrix);
	void Vector2ScreenPrintf(int x, int y, Vec2 vector2);
}