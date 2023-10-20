/*******************************************************************************
* �^�C�g��:		�v���C���[�v���O����
* �v���O������:	player.cpp
* �쐬��:		GP11A132 99 �O������
* �쐬��:		2022/04/18
*******************************************************************************/



/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"
#include "player.h"


/*******************************************************************************
* �}�N����`
*******************************************************************************/


/*******************************************************************************
* �\���̒�`
*******************************************************************************/


/*******************************************************************************
* �v���g�^�C�v�錾
*******************************************************************************/
int GetFieldData(int y, int x);


/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/
PLAYER player[PLAYER_MAX];


/*******************************************************************************
 �֐���:	
 �����@:	
 �߂�l:	
 �����@:	
*******************************************************************************/
// �v���C���[�̏���������
void InitPlayer(void)
{
	player[0].x = 5;
	player[0].y = 5;

}


// �v���C���[�̏I������
void UninitPlayer(void)
{



}


// �v���C���[�̍X�V����
void UpdatePlayer(void)
{
	// �������s���O�ɃL�[���͂������������`�F�b�N����
	if (_kbhit() == 0)
	{	// �L�[���͂��Ȃ���Ή������Ȃ�
		system("cls");	// ��ʃN���A
		return;
	}

	// �ړ�����O�Ɍ��݂̍��W��ۑ����Ă���
	int opx = player[0].x;
	int opy = player[0].y;

	// �L�[���͏���
	int key;
	rewind(stdin);
	key = _getch();
	if ((key == 0) || (key == 0xe0))
	{
		key = _getch();
	}

	system("cls");	// ��ʃN���A

	switch (key)
	{
	case 'a':	// ���ֈړ�
	case 0x4b:
		player[0].x--;
		break;

	case 'd':	// �E�ֈړ�
	case 0x4d:
		player[0].x++;
		break;

	case 'w':	// ��ֈړ�
	case 0x48:
		player[0].y--;
		break;

	case 's':	// ���ֈړ�
	case 0x50:
		player[0].y++;
		break;
	}

	// �ړ���̍��W�����ɂȂ��Ă���̂����ׂ�
//	switch (field[player[0].y][player[0].x])
	switch( GetFieldData(player[0].y, player[0].x) )
	{
	case 0:			// �������Ȃ�
		break;

	case 1:			// ��Q�������猳�̈ʒu�֖߂�
		player[0].x = opx;
		player[0].y = opy;
		break;

	}

}


// �v���C���[�̕`�揈��
void DrawPlayer(void)
{
	printf("P");
}



// �v���C���[�ϐ��̐擪�A�h���X�̎擾�֐�
PLAYER* GetPlayer(void)
{
	return &player[0];
}




