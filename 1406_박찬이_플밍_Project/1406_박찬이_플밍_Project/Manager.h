#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include<codecvt>
#include<fstream>
#include<vector>
#include<conio.h>

using namespace std;

//프로그램 실행(>>북마크 기능 구현)에 필요한 것들을 담은 부모클래스
class Manager {
protected:
	//유저 입력
	int input;

	//콘솔 초기화
	void init_C();
	//커서 이동
	void gotoxy(int x, int y);
	Manager() : input(0) {}
	~Manager() {}
};