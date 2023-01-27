#include "Function.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int Function::clamp(int value, int min, int max) {

	if (value < min) {
		return min;
	}
	else if (value > max) {
		return max;
	}

	return value;
}

void Function::LoadCSV(const char* path, int* array) {
	//一行バッファ
	std::string line_buff;
	//一文字バッファ
	std::string buff;

	//ファイル読み込み
	std::ifstream read_file(path);

	int i = 0;
	int row = 0;

	//一行読み取り
	while (std::getline(read_file, line_buff)) {

		//一行バッファをgetlineに渡せるように変換
		std::istringstream line(line_buff);

		//,の後の数字読み取り
		while (std::getline(line, buff, ',')) {
			array[i] = std::stoi(buff);//値をarrayに保存
			i++;
		}
	}

}

void Function::MatrixScreenPrintf(int x, int y, Matrix2x2 matrix) {
	for (int row = 0; row < 2; ++row) {
		for (int col = 0; col < 2; ++col) {
			Novice::ScreenPrintf(x + col * kColumnWidth, y + row * kRowHeight, "%.02f", matrix.m[row][col]);
		}
	}
}

void Function::MatrixScreenPrintf(int x, int y, Matrix3x3 matrix) {
	for (int row = 0; row < 3; ++row) {
		for (int col = 0; col < 3; ++col) {
			Novice::ScreenPrintf(x + col * kColumnWidth, y + row * kRowHeight, "%.02f", matrix.m[row][col]);
		}
	}
}

void Function::Vector2ScreenPrintf(int x, int y, Vec2 vector2) {
	Novice::ScreenPrintf(x, y, "%.02f", vector2.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector2.y);
}