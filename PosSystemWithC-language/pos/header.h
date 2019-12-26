#ifndef HEADER_H
#define HEADER_H

#include"base.h"

//�޴� ����Ʈ
typedef struct menu {
	char name[20];
	int price;
	int count;
	struct menu *link;
	int table1;
	int table2;
	int table3;
	int table4;
	int table5;
	int table6;
}menu;

//�޴� �����
typedef struct headNode {
	int num;
	menu *head;
	menu *tail;
}headNode;

//���̺� ����ü
typedef struct table {
	int bill;
	int tableNum;
}table;

// �α��� ����ü
typedef struct Login {
	char ID[20];
	char PASSWD[20];
}Login;

// ������� ����ü ����Ʈ
typedef struct Manager {
	char Name[20];
	int Age;
	char PhoneNum[20];
	char RrNum[20];
	char Address[100];
	struct Manager *link;
}Manager;

// �޴� ����� ����Ʈ
typedef struct workerNode {
	int num;
	Manager *head;
	Manager *tail;
}workerNode;


headNode m;
table t1, t2, t3, t4, t5, t6;
workerNode m2;

//���漱��
void display_tableMenu(headNode *node, table *t);
void display_salesShape();
void display_sales(headNode *node);
void display_mainWorker(headNode *node);
void display_menuEdit(headNode *node);
void display_mainManager(headNode *node);
void transfert_main(headNode *node);
void login();
void commute_add(headNode *node);
void commute_view(headNode *node);
void delete(Manager **phead);
void manager(workerNode *node);

void read_count(headNode *node)
{
	FILE *fcount = fopen("count.txt", "r");
	menu *p = node->head;

	while (p != NULL) {
		fscanf(fcount, "%d", &(p->count));
		p = p->link;
	}
	fclose(fcount);
}

void write_count(menu *head)
{
	FILE *fcount = fopen("count.txt", "w");
	menu *p = head;
	while (p != NULL) {
		fprintf(fcount, "%d\n", p->count);
		p = p->link;
	}
	fclose(fcount);
}

//����Ʈ �ʱ�ȭ
void init_head(headNode *node)
{
	node->num = 0;
	node->head = NULL;
	node->tail = NULL;
}

// ������� ����Ʈ �ʱ�ȭ
void init_worker(workerNode *node)
{
	node->num = 0;
	node->head = NULL;
	node->tail = NULL;
}

//���̺� ���� �ʱ�ȭ
void init_table(table *t, int tableNum)
{
	t->bill = 0;
	t->tableNum = tableNum;
}

// nozi���� ���� ����Ʈ
Manager *create_manager(char *Name, int Age, char *PhoneNum, char *RrNum, char *Address) {
	
	Manager *temp = (Manager*)malloc(sizeof(Manager));
	strcpy(temp->Name, Name);
	temp->Age = Age;
	strcpy(temp->PhoneNum, PhoneNum);
	strcpy(temp->RrNum, RrNum);
	strcpy(temp->Address, Address);
	temp->link = NULL;

	return temp;
}

// nozi���� �߰� ����Ʈ
void add_manager(workerNode *node, Manager *new_manager) {
	if (node->tail == NULL) {
		node->head = new_manager;
		node->tail = new_manager;
		node->num++;
	}
	else {
		node->tail->link = new_manager;
		node->tail = new_manager;
		node->num++;
	}
}

// nozió�� ����
void startNozi() {
	add_manager(&m2, create_manager("������", 24, "010-1234-5678", "951217-1234567", "����Ư���� ���ϱ�"));
	add_manager(&m2, create_manager("������", 24, "010-2345-6789", "950823-1345678", "����Ư���� ������"));
	add_manager(&m2, create_manager("����ȣ", 25, "010-2345-6789", "941004-1456789", "����Ư���� �����"));
}

// nozi������� UI
void iUI(Manager *head) {
	Manager *p = head;

	for (int a = 1; a < 4; a++) {
		if (p == NULL) {
			draw_box(30 * a - 22, 9, 30 * a + 3, 22);
		}
		else {
			draw_box(30 * a - 22, 9, 30 * a + 3, 22);
			textcolor(BLACK, WHITE);
			gotoxy(30 * a - 19, 13);
			printf("%s", p->Name);
			gotoxy(30 * a - 19, 14);
			printf("%d", p->Age);
			gotoxy(30 * a - 19, 15);
			printf("%s", p->PhoneNum);
			gotoxy(30 * a - 19, 16);
			printf("%s", p->RrNum);
			gotoxy(30 * a - 19, 17);
			printf("%s", p->Address);
			p = p->link;
		}
	}

	for (int a = 1; a < 4; a++) {
		if (p == NULL) {
			draw_box(30 * a - 22, 24, 30 * a + 3, 37);
		}
		else {
			draw_box(30 * a - 22, 24, 30 * a + 3, 37);
			textcolor(BLACK, WHITE);
			gotoxy(30 * a - 19, 28);
			printf("%s", p->Name);
			gotoxy(30 * a - 19, 29);
			printf("%d", p->Age);
			gotoxy(30 * a - 19, 30);
			printf("%s", p->PhoneNum);
			gotoxy(30 * a - 19, 31);
			printf("%s", p->RrNum);
			gotoxy(30 * a - 19, 32);
			printf("%s", p->Address);
			p = p->link;
		}
	}
}

// nozi�޴� UI
void mUI() {
	cls(); // ȭ�� �ʱ�ȭ
	draw_box(2, 2, 47, 18);
	gotoxy(20, 10);
	printf("���� �߰�");
	draw_box(53, 2, 98, 18);
	gotoxy(71, 10);
	printf("���� ����");
	draw_box(2, 21, 47, 38);
	gotoxy(20, 29);
	printf("���� ����");
	draw_box(53, 21, 98, 38);
	gotoxy(74, 29);
	printf("����");
}

// nozi�߰� �Լ�
void insert(workerNode *node) {
	char Name[20];
	int Age;
	char PhoneNum[20];
	char RrNum[20];
	char Address[100];

	cls(); // ȭ�� �ʱ�ȭ
	draw_box(29, 8, 69, 11);
	gotoxy(30, 9);
	textcolor(BLACK, WHITE);
	printf("   ���ο� ����� ������ �Է����ּ���.\n");
	draw_box(29, 12, 69, 13);
	gotoxy(30, 12);
	textcolor(BLACK, WHITE);
	printf("�̸�: "); scanf("%s", Name);
	draw_box(29, 14, 69, 15);
	gotoxy(30, 14);
	textcolor(BLACK, WHITE);
	printf("����: "); scanf("%d", &Age);
	draw_box(29, 16, 69, 17);
	gotoxy(30, 16);
	textcolor(BLACK, WHITE);
	printf("����ó: "); scanf("%s", PhoneNum);
	draw_box(29, 18, 69, 19);
	gotoxy(30, 18);
	textcolor(BLACK, WHITE);
	printf("�ֹι�ȣ: "); scanf("%s", RrNum);
	draw_box(29, 20, 69, 21);
	gotoxy(30, 20);
	textcolor(BLACK, WHITE);
	printf("�ּ�: ");
	while (getchar() != '\n');
	gets(Address);

	add_manager(&m2, create_manager(Name, Age, PhoneNum, RrNum, Address));
}

