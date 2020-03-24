#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

HRESULT playGround::init()
{
	gameNode::init();
	displayCheck = turn = gameOver = score = targetDisplayCount = 0;
	leftBullet = 10;
	for (int i = 0; i < 10; i++)
	{
		target[i].display = false;
		target[i].hit = false;
		if (i <= 2) target[i].targetRect = RectMakeCenter(200 + (i * 300), WINSIZEY / 1.2, 100, 200); // ��
		else if (i <= 6) target[i].targetRect = RectMakeCenter(((i-2) * 200), WINSIZEY / 2, 75, 150); // ��
		else target[i].targetRect = RectMakeCenter(200 + ((i-5) * 100), WINSIZEY / 4, 50, 100); // ��
	}
	return S_OK;
}

void playGround::release()
{
	gameNode::release();

}

void playGround::update()
{
	gameNode::update();

	if (!gameOver)
	{
		++targetDisplayCount;
		if (targetDisplayCount > 90)
		{
			if (leftBullet == 0 || turn == 10)
			{
				gameOver = true;
			}
			++turn;
			targetDisplayCount = 0;
			for (int i = 0; i < 10; i++)
			{
				target[displayCheck].display = false;
				target[displayCheck].hit = false;

				if (turn == 1 || turn == 4 || turn == 7) // ��
				{
					displayCheck = rand() % 2 + 7;
					target[displayCheck].display = true;
					break;
				}
				else if (turn == 3 || turn == 6 || turn == 8 || turn == 10) // ��
				{
					displayCheck = rand() % 3 + 3;
					target[displayCheck].display = true;
					break;
				}
				else if (turn == 2 || turn == 5 || turn == 9) // ��
				{
					displayCheck = rand() % 3;
					target[displayCheck].display = true;
					break;
				}
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			--leftBullet;
			for (int i = 0; i <= 10; i++)
			{
				if (PtInRect(&target[i].targetRect, _ptMouse))
				{
					if (target[i].display)
					{
						if (!target[i].hit)
						{
							target[i].hit = true;
							++score;
						}
					}
				}
			}
			if (leftBullet == 0 || turn == 10)
			{
				gameOver = true;
			}
		}
	}
}

//����� �׷���!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void playGround::render(HDC hdc)
{
	for (int i = 0; i < 10; i++)
	{
		if (target[i].display)
		{
			Rectangle(hdc, target[i].targetRect.left, target[i].targetRect.top, target[i].targetRect.right, target[i].targetRect.bottom);
			if (target[i].hit)
			{
				HBRUSH brush, oldBrush;
				brush = CreateSolidBrush(RGB(255, 0, 0));
				oldBrush = (HBRUSH)SelectObject(hdc, brush);
				Rectangle(hdc, target[i].targetRect.left, target[i].targetRect.top, target[i].targetRect.right, target[i].targetRect.bottom);
				SelectObject(hdc, oldBrush);
				DeleteObject(brush);
			}
		}
		MoveToEx(hdc, target[i].targetRect.left - 10, target[i].targetRect.bottom, NULL);
		LineTo(hdc, target[i].targetRect.right + 10, target[i].targetRect.bottom);
	}

	char str[20], str2[25], str3[20];
	sprintf_s(str, "Score : %d", score);
	TextOut(hdc, WINSIZEX / 8, WINSIZEY / 8, str, strlen(str));

	sprintf_s(str2, "Left Bullet : %d", leftBullet);
	TextOut(hdc, WINSIZEX / 8, WINSIZEY / 8 + 20, str2, strlen(str2));

	if (turn != 11)
	{
		sprintf_s(str3, "<%d��° �õ�>", turn);
		TextOut(hdc, WINSIZEX / 8, WINSIZEY / 8 + 40, str3, strlen(str3));
	}
	else
	{
		sprintf_s(str3, "<%d��° �õ�>", turn - 1);
		TextOut(hdc, WINSIZEX / 8, WINSIZEY / 8 + 40, str3, strlen(str3));
	}

	if (gameOver)
		TextOut(hdc, WINSIZEX / 2, WINSIZEY / 2, "<���� ����!>", strlen("<���� ����!>"));
}