#include "Screen.h"
#include <Novice.h>
#include "Rand.h" 

void Screen::Update() {

	camera.Update();

	vpVpMatrix = Matrix3x3::MakeIdentityMatrix();
	viewMatrix = Matrix3x3::Inverse(camera.GetMatrix());
	vpVpMatrix *= viewMatrix;
	vpVpMatrix *= orthoMatrix;
	vpVpMatrix *= viewportMatrix;
}

void Screen::DrawLine(const Vec2& pos1, const Vec2& pos2, unsigned int color) {

	Vec2 screenPos1;
	Vec2 screenPos2;

	screenPos1 = (pos1 * vpVpMatrix) + camera.GetShake();
	screenPos2 = (pos2 * vpVpMatrix) + camera.GetShake();

	Novice::DrawLine(screenPos1.x, screenPos1.y, screenPos2.x, screenPos2.y, color);

}

void Screen::DrawEllipse(const Vec2& pos, float radiusX, float radiusY, float angle, unsigned int color, FillMode fillMode) {

	Vec2 screenPos;

	screenPos = pos * vpVpMatrix + camera.GetShake();

	Novice::DrawEllipse(screenPos.x, screenPos.y, radiusX, radiusY, angle, color, fillMode);

}
void Screen::DrawTriangle(const Vec2& pos1, const Vec2& pos2, const Vec2& pos3, unsigned int color, FillMode fillMode) {

	Vec2 screenPos1;
	Vec2 screenPos2;
	Vec2 screenPos3;

	screenPos1 = (pos1 * vpVpMatrix) + camera.GetShake();
	screenPos2 = (pos2 * vpVpMatrix) + camera.GetShake();
	screenPos3 = (pos3 * vpVpMatrix) + camera.GetShake();

	Novice::DrawTriangle(screenPos1.x, screenPos1.y, screenPos2.x, screenPos2.y, screenPos3.x, screenPos3.y, color, fillMode);

}
void Screen::DrawBox(const Vec2& pos, int w, int h, float angle, unsigned int color, FillMode  fillMode) {

	Vec2 screenPos;

	screenPos = (pos * vpVpMatrix) + camera.GetShake();

	Novice::DrawBox(screenPos.x, screenPos.y, w, h, angle, color, fillMode);

}
void Screen::DrawQuad(const Vec2& pos, int GraphX, int GraphY, float angle, int SIZEX, int SIZEY, int textureHandle, unsigned int color, float magX, float magY) {

	Matrix3x3 scale = Matrix3x3::MakeScalingMatrix(magX, magY);

	Vec2 Lefttop((float)(-SIZEX / 2), (SIZEY / 2));
	Vec2 Righttop((float)(SIZEX / 2), (SIZEY / 2));
	Vec2 Leftbottom((float)(-SIZEX / 2), (-SIZEY / 2));
	Vec2 Rightbottom((float)(SIZEX / 2), (-SIZEY / 2));

	Vec2 screenLefttop((float)(-SIZEX / 2), (SIZEY / 2));
	Vec2 screenRighttop((float)(SIZEX / 2), (SIZEY / 2));
	Vec2 screenLeftbottom((float)(-SIZEX / 2), (-SIZEY / 2));
	Vec2 screenRightbottom((float)(SIZEX / 2), (-SIZEY / 2));

	screenLefttop = ((pos + (Lefttop * scale)) * vpVpMatrix) + camera.GetShake();
	screenRighttop = ((pos + (Righttop * scale)) * vpVpMatrix) + camera.GetShake();
	screenLeftbottom = ((pos + (Leftbottom * scale)) * vpVpMatrix) + camera.GetShake();
	screenRightbottom = ((pos + (Rightbottom * scale)) * vpVpMatrix) + camera.GetShake();

	Novice::DrawQuad(screenLefttop.x, screenLefttop.y, screenRighttop.x, screenRighttop.y, screenLeftbottom.x, screenLeftbottom.y, screenRightbottom.x, screenRightbottom.y, GraphX, GraphY, SIZEX, SIZEY, textureHandle, color);

}
void Screen::DrawQuad(const Vec2& leftTop, const Vec2& rightTop, const Vec2& leftBottom, const Vec2& rightBottom, int GraphX, int GraphY, float angle, int SIZEX, int SIZEY, int textureHandle, unsigned int color) {

	Vec2 screenLefttop((float)(-SIZEX / 2), (SIZEY / 2));
	Vec2 screenRighttop((float)(SIZEX / 2), (SIZEY / 2));
	Vec2 screenLeftbottom((float)(-SIZEX / 2), (-SIZEY / 2));
	Vec2 screenRightbottom((float)(SIZEX / 2), (-SIZEY / 2));

	screenLefttop = (leftTop * vpVpMatrix) + camera.GetShake();
	screenRighttop = (rightTop * vpVpMatrix) + camera.GetShake();
	screenLeftbottom = (leftBottom * vpVpMatrix) + camera.GetShake();
	screenRightbottom = (rightBottom * vpVpMatrix) + camera.GetShake();

	Novice::DrawQuad(screenLefttop.x, screenLefttop.y, screenRighttop.x, screenRighttop.y, screenLeftbottom.x, screenLeftbottom.y, screenRightbottom.x, screenRightbottom.y, GraphX, GraphY, SIZEX, SIZEY, textureHandle, color);


}