// nozi���� �Լ�
void change(workerNode *node) {
	Coordi c1;
	DWORD mode;
	WORD key;
	COORD pos;
	int x;      // ���콺�� x��ǥ �����  
	int y;      // ���콺�� y��ǥ �����  
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);     // ���콺 Ȱ��ȭ  
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	int j, k;
	Manager *p = node->head;

	draw_box(14, 2, 85, 7);
	gotoxy(30, 4);
	textcolor(BLACK, WHITE);
	printf("�����ϰ� ���� ��������� Ŭ�� ���ּ���");
	iUI(p); // �������UI

	while (1)
	{
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����        
				y = pos.Y;
				c1.x = x;
				c1.y = y;

				if (c1.x >= 9 && c1.x <= 34 && c1.y >= 10 && c1.y <= 22) {
					for (int a = 1; a < 1; a++) {
						p = p->link;
					}
					break;
				}
				else if (c1.x >= 39 && c1.x <= 64 && c1.y >= 10 && c1.y <= 22) {
					for (int a = 1; a < 2; a++) {
						p = p->link;
					}
					break;
				}
				else if (c1.x >= 69 && c1.x <= 94 && c1.y >= 10 && c1.y <= 22) {
					for (int a = 1; a < 3; a++) {
						p = p->link;
					}
					break;
				}
				else if (c1.x >= 9 && c1.x <= 34 && c1.y >= 25 && c1.y <= 37) {
					for (int a = 1; a < 4; a++) {
						p = p->link;
					}
					break;
				}
				else if (c1.x >= 39 && c1.x <= 64 && c1.y >= 25 && c1.y <= 37) {
					for (int a = 1; a < 5; a++) {
						p = p->link;
					}
					break;
				}
				else if (c1.x >= 69 && c1.x <= 94 && c1.y >= 25 && c1.y <= 37) {
					for (int a = 1; a < 6; a++) {
						p = p->link;
					}
					break;
				}
			}
		}
	}
	do {
		cls(); // ȭ���ʱ�ȭ
		cursor_view(1);
		draw_box(14, 7, 85, 10);
		gotoxy(15, 8);
		textcolor(BLACK, WHITE);
		printf("1.�̸�    2.����    3.����ó    4.�ֹι�ȣ    5.�ּ�    6. ���� >> ");
		draw_box(35, 14, 67, 21);
		gotoxy(36, 15);
		textcolor(BLACK, WHITE);
		printf("    �̸�: %s", p->Name);
		gotoxy(36, 16);
		textcolor(BLACK, WHITE);
		printf("    ����: %d", p->Age);
		gotoxy(36, 17);
		textcolor(BLACK, WHITE);
		printf("  ����ó: %s", p->PhoneNum);
		gotoxy(36, 18);
		textcolor(BLACK, WHITE);
		printf("�ֹι�ȣ: %s", p->RrNum);
		gotoxy(36, 19);
		textcolor(BLACK, WHITE);
		printf("    �ּ�: %s", p->Address);
		gotoxy(84, 8);
		textcolor(BLACK, WHITE);
		scanf("%d", &k);
		
		switch (k) {
		case 1: // �̸� ����
			gotoxy(46, 15);
			scanf("%s", p->Name);
			break;

		case 2: // ���� ����
			gotoxy(46, 16);
			scanf("%d", &p->Age);
			break;

		case 3: // ����ó ����
			gotoxy(46, 17);
			scanf("%s", p->PhoneNum);
			break;

		case 4: // �ֹι�ȣ ����
			gotoxy(46, 18);
			scanf("%s", p->RrNum);
			break;

		case 5: // �ּ� ����
			gotoxy(46, 19);
			scanf("%s", p->Address);
			break;

		case 6: // ����
			break;
		}
	} while (k != 6);
	cursor_view(0);
}

void display_clear(headNode *node, table *t)
{
	menu *p = node->head;

	system("cls");
	draw_box(25, 10, 75, 30);
	textcolor(BLACK, WHITE);
	gotoxy(45, 19);
	printf("���� �Ϸ�");
	textcolor(WHITE, BLACK);
	Sleep(1000);
	if (t->tableNum == 1) {
		while (p != NULL) {
			p->table1 = 0;
			p = p->link;
		}
	}
	else if (t->tableNum == 2) {
		while (p != NULL) {
			p->table2 = 0;
			p = p->link;
		}
	}
	else if (t->tableNum == 3) {
		while (p != NULL) {
			p->table3 = 0;
			p = p->link;
		}
	}
	else if (t->tableNum == 4) {
		while (p != NULL) {
			p->table4 = 0;
			p = p->link;
		}
	}
	else if (t->tableNum == 5) {
		while (p != NULL) {
			p->table5 = 0;
			p = p->link;
		}
	}
	else if (t->tableNum == 6) {
		while (p != NULL) {
			p->table6 = 0;
			p = p->link;
		}
	}
	init_table(t, t->tableNum);
}

// nozi���� �Լ�
void delete(Manager **phead) {

	int j, q;
	Manager *p = *phead;
	Manager *removed = p;

	cls(); // ȭ���ʱ�ȭ
	cursor_view(1);
	draw_box(14, 2, 85, 7);
	gotoxy(30, 4);
	textcolor(BLACK, WHITE);
	printf("�����ϰ� ���� ����� ��ȣ�� �Է����ּ���>> ");
	iUI(p); // �������UI
	gotoxy(74, 4);
	textcolor(RED2, WHITE);
	scanf("%d", &j); // �����ϴ� �����ȣ
	cls(); // ȭ���ʱ�ȭ
	draw_box(30, 23, 50, 30);
	gotoxy(37, 26);
	textcolor(BLACK, WHITE);
	printf("����(1)");
	draw_box(55, 23, 75, 30);
	gotoxy(62, 26);
	textcolor(BLACK, WHITE);
	printf("���(2)");
	textcolor(WHITE, BLACK);
	draw_box(30, 9, 75, 20);

	for (int a = 1; a < j; a++) {
		removed = removed->link;
	}

	for (int a = 1; a < j - 1; a++) {
		p = p->link;
	}

	gotoxy(38, 12);
	textcolor(BLACK, WHITE);
	printf("    �̸�: %s", removed->Name);
	gotoxy(38, 13);
	printf("    ����: %d", removed->Age);
	gotoxy(38, 14);
	printf("  ����ó: %s", removed->PhoneNum);
	gotoxy(38, 15);
	printf("�ֹι�ȣ: %s", removed->RrNum);
	gotoxy(38, 16);
	printf("    �ּ�: %s", removed->Address);
	
	gotoxy(49, 32);
	textcolor(BLACK, WHITE);
	printf(" >>     ");
	textcolor(RED2, WHITE);
	gotoxy(53, 32);
	scanf("%d", &q); // 1. ����, 2. ����
	cursor_view(0);

	if (q == 1) {
		if (j == 1) {
			*phead = (*phead)->link;
		}
		else {
			p->link = removed->link;
		}
		free(removed);
	}
}

// ���÷��� ������� �Լ�
void manager(workerNode *node) {
	Coordi c1;
	DWORD mode;
	WORD key;
	COORD pos;
	int x;      // ���콺�� x��ǥ �����  
	int y;      // ���콺�� y��ǥ �����  
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);     // ���콺 Ȱ��ȭ  
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	time_t now;
	struct tm *tp;
	char *weeks[] = { "��", "��", "ȭ", "��", "��", "��", "��" };

	Manager *p = node->head;

	draw_box(4, 2, 24, 7);
	draw_box(29, 2, 49, 7);
	draw_box(54, 2, 74, 7);
	draw_box(79, 2, 99, 7);

	textcolor(BLACK, WHITE);
	gotoxy(9, 4);
	printf("���� �߰�");
	gotoxy(34, 4);
	printf("���� ����");
	gotoxy(59, 4);
	printf("���� ����");
	gotoxy(85, 4);
	printf("���� ȭ��");
	iUI(p); // �������UI
	while (1)
	{
		time(&now);
		tp = localtime(&now);
		textcolor(WHITE, BLACK);
		gotoxy(2, 38);
		printf("%d��%d��%d��(%s) \%02d��%02d��%02d��", 1900 + tp->tm_year, tp->tm_mon + 1, tp->tm_mday, weeks[tp->tm_wday], tp->tm_hour, tp->tm_min, tp->tm_sec);

		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����        
				y = pos.Y;
				c1.x = x;
				c1.y = y;


				if (c1.x >= 4 && c1.x <= 24 && c1.y >= 2 && c1.y <= 7) {
					cls();
					insert(node); // ������� �߰�
					cls();
					manager(node);
				}
				else if (c1.x >= 29 && c1.x <= 49 && c1.y >= 2 && c1.y <= 7) {
					cls();
					change(node);
					cls();
					manager(node);
				}
				else if (c1.x >= 54 && c1.x <= 74 && c1.y >= 2 && c1.y <= 7) {
					cls();
					delete(&(node->head));
					cls();
					manager(node);
				}
				else if (c1.x >= 79 && c1.x <= 99 && c1.y >= 2 && c1.y <= 7) {
					cls();
					display_mainManager(&m);
				}
			}
		}
	}

}

//�޴� ����
menu *create_menu(char *name, int price)
{
	menu *temp = (menu*)malloc(sizeof(menu));
	temp->count = 0;
	temp->price = price;
	strcpy(temp->name, name);
	temp->link = NULL;
	temp->table1 = 0;
	temp->table2 = 0;
	temp->table3 = 0;
	temp->table4 = 0;
	temp->table5 = 0;
	temp->table6 = 0;

	return temp;
}

void write_sell(menu *head)
{
	FILE *fsell = fopen("sell.txt", "w");
	menu *p = head;
	fprintf(fsell, "\n");
	while (p != NULL) {
		fprintf(fsell, "%14s  :  %3d��  :  %7d\\\n", p->name, p->count, p->count*p->price);
		p = p->link;
	}
	fclose(fsell);
}


void read_sell(headNode *node)
{
	Coordi c1;
	DWORD mode;
	WORD key;
	COORD pos;
	int x;      // ���콺�� x��ǥ �����  
	int y;      // ���콺�� y��ǥ �����  
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);     // ���콺 Ȱ��ȭ  
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	int yy = 8;
	char a;
	FILE *fsell = fopen("sell.txt", "r");
	menu *p = node->head->link;
	menu *best = node->head;

	draw_box(8, 1, 95, 4);
	draw_box(8, 5, 95, 35);
	draw_box(86, 37, 100, 40);

	textcolor(BLACK, WHITE);
	gotoxy(45, 2);
	printf("�Ǹ���� ��Ȳ");
	gotoxy(89, 38);
	printf("����ȭ��");

	gotoxy(15, yy);
	while (1) {
		a = fgetc(fsell);
		printf("%c", a);

		if (a == '\n')
			gotoxy(15, yy++);
		if (feof(fsell) != 0) {
			fclose(fsell);
			break;
		}
	}
	while (p != NULL) {
		if (p->count > best->count) {
			best = p;
			p = p->link;
		}
		else {
			p = p->link;
		}
	}
	gotoxy(15, 30);
	textcolor(RED2, WHITE);
	printf("����Ʈ �޴� : %s", best->name);
	//����
	while (1)
	{
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����        
				y = pos.Y;
				c1.x = x;
				c1.y = y;
				if (c1.x >= 86 && c1.x <= 100 && c1.y >= 37 && c1.y <= 40) {
					cls();
					display_mainManager(node);
				}
			}
		}
	}
}

