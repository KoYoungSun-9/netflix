// 2023-2 ������α׷��� ����: �޲ٹ� ����
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "jjuggumi.h"
#include <conio.h>
#include <Windows.h>

void gotoxy(int row, int col);
void draw(void);

#define	DATA_FILE	"jjuggumi.dat"

int jjuggumi_init(void);
void intro(void);
void mugunghwa(void);

int tick = 0; // �ð�
char map[10][20], front[10][20];

void gotoxy(int row, int col) {
	COORD pos = { col, row }; // ��, �� �ݴ�� ����
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		pos
	);
}
void draw(void) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			if (front[i][j] != map[i][j]) {
				front[i][j] = map[i][j];
				gotoxy(i, j);
				printf("%c", front[i][j]);
			}
		}
	}
}


// low �̻� high ���� ������ �߻���Ű�� �Լ�
int randint(int low, int high) {
	int rnum = rand() % (high - low + 1) + low;
	return rnum;
}

int jjuggumi_init(void) {
	srand((unsigned int)time(NULL));

	printf("�÷��̾� ��: ");
	scanf_s("%d", &n_player);

	n_alive = n_player;
	for (int i = 0; i < n_player; i++) {
		player[i] = true;
	}
	return 0;
}

void intro(void) {
	system("cls");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n");
	printf("     @@@@@@.=@@@@@:     @@@@@@= @@@@@@,                 @@-             ;;. @@#               @@@   \n");
	printf("     @@@@@@#@@@@@@@     @@@@@@@ @@@@@@@                .@@:             @@; @@#     *@@@#     @@@   \n");
	printf("        @@@-   =@@$         =@@     @@@    @@@@@@@@@@  .@@:   #@@@@@@@  @@; @@#    @@@@@@@-   @@@   \n");
	printf("        @@@    @@@          =@@     @@#    @@@@@@@@@@  .@@:   $@@@@@@@  @@; @@#   @@@   @@@   @@@   \n");
	printf("      ,@@@@@~ @@@@          $@@     @@=    @@@    @@@  .@@:        =@@  @@; @@#   @@-    @@!  @@@   \n");
	printf("     *@@@.@@@@@@@@@*        @@@     @@*    @@@    @@@  .@@:        @@@  @@; @@#  :@@     @@@  @@@   \n");
	printf("    @@@@   @@@@= @@@@       @@@    .@@,    @@@    @@@  .@@:        @@@;;@@; @@#  .@@.    @@$  @@@   \n");
	printf("    #@*   -@@@:   *@@       @@!    ~@@     @@@    @@@  .@@:       !@@@@@@@; @@#   @@@   #@@.  @@@   \n");
	printf("           @@         ,;;;;;@@*;;;;$@@;;;  @@@    @@@  .@@:       @@@;;;@@; @@#   -@@@@@@@=   @@@   \n");
	printf("                      $@@@@@@@@@@@@@@@@@@  @@@    @@@  .@@:      @@@.   @@; @@#    ,@@@@@:    @@@   \n");
	printf("   @@@@@@@@@@@@@@@@@@@,;;;;;;;@@@;;;;;;;;  @@@    @@@  .@@:     $@@=    @@; @@#               @@@   \n");
	printf("   @@@@@@@@@@@@@@@@@@@        @@@          @@@    @@@  .@@:    #@@@     @@; @@#                     \n");
	printf("           @@@                @@@          @@@@@@@@@@  .@@:   @@@@      @@; @@#      @@@@@@@@@@@@   \n");
	printf("           @@@                @@@          :@@@@@@@@=  .@@:  ;@@$       @@; @@#      @@@@@@@@@@@@   \n");
	printf("           @@@                @@@                      .@@:   #-        @@; @@#      @@;      @@@   \n");
	printf("           @@@                @@@                      .@@:             @@; @@#      @@;      @@@   \n");
	printf("           @@@                @@@                      .@@:             @@; @@#      @@;      @@@   \n");
	printf("           @@@                @@@                      .@@:             @@; @@#      @@@@@@@@@@@@   \n");
	printf("           @@@                @@@                      .@@:             ;;, @@#      @@@@@@@@@@@@   \n\n\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n");
	printf("W"); Sleep(100); printf("E"); Sleep(100); printf("L"); Sleep(100); printf("C"); Sleep(100); printf("O"); Sleep(100); printf("M");
	Sleep(100); printf("E"); Sleep(100); printf(" "); Sleep(100); printf("T"); Sleep(100); printf("O"); Sleep(100); printf(" "); Sleep(100); printf("T");
	Sleep(100); printf("H"); Sleep(100); printf("E"); Sleep(100); printf(" "); Sleep(100); printf("G"); Sleep(100); printf("A"); Sleep(100); printf("M");
	Sleep(100); printf("E"); Sleep(100); printf("."); Sleep(100); printf("."); Sleep(100); printf("."); Sleep(100); printf("."); Sleep(100); printf("."); Sleep(2000);
	system("cls");

}

void mugunghwa(void) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				if (i == 0 || i == 9 || j == 0 || j == 19)
					map[i][j] = '#';
				else
					map[i][j] = ' ';
			}
		}
		map[1][1] =  '*';
		// 4������ ����(��x, ��y)
		int dx[4] = { -1, 1, 0, 0 };
		int dy[4] = { 0, 0, -1, 1 };
		int x = 1, y = 1;
		int dir = 3; // ����(direction). ó������ ������
		while (1) {
			// 'w', 's', 'a', 'd': �̵�, 'q': ����
			if (_kbhit()) {
				int key = _getch();
				switch (key) {
				case 'w': dir = 0; break; // up (x-1, y+0)
				case 's': dir = 1; break; // down (x+1, y+0)
				case 'a': dir = 2; break; // left (x+0, y-1)
				case 'd': dir = 3; break; // right (x+0, y+1)
				case 'q': return 0;
				}
			}
			// 0.1�ʸ��� '*' �̵�

			draw();
			Sleep(10);
			tick += 10;
		}
	
}





int main(void) {
	//jjuggumi_init();
	//sample();
	//intro();
	//nightgame();
	mugunghwa();
	//juldarigi();
	//jebi();
	//ending();
	return 0;
}

