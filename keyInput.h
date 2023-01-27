#pragma once
#include <Novice.h>

//毎ループキーの確認
void CheckKey();
//キー入力
bool EmptyKey(int Keys);
bool TriggerKey(char Keys);
bool PressKey(int Keys);
bool ReleaseKey(int Keys);