//�޴� �߰�
void add_menu(headNode *node, menu *new_menu)
{
	if (node->tail == NULL) {
		node->head = new_menu;
		node->tail = new_menu;
		node->num++;
	}
	else {
		node->tail->link = new_menu;
		node->tail = new_menu;
		node->num++;
	}
}

void file_menu(char *str, int n)
{
	FILE *fmenu = fopen("menu.txt", "a");
	fprintf(fmenu, "%s\n", str);
	fprintf(fmenu, "%d\n", n);
	fclose(fmenu);
}

void startAdd() {

	int cp, price;
	char name[20];
	FILE *fmenu = fopen("menu.txt", "r");
	
	while (1) {
		cp = fscanf(fmenu,"%s", name);
		if (cp == -1)
			break;
		fscanf(fmenu, "%d", &price);
		add_menu(&m, create_menu(name, price));
	}
	fclose(fmenu);
}

void cancel(menu *head, table *t, int num)
{
	menu *p = head;
	if (m.num < num + 1)
		return;
	for (int i = 0; i < num; i++) {
		p = p->link;
	}
	if (t->tableNum == 1) {
		if (p->table1 <= 0)
			return;
		p->table1--;
		t->bill -= p->price;
		totalPrice -= p->price;
		p->count--;
	}
	else if (t->tableNum == 2) {
		if (p->table2 <= 0)
			return;
		p->table2--;
		t->bill -= p->price;
		totalPrice -= p->price;
		p->count--;
	}
	else if (t->tableNum == 3) {
		if (p->table3 <= 0)
			return;
		p->table3--;
		t->bill -= p->price;
		totalPrice -= p->price;
		p->count--;
	}
	else if (t->tableNum == 4) {
		if (p->table4 <= 0)
			return;
		p->table4--;
		t->bill -= p->price;
		totalPrice -= p->price;
		p->count--;
	}
	else if (t->tableNum == 5) {
		if (p->table5 <= 0)
			return;
		p->table5--;
		t->bill -= p->price;
		totalPrice -= p->price;
		p->count--;
	}
	else if (t->tableNum == 6) {
		if (p->table6 <= 0)
			return;
		p->table6--;
		t->bill -= p->price;
		totalPrice -= p->price;
		p->count--;
	}
	write_sell(head);
	write_count(head);
}

void order(menu *head, table *t, int num)
{
	menu *p = head;
	if (m.num < num + 1)
		return;
	for (int i = 0; i < num; i++) {
		p = p->link;
	}
	if (t->tableNum == 1) {
		p->table1++;
		t->bill += p->price;
		totalPrice += p->price;
		p->count++;
	}
	else if (t->tableNum == 2) {
		p->table2++;
		t->bill += p->price;
		totalPrice += p->price;
		p->count++;
	}
	else if (t->tableNum == 3) {
		p->table3++;
		t->bill += p->price;
		totalPrice += p->price;
		p->count++;
	}
	else if (t->tableNum == 4) {
		p->table4++;
		t->bill += p->price;
		totalPrice += p->price;
		p->count++;
	}
	else if (t->tableNum == 5) {
		p->table5++;
		t->bill += p->price;
		totalPrice += p->price;
		p->count++;
	}
	else if (t->tableNum == 6) {
		p->table6++;
		t->bill += p->price;
		totalPrice += p->price;
		p->count++;
	}
	write_sell(head);
	write_count(head);
}

void display_cancelMenu(headNode *node, table *t)
{
	Coordi c1;
	DWORD mode;
	WORD key;
	COORD pos;
	int x;      // ���콺�� x��ǥ �����  
	int y;      // ���콺�� y��ǥ �����  
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);     // ���콺 Ȱ��ȭ  
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	int xx = 4; int yy = 5; int cnt = 1; int i = 2; // i : �ֹ���� ��� ��ġ
	time_t now;
	struct tm *tp;
	char *weeks[] = { "��", "��", "ȭ", "��", "��", "��", "��" };
	menu *p = node->head;
	menu *pp = node->head;
	//textcolor(WHITE, BLACK);
	draw_box(2, 1, 66, 36);
	draw_box(70, 1, 100, 36);
	draw_box(54, 37, 68, 40);
	draw_box(70, 37, 84, 40);
	draw_box(86, 37, 100, 40);
	textcolor(BLACK, WHITE);
	gotoxy(28, 1);
	printf("��        ��");
	gotoxy(80, 1);
	printf("�� �� �� ��");
	gotoxy(57, 38);
	printf("�߰��ϱ�");
	gotoxy(73, 38);
	printf("�����ϱ�");
	gotoxy(89, 38);
	printf("����ȭ��");
	while (p != NULL) {
		if (cnt == 9) {
			xx = 35;
			yy = 5;
		}
		gotoxy(xx, yy);
		printf("%15s : %5d\\ ", &p->name, p->price);
		p = p->link;
		cnt++;
		yy += 4;
	}

	if (t->tableNum == 1) {
		while (pp != NULL) {
			if (pp->table1 > 0) {
				gotoxy(70, i += 2);
				printf("%14s : %2d��   \n", pp->name, pp->table1);
			}
			pp = pp->link;
		}

		gotoxy(80, 35);
		printf("�� �� : %6d\\\n", t->bill);
	}
	else if (t->tableNum == 2) {
		while (pp != NULL) {
			if (pp->table2 > 0) {
				gotoxy(70, i += 2);
				printf("%14s : %2d��   \n", pp->name, pp->table2);
			}
			pp = pp->link;
		}


		gotoxy(80, 35);
		printf("�� �� : %6d\\\n", t->bill);
	}
	else if (t->tableNum == 3) {
		while (pp != NULL) {
			if (pp->table3 > 0) {
				gotoxy(70, i += 2);
				printf("%14s : %2d��   \n", pp->name, pp->table3);
			}
			pp = pp->link;
		}
		gotoxy(80, 35);
		printf("�� �� : %6d\\\n", t->bill);
	}
	else if (t->tableNum == 4) {
		while (pp != NULL) {
			if (pp->table4 > 0) {
				gotoxy(70, i += 2);
				printf("%14s : %2d��   \n", pp->name, pp->table4);
			}
			pp = pp->link;
		}
		gotoxy(80, 35);
		printf("�� �� : %6d\\\n", t->bill);
	}
	else if (t->tableNum == 5) {
		while (pp != NULL) {
			if (pp->table5 > 0) {
				gotoxy(70, i += 2);
				printf("%14s : %2d��   \n", pp->name, pp->table5);
			}
			pp = pp->link;
		}
		gotoxy(80, 35);
		printf("�� �� : %6d\\\n", t->bill);
	}
	else if (t->tableNum == 6) {
		while (pp != NULL) {
			if (pp->table6 > 0) {
				gotoxy(70, i += 2);
				printf("%14s : %2d��   \n", pp->name, pp->table6);
			}
			pp = pp->link;
		}
		gotoxy(80, 35);
		printf("�� �� : %6d\\\n", t->bill);
	}

	textcolor(WHITE, BLACK);
	gotoxy(2, 2);
	printf("                                                                 ");
	for (int i = 3; i < 36; i += 4) {
		gotoxy(2, i);
		printf("                                                                 ");
	}
	for (int j = 4; j < 40; j++) {
		gotoxy(33, j);
		printf("  ");
	}

	textcolor(WHITE, BLACK);
	gotoxy(40, 38);
	printf("TABLE %d", t->tableNum);
	while (1)
	{

		time(&now);
		tp = localtime(&now);
		gotoxy(2, 38);
		printf("%d��%d��%d��(%s) \%02d��%02d��%02d��", 1900 + tp->tm_year, tp->tm_mon + 1, tp->tm_mday, weeks[tp->tm_wday], tp->tm_hour, tp->tm_min, tp->tm_sec);

		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����        
				y = pos.Y;
				c1.x = x;
				c1.y = y;
				for (int j = 0; j < 8; j++) {
					if (c1.x >= 2 && c1.x <= 32 && c1.y >= (j + 1) * 4 && c1.y <= (j + 1) * 4 + 2) {
						cancel(node->head, t, j);
						display_cancelMenu(node, t);
					}
				}
				for (int j = 0; j < 8; j++) {
					if (c1.x >= 35 && c1.x <= 65 && c1.y >= (j + 1) * 4 && c1.y <= (j + 1) * 4 + 2) {
						cancel(node->head, t, j + 8);
						display_cancelMenu(node, t);
					}
				}

				if (c1.x >= 54 && c1.x <= 68 && c1.y >= 37 && c1.y <= 40) {
					system("cls");
					display_tableMenu(node, t);
				}
				else if (c1.x >= 70 && c1.x <= 84 && c1.y >= 37 && c1.y <= 40) {
					display_clear(node, t);
					system("cls");
					display_sales(node);
				}
				else if (c1.x >= 86 && c1.x <= 100 && c1.y >= 37 && c1.y <= 40) {
					system("cls");
					display_sales(node);
				}
			}
		}
	}
}

