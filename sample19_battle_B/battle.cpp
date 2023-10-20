/*******************************************************************************
* タイトル:		Battleプログラム
* プログラム名:	battle.cpp
* 作成者:		GP11A132 99 外岡高明
* 作成日:		2021/04/26
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"
#include "battle.h"

/*******************************************************************************
* マクロ定義
*******************************************************************************/


/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言(こんな関数を用意してありますよ宣言/関数の説明書)
*******************************************************************************/



/*******************************************************************************
* グローバル変数
*******************************************************************************/

BATTLE		bPlayer;			// バトル用のプレイヤーワーク
BATTLE		bEnemy;				// バトル用のエネミーワーク

int			winBattle = 0;		// 戦闘の勝ち負け、1ならプレイヤーの勝ち、2ならエネミーの勝ち
int			turn = 1;			// １番最初のDrawBattle()はスキップする為用

// バトルの初期化処理
void InitBattle(void)
{
	SetBattle(0);	// バトルの０番で初期化
}


// バトルの終了処理
void UninitBattle(void)
{

}


// バトルの更新処理
void UpdateBattle(void)
{
	// バトルが終了していたらリザルトへ移動する
	if (winBattle != 0)
	{
		// キー入力待ち
		rewind(stdin);
		(void)_getch();

		system("cls");
		SetMode(0);			// ゲームモードをリザルトへ遷移
		return;
	}

	// プレイヤーがエネミーを攻撃
	if (bPlayer.hp > 0)
	{
		bEnemy.damage = rand() % bPlayer.atk;

		bEnemy.hp -= bEnemy.damage;
		if (bEnemy.hp < 1)
		{	// 相手が死んだ時の処理
			bEnemy.hp = 0;
			winBattle = 1;
		}
	}

	// エネミーの攻撃
	if (bEnemy.hp > 0)
	{
		bPlayer.damage = rand() % bPlayer.atk;

		bPlayer.hp -= bPlayer.damage;
		if (bPlayer.hp < 1)
		{	// 相手が死んだ時の処理
			bPlayer.hp = 0;
			winBattle = 2;
		}
	}



}


// バトル描画処理
void DrawBattle(void)
{
	system("cls");

	// バトルの１ターン目だけメッセージを表示する
	if (turn > 0)
	{
		turn = 0;
		printf("%sは%sと出会った！！\n", &bPlayer.name[0], &bEnemy.name[0]);

		// キー入力待ち
		rewind(stdin);
		(void)_getch();
		return;
	}

	// プレイヤー側のメッセージ
	printf("%sは%sへ%dのダメージを与えた！\n\n", &bPlayer.name[0], &bEnemy.name[0], bEnemy.damage);
	if (winBattle == 1)
	{
		printf("%sの勝ち！！", &bPlayer.name[0]);
		return;
	}

	// キー入力待ち
	rewind(stdin);
	(void)_getch();


	// エネミー側のメッセージ
	printf("%sは%sへ%dのダメージを与えた！\n\n", &bEnemy.name[0], &bPlayer.name[0], bPlayer.damage);
	if (winBattle == 2)
	{
		printf("%sの勝ち！！", &bEnemy.name[0]);
		return;
	}

	// キー入力待ち
	rewind(stdin);
	(void)_getch();
}


// エネミー番号を引数に貰ってそれを元にバトルの初期化を行う
void SetBattle(int no)
{
	PLAYER* player = GetPlayer();
	ENEMY* enemy = GetEnemy();

	// 引数の番号によってバトルの種類を変える処理
	switch (no)
	{
	case 0:	// スライムとの戦闘
		strcpy(&bPlayer.name[0], "プレイヤー");
		bPlayer.hp      = 100;
		bPlayer.hp_max  = 100;
		bPlayer.atk     = 30;
		bPlayer.atk_max = 30;
		bPlayer.player  = &player[0];

		strcpy(&bEnemy.name[0], "スライム");
		bEnemy.hp      = 100;
		bEnemy.hp_max  = 100;
		bEnemy.atk     = 30;
		bEnemy.atk_max = 30;
		bEnemy.enemy = &enemy[no];
		break;

	case 1:	// 中ボス戦
		break;

	case 2:	// ボス戦
		break;

	default:
		break;
	}

	winBattle = 0;		// 勝ち負けを初期化
	turn = 1;			// 次が最初のターン
}


// バトルの勝ち負けを取得する
int GetBattleResult(void)
{
	return winBattle;
}


