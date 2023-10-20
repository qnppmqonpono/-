/*******************************************************************************
* タイトル:		プレイヤープログラム
* プログラム名:	player.cpp
* 作成者:		GP11A132 99 外岡高明
* 作成日:		2022/04/18
*******************************************************************************/



/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"
#include "player.h"


/*******************************************************************************
* マクロ定義
*******************************************************************************/


/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
int GetFieldData(int y, int x);


/*******************************************************************************
* グローバル変数
*******************************************************************************/
PLAYER player[PLAYER_MAX];


/*******************************************************************************
 関数名:	
 引数　:	
 戻り値:	
 説明　:	
*******************************************************************************/
// プレイヤーの初期化処理
void InitPlayer(void)
{
	player[0].x = 5;
	player[0].y = 5;

}


// プレイヤーの終了処理
void UninitPlayer(void)
{



}


// プレイヤーの更新処理
void UpdatePlayer(void)
{
	// 処理を行う前にキー入力があったかをチェックする
	if (_kbhit() == 0)
	{	// キー入力がなければ何もしない
		system("cls");	// 画面クリア
		return;
	}

	// 移動する前に現在の座標を保存しておく
	int opx = player[0].x;
	int opy = player[0].y;

	// キー入力処理
	int key;
	rewind(stdin);
	key = _getch();
	if ((key == 0) || (key == 0xe0))
	{
		key = _getch();
	}

	system("cls");	// 画面クリア

	switch (key)
	{
	case 'a':	// 左へ移動
	case 0x4b:
		player[0].x--;
		break;

	case 'd':	// 右へ移動
	case 0x4d:
		player[0].x++;
		break;

	case 'w':	// 上へ移動
	case 0x48:
		player[0].y--;
		break;

	case 's':	// 下へ移動
	case 0x50:
		player[0].y++;
		break;
	}

	// 移動後の座標が何になっているのか調べる
//	switch (field[player[0].y][player[0].x])
	switch( GetFieldData(player[0].y, player[0].x) )
	{
	case 0:			// 何もしない
		break;

	case 1:			// 障害物だから元の位置へ戻す
		player[0].x = opx;
		player[0].y = opy;
		break;

	}

}


// プレイヤーの描画処理
void DrawPlayer(void)
{
	printf("P");
}



// プレイヤー変数の先頭アドレスの取得関数
PLAYER* GetPlayer(void)
{
	return &player[0];
}