void display_tableMenu(headNode *node, table *t)
{
	Coordi c1;
	DWORD mode;
	WORD key;
	COORD pos;
	int x;      // ���콺�� x��ǥ �����  
	int y;      // ���콺�� y��ǥ �����  
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);     // ���콺 Ȱ��ȭ  
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	int xx = 4; int yy = 5; int cnt = 1; int i = 2; // i : �ֹ���� ��� ��ġ
	time_t now;
	struct tm *tp;
	char *weeks[] = { "��", "��", "ȭ", "��", "��", "��", "��" };
	menu *p = node->head;
	menu *pp = node->head;

	draw_box(2, 1, 66, 36);
	draw_box(70, 1, 100, 36);
	draw_box(54, 37, 68, 40);
	draw_box(70, 37, 84, 40);
	draw_box(86, 37, 100, 40);
	textcolor(BLACK, WHITE);
	gotoxy(28, 1);
	printf("��        ��");
	gotoxy(80, 1);
	printf("�� �� �� ��");
	gotoxy(57, 38);
	printf("����ϱ�");
	gotoxy(73, 38);
	printf("�����ϱ�");
	gotoxy(89, 38);
	printf("����ȭ��");
	while (p != NULL) {
		while (p != NULL) {
			if (cnt == 9) {
				xx = 35;
				yy = 5;
			}
			gotoxy(xx, yy);
			printf("%15s : %5d\\ ", &p->name, p->price);
			p = p->link;
			cnt++;
			yy += 4;
		}
	}

	if (t->tableNum == 1) {
		while (pp != NULL) {
			if (pp->table1 > 0) {
				gotoxy(70, i += 2);
				printf("%14s : %2d��   \n", pp->name, pp->table1);
			}
			pp = pp->link;
		}

		gotoxy(80, 35);
		printf("�� �� : %6d\\\n", t->bill);
	}
	else if (t->tableNum == 2) {
		while (pp != NULL) {
			if (pp->table2 > 0) {
				gotoxy(70, i += 2);
				printf("%14s : %2d��   \n", pp->name, pp->table2);
			}
			pp = pp->link;
		}


		gotoxy(80, 35);
		printf("�� �� : %6d\\\n", t->bill);
	}
	else if (t->tableNum == 3) {
		while (pp != NULL) {
			if (pp->table3 > 0) {
				gotoxy(70, i += 2);
				printf("%14s : %2d��   \n", pp->name, pp->table3);
			}
			pp = pp->link;
		}
		gotoxy(80, 35);
		printf("�� �� : %6d\\\n", t->bill);
	}
	else if (t->tableNum == 4) {
		while (pp != NULL) {
			if (pp->table4 > 0) {
				gotoxy(70, i += 2);
				printf("%14s : %2d��   \n", pp->name, pp->table4);
			}
			pp = pp->link;
		}
		gotoxy(80, 35);
		printf("�� �� : %6d\\\n", t->bill);
	}
	else if (t->tableNum == 5) {
		while (pp != NULL) {
			if (pp->table5 > 0) {
				gotoxy(70, i += 2);
				printf("%14s : %2d��   \n", pp->name, pp->table5);
			}
			pp = pp->link;
		}
		gotoxy(80, 35);
		printf("�� �� : %6d\\\n", t->bill);
	}
	else if (t->tableNum == 6) {
		while (pp != NULL) {
			if (pp->table6 > 0) {
				gotoxy(70, i += 2);
				printf("%14s : %2d��   \n", pp->name, pp->table6);
			}
			pp = pp->link;
		}
		gotoxy(80, 35);
		printf("�� �� : %6d\\\n", t->bill);
	}

	textcolor(WHITE, BLACK);
	gotoxy(2, 2);
	printf("                                                                 ");
	for (int i = 3; i < 36; i += 4) {
		gotoxy(2, i);
		printf("                                                                 ");
	}
	for (int j = 4; j < 40; j++) {
		gotoxy(33, j);
		printf("  ");
	}

	textcolor(WHITE, BLACK);
	gotoxy(40, 38);
	printf("TABLE %d", t->tableNum);
	while (1)
	{

		time(&now);
		tp = localtime(&now);
		gotoxy(2, 38);
		printf("%d��%d��%d��(%s) \%02d��%02d��%02d��", 1900 + tp->tm_year, tp->tm_mon + 1, tp->tm_mday, weeks[tp->tm_wday], tp->tm_hour, tp->tm_min, tp->tm_sec);
		//Sleep(100);

		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����        
				y = pos.Y;
				c1.x = x;
				c1.y = y;
				for (int j = 0; j < 8; j++) {
					if (c1.x >= 2 && c1.x <= 32 && c1.y >= (j + 1) * 4 && c1.y <= (j + 1) * 4 + 2) {
						order(node->head, t, j);
						display_tableMenu(node, t);
					}
				}
				for (int j = 0; j < 8; j++) {
					if (c1.x >= 35 && c1.x <= 65 && c1.y >= (j + 1) * 4 && c1.y <= (j + 1) * 4 + 2) {
						order(node->head, t, j + 8);
						display_tableMenu(node, t);
					}
				}
				if (c1.x >= 54 && c1.x <= 68 && c1.y >= 37 && c1.y <= 40) {
					system("cls");
					display_cancelMenu(node, t);
				}
				else if (c1.x >= 70 && c1.x <= 84 && c1.y >= 37 && c1.y <= 40) {
					display_clear(node, t);
					system("cls");
					display_sales(node);
				}
				else if (c1.x >= 86 && c1.x <= 100 && c1.y >= 37 && c1.y <= 40) {
					system("cls");
					display_sales(node);
				}
			}
		}
	}
}

