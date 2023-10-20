/*******************************************************************************
* �^�C�g��:		Battle�v���O����
* �v���O������:	battle.cpp
* �쐬��:		GP11A132 99 �O������
* �쐬��:		2021/04/26
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"
#include "battle.h"

/*******************************************************************************
* �}�N����`
*******************************************************************************/


/*******************************************************************************
* �\���̒�`
*******************************************************************************/


/*******************************************************************************
* �v���g�^�C�v�錾(����Ȋ֐���p�ӂ��Ă���܂���錾/�֐��̐�����)
*******************************************************************************/



/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/

BATTLE		bPlayer;			// �o�g���p�̃v���C���[���[�N
BATTLE		bEnemy;				// �o�g���p�̃G�l�~�[���[�N

int			winBattle = 0;		// �퓬�̏��������A1�Ȃ�v���C���[�̏����A2�Ȃ�G�l�~�[�̏���
int			turn = 1;			// �P�ԍŏ���DrawBattle()�̓X�L�b�v����חp

// �o�g���̏���������
void InitBattle(void)
{
	SetBattle(0);	// �o�g���̂O�Ԃŏ�����
}


// �o�g���̏I������
void UninitBattle(void)
{

}


// �o�g���̍X�V����
void UpdateBattle(void)
{
	// �o�g�����I�����Ă����烊�U���g�ֈړ�����
	if (winBattle != 0)
	{
		// �L�[���͑҂�
		rewind(stdin);
		(void)_getch();

		system("cls");
		SetMode(0);			// �Q�[�����[�h�����U���g�֑J��
		return;
	}

	// �v���C���[���G�l�~�[���U��
	if (bPlayer.hp > 0)
	{
		bEnemy.damage = rand() % bPlayer.atk;

		bEnemy.hp -= bEnemy.damage;
		if (bEnemy.hp < 1)
		{	// ���肪���񂾎��̏���
			bEnemy.hp = 0;
			winBattle = 1;
		}
	}

	// �G�l�~�[�̍U��
	if (bEnemy.hp > 0)
	{
		bPlayer.damage = rand() % bPlayer.atk;

		bPlayer.hp -= bPlayer.damage;
		if (bPlayer.hp < 1)
		{	// ���肪���񂾎��̏���
			bPlayer.hp = 0;
			winBattle = 2;
		}
	}



}


// �o�g���`�揈��
void DrawBattle(void)
{
	system("cls");

	// �o�g���̂P�^�[���ڂ������b�Z�[�W��\������
	if (turn > 0)
	{
		turn = 0;
		printf("%s��%s�Əo������I�I\n", &bPlayer.name[0], &bEnemy.name[0]);

		// �L�[���͑҂�
		rewind(stdin);
		(void)_getch();
		return;
	}

	// �v���C���[���̃��b�Z�[�W
	printf("%s��%s��%d�̃_���[�W��^�����I\n\n", &bPlayer.name[0], &bEnemy.name[0], bEnemy.damage);
	if (winBattle == 1)
	{
		printf("%s�̏����I�I", &bPlayer.name[0]);
		return;
	}

	// �L�[���͑҂�
	rewind(stdin);
	(void)_getch();


	// �G�l�~�[���̃��b�Z�[�W
	printf("%s��%s��%d�̃_���[�W��^�����I\n\n", &bEnemy.name[0], &bPlayer.name[0], bPlayer.damage);
	if (winBattle == 2)
	{
		printf("%s�̏����I�I", &bEnemy.name[0]);
		return;
	}

	// �L�[���͑҂�
	rewind(stdin);
	(void)_getch();
}


// �G�l�~�[�ԍ��������ɖ���Ă�������Ƀo�g���̏��������s��
void SetBattle(int no)
{
	PLAYER* player = GetPlayer();
	ENEMY* enemy = GetEnemy();

	// �����̔ԍ��ɂ���ăo�g���̎�ނ�ς��鏈��
	switch (no)
	{
	case 0:	// �X���C���Ƃ̐퓬
		strcpy(&bPlayer.name[0], "�v���C���[");
		bPlayer.hp      = 100;
		bPlayer.hp_max  = 100;
		bPlayer.atk     = 30;
		bPlayer.atk_max = 30;
		bPlayer.player  = &player[0];

		strcpy(&bEnemy.name[0], "�X���C��");
		bEnemy.hp      = 100;
		bEnemy.hp_max  = 100;
		bEnemy.atk     = 30;
		bEnemy.atk_max = 30;
		bEnemy.enemy = &enemy[no];
		break;

	case 1:	// ���{�X��
		break;

	case 2:	// �{�X��
		break;

	default:
		break;
	}

	winBattle = 0;		// ����������������
	turn = 1;			// �����ŏ��̃^�[��
}


// �o�g���̏����������擾����
int GetBattleResult(void)
{
	return winBattle;
}


