#pragma once
class gameNode
{
public:
	gameNode();
	virtual ~gameNode();

	//����ũ�μ���Ʈ ���� ����� ��ȯ��
	//S_OK, E_FAIL, SUCCDED ������ �ʱ�ȭ�� �ߵƴ��� �ƴ��� ���â�� ȣ��

	virtual HRESULT init();			//�ʱ�ȭ ���� �Լ�
	virtual void release();			//�޸� ���� �Լ�
	virtual void update();			//���� ���� �Լ�
	virtual void render(HDC hdc);	//�׸��� ���� �Լ�

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

};