//void Screen::DrawQuadMap(const Vec2& pos, int animestart, int SIZE, int textureHandle, unsigned int color = WHITE);
//void Screen::DrawSprite(const Vec2& pos, int textureHandle, float scaleX, float scaleY, float angle, unsigned int color);
//void Screen::DrawSpriteRect(const Vec2& pos, int  srcX, int srcY, int  srcW, int srcH, int textureHandle, float scaleX, float scaleY, float angle, unsigned int color);

//void Screen::DrawLine(float x1, float y1, float x2, float y2,unsigned int color) {
//	Novice::DrawLine(x1 + Camerashake.x - Scroll.x, -y1 + OriginY + Camerashake.y + Scroll.y, x2 + Camerashake.x - Scroll.x, -y2 + OriginY + Camerashake.y + Scroll.y, color);
//}
//
//void Screen::DrawEllipse(float x, float y, float radiusX, float radiusY, float angle, unsigned int color, FillMode fillMode) {
//	Novice::DrawEllipse(x + Camerashake.x - Scroll.x, -y + OriginY + Camerashake.y + Scroll.y, radiusX, radiusY, angle, color, fillMode);
//}
//
//void Screen::DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, unsigned int color, FillMode fillMode) {
//	Novice::DrawTriangle(x1 + Camerashake.x - Scroll.x, -y1 + OriginY + Camerashake.y, x2 + Camerashake.x - Scroll.x, -y2 + OriginY + Camerashake.y, x3 + Camerashake.x - Scroll.x, -y3 + OriginY + Camerashake.y + Scroll.y, color, fillMode);
//}
//
//void Screen::DrawBox(float x, float y, int w, int h, float angle, unsigned int color, FillMode  fillMode) {
//	Novice::DrawBox(x + Camerashake.x - Scroll.x, -y + OriginY + Camerashake.y + Scroll.y, w, h, angle, color, fillMode);
//}
//
//void Screen::DrawQuad(float x, float y,int GraphX, int GraphY, float angle, int SIZEX, int SIZEY, int textureHandle, unsigned int color) {
//	
//	Vec2 center(x, y);
//
//	Vec2 lefttop((float)(-SIZEX / 2), (SIZEY / 2));
//	Vec2 righttop((float)(SIZEX / 2), (SIZEY / 2));
//	Vec2 leftbottom((float)(-SIZEX / 2), (-SIZEY / 2));
//	Vec2 rightbottom((float)(SIZEX / 2), (-SIZEY / 2));
//
//
//	lefttop = lefttop.Rotated(angle) + center;
//	righttop = righttop.Rotated(angle) + center;
//	leftbottom = leftbottom.Rotated(angle) + center;
//	rightbottom = rightbottom.Rotated(angle) + center;
//
//	Novice::DrawQuad(
//
//	
//
//		lefttop.x + Camerashake.x - Scroll.x,
//		-lefttop.y + OriginY + Camerashake.y + Scroll.y,
//		righttop.x + Camerashake.x - Scroll.x,
//		-righttop.y + OriginY + Camerashake.y + Scroll.y,
//		leftbottom.x + Camerashake.x - Scroll.x,
//		-leftbottom.y + OriginY + Camerashake.y + Scroll.y,
//		rightbottom.x + Camerashake.x - Scroll.x,
//		-rightbottom.y + OriginY + Camerashake.y + Scroll.y,
//		GraphX, GraphY, SIZEX, SIZEY, textureHandle, color);
//}
//
//void Screen::DrawQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int GraphX, int GraphY, float angle, int SIZEX, int SIZEY, int textureHandle, unsigned int color) {
//
//	Vec2 lefttop(x1, y1);
//	Vec2 righttop(x2, y2);
//	Vec2 leftbottom(x3, y3);
//	Vec2 rightbottom(x4, y4);
//
//	lefttop = lefttop.Rotated(angle);
//	righttop = righttop.Rotated(angle);
//	leftbottom = leftbottom.Rotated(angle);
//	rightbottom = rightbottom.Rotated(angle);
//
//	Novice::DrawQuad(
//
//		lefttop.x + Camerashake.x - Scroll.x,
//		-lefttop.y + OriginY + Camerashake.y + Scroll.y,
//		righttop.x + Camerashake.x - Scroll.x,
//		-righttop.y + OriginY + Camerashake.y + Scroll.y,
//		leftbottom.x + Camerashake.x - Scroll.x,
//		-leftbottom.y + OriginY + Camerashake.y + Scroll.y,
//		rightbottom.x + Camerashake.x - Scroll.x,
//		-rightbottom.y + OriginY + Camerashake.y + Scroll.y,
//		GraphX, GraphY, SIZEX, SIZEY, textureHandle, color);
//}

