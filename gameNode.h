#pragma once
class gameNode
{
public:
	gameNode();
	virtual ~gameNode();

	//마이크로소프트 전용 디버깅 반환자
	//S_OK, E_FAIL, SUCCDED 등으로 초기화가 잘됐는지 아닌지 출력창에 호출

	virtual HRESULT init();			//초기화 전용 함수
	virtual void release();			//메모리 해제 함수
	virtual void update();			//연산 전용 함수
	virtual void render(HDC hdc);	//그리기 전용 함수

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

};

