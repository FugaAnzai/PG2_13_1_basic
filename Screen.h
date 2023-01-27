#pragma once
#include <Novice.h>
#include "Vec2.h"
#include "Matrix3x3.h"
#include "Camera.h"

class Screen
{
public:
	const int ScreenWidth;
	const int ScreenHeight;

	Matrix3x3 viewMatrix;
	Matrix3x3 orthoMatrix;
	Matrix3x3 viewportMatrix;
	Matrix3x3 vpVpMatrix;

	Camera camera;


	//コンストラクタ
public:
	Screen(int width,int height) : ScreenWidth(width),ScreenHeight(height) {
		
		viewMatrix = Matrix3x3::MakeIdentityMatrix();
		orthoMatrix = Matrix3x3::MakeOrthoGraphicMatrix(Vec2(-((float)width / 2), ((float)height / 2)), Vec2((float)width / 2, -((float)height / 2)));
		viewportMatrix = Matrix3x3::MakeViewportMatrix(Vec2(0, 0), width, height);
		vpVpMatrix = Matrix3x3::MakeIdentityMatrix();
	}

	void Update();

	//値の設定

	//ワールド座標での描画
	void DrawLine(const Vec2& pos1, const Vec2& pos2, unsigned int color);
	void DrawEllipse(const Vec2& pos, float radiusX, float radiusY, float angle, unsigned int color, FillMode fillMode);
	void DrawTriangle(const Vec2& pos1, const Vec2& pos2, const Vec2& pos3, unsigned int color, FillMode fillMode);
	void DrawBox(const Vec2& pos,int w, int h,float angle,unsigned int color,FillMode  fillMode);
	void DrawQuad(const Vec2& pos, int GraphX, int GraphY,float angle, int SIZEX, int SIZEY, int textureHandle, unsigned int color, float magX = 1.0f, float magY = 1.0f);
	void DrawQuad(const Vec2& leftTop, const Vec2& rightTop, const Vec2& leftBottom, const Vec2& rightBottom, int GraphX, int GraphY, float angle, int SIZEX, int SIZEY, int textureHandle, unsigned int color);
	void DrawQuadMap(const Vec2& pos, int animestart, int SIZE, int textureHandle, unsigned int color = WHITE);
	void DrawSprite(const Vec2& pos, int textureHandle,float scaleX, float scaleY,float angle,unsigned int color);
	void DrawSpriteRect(const Vec2& pos, int  srcX, int srcY,int  srcW, int srcH,int textureHandle,float scaleX, float scaleY,float angle,unsigned int color);
};