void changeTable(headNode *node, int a, int b)
{
	int tmp;
	menu *p = node->head;

	if ((a == 1 && b == 2) || (a == 2 && b == 1)) {
		tmp = t1.bill;
		t1.bill = t2.bill;
		t2.bill = tmp;
		while (p != NULL) {
			if (p->table1 > 0 || p->table2 > 0) {
				tmp = p->table1;
				p->table1 = p->table2;
				p->table2 = tmp;
			}
			p = p->link;
		}
	}
	else if ((a == 1 && b == 3) || (a == 3 && b == 1)) {
		tmp = t1.bill;
		t1.bill = t3.bill;
		t3.bill = tmp;
		while (p != NULL) {
			if (p->table1 > 0 || p->table3 > 0) {
				tmp = p->table1;
				p->table1 = p->table3;
				p->table3 = tmp;
			}
			p = p->link;
		}
	}
	else if ((a == 1 && b == 4) || (a == 4 && b == 1)) {
		tmp = t1.bill;
		t1.bill = t4.bill;
		t4.bill = tmp;
		while (p != NULL) {
			if (p->table1 > 0 || p->table4 > 0) {
				tmp = p->table1;
				p->table1 = p->table4;
				p->table4 = tmp;
			}
			p = p->link;
		}
	}
	else if ((a == 1 && b == 5) || (a == 5 && b == 1)) {
		tmp = t1.bill;
		t1.bill = t5.bill;
		t5.bill = tmp;
		while (p != NULL) {
			if (p->table1 > 0 || p->table5 > 0) {
				tmp = p->table1;
				p->table1 = p->table5;
				p->table5 = tmp;
			}
			p = p->link;
		}
	}
	else if ((a == 1 && b == 6) || (a == 6 && b == 1)) {
		tmp = t1.bill;
		t1.bill = t6.bill;
		t6.bill = tmp;
		while (p != NULL) {
			if (p->table1 > 0 || p->table6 > 0) {
				tmp = p->table1;
				p->table1 = p->table6;
				p->table6 = tmp;
			}
			p = p->link;
		}
	}
	else if ((a == 2 && b == 3) || (a == 3 && b == 2)) {
		tmp = t3.bill;
		t3.bill = t2.bill;
		t2.bill = tmp;
		while (p != NULL) {
			if (p->table2 > 0 || p->table3 > 0) {
				tmp = p->table2;
				p->table2 = p->table3;
				p->table3 = tmp;
			}
			p = p->link;
		}
	}
	else if ((a == 2 && b == 4) || (a == 4 && b == 2)) {
		tmp = t4.bill;
		t4.bill = t2.bill;
		t2.bill = tmp;
		while (p != NULL) {
			if (p->table2 > 0 || p->table4 > 0) {
				tmp = p->table2;
				p->table2 = p->table4;
				p->table4 = tmp;
			}
			p = p->link;
		}
	}
	else if ((a == 2 && b == 5) || (a == 5 && b == 2)) {
		tmp = t5.bill;
		t5.bill = t2.bill;
		t2.bill = tmp;
		while (p != NULL) {
			if (p->table2 > 0 || p->table5 > 0) {
				tmp = p->table2;
				p->table2 = p->table5;
				p->table5 = tmp;
			}
			p = p->link;
		}
	}
	else if ((a == 2 && b == 6) || (a == 6 && b == 2)) {
		tmp = t6.bill;
		t6.bill = t2.bill;
		t2.bill = tmp;
		while (p != NULL) {
			if (p->table2 > 0 || p->table6 > 0) {
				tmp = p->table2;
				p->table2 = p->table6;
				p->table6 = tmp;
			}
			p = p->link;
		}
	}
	else if ((a == 3 && b == 4) || (a == 4 && b == 3)) {
		tmp = t3.bill;
		t3.bill = t4.bill;
		t4.bill = tmp;
		while (p != NULL) {
			if (p->table3 > 0 || p->table4 > 0) {
				tmp = p->table3;
				p->table3 = p->table4;
				p->table4 = tmp;
			}
			p = p->link;
		}
	}
	else if ((a == 3 && b == 5) || (a == 5 && b == 3)) {
		tmp = t3.bill;
		t3.bill = t5.bill;
		t5.bill = tmp;
		while (p != NULL) {
			if (p->table3 > 0 || p->table5 > 0) {
				tmp = p->table3;
				p->table3 = p->table5;
				p->table5 = tmp;
			}
			p = p->link;
		}
	}
	else if ((a == 3 && b == 6) || (a == 6 && b == 3)) {
		tmp = t3.bill;
		t3.bill = t6.bill;
		t6.bill = tmp;
		while (p != NULL) {
			if (p->table3 > 0 || p->table6 > 0) {
				tmp = p->table3;
				p->table3 = p->table6;
				p->table6 = tmp;
			}
			p = p->link;
		}
	}
	else if ((a == 4 && b == 5) || (a == 5 && b == 4)) {
		tmp = t5.bill;
		t5.bill = t4.bill;
		t4.bill = tmp;
		while (p != NULL) {
			if (p->table4 > 0 || p->table5 > 0) {
				tmp = p->table4;
				p->table4 = p->table5;
				p->table5 = tmp;
			}
			p = p->link;
		}
	}
	else if ((a == 4 && b == 6) || (a == 6 && b == 4)) {
		tmp = t6.bill;
		t6.bill = t4.bill;
		t4.bill = tmp;
		while (p != NULL) {
			if (p->table4 > 0 || p->table6 > 0) {
				tmp = p->table4;
				p->table4 = p->table6;
				p->table6 = tmp;
			}
			p = p->link;
		}
	}
	else if ((a == 5 && b == 6) || (a == 6 && b == 5)) {
		tmp = t5.bill;
		t5.bill = t6.bill;
		t6.bill = tmp;
		while (p != NULL) {
			if (p->table5 > 0 || p->table6 > 0) {
				tmp = p->table5;
				p->table5 = p->table6;
				p->table6 = tmp;
			}
			p = p->link;
		}
	}
}

void display_tableMove(headNode *node) 
{
	Coordi c1;
	DWORD mode;
	WORD key;
	COORD pos;
	int x, y;      // ���콺�� x,y��ǥ ����� 
	int a, b, check;
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);     // ���콺 Ȱ��ȭ  
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	int i = 3, cnt = 0;
	menu *p = node->head;

	display_salesShape();
	draw_box(36, 37, 50, 40);
	draw_box(52, 37, 66, 40);
	//draw_box(70, 37, 84, 40);
	//draw_box(86, 37, 100, 40);

	textcolor(BLACK, WHITE);
	gotoxy(76, 38);
	printf("Ȯ��");
	gotoxy(92, 38);
	printf("���");

	while (p != NULL) {
		if (p->table1 > 0) {
			gotoxy(2, i++);
			printf("%14s : %2d��   \n", p->name, p->table1);
			cnt++;
			if (cnt > 9) {
				gotoxy(17, i);
				printf("��");
				gotoxy(17, i + 1);
				printf("��");
				gotoxy(17, i + 2);
				printf("��");
				break;
			}
		}
		p = p->link;
	}
	cnt = 0; i = 3;
	p = node->head;
	while (p != NULL) {
		if (p->table2 > 0) {
			gotoxy(36, i++);
			printf("%14s : %2d��   \n", p->name, p->table2);
			cnt++;
			if (cnt > 9) {
				gotoxy(51, i);
				printf("��");
				gotoxy(51, i + 1);
				printf("��");
				gotoxy(51, i + 2);
				printf("��");
				break;
			}
		}
		p = p->link;
	}
	cnt = 0; i = 3;
	p = node->head;
	while (p != NULL) {
		if (p->table3 > 0) {
			gotoxy(70, i++);
			printf("%14s : %2d��   \n", p->name, p->table3);
			cnt++;
			if (cnt > 9) {
				gotoxy(85, i);
				printf("��");
				gotoxy(85, i + 1);
				printf("��");
				gotoxy(85, i + 2);
				printf("��");
				break;
			}
		}
		p = p->link;
	}
	cnt = 0; i = 21;
	p = node->head;
	while (p != NULL) {
		if (p->table4 > 0) {
			gotoxy(2, i++);
			printf("%14s : %2d��   \n", p->name, p->table4);
			cnt++;
			if (cnt > 9) {
				gotoxy(17, i);
				printf("��");
				gotoxy(17, i + 1);
				printf("��");
				gotoxy(17, i + 2);
				printf("��");
				break;
			}
		}
		p = p->link;
	}
	cnt = 0; i = 21;
	p = node->head;
	while (p != NULL) {
		if (p->table5 > 0) {
			gotoxy(36, i++);
			printf("%14s : %2d��   \n", p->name, p->table5);
			cnt++;
			if (cnt > 9) {
				gotoxy(51, i);
				printf("��");
				gotoxy(51, i + 1);
				printf("��");
				gotoxy(51, i + 2);
				printf("��");
				break;
			}
		}
		p = p->link;
	}
	cnt = 0; i = 21;
	p = node->head;
	while (p != NULL) {
		if (p->table6 > 0) {
			gotoxy(70, i++);
			printf("%14s : %2d��   \n", p->name, p->table6);
			cnt++;
			if (cnt > 9) {
				gotoxy(85, i);
				printf("��");
				gotoxy(85, i + 1);
				printf("��");
				gotoxy(85, i + 2);
				printf("��");
				break;
			}
		}
		p = p->link;
	}
	
	while (1) {
		gotoxy(2, 38);
		textcolor(15, 0);
		printf("�̵� �� ���̺��� �����ϼ���");
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����        
				y = pos.Y;
				c1.x = x;
				c1.y = y;
				textcolor(RED2, WHITE);
				if (c1.x >= 2 && c1.x <= 32 && c1.y >= 1 && c1.y <= 17) {
					gotoxy(40, 38);
					printf("TABLE1");
					a = 1;
					break;
				}
				else if (c1.x >= 36 && c1.x <= 66 && c1.y >= 1 && c1.y <= 17) {
					gotoxy(40, 38);
					printf("TABLE2");
					a = 2;
					break;
				}
				else if (c1.x >= 70 && c1.x <= 100 && c1.y >= 1 && c1.y <= 17) {
					gotoxy(40, 38);
					printf("TABLE3");
					a = 3;
					break;
				}
				else if (c1.x >= 2 && c1.x <= 32 && c1.y >= 19 && c1.y <= 36) {
					gotoxy(40, 38);
					printf("TABLE4");
					a = 4;
					break;
				}
				else if (c1.x >= 36 && c1.x <= 66 && c1.y >= 19 && c1.y <= 36) {
					gotoxy(40, 38);
					printf("TABLE5");
					a = 5;
					break;
				}
				else if (c1.x >= 70 && c1.x <= 100 && c1.y >= 19 && c1.y <= 36) {
					gotoxy(40, 38);
					printf("TABLE6");
					a = 6;
					break;
				}
			}
		}
	}

	while (1) {
		gotoxy(2, 38);
		textcolor(WHITE, BLACK);
		printf("�̵� �� ���̺��� �����ϼ���");
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����        
				y = pos.Y;
				c1.x = x;
				c1.y = y;
				textcolor(RED2, WHITE);
				if (c1.x >= 2 && c1.x <= 32 && c1.y >= 1 && c1.y <= 17) {
					gotoxy(56, 38);
					printf("TABLE1");
					b = 1;
					break;
				}
				else if (c1.x >= 36 && c1.x <= 66 && c1.y >= 1 && c1.y <= 17) {
					gotoxy(56, 38);
					printf("TABLE2");
					b = 2;
					break;
				}
				else if (c1.x >= 70 && c1.x <= 100 && c1.y >= 1 && c1.y <= 17) {
					gotoxy(56, 38);
					printf("TABLE3");
					b = 3;
					break;
				}
				else if (c1.x >= 2 && c1.x <= 32 && c1.y >= 19 && c1.y <= 36) {
					gotoxy(56, 38);
					printf("TABLE4");
					b = 4;
					break;
				}
				else if (c1.x >= 36 && c1.x <= 66 && c1.y >= 19 && c1.y <= 36) {
					gotoxy(56, 38);
					printf("TABLE5");
					b = 5;
					break;
				}
				else if (c1.x >= 70 && c1.x <= 100 && c1.y >= 19 && c1.y <= 36) {
					gotoxy(56, 38);
					printf("TABLE6");
					b = 6;
					break;
				}
			}
		}
	}
	while (1) {
		gotoxy(2, 38);
		textcolor(WHITE, BLACK);
		printf("Ȯ�� ��ư�� ��������             ");
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����        
				y = pos.Y;
				c1.x = x;
				c1.y = y;
				if (c1.x >= 70 && c1.x <= 84 && c1.y >= 37 && c1.y <= 40) {
					changeTable(node, a, b);
					system("cls");
					display_sales(node);
					break;
				}
				else if (c1.x >= 86 && c1.x <= 100 && c1.y >= 37 && c1.y <= 40) {
					system("cls");
					display_tableMove(node);
				}
			}
		}
	}	
}

