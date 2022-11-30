#include"Bookmark.h"
#include<iostream>

int main() {
	//객체 생성
	Bookmark* bookmark = new Bookmark();
	bookmark->printscreen();
	//x를 눌러 메인화면을 나갔을 때
	system("cls");
	system("pause");
	cout << "진짜 종료하시겠습니까?" << endl << "네(enter) / 아니요(backspace)" << endl;
	int temp_input;
	for (;;) {
		temp_input = _getch();
		//enter
		if (temp_input == 13) break;
		//backspace
		else if (temp_input == 8) {
			bookmark->printscreen();
			system("cls");
			cout << "진짜 종료하시겠습니까?" << endl << "네(enter) / 아니요(backspace)" << endl;
		}
		else continue;
	}
	delete bookmark;
	return 0;
}