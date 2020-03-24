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

	virtual HRESULT init();			//초기화 전용 함수
	virtual void release();			//메모리 해제 함수
	virtual void update();			//연산 전용 함수
	virtual void render(HDC hdc);	//그리기 전용 함수
};