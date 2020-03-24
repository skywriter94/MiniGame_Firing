#pragma once
#include "gameNode.h"
#include <iostream>

using namespace std;

class playGround : public gameNode
{
private:
	struct Target
	{
		RECT targetRect;
		bool display;
		bool hit;
	};
	Target target[10];
	int targetDisplayCount;
	int score, leftBullet;
	int turn, displayCheck;
	bool gameOver;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ ���� �Լ�
	virtual void release();			//�޸� ���� �Լ�
	virtual void update();			//���� ���� �Լ�
	virtual void render(HDC hdc);	//�׸��� ���� �Լ�
};