#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include<codecvt>
#include<fstream>
#include<vector>
#include<conio.h>
#include"Manager.h"

//���� ����¿��� ������ ����
#define filepath "URL.txt"

using namespace std;

class Bookmark : public Manager {
private:
	int full; //�� ���� -1, �� ���̸� 1, �� �� �ƴϸ� 0 / �� ������ ���۵ǹǷ� -1�� �ʱ�ȭ �ʿ�
	int index;	//���Ϳ��� ���� ������ �� �� �ε��� / �ּ�, ���� ������ ����ǹǷ� 1�� �ʱ�ȭ �ʿ�
	vector<string> urls;	//���� ������ �����ϴ� ����

	//����â ����
	void drawselect();	//����â �׸��Ⱑ �ݺ��� �߰�
	//�ּ� �Է� â
	void saveurl();
	//�ּ� ���� �Է� â
	void savename();
	//saveurl, savename�� ȣ���� filepath�� ����(�ϸ�ũ �߰� ���)
	void saveboth();
	//�ϸ�ũ ����
	void amendBookmark();
	//�ϸ�ũ ����
	void deleteurl();
	//���Ͽ� �ִ� �ϸ�ũ ������ ���ͷ� ��ȯ
	//���Ͽ� �ִ� �ϸ�ũ ������ �������(urls)�� ����
	void filelist();
public:
	//�⺻ ȭ�� ���
	void printscreen();
	//��ü ������ �ܼ� �ʱ�ȭ
	Bookmark() : full(-1), index(1) { init_C(); }
	~Bookmark() {}
};