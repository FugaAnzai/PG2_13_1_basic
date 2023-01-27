#include <Novice.h>
#include <stdlib.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Screen.h"
#include "keyInput.h"
#include "Vec2.h"
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "Function.h"
#include "Rand.h"
#include "Enemy.h"
#include "Player.h"

const char kWindowTitle[] = "LC1A_02_アンザイフウガ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	//Screenクラスのインスタンス
	Screen screen(1280, 720);

	//変数の初期化

	Enemy enemy[2];
	enemy[1].Init(Vec2(100, 100));

	Player player(&screen);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		
		CheckKey();

		///
		/// ↓更新処理ここから
		///

		for (int i = 0; i < 2; i++) {
			enemy[i].Update();

			if (player.GetBullet().GetTransform().DistanceFrom(enemy[i].GetTransform()) < 35) {
				enemy[i].SetIsAlive(false);
			}

		}

		player.Update();

		//レンダリングパイプライン
		screen.Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		screen.DrawLine(Vec2(0, -20000), Vec2(0, 20000), RED);
		screen.DrawLine(Vec2(-20000, 0), Vec2(20000, 0), BLUE);

		for (int i = 0; i < 2; i++) {
			enemy[i].Draw(screen);
		}

		player.Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (TriggerKey(DIK_ESCAPE)) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
