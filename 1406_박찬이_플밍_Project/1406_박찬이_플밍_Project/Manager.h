#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include<codecvt>
#include<fstream>
#include<vector>
#include<conio.h>

using namespace std;

//���α׷� ����(>>�ϸ�ũ ��� ����)�� �ʿ��� �͵��� ���� �θ�Ŭ����
class Manager {
protected:
	//���� �Է�
	int input;

	//�ܼ� �ʱ�ȭ
	void init_C();
	//Ŀ�� �̵�
	void gotoxy(int x, int y);
	Manager() : input(0) {}
	~Manager() {}
};