void display_salesShape() { //����

	draw_box(2, 1, 32, 17);
	draw_box(36, 1, 66, 17);
	draw_box(70, 1, 100, 17);
	draw_box(2, 19, 32, 36);
	draw_box(36, 19, 66, 36);
	draw_box(70, 19, 100, 36);
	
	draw_box(70, 37, 84, 40);
	draw_box(86, 37, 100, 40);

	textcolor(BLACK, WHITE);
	for (int i = 1; i < 70; i+=34) {
		gotoxy(i + 13, 1);
		printf("TABLE %d", i%33);
	}
	for (int i = 4; i < 73; i += 34) {
		gotoxy(i + 10, 19);
		printf("TABLE %d", i % 33);
	}
	gotoxy(10, 16);
	printf("�� �� : %6d\\\n", t1.bill);	
	gotoxy(44, 16);
	printf("�� �� : %6d\\\n", t2.bill);
	gotoxy(78, 16);
	printf("�� �� : %6d\\\n", t3.bill);
	gotoxy(10, 35);
	printf("�� �� : %6d\\\n", t4.bill);
	gotoxy(44, 35);
	printf("�� �� : %6d\\\n", t5.bill);
	gotoxy(78, 35);
	printf("�� �� : %6d\\\n", t6.bill);


}

void display_sales(headNode *node) {

	Coordi c1;
	DWORD mode;
	WORD key;
	COORD pos;
	int x,y;      // ���콺�� x,y��ǥ �����  
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);     // ���콺 Ȱ��ȭ  
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	time_t now;
	struct tm *tp;
	char *weeks[] = { "��", "��", "ȭ", "��", "��", "��", "��" };
	int i=3, cnt=0;
	menu *p = node->head;

	display_salesShape();
	gotoxy(72, 38);
	printf("���̺��̵�");
	gotoxy(89, 38);
	printf("����ȭ��");
	while(p!=NULL){
		if (p->table1 > 0) {
			gotoxy(2, i++);
			printf("%14s : %2d��   \n", p->name, p->table1);
			cnt++;
			if (cnt > 9) {
				gotoxy(17, i);
				printf("��");
				gotoxy(17, i + 1);
				printf("��");
				gotoxy(17, i + 2);
				printf("��");
				break;
			}
		}
		p = p->link;
	}
	cnt = 0; i = 3;
	p = node->head;
	while (p != NULL) {
		if (p->table2 > 0) {
			gotoxy(36, i++);
			printf("%14s : %2d��   \n", p->name, p->table2);
			cnt++;
			if (cnt > 9) {
				gotoxy(51, i);
				printf("��");
				gotoxy(51, i + 1);
				printf("��");
				gotoxy(51, i + 2);
				printf("��");
				break;
			}
		}
		p = p->link;
	}
	cnt = 0; i = 3;
	p = node->head;
	while (p != NULL) {
		if (p->table3 > 0) {
			gotoxy(70, i++);
			printf("%14s : %2d��   \n", p->name, p->table3);
			cnt++;
			if (cnt > 9) {
				gotoxy(85, i);
				printf("��");
				gotoxy(85, i + 1);
				printf("��");
				gotoxy(85, i + 2);
				printf("��");
				break;
			}
		}
		p = p->link;
	}
	cnt = 0; i = 21;
	p = node->head;
	while (p != NULL) {
		if (p->table4 > 0) {
			gotoxy(2, i++);
			printf("%14s : %2d��   \n", p->name, p->table4);
			cnt++;
			if (cnt > 9) {
				gotoxy(17, i);
				printf("��");
				gotoxy(17, i + 1);
				printf("��");
				gotoxy(17, i + 2);
				printf("��");
				break;
			}
		}
		p = p->link;
	}
	cnt = 0; i = 21;
	p = node->head;
	while (p != NULL) {
		if (p->table5 > 0) {
			gotoxy(36, i++);
			printf("%14s : %2d��   \n", p->name, p->table5);
			cnt++;
			if (cnt > 9) {
				gotoxy(51, i);
				printf("��");
				gotoxy(51, i + 1);
				printf("��");
				gotoxy(51, i + 2);
				printf("��");
				break;
			}
		}
		p = p->link;
	}
	cnt = 0; i = 21;
	p = node->head;
	while (p != NULL) {
		if (p->table6 > 0) {
			gotoxy(70, i++);
			printf("%14s : %2d��   \n", p->name, p->table6);
			cnt++;
			if (cnt > 9) {
				gotoxy(85, i);
				printf("��");
				gotoxy(85, i + 1);
				printf("��");
				gotoxy(85, i + 2);
				printf("��");
				break;
			}
		}
		p = p->link;
	}

	while (1)
	{
		textcolor(WHITE, BLACK);
		time(&now);
		tp = localtime(&now);
		gotoxy(2, 38);
		printf("%d��%d��%d��(%s) \%02d��%02d��%02d��     ���� �� �Ǹűݾ� : %d��\r", 1900 + tp->tm_year, tp->tm_mon + 1, tp->tm_mday, weeks[tp->tm_wday], tp->tm_hour, tp->tm_min, tp->tm_sec,totalPrice);
		//Sleep(100);

		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����        
				y = pos.Y;
				c1.x = x;
				c1.y = y;
				if (c1.x >= 2 && c1.x <= 32 && c1.y >= 1 && c1.y <= 17) {
					system("cls");
					display_tableMenu(&m, &t1);
				}
				else if (c1.x >= 36 && c1.x <= 66 && c1.y >= 1 && c1.y <= 17) {
					system("cls");
					display_tableMenu(&m, &t2);
				}
				else if (c1.x >= 70 && c1.x <= 100 && c1.y >= 1 && c1.y <= 17) {
					system("cls");
					display_tableMenu(&m, &t3);
				}
				else if (c1.x >= 2 && c1.x <= 32 && c1.y >= 19 && c1.y <= 36) {
					system("cls");
					display_tableMenu(&m, &t4);
				}
				else if (c1.x >= 36 && c1.x <= 66 && c1.y >= 19 && c1.y <= 36) {
					system("cls");
					display_tableMenu(&m, &t5);
				}
				else if (c1.x >= 70 && c1.x <= 100 && c1.y >= 19 && c1.y <= 36) {
					system("cls");
					display_tableMenu(&m, &t6);
				}
				else if (c1.x >= 70 && c1.x <= 84 && c1.y >= 37 && c1.y <= 40) {
					system("cls");
					display_tableMove(node);// '���̺��̵�' �Լ����
					break; 
				}
				else if (c1.x >= 86 && c1.x <= 100 && c1.y >= 37 && c1.y <= 40) {
					system("cls");
					display_mainWorker(node);// '����ȭ��' �Լ����
				}

				//gotoxy(x, y);
				//textcolor(1, 2);
				//printf("%d , %d\n", x, y);
			}
		}
	}
}

