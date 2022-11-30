#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include<codecvt>
#include<fstream>
#include<vector>
#include<conio.h>
#include"Manager.h"

//파일 입출력에서 내용을 저장
#define filepath "URL.txt"

using namespace std;

class Bookmark : public Manager {
private:
	int full; //맨 위면 -1, 맨 밑이면 1, 둘 다 아니면 0 / 맨 위에서 시작되므로 -1로 초기화 필요
	int index;	//벡터에서 값을 가져올 때 쓸 인덱스 / 주소, 설명 순으로 진행되므로 1로 초기화 필요
	vector<string> urls;	//파일 내용을 저장하는 벡터

	//선택창 구현
	void drawselect();	//선택창 그리기가 반복돼 추가
	//주소 입력 창
	void saveurl();
	//주소 설명 입력 창
	void savename();
	//saveurl, savename을 호출해 filepath에 저장(북마크 추가 기능)
	void saveboth();
	//북마크 수정
	void amendBookmark();
	//북마크 삭제
	void deleteurl();
	//파일에 있는 북마크 내용을 벡터로 반환
	//파일에 있는 북마크 내용을 멤버변수(urls)에 저장
	void filelist();
public:
	//기본 화면 출력
	void printscreen();
	//객체 생성시 콘솔 초기화
	Bookmark() : full(-1), index(1) { init_C(); }
	~Bookmark() {}
};