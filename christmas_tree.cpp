#include <iostream>
#include <Windows.h>
#include <ctime>
#include <thread>
using namespace std;
HANDLE out;
COORD pos;

void draw_tree(int h) {
	int color = rand() % 15 + 1;
	for (int i = 0; i <= h; i++) {
		SetConsoleTextAttribute(out, 0);
		for (int j = 0; j < h - i; j++) {
			cout << " ";
		}
		if (i % 3 == 0) {
			for (int j = i * 2 - 1; j > 0; j--) {
				if (j % 2 == 0) {
					SetConsoleTextAttribute(out, color * 16);
				}
				else {
					SetConsoleTextAttribute(out, 160);
				}
				cout << " ";
			}
		}
		else {
			SetConsoleTextAttribute(out, 160);
			for (int j = i * 2 - 1; j > 0; j--) {
				cout << " ";
			}
		}
		cout << endl;
	}
}
void en_draw_text() {
	int color = rand() % 15 + 1;
	SetConsoleTextAttribute(out, color);
	cout << "Hapy New Year!";
}
void ru_draw_text() {
	int color = rand() % 15 + 1;
	SetConsoleTextAttribute(out, color);
	cout << "С Новым Годом!";
}
int main()
{
	out = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(0));
	int h;
	cin >> h;

	system("CLS");
	setlocale(LC_ALL, "Russian");
	while (true) {
		pos.X = 0; pos.Y = 0;
		SetConsoleCursorPosition(out, pos);
		draw_tree(h);
		cout << endl;
		pos.X = (h - 8); pos.Y = h + 2;
		SetConsoleCursorPosition(out, pos);
		en_draw_text();
		pos.X = (h - 8); pos.Y = h + 4;
		SetConsoleCursorPosition(out, pos);
		ru_draw_text();

		this_thread::sleep_for(chrono::milliseconds(500));
	}
}