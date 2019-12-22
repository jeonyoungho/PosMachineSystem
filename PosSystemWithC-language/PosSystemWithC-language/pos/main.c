#include"base.h"
#include"header.h"

int main(){

	init_head(&m);
	init_worker(&m2);
	startAdd();
	startNozi();
	init_table(&t1, 1);
	init_table(&t2, 2);
	init_table(&t3, 3);
	init_table(&t4, 4);
	init_table(&t5, 5);
	init_table(&t6, 6);

	system("MODE CON COLS=103 lINES=41");
	system("COLOR 0f");
	login();
}

