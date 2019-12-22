#ifndef BASE_H
#define BASE_H

#include<stdio.h>
#include <windows.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define BLACK    0
#define BLUE1    1
#define GREEN1   2
#define CYAN1    3
#define RED1     4
#define MAGENTA1 5
#define YELLOW1  6
#define GRAY1    7
#define GRAY2    8
#define BLUE2    9
#define GREEN2   10
#define CYAN2    11
#define RED2     12
#define MAGENTA2 13
#define YELLOW2  14
#define WHITE    15

int totalPrice = 0;

HANDLE COUT = 0;    // 콘솔 출력 장치
HANDLE CIN = 0;        // 콘솔 입력 장치 

//void removeCursor() { // 커서를 안보이게 한다
//
//	CONSOLE_CURSOR_INFO curInfo;
//	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
//	curInfo.bVisible = 0;
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
//}

// 0넣으면숨기기, 1넣으면보이기
void cursor_view(char s)      
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = s;
	ConsoleCursor.dwSize = 2;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);

}

void textcolor(int fg_color, int bg_color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

void gotoxy(int x, int y) //내가 원하는 위치로 커서 이동
{
	COORD pos; // Windows.h 에 정의
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void draw_box(int x1, int y1, int x2, int y2)
{
	int x, y;
	textcolor(BLACK, WHITE);
	gotoxy(x1, y1);
	for (y = y1; y <= y2; y++) {
		for (x = x1; x <= x2; x++) {
			printf(" ");
		}
		gotoxy(x1, y);
	}
	textcolor(WHITE, BLACK);
}

typedef struct Coordi//좌표 형식 정의
{
	double x;
	double y;
}Coordi;

int be_input() {
	INPUT_RECORD input_record;
	DWORD input_count;
	PeekConsoleInput(CIN, &input_record, 1, &input_count);
	return input_count;
}

int get_input(WORD *vkey, COORD *pos)
{
	INPUT_RECORD input_record;
	DWORD input_count;
	ReadConsoleInput(CIN, &input_record, 1, &input_count);
	switch (input_record.EventType)
	{
	case MOUSE_EVENT:
		if (pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED))
		{
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			GetConsoleScreenBufferInfo(COUT, &csbi);
			*pos = input_record.Event.MouseEvent.dwMousePosition;
			pos->X -= csbi.srWindow.Left;
			pos->Y -= csbi.srWindow.Top;
			return MOUSE_EVENT;
		}
		break;
	} //    FlushConsoleInputBuffer(CIN);   
	return 0;
}

void cls()
{
	system("cls");
	system("COLOR 0f");
}
#endif