void display_mainWorker(headNode *node) 
{
	Coordi c1;
	DWORD mode;
	WORD key;
	COORD pos;
	int x;      // ���콺�� x��ǥ �����  
	int y;      // ���콺�� y��ǥ �����  
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);     // ���콺 Ȱ��ȭ  
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	draw_box(2, 1, 48, 15);
	gotoxy(22, 7);
	textcolor(0, 15);
	printf("��������");
	draw_box(52, 1, 100, 15);
	gotoxy(72, 7);
	textcolor(0, 15);
	printf("��/��� ���");
	draw_box(2, 20, 48, 35);
	gotoxy(20, 26);
	textcolor(0, 15);
	printf("�μ��ΰ����");
	draw_box(52, 20, 100, 35);
	gotoxy(73, 26);
	textcolor(0, 15);
	printf("�α� �ƿ�");

	time_t now;
	struct tm *tp;
	char *weeks[] = { "��", "��", "ȭ", "��", "��", "��", "��" };

	while (1)
	{
		time(&now);
		tp = localtime(&now);
		textcolor(15, 0);
		gotoxy(2, 38);
		printf("%d��%d��%d��(%s) \%02d��%02d��%02d��", 1900 + tp->tm_year, tp->tm_mon + 1, tp->tm_mday, weeks[tp->tm_wday], tp->tm_hour, tp->tm_min, tp->tm_sec);

		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����        
				y = pos.Y;
				c1.x = x;
				c1.y = y;

				if (c1.x >= 2 && c1.x <= 48 && c1.y >= 1 && c1.y <= 15) {
					system("cls");
					display_sales(node); // ��������
					break;
				}
				else if (c1.x >= 52 && c1.x <= 100 && c1.y >= 1 && c1.y <= 15) {
					cls();
					commute_add(node); //����� ���
					cls();
					display_mainWorker(node);
				}
				else if (c1.x >= 2 && c1.x <= 48 && c1.y >= 20 && c1.y <= 35) {
					cls();
					transfert_main(node);
					//�μ��ΰ�
				}

				else if (c1.x >= 52 && c1.x <= 100 && c1.y >= 20 && c1.y <= 35) {
					system("cls");
					login();
				}
			}
		}
	}
}

void display_mainManager(headNode *node)
{
	Coordi c1;
	DWORD mode;
	WORD key;
	COORD pos;
	int x;      // ���콺�� x��ǥ �����  
	int y;      // ���콺�� y��ǥ �����  
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);     // ���콺 Ȱ��ȭ  
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	draw_box(2, 1, 48, 15);
	gotoxy(20, 7);
	textcolor(0, 15);
	printf("�޴� ����/���");
	draw_box(52, 1, 100, 15);
	gotoxy(72, 7);
	textcolor(0, 15);
	printf("��/��� ���");
	draw_box(2, 20, 48, 35);
	gotoxy(20, 26);
	textcolor(0, 15);
	printf("������� ����");
	draw_box(52, 20, 100, 35);
	gotoxy(73, 26);
	textcolor(0, 15);
	printf("�Ǹ� ���");
	draw_box(86, 37, 100, 40);
	gotoxy(89, 38);
	textcolor(BLACK, WHITE);
	printf("�α׾ƿ�");

	time_t now;
	struct tm *tp;
	char *weeks[] = { "��", "��", "ȭ", "��", "��", "��", "��" };

	while (1)
	{
		time(&now);
		tp = localtime(&now);
		textcolor(15, 0);
		gotoxy(2, 38);
		printf("%d��%d��%d��(%s) \%02d��%02d��%02d��", 1900 + tp->tm_year, tp->tm_mon + 1, tp->tm_mday, weeks[tp->tm_wday], tp->tm_hour, tp->tm_min, tp->tm_sec);

		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����        
				y = pos.Y;
				c1.x = x;
				c1.y = y;

				if (c1.x >= 2 && c1.x <= 48 && c1.y >= 1 && c1.y <= 15) {
					system("cls");
					display_menuEdit(node); // �޴� ����
					break;
				}
				else if (c1.x >= 52 && c1.x <= 100 && c1.y >= 1 && c1.y <= 15) {
					cls(); 
					commute_view(node); //����� Ȯ��
				}
				else if (c1.x >= 2 && c1.x <= 48 && c1.y >= 20 && c1.y <= 35) {
					cls();
					manager(&m2); //������� ����
				}
				else if (c1.x >= 52 && c1.x <= 100 && c1.y >= 20 && c1.y <= 35) {
					cls();
					read_sell(node);
				}
				else if (c1.x >= 86 && c1.x <= 100 && c1.y >= 37 && c1.y <= 40) {
					cls();
					login(); // �α׾ƿ�
				}
			}
		}
	}
}

void display_menuDelete(headNode *node)
{
	char name[20];
	menu *p = node->head;
	menu *pre = NULL;
	menu *w;
	FILE *fmenu;

	cursor_view(1);
	draw_box(32, 14, 71, 24);
	gotoxy(36, 18);
	textcolor(BLACK, WHITE);
	printf("�̸� : ");
	gotoxy(35, 21);
	textcolor(RED2, WHITE);
	printf("������ �޴��� �̸��� �Է��ϼ���");
	textcolor(BLACK, WHITE);
	gotoxy(44, 18);
	scanf("%s", name);
	cursor_view(0);
	if (strcmp(name, p->name) == 0) {
		node->head = node->head->link;
	}
	else {
		while (p != NULL) {
			if (strcmp(p->name, name) == 0)
				break;
			pre = p;
			p = p->link;
		}
		if (p == NULL) {
			cls();
			draw_box(32, 14, 71, 24);
			gotoxy(39, 18);
			textcolor(RED2, WHITE);
			printf("�޴��� �������� �ʽ��ϴ�");
			Sleep(700);
			cls();
			display_menuEdit(node);
			return;
		}
		if (p == node->tail) {
			node->tail = pre;
		}
		pre->link = p->link;

		w = node->head;
		fmenu = fopen("menu.txt", "w");
		while (w != NULL) {
			fprintf(fmenu, "%s\n", w->name);
			fprintf(fmenu, "%d\n", w->price);
			w = w->link;
		}
		fclose(fmenu);
	}
	free(p);
	node->num--;

	write_sell(node->head);
	write_count(node->head);
}

void display_menuAdd(headNode *node)
{
	char name[20];
	int price;

	cursor_view(1);
	draw_box(32, 14, 71, 24);
	gotoxy(36, 17);
	textcolor(BLACK, WHITE);
	printf("�̸� : ");
	gotoxy(36, 19);
	printf("���� : ");
	gotoxy(35, 21);
	textcolor(RED2, WHITE);
	printf("�߰��� �޴��� ������ �Է��ϼ���");
	textcolor(BLACK, WHITE);

	gotoxy(44, 17);
	scanf("%s", name);
	gotoxy(44, 19);
	scanf("%d", &price);
	file_menu(name, price);
	add_menu(node, create_menu(name, price));
	write_sell(node->head);
	write_count(node->head);
	cursor_view(0);
}

void display_menuEdit(headNode *node)
{
	Coordi c1;
	DWORD mode;
	WORD key;
	COORD pos;
	int x;      // ���콺�� x��ǥ �����  
	int y;      // ���콺�� y��ǥ �����  
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);     // ���콺 Ȱ��ȭ  
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	draw_box(3, 10, 49, 30);
	draw_box(54, 10, 100, 30);
	draw_box(86, 37, 100, 40);
	textcolor(BLACK, WHITE);
	gotoxy(89, 38);
	printf("����ȭ��");
	gotoxy(22, 20);
	printf("�޴� ���");
	gotoxy(73, 20);
	printf("�޴� ����");
	while (1)
	{
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����        
				y = pos.Y;
				c1.x = x;
				c1.y = y;

				if (c1.x >= 3 && c1.x <= 49 && c1.y >= 10 && c1.y <= 30) {
					cls();
					display_menuAdd(node); //�޴� �߰�
					cls();
					display_menuEdit(node);
				}
				else if (c1.x >= 54 && c1.x <= 100 && c1.y >= 10 && c1.y <= 30) {
					cls();
					display_menuDelete(node); //�޴� ����
					cls();
					display_menuEdit(node);
				}
				else if (c1.x >= 86 && c1.x <= 100 && c1.y >= 37 && c1.y <= 40) {
					cls();
					display_mainManager(node); //���� ȭ��
				}
			}
		}
	}
}

void login()
{
	char id[20];
	char passwd[20];

	Login *worker = (Login*)malloc(sizeof(Login));
	strcpy(worker->ID, "worker");
	strcpy(worker->PASSWD, "1q2w3e4r");

	Login *manager = (Login*)malloc(sizeof(Login));
	strcpy(manager->ID, "manager");
	strcpy(manager->PASSWD, "1q2w3e4r");
	draw_box(32, 14, 71, 24);
	gotoxy(36, 17);
	textcolor(BLACK, WHITE);
	printf("    ID : ");
	gotoxy(36, 19);
	printf("PASSWD : ");

	cursor_view(1);
	while (1) {
		gotoxy(46, 17);
		scanf("%s", id);
		gotoxy(46, 19);
		scanf("%s", passwd);

		if (strcmp(id, worker->ID) == 0 && strcmp(passwd, worker->PASSWD) == 0) {
			system("CLS");
			system("COLOR 0f");
			cursor_view(0);
			read_count(&m);
			write_sell(m.head);
			display_mainWorker(&m);
		}

		else if (strcmp(id, manager->ID) == 0 && strcmp(passwd, manager->PASSWD) == 0) {
			system("CLS");
			system("COLOR 0f");
			cursor_view(0);
			read_count(&m);
			write_sell(m.head);
			display_mainManager(&m);
		}

		else {
			system("CLS");
			system("COLOR 0f");
			draw_box(32, 14, 71, 24);
			gotoxy(36, 17);
			textcolor(BLACK, WHITE);
			printf("    ID : ");
			gotoxy(36, 19);
			printf("PASSWD : ");
			gotoxy(35, 21);
			textcolor(RED2, WHITE);
			printf("���̵� �н����带 �ٽ� Ȯ���ϼ���");
			textcolor(BLACK, WHITE);
		}
	}
}

