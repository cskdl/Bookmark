#include"Manager.h"

void Manager::gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void Manager::init_C() {
	//57 * 20(���δ� �� ĭ�� ��� �뷫 ���� 2ĭ/ ���η� �� ���簢�� ���)
	system("mode con: cols=57 lines=20");
	SetConsoleTitle(TEXT("��������¥�����Ұųİ�����ִºϸ�ũ"));
}