//void Screen::DrawQuadMap(float x, float y, int animestart, int SIZE, int textureHandle, unsigned int color) {
//	Novice::DrawQuad(
//		x + Camerashake.x - Scroll.x,
//		-(y + SIZE) + OriginY + Camerashake.y + Scroll.y,
//		(x + SIZE) + Camerashake.x - Scroll.x,
//		-(y + SIZE) + OriginY + Camerashake.y + Scroll.y,
//		x + Camerashake.x - Scroll.x,
//		-y + OriginY + Camerashake.y + Scroll.y,
//		(x + SIZE) + Camerashake.x - Scroll.x,
//		-y + OriginY + Camerashake.y + Scroll.y,
//		animestart * SIZE, 0, SIZE, SIZE, textureHandle, color);
//}

//void Screen::DrawSprite(float destX, float destY, int textureHandle, float scaleX, float scaleY, float angle, unsigned int color) {
//	Novice::DrawSprite(destX + Camerashake.x - Scroll.x, -destY + OriginY + Camerashake.y, textureHandle, scaleX, scaleY, angle, color);
//}
//
//void Screen::DrawSpriteRect(float destX, float destY, int  srcX, int srcY, int  srcW, int srcH, int textureHandle, float scaleX, float scaleY, float angle, unsigned int color) {
//	Novice::DrawSpriteRect(destX + Camerashake.x - Scroll.x, -destY + OriginY + Camerashake.y, srcX, srcY, srcW, srcH, textureHandle, scaleX, scaleY, angle, color);
//}