void commute() {
	draw_box(25, 10, 75, 30);
}

void transfert_view(headNode *node) 
{
	Coordi c1;
	DWORD mode;
	WORD key;
	COORD pos;
	int x;      // ���콺�� x��ǥ �����  
	int y;      // ���콺�� y��ǥ �����  
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);     // ���콺 Ȱ��ȭ  
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	int cp, yy = 7, date = 0;
	char time[20], name[20], str[100], a, ch;
	int feof(FILE * stream);

	FILE *fp;
	fp = fopen("trans.txt", "r");

	draw_box(8, 1, 95, 4);
	draw_box(8, 5, 95, 35);
	draw_box(86, 37, 100, 40);
	
	textcolor(BLACK, WHITE);
	gotoxy(45, 2);
	printf("�μ��ΰ� ��Ȳ");
	gotoxy(89, 38);
	printf("����ȭ��");

	gotoxy(15, yy);
	while (1) {
		a = fgetc(fp);
		printf("%c", a);

		if (a == '\n')
			gotoxy(15, yy++);
		if (feof(fp) != 0) {
			fclose(fp);
			break;
		}
	}
	while (1)
	{
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����        
				y = pos.Y;
				c1.x = x;
				c1.y = y;
				if (c1.x >= 86 && c1.x <= 100 && c1.y >= 37 && c1.y <= 40) {
					cls();
					transfert_main(node);
				}
			}
		}
	}
}

void transfert_add(headNode *node) {
	int date;
	char time[20];
	char name[20];
	char str[100];

	draw_box(8, 1, 95, 4);
	draw_box(8, 5, 95, 35);

	textcolor(BLACK, WHITE);
	gotoxy(45, 2);
	printf("�μ��ΰ� �߰�");
	gotoxy(17, 7);
	printf("��¥ �ð� ������� ���� �μ��ΰ踦 �����ּ���");
	gotoxy(17, 9);
	textcolor(RED2, WHITE);
	printf("����) 20180610 14:15 ȫ�浿 - �ַ� ���� �־��ֽñ� �ٶ��ϴ�.");
	textcolor(BLACK, WHITE);

	

	cursor_view(1);
	gotoxy(17, 13);
	printf("��¥ : ");
	scanf("%d", &date);
	gotoxy(17, 15);
	printf("�ð� : ");
	scanf("%s", time);
	gotoxy(17, 17);
	printf("����� : ");
	scanf("%s", name);
	gotoxy(17, 19);
	printf("�μ��ΰ� ���� : ");
	while (getchar() != '\n') {

	};//���ۺ���
	gets(str);
	FILE *fp;
	//// ���Ͽ� ���(write)
	fp = fopen("trans.txt", "a"); // w�� write mode, a�� �߰�(append)
	fprintf(fp, "%d %s %s - %s\n", date, time, name, str);
	fclose(fp);
	cursor_view(0);
}

// �μ��ΰ� ����
void transfert_main(headNode *node) {
	Coordi c1;
	DWORD mode;
	WORD key;
	COORD pos;
	int x, y;      // ���콺�� x,y��ǥ �����  
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);     // ���콺 Ȱ��ȭ  
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	time_t now;
	struct tm *tp;
	char *weeks[] = { "��", "��", "ȭ", "��", "��", "��", "��" };

	draw_box(8, 12, 30, 24);
	draw_box(40, 12, 62, 24);
	draw_box(72, 12, 94, 24);

	gotoxy(13, 17);
	textcolor(BLACK, WHITE);
	printf("�μ��ΰ� �߰�");

	gotoxy(45, 17);
	textcolor(BLACK, WHITE);
	printf("�μ��ΰ� Ȯ��");
	gotoxy(80, 17);
	textcolor(BLACK, WHITE);
	printf("����ȭ��");


	while (1)
	{
		time(&now);
		tp = localtime(&now);
		textcolor(15, 0);
		gotoxy(2, 38);
		printf("%d��%d��%d��(%s) \%02d��%02d��%02d��", 1900 + tp->tm_year, tp->tm_mon + 1, tp->tm_mday, weeks[tp->tm_wday], tp->tm_hour, tp->tm_min, tp->tm_sec);

		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����        
				y = pos.Y;
				c1.x = x;
				c1.y = y;

				if (c1.x >= 8 && c1.x <= 30 && c1.y >= 12 && c1.y <= 24) {
					cls();
					transfert_add(node);//�μ��ΰ� �߰��ϱ�
					cls();
					transfert_main(node);
					//break;
				}
				else if (c1.x >= 40 && c1.x <= 62 && c1.y >= 12 && c1.y <= 24) {
					cls();
					transfert_view(node);//�μ��ΰ� Ȯ��
					cls();
					transfert_main(node);
				//	break;
				}
				else if (c1.x >= 72 && c1.x <= 94 && c1.y >= 12 && c1.y <= 24) {
					cls();
					display_mainWorker(node);//����ȭ��
					//break;
				}
			}
		}
	}
}

//����� �߰��ϱ�
void commute_add(headNode *node) {

	Coordi c1;
	DWORD mode;
	WORD key;
	COORD pos;
	int x, y;      // ���콺�� x,y��ǥ �����  
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);     // ���콺 Ȱ��ȭ  
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	time_t now = time(NULL);
	struct tm *tp;
	char *weeks[] = { "��", "��", "ȭ", "��", "��", "��", "��" };

	char name[10];

	draw_box(32, 14, 48, 17);
	draw_box(56, 14, 72, 17);
	draw_box(32, 19, 72, 24);

	gotoxy(38, 15);
	textcolor(BLUE1, WHITE);
	printf("���");
	gotoxy(62, 15);
	textcolor(RED2, WHITE);
	printf("���");
	cursor_view(1);
	gotoxy(40, 21);
	textcolor(BLACK, WHITE);
	printf("����� : ");
	scanf("%s", name);

	cursor_view(0);
	while (1)
	{
		time(&now);
		tp = localtime(&now);
		textcolor(15, 0);
		gotoxy(2, 38);
		printf("%d��%d��%d��(%s) \%02d��%02d��%02d��", 1900 + tp->tm_year, tp->tm_mon + 1, tp->tm_mday, weeks[tp->tm_wday], tp->tm_hour, tp->tm_min, tp->tm_sec);

		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����        
				y = pos.Y;
				c1.x = x;
				c1.y = y;

				if (c1.x >= 32 && c1.x <= 48 && c1.y >= 14 && c1.y <= 17) { // ���
					FILE *fp;
					//// ���Ͽ� ���(write)
					fp = fopen("commute.txt", "a"); // w�� write mode, a�� �߰�(append)
					fprintf(fp, "%s %d��%d��%d��(%s) \%02d��%02d��%02d�� ���\n", name, 1900 + tp->tm_year, tp->tm_mon + 1, tp->tm_mday, weeks[tp->tm_wday], tp->tm_hour, tp->tm_min, tp->tm_sec);
					fclose(fp);
					cursor_view(0);
					break;
				}
				else if (c1.x >= 56 && c1.x <= 72 && c1.y >= 14 && c1.y <= 17) { //���
					FILE *fp;
					//// ���Ͽ� ���(write)
					fp = fopen("commute.txt", "a"); // w�� write mode, a�� �߰�(append)
					fprintf(fp, "%s %d��%d��%d��(%s) \%02d��%02d��%02d�� ���\n", name, 1900 + tp->tm_year, tp->tm_mon + 1, tp->tm_mday, weeks[tp->tm_wday], tp->tm_hour, tp->tm_min, tp->tm_sec);
					fclose(fp);
					cursor_view(0);
					break;
				}

			}
		}
	}
}

//����� Ȯ��
void commute_view(headNode *node) {
	Coordi c1;
	DWORD mode;
	WORD key;
	COORD pos;
	int x;      // ���콺�� x��ǥ �����  
	int y;      // ���콺�� y��ǥ �����  
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);     // ���콺 Ȱ��ȭ  
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	int cp, yy = 7, date = 0;
	char a;
	int feof(FILE * stream);
	FILE *fp;
	fp = fopen("commute.txt", "r");

	draw_box(8, 1, 95, 4);
	draw_box(8, 5, 95, 35);
	draw_box(86, 37, 100, 40);

	textcolor(BLACK, WHITE);
	gotoxy(45, 2);
	printf("����� ��Ȳ");
	gotoxy(89, 38);
	printf("����ȭ��");

	gotoxy(15, yy);
	textcolor(BLUE1, WHITE);
	while (1) {
		a = fgetc(fp);

		printf("%c", a);

		if (a == '\n')
			gotoxy(15, yy++);
		if (feof(fp) != 0) {
			fclose(fp);
			break;
		}
	}
	while (1)
	{
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����        
				y = pos.Y;
				c1.x = x;
				c1.y = y;
				if (c1.x >= 86 && c1.x <= 100 && c1.y >= 37 && c1.y <= 40) {
					cls();
					display_mainManager(node);
				}
			}
		}
	}
}
#endif //HEADER_H