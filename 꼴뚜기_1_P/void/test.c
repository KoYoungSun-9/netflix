#include <stdio.h>
#include <Windows.h>
#include <conio.h>
void gotoxy(int row, int col);
void draw(void);
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

int main(void) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			if (i == 0 || i == 9 || j == 0 || j == 19)
				map[i][j] = '#';
			else
				map[i][j] = ' ';
		}
	}
	map[1][1] = '*';
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
		if (tick % 100 == 0) {
			// nx, ny: ���� ��ġ
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			// (nx, ny)�� �̵��� �� ������ pass
			if (nx > 0 && nx < 9 &&
				ny > 0 && ny < 19) {
				map[x][y] = ' '; // �����
				x = nx; y = ny; // �̵�
				map[x][y] = '*'; // �� ��ġ�� ���
			}
		}
		draw();
		Sleep(10);
		tick += 10;
	}
}
