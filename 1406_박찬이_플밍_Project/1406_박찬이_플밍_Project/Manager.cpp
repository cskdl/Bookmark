#include"Manager.h"

void Manager::gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void Manager::init_C() {
	//57 * 20(세로는 한 칸이 길다 대략 가로 2칸/ 가로로 긴 직사각형 모양)
	system("mode con: cols=57 lines=20");
	SetConsoleTitle(TEXT("나에게진짜삭제할거냐고물어봐주는북마크"));
}