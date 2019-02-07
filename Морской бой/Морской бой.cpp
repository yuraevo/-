#include<iostream>
#include<Windows.h>
#include<ctime>
#include<conio.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD position;
int count_for_ship = 0;
int y_coordinat_panel = 1;
int positionX_for_PlayerMove = 1;
int positionY_for_PlayerMove = 1;
void Download(); // загрузка
void Menu();
void DrawField(); // рисовка поля 
void DrawCoordinates(); // рисовка координат
void WorkWithKeys(char mass[10][20]); // работа с клавишами и заполнение ячеек 
void CreateShip4(char mass[10][20]); //создание бота
void CreateShip3(char mass[10][20]);
void CreateShip2(char mass[10][20]);
void CreateShip1(char mass[10][20]);
void CreateBot(char mass[10][20]);
void PlayerMove(char mass[10][20]);
void BotMove(char mass[10][20]);
void PrintMass(char mass[10][20]); // вывод массива на экран

int main()
{
	srand(time(0));
	system("mode con cols=130 lines=40");
	system("title Sea Battle");
	srand(time(0));
	char mass[10][20];
	Download();
	//Menu();
	DrawField();
	DrawCoordinates();
	WorkWithKeys(mass);
	CreateBot(mass);
	PlayerMove(mass);
	PrintMass(mass);
	_getch();
	_getch();
}
void PrintMass(char mass[10][20]) {
	position.X = 60;
	position.Y = 25;
	SetConsoleCursorPosition(hConsole, position);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			cout << mass[i][j] << " ";
		}
		position.Y++;
		SetConsoleCursorPosition(hConsole, position);

	}
}
void Download() {
	position.X = 55;
	position.Y = 32;
	SetConsoleCursorPosition(hConsole, position);
	cout << "DOWNLOAD...";
	for (int i = 15; i < 110; i++) {
		position.X = i;
		position.Y = 33;
		SetConsoleCursorPosition(hConsole, position);
		cout << (char)219;
		Sleep(20);
	}
	for (int i = 110; i >= 15; i--) {
		position.X = i;
		position.Y = 33;
		SetConsoleCursorPosition(hConsole, position);
		cout << " ";
	}
	position.X = 55;
	position.Y = 32;
	SetConsoleCursorPosition(hConsole, position);
	cout << "           ";
}
void Menu() {
	for (int i = 25; i < 50; i++) {
		SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		position.X = i;
		position.Y = 15;
		SetConsoleCursorPosition(hConsole, position);
		cout << char(219);
		Sleep(20);
	}
	for (int i = 25; i < 50; i++) {
		SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		position.X = i;
		position.Y = 15;
		SetConsoleCursorPosition(hConsole, position);
	}
	for (int i = 25; i < 50; i++) {
		SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		position.X = i;
		position.Y = 15;
		SetConsoleCursorPosition(hConsole, position);
	}
	//SetConsoleTextAttribute(hConsole, FORE);
}
void DrawField() {
	//SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	int x = 0;
	int y = 0;

	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(hConsole, position);
	cout << (char)218 << endl; 
	x++;
	for (y; y < 20; y++) {
		if (y % 2 == 0) {
			position.X = x;
			position.Y = y;
			SetConsoleCursorPosition(hConsole, position);
			cout << (char)180 << endl;
		}
		else {
			position.X = x;
			position.Y = y;
			SetConsoleCursorPosition(hConsole, position);
			cout << (char)179 << endl;
		}
		for (x; x < 40; x++) {
			if (x % 2 == 0) {
				position.X = x;
				position.Y = y;
				SetConsoleCursorPosition(hConsole, position);
				cout << (char)194 << endl;
			}
			else {
				position.X = x;
				position.Y = y;
				SetConsoleCursorPosition(hConsole, position);
				cout << (char)196 << endl;
			}
			if (x == 39) {
				position.X = x + 1;
				position.Y = y;
				SetConsoleCursorPosition(hConsole, position);
				cout << (char)191 << endl;
			}
		}
	}

	y = 1;
	x = 0;
	for (y; y <= 20; y++) {
		if (y % 2 == 0) {
			position.X = x;
			position.Y = y;
			SetConsoleCursorPosition(hConsole, position);
			cout << (char)195 << endl;
			if (y == 20) {
				position.X = x;
				position.Y = y;
				SetConsoleCursorPosition(hConsole, position);
				cout << (char)192 << endl;
			}
		}
		else {
			position.X = x;
			position.Y = y;
			SetConsoleCursorPosition(hConsole, position);
			cout << (char)179 << endl;
		}
	}

	for (y = 1; y <= 20; y++) {
		if (y % 2 == 0) {
			for (x = 1; x < 40; x++) {
				position.X = x;
				position.Y = y;
				SetConsoleCursorPosition(hConsole, position);
				cout << (char)196 << endl;
			}
		}
		if (y == 20) {
			position.X = x;
			position.Y = y;
			SetConsoleCursorPosition(hConsole, position);
			cout << (char)217 << endl;
		}
	}

	for (x = 1; x < 40; x++) {
		if (x % 2 == 0) {
			for (y = 1; y <= 20; y++) {
				if (y % 2 == 0) {
					position.X = x;
					position.Y = y;
					SetConsoleCursorPosition(hConsole, position);
					cout << (char)197 << endl;
					if (y == 20) {
						position.X = x;
						position.Y = y;
						SetConsoleCursorPosition(hConsole, position);
						cout << (char)193 << endl;
					}
				}
				else {
					position.X = x;
					position.Y = y;
					SetConsoleCursorPosition(hConsole, position);
					cout << (char)179 << endl;
				}
			}
		}
	}
	for (int x = 1, y = 10; x < 40; x++) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
		position.X = x;
		position.Y = y;
		SetConsoleCursorPosition(hConsole, position);
		cout << (char)196 << endl;
	}
	//SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);
}
void DrawCoordinates() {

	position.X = 41;
	position.Y = 1;
	SetConsoleCursorPosition(hConsole, position);
	cout << "1";
	
	position.X = 41;
	position.Y = 3;
	SetConsoleCursorPosition(hConsole, position);
	cout << "2";

	position.X = 41;
	position.Y = 5;
	SetConsoleCursorPosition(hConsole, position);
	cout << "3";

	position.X = 41;
	position.Y = 7;
	SetConsoleCursorPosition(hConsole, position);
	cout << "4";

	position.X = 41;
	position.Y = 9;
	SetConsoleCursorPosition(hConsole, position);
	cout << "5";

	position.X = 41;
	position.Y = 11;
	SetConsoleCursorPosition(hConsole, position);
	cout << "6";

	position.X = 41;
	position.Y = 13;
	SetConsoleCursorPosition(hConsole, position);
	cout << "7";

	position.X = 41;
	position.Y = 15;
	SetConsoleCursorPosition(hConsole, position);
	cout << "8";

	position.X = 41;
	position.Y = 17;
	SetConsoleCursorPosition(hConsole, position);
	cout << "9";

	position.X = 41;
	position.Y = 19;
	SetConsoleCursorPosition(hConsole, position);
	cout << "10";

	//

	position.X = 1;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "1";

	position.X = 3;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "2";

	position.X = 5;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "3";

	position.X = 7;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "4";

	position.X = 9;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "5";

	position.X = 11;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "6";

	position.X = 13;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "7";

	position.X = 15;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "8";

	position.X = 17;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "9";

	position.X = 19;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "0";



	position.X = 21;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "1";

	position.X = 23;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "2";

	position.X = 25;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "3";

	position.X = 27;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "4";

	position.X = 29;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "5";

	position.X = 31;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "6";

	position.X = 33;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "7";

	position.X = 35;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "8";

	position.X = 37;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "9";

	position.X = 39;
	position.Y = 21;
	SetConsoleCursorPosition(hConsole, position);
	cout << "0";
}
void WorkWithKeys(char mass[10][20]) {
	int x;
	int y;
	//int y_coordinat_panel = 1;
	char key;
	setlocale(0, "");
	position.X = 50;
	position.Y = y_coordinat_panel;
	SetConsoleCursorPosition(hConsole, position);
	//cout << "Добро пожаловать в морской бой. Ваше поле начинается с координат (6:1)" << endl;
	cout << "Д"; Sleep(30); cout << "о"; Sleep(30); cout << "б"; Sleep(30); cout << "р"; Sleep(30); cout << "о"; Sleep(30); cout << " "; Sleep(30);
	cout << "п"; Sleep(30); cout << "о"; Sleep(30); cout << "ж"; Sleep(30); cout << "а"; Sleep(30); cout << "л"; Sleep(30); cout << "о"; Sleep(30); cout << "в"; Sleep(30);
	cout << "а"; Sleep(30); cout << "т"; Sleep(30); cout << "ь"; Sleep(30); Sleep(30); cout << " "; Sleep(30); cout << "в"; Sleep(30); 
	cout << " "; Sleep(30); cout << "м"; Sleep(30); cout << "о"; Sleep(30); cout << "р"; Sleep(30); cout << "с"; Sleep(30);
	cout << "к"; Sleep(30); cout << "о"; Sleep(30); cout << "й"; Sleep(30); cout << " "; Sleep(30); cout << "б"; Sleep(30); cout << "о"; Sleep(30);
	cout << "й"; Sleep(30); cout << "."; Sleep(30); cout << " "; Sleep(30); cout << "В"; Sleep(30); cout << "а"; Sleep(30);
	cout << "ш"; Sleep(30); cout << "е"; Sleep(30); cout << " "; Sleep(30); cout << "п"; Sleep(30); 
	cout << "о"; Sleep(30); cout << "л"; Sleep(30); cout << "е"; Sleep(30); cout << " "; Sleep(30); cout << "н"; Sleep(30);
	cout << "а"; Sleep(30); cout << "ч"; Sleep(30); cout << "и"; Sleep(30); cout << "н"; Sleep(30); cout << "а"; Sleep(30);
	cout << "е"; Sleep(30); cout << "т"; Sleep(30); cout << "с"; Sleep(30); cout << "я"; Sleep(30); cout << " "; Sleep(30);
	cout << "с"; Sleep(30); cout << " "; Sleep(30); cout << "к"; Sleep(30); cout << "о"; Sleep(30); cout << "о"; Sleep(30);
	cout << "р"; Sleep(30); cout << "д"; Sleep(30); cout << "и"; Sleep(30); cout << "н"; Sleep(30); cout << "а"; Sleep(30); cout << "т"; Sleep(30);
	cout << " "; Sleep(30); cout << "("; Sleep(30); cout << "6"; Sleep(30); cout << ":"; Sleep(30); cout << "1"; Sleep(30);
	cout << ")"; Sleep(30);

	position.X = 50;
	position.Y = ++y_coordinat_panel;
	SetConsoleCursorPosition(hConsole, position);
	//cout << "Нажмите SPACE для начала игры.";
	cout << "Н"; Sleep(30); cout << "а"; Sleep(30); cout << "ж"; Sleep(30); cout << "м"; Sleep(30); cout << "и"; Sleep(30);
	cout << "т"; Sleep(30); cout << "е"; Sleep(30); cout << " "; Sleep(30); cout << "S"; Sleep(30); cout << "P"; Sleep(30);
	cout << "A"; Sleep(30); cout << "C"; Sleep(30); cout << "E"; Sleep(30); cout << " "; Sleep(30); cout << "д"; Sleep(30);
	cout << "л"; Sleep(30); cout << "я"; Sleep(30); cout << " "; Sleep(30); cout << "н"; Sleep(30); cout << "а"; Sleep(30);
	cout << "ч"; Sleep(30); cout << "а"; Sleep(30); cout << "л"; Sleep(30); cout << "а"; Sleep(30); cout << " "; Sleep(30);
	cout << "и"; Sleep(30); cout << "г"; Sleep(30); cout << "р"; Sleep(30); cout << "ы"; Sleep(30); cout << "."; Sleep(30);
	int x_for_mass = 0;
	int y_for_mass = 5;
	int count = 0;
	for(x = 1, y = 11;  ; ) {
		key = _getch();
		switch (key) {
		case 77: //вправо
			if (x > 38) {
				position.X = x - 2;
				x -= 2;
				position.Y = y;
				SetConsoleCursorPosition(hConsole, position);
			}
			position.X = x + 2;
			x += 2;
			position.Y = y;
			SetConsoleCursorPosition(hConsole, position);
			if(x_for_mass < 19)
				x_for_mass += 1;
			break;
		case 75: // влево
			if (x < 2) {
				position.X = x + 2;
				x += 2;
				position.Y = y;
				SetConsoleCursorPosition(hConsole, position);
			}
			position.X = x - 2;
			x -= 2;
			position.Y = y;
			SetConsoleCursorPosition(hConsole, position);
			if(x_for_mass > 0)
				x_for_mass -= 1;
			break;
		case 80: //вниз
			if (y > 18) {
				position.X = x;
				position.Y = y - 2;
				y -= 2;
				SetConsoleCursorPosition(hConsole, position);
			}
			position.X = x;
			position.Y = y + 2;
			y += 2;
			SetConsoleCursorPosition(hConsole, position);
			if(y_for_mass < 9)
				y_for_mass += 1;
			break;
		case 72: //вверх
			if (y <= 11) {
				position.X = x;
				position.Y = y + 2;
				y += 2;
				SetConsoleCursorPosition(hConsole, position);
			}
			position.X = x;
			position.Y = y - 2;
			y -= 2;
			SetConsoleCursorPosition(hConsole, position);
			if(y_for_mass > 5)
				y_for_mass -= 1;
			break;
		case 32: // space
			position.X = 50;
			position.Y = ++y_coordinat_panel;
			SetConsoleCursorPosition(hConsole, position);
			//cout << "Начало игры! Расставьте свои корабли, капитан!";
			cout << "Н"; Sleep(30); cout << "а"; Sleep(30); cout << "ч"; Sleep(30); cout << "а"; Sleep(30); cout << "л"; Sleep(30);
			cout << "о"; Sleep(30); cout << " "; Sleep(30); cout << "и"; Sleep(30); cout << "г"; Sleep(30); cout << "р"; Sleep(30);
			cout << "ы"; Sleep(30); cout << "!"; Sleep(30); cout << " "; Sleep(30); cout << "Р"; Sleep(30); cout << "а"; Sleep(30);
			cout << "с"; Sleep(30); cout << "с"; Sleep(30); cout << "т"; Sleep(30); cout << "а"; Sleep(30); cout << "в"; Sleep(30);
			cout << "ь"; Sleep(30); cout << "т"; Sleep(30); cout << "е"; Sleep(30); cout << " "; Sleep(30); cout << "с"; Sleep(30);
			cout << "в"; Sleep(30); cout << "о"; Sleep(30); cout << "и"; Sleep(30); cout << " "; Sleep(30); cout << "к"; Sleep(30);
			cout << "о"; Sleep(30); cout << "р"; Sleep(30); cout << "а"; Sleep(30); cout << "б"; Sleep(30); cout << "л"; Sleep(30);
			cout << "и"; Sleep(30); cout << ","; Sleep(30); cout << " "; Sleep(30); cout << "к"; Sleep(30); cout << "а"; Sleep(30);
			cout << "п"; Sleep(30); cout << "и"; Sleep(30); cout << "т"; Sleep(30); cout << "а"; Sleep(30); cout << "н"; Sleep(30);
			cout << "!"; Sleep(30);
			position.X = 50;
			position.Y = ++y_coordinat_panel;
			SetConsoleCursorPosition(hConsole, position);
			//cout << "Передвижение по координатам происходит с помощью стрелочек.";
			cout << "П"; Sleep(30); cout << "е"; Sleep(30); cout << "р"; Sleep(30); cout << "е"; Sleep(30); cout << "д"; Sleep(30);
			cout << "в"; Sleep(30); cout << "и"; Sleep(30); cout << "ж"; Sleep(30); cout << "е"; Sleep(30); cout << "н"; Sleep(30);
			cout << "и"; Sleep(30); cout << "е"; Sleep(30); cout << " "; Sleep(30); cout << "п"; Sleep(30); cout << "о"; Sleep(30); cout << " "; Sleep(30);
			cout << "к"; Sleep(30); cout << "о"; Sleep(30); cout << "о"; Sleep(30); cout << "р"; Sleep(30); cout << "д"; Sleep(30);
			cout << "и"; Sleep(30); cout << "н"; Sleep(30); cout << "а"; Sleep(30); cout << "т"; Sleep(30); cout << "а"; Sleep(30);
			cout << "м"; Sleep(30); cout << " "; Sleep(30); cout << "п"; Sleep(30); cout << "р"; Sleep(30); cout << "о"; Sleep(30);
			cout << "и"; Sleep(30); cout << "с"; Sleep(30); cout << "х"; Sleep(30); cout << "о"; Sleep(30); cout << "д"; Sleep(30);
			cout << "и"; Sleep(30); cout << "т"; Sleep(30); cout << " "; Sleep(30); cout << "с"; Sleep(30); cout << " "; Sleep(30);
			cout << "п"; Sleep(30); cout << "о"; Sleep(30); cout << "м"; Sleep(30); cout << "о"; Sleep(30); cout << "щ"; Sleep(30);
			cout << "ь"; Sleep(30); cout << "ю"; Sleep(30); cout << " "; Sleep(30); cout << "с"; Sleep(30); cout << "т"; Sleep(30);
			cout << "р"; Sleep(30); cout << "е"; Sleep(30); cout << "л"; Sleep(30); cout << "о"; Sleep(30); cout << "ч"; Sleep(30);
			cout << "е"; Sleep(30); cout << "к"; Sleep(30); cout << "."; Sleep(30);

			position.X = 50;
			position.Y = ++y_coordinat_panel;
			SetConsoleCursorPosition(hConsole, position);
			//cout << "Расстановка кораблей - ENTER.";
			cout << "Р"; Sleep(30); cout << "а"; Sleep(30); cout << "с"; Sleep(30); cout << "с"; Sleep(30); cout << "т"; Sleep(30);
			cout << "а"; Sleep(30); cout << "н"; Sleep(30); cout << "о"; Sleep(30); cout << "в"; Sleep(30); cout << "к"; Sleep(30);
			cout << "а"; Sleep(30); cout << " "; Sleep(30); cout << "к"; Sleep(30); cout << "о"; Sleep(30); cout << "р"; Sleep(30); cout << "а"; Sleep(30);
			cout << "б"; Sleep(30); cout << "л"; Sleep(30); cout << "е"; Sleep(30); cout << "й"; Sleep(30); cout << "-"; Sleep(30);
			cout << " "; Sleep(30); cout << "E"; Sleep(30); cout << "N"; Sleep(30); cout << "T"; Sleep(30); cout << "E"; Sleep(30);
			cout << "R"; Sleep(30); cout << "."; 

			position.X = 50;
			position.Y = ++y_coordinat_panel;
			SetConsoleCursorPosition(hConsole, position);
			//cout << "Завершение расстановки - ESC.";
			cout << "З"; Sleep(30); cout << "а"; Sleep(30); cout << "в"; Sleep(30); cout << "е"; Sleep(30); cout << "р"; Sleep(30);
			cout << "ш"; Sleep(30); cout << "е"; Sleep(30); cout << "н"; Sleep(30); cout << "и"; Sleep(30); cout << "е"; Sleep(30);
			cout << " "; Sleep(30); cout << "р"; Sleep(30); cout << "а"; Sleep(30); cout << "с"; Sleep(30); cout << "с"; Sleep(30); 
			cout << "т"; Sleep(30); cout << "а"; Sleep(30); cout << "н"; Sleep(30); cout << "о"; Sleep(30); cout << "в"; Sleep(30);
			cout << "к"; Sleep(30); cout << "и"; Sleep(30); cout << " "; Sleep(30); cout << "-"; Sleep(30); cout << " "; Sleep(30);
			cout << "E"; Sleep(30); cout << "S"; Sleep(30); cout << "C"; Sleep(30); cout << "."; Sleep(30);
			position.X = 1;
			position.Y = 11;
			SetConsoleCursorPosition(hConsole, position);
			x_for_mass = 0;
			y_for_mass = 5;
			break;
		case 13: // enter
			if (mass[y_for_mass][x_for_mass] != '*' && mass[y_for_mass][x_for_mass] != '0' &&
				mass[y_for_mass - 1][x_for_mass] != '*' && mass[y_for_mass - 1][x_for_mass] != '0' &&
				mass[y_for_mass - 1][x_for_mass - 1] != '*' && mass[y_for_mass - 1][x_for_mass - 1] != '0'&&
				mass[y_for_mass][x_for_mass - 1] != '*' && mass[y_for_mass][x_for_mass - 1] != '0' &&
				mass[y_for_mass + 1][x_for_mass] != '*' && mass[y_for_mass + 1][x_for_mass] != '0' &&
				mass[y_for_mass + 1][x_for_mass - 1] != '*' && mass[y_for_mass + 1][x_for_mass - 1] != '0' &&
				mass[y_for_mass][x_for_mass - 1] != '*' && mass[y_for_mass][x_for_mass - 1] != '0'
				&&
				mass[y_for_mass][x_for_mass] != '*' && mass[y_for_mass][x_for_mass] != '0' &&
				mass[y_for_mass - 2][x_for_mass] != '*' && mass[y_for_mass - 2][x_for_mass] != '0' &&
				mass[y_for_mass - 2][x_for_mass - 2] != '*' && mass[y_for_mass - 2][x_for_mass - 2] != '0'&&
				mass[y_for_mass][x_for_mass - 2] != '*' && mass[y_for_mass][x_for_mass - 2] != '0' &&
				mass[y_for_mass + 2][x_for_mass] != '*' && mass[y_for_mass + 2][x_for_mass] != '0' &&
				mass[y_for_mass + 2][x_for_mass - 2] != '*' && mass[y_for_mass + 2][x_for_mass - 2] != '0' &&
				mass[y_for_mass][x_for_mass - 2] != '*' && mass[y_for_mass][x_for_mass - 2] != '0') {
				count = 0;
			}
			if (count < 2) {
				count = count + 1;
				if (count == 1) {
					position.X = x;
					position.Y = y;
					SetConsoleCursorPosition(hConsole, position);
					cout << "*";
					if (y_for_mass == 5) {
						if (x_for_mass == 0) {
							mass[y_for_mass][x_for_mass] = '*';
							mass[y_for_mass][x_for_mass + 1] = '0';
							mass[y_for_mass + 1][x_for_mass] = '0';
							mass[y_for_mass + 1][x_for_mass + 1] = '0';
							break;
						}
						else {
							mass[y_for_mass][x_for_mass] = '*';
							mass[y_for_mass][x_for_mass + 1] = '0';
							mass[y_for_mass + 1][x_for_mass] = '0';
							mass[y_for_mass][x_for_mass - 1] = '0';
							mass[y_for_mass + 1][x_for_mass - 1] = '0';
							mass[y_for_mass + 1][x_for_mass + 1] = '0';
							break;
						}
					}
					else if (y_for_mass == 9) {
						if (x_for_mass == 0) {
							mass[y_for_mass][x_for_mass] = '*';
							mass[y_for_mass - 1][x_for_mass] = '0';
							mass[y_for_mass - 1][x_for_mass + 1] = '0';
							mass[y_for_mass][x_for_mass + 1] = '0';
							break;
						}
						else if (x_for_mass == 19) {
							mass[y_for_mass][x_for_mass] = '*';
							mass[y_for_mass - 1][x_for_mass] = '0';
							mass[y_for_mass - 1][x_for_mass - 1] = '0';
							mass[y_for_mass][x_for_mass - 1] = '0';
							break;
						}
						else {
							mass[y_for_mass][x_for_mass] = '*';
							mass[y_for_mass - 1][x_for_mass] = '0';
							mass[y_for_mass - 1][x_for_mass + 1] = '0';
							mass[y_for_mass - 1][x_for_mass - 1] = '0';
							mass[y_for_mass][x_for_mass + 1] = '0';
							mass[y_for_mass][x_for_mass - 1] = '0';
							break;
						}
					}
					else if (x_for_mass == 0 && y_for_mass != 0) {
						mass[y_for_mass][x_for_mass] = '*';
						mass[y_for_mass - 1][x_for_mass] = '0';
						mass[y_for_mass - 1][x_for_mass + 1] = '0';
						mass[y_for_mass][x_for_mass + 1] = '0';
						mass[y_for_mass + 1][x_for_mass + 1] = '0';
						mass[y_for_mass + 1][x_for_mass] = '0';
						break;
					}
					else if (x_for_mass == 19 && y_for_mass != 0) {
						mass[y_for_mass][x_for_mass] = '*';
						mass[y_for_mass - 1][x_for_mass] = '0';
						mass[y_for_mass - 1][x_for_mass - 1] = '0';
						mass[y_for_mass][x_for_mass - 1] = '0';
						mass[y_for_mass + 1][x_for_mass] = '0';
						mass[y_for_mass + 1][x_for_mass - 1] = '0';
						break;
					}
					else {
						if (mass[y_for_mass][x_for_mass + 1] == '*') {
							mass[y_for_mass][x_for_mass] = '*';
							mass[y_for_mass - 1][x_for_mass] = '0';
							mass[y_for_mass + 1][x_for_mass] = '0';
							mass[y_for_mass][x_for_mass - 1] = '0';
							mass[y_for_mass - 1][x_for_mass - 1] = '0';
							mass[y_for_mass - 1][x_for_mass + 1] = '0';
							mass[y_for_mass + 1][x_for_mass + 1] = '0';
							mass[y_for_mass + 1][x_for_mass - 1] = '0';
							break;
						}
						else {
							mass[y_for_mass][x_for_mass] = '*';
							mass[y_for_mass - 1][x_for_mass] = '0';
							mass[y_for_mass + 1][x_for_mass] = '0';
							mass[y_for_mass][x_for_mass - 1] = '0';
							mass[y_for_mass - 1][x_for_mass - 1] = '0';
							mass[y_for_mass - 1][x_for_mass + 1] = '0';
							mass[y_for_mass + 1][x_for_mass + 1] = '0';
							mass[y_for_mass + 1][x_for_mass - 1] = '0';
							mass[y_for_mass][x_for_mass + 1] = '0';
							break;
						}
					}
				}
				else {
					if (mass[y_for_mass - 1][x_for_mass - 1] != '*' &&
						mass[y_for_mass - 1][x_for_mass + 1] != '*' &&
						mass[y_for_mass + 1][x_for_mass - 1] != '*' &&
						mass[y_for_mass + 1][x_for_mass + 1] != '*') {
						mass[y_for_mass][x_for_mass] = '*';
					}
					else {
						position.X = 50;
						position.Y = ++y_coordinat_panel;
						SetConsoleCursorPosition(hConsole, position);
						//cout << "Вы ввели недопустимую координату, подумайте о другом местоположении.";
						cout << "В"; Sleep(30); cout << "ы"; Sleep(30); cout << " "; Sleep(30); cout << "в"; Sleep(30); cout << "в"; Sleep(30);
						cout << "е"; Sleep(30); cout << "л"; Sleep(30); cout << "и"; Sleep(30); cout << " "; Sleep(30); cout << "н"; Sleep(30);
						cout << "е"; Sleep(30); cout << "д"; Sleep(30); cout << "о"; Sleep(30); cout << "п"; Sleep(30); cout << "у"; Sleep(30); cout << "с"; Sleep(30);
						cout << "т"; Sleep(30); cout << "и"; Sleep(30); cout << "м"; Sleep(30); cout << "у"; Sleep(30); cout << "ю"; Sleep(30);
						cout << " "; Sleep(30); cout << "к"; Sleep(30); cout << "о"; Sleep(30); cout << "о"; Sleep(30); cout << "р"; Sleep(30);
						cout << "д"; Sleep(30); cout << "и"; Sleep(30); cout << "н"; Sleep(30); cout << "а"; Sleep(30); cout << "т"; Sleep(30);
						cout << "у"; Sleep(30); cout << ","; Sleep(30); cout << " "; Sleep(30); cout << "п"; Sleep(30); cout << "о"; Sleep(30);
						cout << "д"; Sleep(30); cout << "у"; Sleep(30); cout << "м"; Sleep(30); cout << "а"; Sleep(30); cout << "й"; Sleep(30);
						cout << "т"; Sleep(30); cout << "е"; Sleep(30); cout << " "; Sleep(30); cout << "о"; Sleep(30); cout << " "; Sleep(30);
						cout << "д"; Sleep(30); cout << "р"; Sleep(30); cout << "у"; Sleep(30); cout << "г"; Sleep(30); cout << "о"; Sleep(30);
						cout << "м"; Sleep(30); cout << " "; Sleep(30); cout << "м"; Sleep(30); cout << "е"; Sleep(30); cout << "с"; Sleep(30);
						cout << "т"; Sleep(30); cout << "о"; Sleep(30); cout << "п"; Sleep(30); cout << "о"; Sleep(30); cout << "л"; Sleep(30);
						cout << "о"; Sleep(30); cout << "ж"; Sleep(30); cout << "е"; Sleep(30); cout << "н"; Sleep(30); cout << "и"; Sleep(30);
						cout << "и"; Sleep(30); cout << "."; Sleep(30);
					}
				}
				if (mass[y_for_mass][x_for_mass] == '*' && mass[y_for_mass][x_for_mass + 1] == '*') {
					if (y_for_mass == 9) {
						position.X = x;
						position.Y = y;
						SetConsoleCursorPosition(hConsole, position);
						cout << "*";
						mass[y_for_mass][x_for_mass] = '*';
						mass[y_for_mass - 1][x_for_mass] = '0';
						mass[y_for_mass - 1][x_for_mass + 1] = '0';
						mass[y_for_mass - 1][x_for_mass - 1] = '0';
						mass[y_for_mass][x_for_mass - 1] = '0';
						break;
					}
					else if (y_for_mass == 5) {
						position.X = x;
						position.Y = y;
						SetConsoleCursorPosition(hConsole, position);
						cout << "*";
						mass[y_for_mass][x_for_mass] = '*';
						mass[y_for_mass][x_for_mass - 1] = '0';
						mass[y_for_mass + 1][x_for_mass + 1] = '0';
						mass[y_for_mass + 1][x_for_mass] = '0';
						mass[y_for_mass + 1][x_for_mass - 1] = '0';
						break;
					}
					else if(mass[y_for_mass][x_for_mass] == '*' && mass[y_for_mass][x_for_mass + 1] == '*') {
						position.X = x;
						position.Y = y;
						SetConsoleCursorPosition(hConsole, position);
						cout << "*";
						mass[y_for_mass - 1][x_for_mass] = '0';
						mass[y_for_mass + 1][x_for_mass + 1] = '0';
						mass[y_for_mass + 1][x_for_mass] = '0';
						mass[y_for_mass - 1][x_for_mass + 1] = '0';
						mass[y_for_mass][x_for_mass - 1] = '0';
						mass[y_for_mass - 1][x_for_mass - 1] = '0';
						mass[y_for_mass + 1][x_for_mass - 1] = '0';
						break;
					}
					else {
						position.X = 50;
						position.Y = ++ y_coordinat_panel;
						SetConsoleCursorPosition(hConsole, position);
						cout << "Вы ввели неправильную координату";
						count = 0;
						break;
					}
				}
				else if (mass[y_for_mass][x_for_mass] == '*' && mass[y_for_mass][x_for_mass - 1] == '*') {
					if (y_for_mass == 9) {
						position.X = x;
						position.Y = y;
						SetConsoleCursorPosition(hConsole, position);
						cout << "*";
						if (x_for_mass == 19) {
							mass[y_for_mass - 1][x_for_mass] = '0';
							mass[y_for_mass - 1][x_for_mass - 1] = '0';
							break;
						}
						mass[y_for_mass - 1][x_for_mass] = '0';
						mass[y_for_mass - 1][x_for_mass - 1] = '0';
						mass[y_for_mass - 1][x_for_mass + 1] = '0';
						mass[y_for_mass][x_for_mass + 1] = '0';
						break;
					}
					else if (y_for_mass == 5) {
						position.X = x;
						position.Y = y;
						SetConsoleCursorPosition(hConsole, position);
						cout << "*";
						if (x_for_mass == 19) {
							mass[y_for_mass + 1][x_for_mass] = '0';
							break;
						}
						else {
							mass[y_for_mass + 1][x_for_mass] = '0';
							mass[y_for_mass + 1][x_for_mass + 1] = '0';
							mass[y_for_mass][x_for_mass + 1] = '0';
							break;
						}
						mass[y_for_mass + 1][x_for_mass] = '0';
						mass[y_for_mass + 1][x_for_mass + 1] = '0';
						mass[y_for_mass][x_for_mass + 1] = '0';
						break;
					}
					else {
						position.X = x;
						position.Y = y;
						SetConsoleCursorPosition(hConsole, position);
						cout << "*";
						if (x_for_mass == 19) {
							mass[y_for_mass - 1][x_for_mass] = '0';
							//mass[y_for_mass - 1][x_for_mass - 1] = '0';
							mass[y_for_mass + 1][x_for_mass] = '0';
							break;
						}
						mass[y_for_mass - 1][x_for_mass] = '0';
						mass[y_for_mass - 1][x_for_mass - 1] = '0';
						mass[y_for_mass + 1][x_for_mass] = '0';
						mass[y_for_mass + 1][x_for_mass - 1] = '0';
						mass[y_for_mass + 1][x_for_mass + 1] = '0';
						mass[y_for_mass - 1][x_for_mass + 1] = '0';
						mass[y_for_mass][x_for_mass + 1] = '0';
						break;
					}
				}
				else if (mass[y_for_mass][x_for_mass] == '*' && mass[y_for_mass + 1][x_for_mass] == '*') {
					if (x_for_mass == 0) {
						position.X = x;
						position.Y = y;
						SetConsoleCursorPosition(hConsole, position);
						cout << "*";
						if (y_for_mass == 5) {
							if (mass[y_for_mass + 1][x_for_mass] == '*') {
								mass[y_for_mass][x_for_mass + 1] = '0';
								mass[y_for_mass + 1][x_for_mass + 1] = '0';
								break;
							}
							else if (mass[y_for_mass - 1][x_for_mass] = '*') {
								mass[y_for_mass + 1][x_for_mass] = '0';
								mass[y_for_mass][x_for_mass + 1] = '0';
								mass[y_for_mass + 1][x_for_mass + 1] = '0';
								break;
							}
						}
						if (y_for_mass == 9) {
							if (mass[y_for_mass + 1][x_for_mass] == '*') {
								mass[y_for_mass][x_for_mass + 1] = '0';
								mass[y_for_mass - 1][x_for_mass - 1] = '0';
								mass[y_for_mass - 1][x_for_mass] = '0';
								break;
							}
							else if (mass[y_for_mass - 1][x_for_mass] = '*') {
								//mass[y_for_mass + 1][x_for_mass] = '0';
								mass[y_for_mass][x_for_mass + 1] = '0';
								//mass[y_for_mass + 1][x_for_mass + 1] = '0';
								break;
							}
						}
						mass[y_for_mass][x_for_mass + 1] = '0';
						mass[y_for_mass + 1][x_for_mass + 1] = '0';
						mass[y_for_mass - 1][x_for_mass] = '0';
						mass[y_for_mass - 1][x_for_mass + 1] = '0';
						break;
					}
					else if (x_for_mass == 19) {
						position.X = x;
						position.Y = y;
						SetConsoleCursorPosition(hConsole, position);
						cout << "*";
						if (y_for_mass != 5) {
							mass[y_for_mass - 1][x_for_mass] = '0';
							mass[y_for_mass - 1][x_for_mass - 1] = '0';
						}
						mass[y_for_mass][x_for_mass - 1] = '0';
						mass[y_for_mass + 1][x_for_mass - 1] = '0';
						break;
					}
					else {
						position.X = x;
						position.Y = y;
						SetConsoleCursorPosition(hConsole, position);
						cout << "*";
						if (y_for_mass == 5) {
							mass[y_for_mass][x_for_mass + 1] = '0';
							mass[y_for_mass + 1][x_for_mass + 1] = '0';
							mass[y_for_mass][x_for_mass - 1] = '0';
							mass[y_for_mass + 1][x_for_mass - 1] = '0';
							break;
						}
						else {
							mass[y_for_mass][x_for_mass + 1] = '0';
							mass[y_for_mass + 1][x_for_mass + 1] = '0';
							mass[y_for_mass][x_for_mass - 1] = '0';
							mass[y_for_mass + 1][x_for_mass - 1] = '0';
							mass[y_for_mass - 1][x_for_mass] = '0';
							mass[y_for_mass - 1][x_for_mass - 1] = '0';
							mass[y_for_mass - 1][x_for_mass + 1] = '0';
							break;
						}
					}
				}
				else if (mass[y_for_mass][x_for_mass] == '*' && mass[y_for_mass - 1][x_for_mass] == '*') {
					if (x_for_mass == 0) {
						position.X = x;
						position.Y = y;
						SetConsoleCursorPosition(hConsole, position);
						cout << "*";
						mass[y_for_mass][x_for_mass + 1] = '0';
						mass[y_for_mass - 1][x_for_mass + 1] = '0';
						mass[y_for_mass + 1][x_for_mass] = '0';
						mass[y_for_mass + 1][x_for_mass + 1] = '0';
						break;
					}
					else if (x_for_mass == 19) {
						position.X = x;
						position.Y = y;
						SetConsoleCursorPosition(hConsole, position);
						cout << "*";
						mass[y_for_mass][x_for_mass - 1] = '0';
						mass[y_for_mass - 1][x_for_mass - 1] = '0';
						mass[y_for_mass + 1][x_for_mass] = '0';
						mass[y_for_mass + 1][x_for_mass - 1] = '0';
						break;
					}
					else {
						position.X = x;
						position.Y = y;
						SetConsoleCursorPosition(hConsole, position);
						cout << "*";
						if (y_for_mass == 5) {
							mass[y_for_mass][x_for_mass + 1] = '0';
							mass[y_for_mass + 1][x_for_mass] = '0';
							mass[y_for_mass + 1][x_for_mass - 1] = '0';
							mass[y_for_mass + 1][x_for_mass + 1] = '0';
							break;
						}
						else if (y_for_mass == 9) {
							mass[y_for_mass][x_for_mass + 1] = '0';
							mass[y_for_mass - 1][x_for_mass + 1] = '0';
							mass[y_for_mass][x_for_mass - 1] = '0';
							mass[y_for_mass - 1][x_for_mass - 1] = '0';
							break;
						}
						else {
							mass[y_for_mass][x_for_mass + 1] = '0';
							mass[y_for_mass - 1][x_for_mass + 1] = '0';
							mass[y_for_mass][x_for_mass - 1] = '0';
							mass[y_for_mass - 1][x_for_mass - 1] = '0';
							mass[y_for_mass + 1][x_for_mass] = '0';
							mass[y_for_mass + 1][x_for_mass - 1] = '0';
							mass[y_for_mass + 1][x_for_mass + 1] = '0';
							break;
						}
					}
				}
				/*else if (count > 1) {
					mass[y_for_mass][x_for_mass] = 'M';
					position.X = 50;
					position.Y = ++y_coordinat_panel;
					SetConsoleCursorPosition(hConsole, position);
					cout << "Вы ввели неправильную координату";
					count = 0;
					break;
				}*/
				break;
			}
			if (mass[y_for_mass][x_for_mass] != '*' && (mass[y_for_mass][x_for_mass + 1] != '*' && mass[y_for_mass][x_for_mass - 1] != '*')
				&& (mass[y_for_mass + 1][x_for_mass] != '*' && mass[y_for_mass - 1][x_for_mass] != '*')) {
				if (mass[y_for_mass][x_for_mass] != '0' && (mass[y_for_mass][x_for_mass + 1] != '0' && mass[y_for_mass][x_for_mass - 1] != '0')
					&& (mass[y_for_mass + 1][x_for_mass] != '0' && mass[y_for_mass - 1][x_for_mass] != '0')) {
					position.X = x;
					position.Y = y;
					SetConsoleCursorPosition(hConsole, position);
					cout << "*";
					mass[y_for_mass][x_for_mass] = '*';
					count = 1;
					break;
				}
				/*else {
					mass[y_for_mass][x_for_mass] = 'M';
					position.X = 50;
					position.Y = ++y_coordinat_panel;
					SetConsoleCursorPosition(hConsole, position);
					cout << "Вы ввели неправильную координату";
					count = 0;
					break;
				}*/
				break;
			}
			if (count == 2) {
				if (((mass[y_for_mass][x_for_mass] == '*' || (mass[y_for_mass][x_for_mass + 1] == '*' || mass[y_for_mass][x_for_mass - 1] == '*')) &&
					(mass[y_for_mass + 1][x_for_mass] != '*' || mass[y_for_mass - 1][x_for_mass] != '*'))) {
					position.X = x;
					position.Y = y;
					SetConsoleCursorPosition(hConsole, position);
					cout << "*";
					mass[y_for_mass][x_for_mass] = '*';
					if (y_for_mass == 5) {
						if (x_for_mass == 19) {
							mass[y_for_mass + 1][x_for_mass] = '0';
						}
						else {
							if (mass[y_for_mass][x_for_mass + 1] == '*') {
								mass[y_for_mass + 1][x_for_mass] = '0';
								mass[y_for_mass + 1][x_for_mass + 1] = '0';
								mass[y_for_mass + 1][x_for_mass - 1] = '0';
								mass[y_for_mass][x_for_mass - 1] = '0';
								break;
							}
							else if (mass[y_for_mass][x_for_mass - 1] == '*') {
								mass[y_for_mass + 1][x_for_mass] = '0';
								mass[y_for_mass + 1][x_for_mass + 1] = '0';
								mass[y_for_mass + 1][x_for_mass - 1] = '0';
								mass[y_for_mass][x_for_mass + 1] = '0';
								break;
							}
						}
						break;
					}
					else if (y_for_mass == 9) {
						if (x_for_mass == 19) {
							mass[y_for_mass - 1][x_for_mass] = '0';
							mass[y_for_mass - 1][x_for_mass - 1] = '0';
							//mass[y_for_mass][x_for_mass - 1] = '0';
							break;
						}
						else {
							if (mass[y_for_mass][x_for_mass + 1] == '*') {
								if (x_for_mass == 0) {
									mass[y_for_mass - 1][x_for_mass] = '0';
									break;
								}
								mass[y_for_mass - 1][x_for_mass] = '0';
								mass[y_for_mass - 1][x_for_mass + 1] = '0';
								mass[y_for_mass - 1][x_for_mass - 1] = '0';
								mass[y_for_mass][x_for_mass - 1] = '0';
								break;
							}
							else if (mass[y_for_mass][x_for_mass - 1] == '*') {
								mass[y_for_mass - 1][x_for_mass] = '0';
								mass[y_for_mass - 1][x_for_mass + 1] = '0';
								mass[y_for_mass - 1][x_for_mass - 1] = '0';
								mass[y_for_mass][x_for_mass + 1] = '0';
								break;
							}
						}
						break; 
					}
					else { 
						if (x_for_mass == 19) {
							mass[y_for_mass + 1][x_for_mass] = '0';
							mass[y_for_mass - 1][x_for_mass] = '0';
							break;
						}
						else if (mass[y_for_mass][x_for_mass + 1] == '*') {
							mass[y_for_mass + 1][x_for_mass] = '0';
							mass[y_for_mass - 1][x_for_mass] = '0';
							mass[y_for_mass + 1][x_for_mass + 1] = '0';
							mass[y_for_mass - 1][x_for_mass + 1] = '0';
							mass[y_for_mass - 1][x_for_mass - 1] = '0';
							mass[y_for_mass + 1][x_for_mass - 1] = '0';
							mass[y_for_mass][x_for_mass - 1] = '0';
							break;
						}
						else {
							mass[y_for_mass + 1][x_for_mass] = '0';
							mass[y_for_mass - 1][x_for_mass] = '0';
							mass[y_for_mass][x_for_mass + 1] = '0';
							mass[y_for_mass + 1][x_for_mass + 1] = '0';
							mass[y_for_mass - 1][x_for_mass + 1] = '0';
						}
					}
					break;
				}
				else if ((mass[y_for_mass][x_for_mass] == '*' || mass[y_for_mass - 1][x_for_mass] == '*' || mass[y_for_mass + 1][x_for_mass] == '*') &&
					(mass[y_for_mass][x_for_mass + 1] != '*' || mass[y_for_mass][x_for_mass - 1] != '*')) {
					position.X = x;
					position.Y = y;
					SetConsoleCursorPosition(hConsole, position);
					cout << "*";
					mass[y_for_mass][x_for_mass] = '*';
					if (x_for_mass == 0) {
						if (mass[y_for_mass + 1][x_for_mass] == '*') {
							if (y_for_mass == 5) {
								mass[y_for_mass][x_for_mass + 1] = '0';
								break;
							}
							mass[y_for_mass][x_for_mass + 1] = '0';
							mass[y_for_mass - 1][x_for_mass] = '0';
							mass[y_for_mass - 1][x_for_mass + 1] = '0';
							break;
						}
						else if (mass[y_for_mass - 1][x_for_mass] == '*') {
							mass[y_for_mass][x_for_mass + 1] = '0';
							mass[y_for_mass + 1][x_for_mass] = '0';
							mass[y_for_mass + 1][x_for_mass + 1] = '0';
							break;
						}
						//mass[y_for_mass][x_for_mass + 1] = '0';
						////mass[y_for_mass + 1][x_for_mass] = '0';
						//mass[y_for_mass + 1][x_for_mass + 1] = '0';
						////mass[y_for_mass - 1][x_for_mass] = '0';
						//mass[y_for_mass - 1][x_for_mass + 1] = '0';
						//mass[y_for_mass + 1][x_for_mass] = '0';
					}
					else if (x_for_mass == 19) {
						if (mass[y_for_mass + 1][x_for_mass] == '*') {
							if (y_for_mass == 5) {
								mass[y_for_mass][x_for_mass - 1] = '0';
								break;
							}
							else {
								mass[y_for_mass][x_for_mass - 1] = '0';
								mass[y_for_mass - 1][x_for_mass] = '0';
								mass[y_for_mass - 1][x_for_mass - 1] = '0';
								break;
							}
						}
						else {
							mass[y_for_mass][x_for_mass - 1] = '0';
							mass[y_for_mass + 1][x_for_mass] = '0';
							mass[y_for_mass + 1][x_for_mass - 1] = '0';
						}
					}
					else {
						if (mass[y_for_mass - 1][x_for_mass] == '*') {
							if (y_for_mass == 5) {
								mass[y_for_mass][x_for_mass + 1] = '0';
								mass[y_for_mass][x_for_mass - 1] = '0';
								mass[y_for_mass + 1][x_for_mass - 1] = '0';
								mass[y_for_mass + 1][x_for_mass + 1] = '0';
								mass[y_for_mass + 1][x_for_mass] = '0';
								break;
							}
							else if (y_for_mass == 9) {
								mass[y_for_mass][x_for_mass + 1] = '0';
								mass[y_for_mass][x_for_mass - 1] = '0';
								break;
							}
							else {
								mass[y_for_mass][x_for_mass + 1] = '0';
								mass[y_for_mass][x_for_mass - 1] = '0';
								mass[y_for_mass + 1][x_for_mass - 1] = '0';
								mass[y_for_mass + 1][x_for_mass + 1] = '0';
								mass[y_for_mass + 1][x_for_mass] = '0';

							}
						}
						else if (mass[y_for_mass + 1][x_for_mass] == '*') {
							if (y_for_mass == 5) {
								mass[y_for_mass][x_for_mass + 1] = '0';
								mass[y_for_mass][x_for_mass - 1] = '0';
								break;
							}
							mass[y_for_mass][x_for_mass + 1] = '0';
							mass[y_for_mass][x_for_mass - 1] = '0';
							mass[y_for_mass - 1][x_for_mass] = '0';
							mass[y_for_mass - 1][x_for_mass + 1] = '0';
							mass[y_for_mass - 1][x_for_mass - 1] = '0';
							break;
						}
						//mass[y_for_mass][x_for_mass + 1] = '0';
						//mass[y_for_mass][x_for_mass - 1] = '0';
						////mass[y_for_mass + 1][x_for_mass] = '0';
						//mass[y_for_mass + 1][x_for_mass - 1] = '0';
						//mass[y_for_mass + 1][x_for_mass + 1] = '0';
						//mass[y_for_mass - 1][x_for_mass] = '0';
						//mass[y_for_mass - 1][x_for_mass + 1] = '0';
						//mass[y_for_mass - 1][x_for_mass - 1] = '0';
					}
					break;
				}
				if (mass[y_for_mass][x_for_mass] != '*' && (mass[y_for_mass][x_for_mass + 1] != '*' || mass[y_for_mass][x_for_mass - 1] != '*')
					&& (mass[y_for_mass + 1][x_for_mass] != '*' || mass[y_for_mass - 1][x_for_mass] != '*')) {
					if (mass[y_for_mass][x_for_mass] != '0' && (mass[y_for_mass][x_for_mass + 1] != '0' || mass[y_for_mass][x_for_mass - 1] != '0')
						&& (mass[y_for_mass + 1][x_for_mass] != '0' || mass[y_for_mass - 1][x_for_mass] != '0')) {
						position.X = x;
						position.Y = y;
						SetConsoleCursorPosition(hConsole, position);
						cout << "*";
						mass[y_for_mass][x_for_mass] = '*';
						//count = 1;
						break;
					}
				}
				/*else {
					position.X = 50;
					position.Y = ++y_coordinat_panel;
					SetConsoleCursorPosition(hConsole, position);
					cout << "Вы ввели неправильную координату";
					count = 0;
					break;
				}*/
			}
		case 27: 
			position.X = 50;
			position.Y = ++y_coordinat_panel;
			SetConsoleCursorPosition(hConsole, position);
			//cout << "Ваши корабли расставлены и готовы к бою!";
			cout << "В"; Sleep(30); cout << "а"; Sleep(30); cout << "ш"; Sleep(30); cout << "и"; Sleep(30); cout << " "; Sleep(30);
			cout << "к"; Sleep(30); cout << "о"; Sleep(30); cout << "р"; Sleep(30); cout << "а"; Sleep(30); cout << "б"; Sleep(30);
			cout << "л"; Sleep(30); cout << "и"; Sleep(30); cout << " "; Sleep(30); cout << "р"; Sleep(30); cout << "а"; Sleep(30); cout << "с"; Sleep(30);
			cout << "с"; Sleep(30); cout << "т"; Sleep(30); cout << "а"; Sleep(30); cout << "в"; Sleep(30); cout << "л"; Sleep(30);
			cout << "е"; Sleep(30); cout << "н"; Sleep(30); cout << "ы"; Sleep(30); cout << " "; Sleep(30); cout << "и"; Sleep(30);
			cout << " "; Sleep(30); cout << "г"; Sleep(30); cout << "о"; Sleep(30); cout << "т"; Sleep(30); cout << "о"; Sleep(30);
			cout << "в"; Sleep(30); cout << "ы"; Sleep(30); cout << " "; Sleep(30); cout << "к"; Sleep(30); cout << " "; Sleep(30);
			cout << "б"; Sleep(30); cout << "о"; Sleep(30); cout << "ю"; Sleep(30); cout << "!";
			return;
		}
	}
}
void CreateShip4(char mass[10][20]) {
	int i = rand() % 5;
	int j = rand() % 20;
	int granitca_vertical_min = 0;
	int granitca_vertical_max = 4;
	int granitca_horisontal_min = 0;
	int granitca_horisontal_max = 19;
	int napravlenie = rand() % 2;

	if (napravlenie == 0) {
		if (j <= 16 && j <= granitca_horisontal_max) {
			for (int a = 0; a < 4; a++) { 
				if (i == granitca_vertical_min) {
					if (a == 0 && j != granitca_horisontal_min) {
						mass[i][j - 1] = '0';
						mass[i + 1][j - 1] = '0';
					}
					if (a == 3 && j != granitca_horisontal_max) {
						mass[i][j + 1] = '0';
						mass[i + 1][j + 1] = '0';
					}
					mass[i + 1][j] = '0';
				}
				if (i == granitca_vertical_max) {
					if (a == 0 && j != granitca_horisontal_min) {
						mass[i][j - 1] = '0';
						mass[i - 1][j - 1] = '0';
					}
					if (a == 3 && j != granitca_horisontal_max) {
						mass[i][j + 1] = '0';
						mass[i - 1][j + 1] = '0';
					}
					mass[i - 1][j] = '0';
				}
				if (i != granitca_vertical_min && i != granitca_vertical_max) {
					if (a == 0 && j != granitca_horisontal_min) {
						mass[i][j - 1] = '0';
						mass[i - 1][j - 1] = '0';
						mass[i + 1][j - 1] = '0';
					}
					if (a == 3 && j != granitca_horisontal_max) {
						mass[i][j + 1] = '0';
						mass[i + 1][j + 1] = '0';
						mass[i - 1][j + 1] = '0';
					}
					mass[i - 1][j] = '0';
					mass[i + 1][j] = '0';
				}
				mass[i][j++] = '+';
			}
		}
		else  {
			CreateShip4(mass);
		}
	}
	else if (napravlenie == 1) {
		if (i <= 1 && i <= granitca_vertical_max) {
			for (int b = 0; b < 4; b++) {
				if (j == granitca_horisontal_min) {
					if (b == 0 && i != granitca_vertical_min) {
						mass[i - 1][j] = '0';
						mass[i - 1][j + 1] = '0';
					}
					if (b == 3 && i != granitca_vertical_max) {
						mass[i + 1][j] = '0';
						mass[i + 1][j + 1] = '0';
					}
					mass[i][j + 1] = '0';
				}
				if (j == granitca_horisontal_max) {
					if (b == 0 && i != granitca_vertical_min) {
						mass[i - 1][j] = '0';
						mass[i - 1][j - 1] = '0';
					}
					if (b == 3 && i != granitca_vertical_max) {
						mass[i + 1][j] = '0';
						mass[i + 1][j - 1] = '0';
					}
					mass[i][j - 1] = '0';
				}
				if (j != granitca_horisontal_min && j != granitca_horisontal_max) {
					if (b == 0 && i != granitca_vertical_min) {
						mass[i - 1][j] = '0';
						mass[i - 1][j - 1] = '0';
						mass[i - 1][j + 1] = '0';
					}
					if (b == 3 && i != granitca_vertical_max) {
						mass[i + 1][j] = '0';
						mass[i + 1][j - 1] = '0';
						mass[i + 1][j + 1] = '0';
					}
					mass[i][j + 1] = '0';
					mass[i][j - 1] = '0';
				}
				mass[i++][j] = '+';
			}
		}
		else {
			CreateShip4(mass);
		}
	}
}

void CreateShip3(char mass[10][20]) {
	int i = rand() % 5;
	int j = rand() % 20;
	int granitca_vertical_min = 0;
	int granitca_vertical_max = 4;
	int granitca_horisontal_min = 0;
	int granitca_horisontal_max = 19;
	int napravlenie = rand() % 2;

	if (mass[i][j] != '+' && mass[i][j] != '0' &&
		mass[i + 1][j] != '+' && mass[i + 1][j] != '0' &&
		mass[i + 1][j + 1] != '+' && mass[i + 1][j + 1] != '0' &&
		mass[i + 1][j - 1] != '+' && mass[i + 1][j - 1] != '0' &&

		mass[i - 1][j] != '+' && mass[i - 1][j] != '0' &&
		mass[i - 1][j + 1] != '+' && mass[i - 1][j + 1] != '0' &&
		mass[i - i][j - 1] != '+' && mass[i - 1][j - 1] != '0' &&

		mass[i][j - 1] != '+' && mass[i][j - 1] != '0' &&
		mass[i][j + 1] != '+' && mass[i][j + 1] != '0'
		

		&& mass[i + 2][j] != '+' && mass[i + 2][j] != '0' &&
		mass[i + 2][j + 2] != '+' && mass[i + 2][j + 2] != '0' &&
		mass[i + 2][j - 2] != '+' && mass[i + 2][j - 2] != '0' &&

		mass[i - 2][j] != '+' && mass[i - 2][j] != '0' &&
		mass[i - 2][j + 2] != '+' && mass[i - 2][j + 2] != '0' &&
		mass[i - 2][j - 2] != '+' && mass[i - 2][j - 2] != '0' &&

		mass[i][j - 2] != '+' && mass[i][j - 2] != '0' &&
		mass[i][j + 2] != '+' && mass[i][j + 2] != '0') {

		if (napravlenie == 0) {
			if (j <= 17 && j <= granitca_horisontal_max) {
				for (int b = 0; b < 3; b++) { 
					if (i == granitca_vertical_min) {
						if (b == 0 && j != granitca_horisontal_min) {
							mass[i][j - 1] = '0';
							mass[i + 1][j - 1] = '0';
						}
						if (b == 2 && j != granitca_horisontal_max) {
							mass[i][j + 1] = '0';
							mass[i + 1][j + 1] = '0';
						}
						mass[i + 1][j] = '0';
					}
					if (i == granitca_vertical_max) {
						if (b == 0 && j != granitca_horisontal_min) {
							mass[i][j - 1] = '0';
							mass[i - 1][j - 1] = '0';
						}
						if (b == 2 && j != granitca_horisontal_max) {
							mass[i][j + 1] = '0';
							mass[i - 1][j + 1] = '0';
						}
						mass[i - 1][j] = '0';
					}
					if (i != granitca_vertical_min && i != granitca_vertical_max) {
						if (b == 0 && j != granitca_horisontal_min) {
							mass[i][j - 1] = '0';
							mass[i - 1][j - 1] = '0';
							mass[i + 1][j - 1] = '0';
						}
						if (b == 2 && j != granitca_horisontal_max) {
							mass[i][j + 1] = '0';
							mass[i + 1][j + 1] = '0';
							mass[i - 1][j + 1] = '0';
						}
						mass[i - 1][j] = '0';
						mass[i + 1][j] = '0';
					}
					mass[i][j++] = '+';
				}

			}
			else {
				CreateShip3(mass);
			}
		}
		else if (napravlenie == 1) {
			if (i <= 2 && i <= granitca_vertical_max) {
				for (int b = 0; b < 3; b++) {
					if (j == granitca_horisontal_min) {
						if (b == 0 && i != granitca_vertical_min) {
							mass[i - 1][j] = '0';
							mass[i - 1][j + 1] = '0';
						}
						if (b == 2 && i != granitca_vertical_max) {
							mass[i + 1][j] = '0';
							mass[i + 1][j + 1] = '0';
						}
						mass[i][j + 1] = '0';
					}
					if (j == granitca_horisontal_max) {
						if (b == 0 && i != granitca_vertical_min) {
							mass[i - 1][j] = '0';
							mass[i - 1][j - 1] = '0';
						}
						if (b == 2 && i != granitca_vertical_max) {
							mass[i + 1][j] = '0';
							mass[i + 1][j - 1] = '0';
						}
						mass[i][j - 1] = '0';
					}
					if (j != granitca_horisontal_min && j != granitca_horisontal_max) {
						if (b == 0 && i != granitca_vertical_min) {
							mass[i - 1][j] = '0';
							mass[i - 1][j - 1] = '0';
							mass[i - 1][j + 1] = '0';
						}
						if (b == 2 && i != granitca_vertical_max) {
							mass[i + 1][j] = '0';
							mass[i + 1][j - 1] = '0';
							mass[i + 1][j + 1] = '0';
						}
						mass[i][j + 1] = '0';
						mass[i][j - 1] = '0';
					}
					mass[i++][j] = '+';
				}
			}
			else {
				CreateShip3(mass);
			}
		}
	}	
	else {
	CreateShip3(mass);
	}
}

void CreateShip2(char mass[10][20]) {
	count_for_ship++;
		int i = rand() % 5;
		int j = rand() % 20;
		int granitca_vertical_min = 0;
		int granitca_vertical_max = 4;
		int granitca_horisontal_min = 0;
		int granitca_horisontal_max = 19;
		int napravlenie = rand() % 2;
		if (mass[i][j] != '+' && mass[i][j] != '0' &&
			mass[i + 1][j] != '+' && mass[i + 1][j] != '0' &&
			mass[i + 1][j + 1] != '+' && mass[i + 1][j + 1] != '0' &&
			mass[i + 1][j - 1] != '+' && mass[i + 1][j - 1] != '0' &&

			mass[i - 1][j] != '+' && mass[i - 1][j] != '0' &&
			mass[i - 1][j + 1] != '+' && mass[i - 1][j + 1] != '0' &&
			mass[i - i][j - 1] != '+' && mass[i - 1][j - 1] != '0' &&

			mass[i][j - 1] != '+' && mass[i][j - 1] != '0' &&
			mass[i][j + 1] != '+' && mass[i][j + 1] != '0'


			&& mass[i + 2][j] != '+' && mass[i + 2][j] != '0' &&
			mass[i + 2][j + 2] != '+' && mass[i + 2][j + 2] != '0' &&
			mass[i + 2][j - 2] != '+' && mass[i + 2][j - 2] != '0' &&

			mass[i - 2][j] != '+' && mass[i - 2][j] != '0' &&
			mass[i - 2][j + 2] != '+' && mass[i - 2][j + 2] != '0' &&
			mass[i - 2][j - 2] != '+' && mass[i - 2][j - 2] != '0' &&

			mass[i][j - 2] != '+' && mass[i][j - 2] != '0' &&
			mass[i][j + 2] != '+' && mass[i][j + 2] != '0') {

			if (napravlenie == 0) {
				if (j <= 18 && j <= granitca_horisontal_max) {
					for (int b = 0; b < 2; b++) {
						if (i == granitca_vertical_min) {
							if (b == 0 && j != granitca_horisontal_min) {
								mass[i][j - 1] = '0';
								mass[i + 1][j - 1] = '0';
							}
							if (b == 1 && j != granitca_horisontal_max) {
								mass[i][j + 1] = '0';
								mass[i + 1][j + 1] = '0';
							}
							mass[i + 1][j] = '0';
						}
						if (i == granitca_vertical_max) {
							if (b == 0 && j != granitca_horisontal_min) {
								mass[i][j - 1] = '0';
								mass[i - 1][j - 1] = '0';
							}
							if (b == 1 && j != granitca_horisontal_max) {
								mass[i][j + 1] = '0';
								mass[i - 1][j + 1] = '0';
							}
							mass[i - 1][j] = '0';
						}
						if (i != granitca_vertical_min && i != granitca_vertical_max) {
							if (b == 0 && j != granitca_horisontal_min) {
								mass[i][j - 1] = '0';
								mass[i - 1][j - 1] = '0';
								mass[i + 1][j - 1] = '0';
							}
							if (b == 1 && j != granitca_horisontal_max) {
								mass[i][j + 1] = '0';
								mass[i + 1][j + 1] = '0';
								mass[i - 1][j + 1] = '0';
							}
							mass[i - 1][j] = '0';
							mass[i + 1][j] = '0';
						}
						mass[i][j++] = '+';
					}

				}
				else {
					CreateShip2(mass);
				}
			}
			else if (napravlenie == 1) {
				if (i <= 3 && i <= granitca_vertical_max) {
					for (int b = 0; b < 2; b++) {
						if (j == granitca_horisontal_min) {
							if (b == 0 && i != granitca_vertical_min) {
								mass[i - 1][j] = '0';
								mass[i - 1][j + 1] = '0';
							}
							if (b == 1 && i != granitca_vertical_max) {
								mass[i + 1][j] = '0';
								mass[i + 1][j + 1] = '0';
							}
							mass[i][j + 1] = '0';
						}
						if (j == granitca_horisontal_max) {
							if (b == 0 && i != granitca_vertical_min) {
								mass[i - 1][j] = '0';
								mass[i - 1][j - 1] = '0';
							}
							if (b == 1 && i != granitca_vertical_max) {
								mass[i + 1][j] = '0';
								mass[i + 1][j - 1] = '0';
							}
							mass[i][j - 1] = '0';
						}
						if (j != granitca_horisontal_min && j != granitca_horisontal_max) {
							if (b == 0 && i != granitca_vertical_min) {
								mass[i - 1][j] = '0';
								mass[i - 1][j - 1] = '0';
								mass[i - 1][j + 1] = '0';
							}
							if (b == 1 && i != granitca_vertical_max) {
								mass[i + 1][j] = '0';
								mass[i + 1][j - 1] = '0';
								mass[i + 1][j + 1] = '0';
							}
							mass[i][j + 1] = '0';
							mass[i][j - 1] = '0';
						}
						mass[i++][j] = '+';
					}
				}
				else {
					CreateShip2(mass);
				}
			}
		
		else {
				if (count_for_ship < 2000) {
					CreateShip2(mass);
			}
				else {
					count_for_ship = 0;
					return;
				}
			//CreateShip2(mass);
		}
	}
	else {
		return;
	}
}

void CreateShip1(char mass[10][20]) {
	count_for_ship++;
	int i = rand() % 5;
	int j = rand() % 20;
	int granitca_vertical_min = 0;
	int granitca_vertical_max = 4;
	int granitca_horisontal_min = 0;
	int granitca_horisontal_max = 19;
	int napravlenie = rand() % 2;
	if (mass[i][j] != '+' && mass[i][j] != '0' &&
		mass[i + 1][j] != '+' && mass[i + 1][j] != '0' &&
		mass[i + 1][j + 1] != '+' && mass[i + 1][j + 1] != '0' &&
		mass[i + 1][j - 1] != '+' && mass[i + 1][j - 1] != '0' &&

		mass[i - 1][j] != '+' && mass[i - 1][j] != '0' &&
		mass[i - 1][j + 1] != '+' && mass[i - 1][j + 1] != '0' &&
		mass[i - i][j - 1] != '+' && mass[i - 1][j - 1] != '0' &&

		mass[i][j - 1] != '+' && mass[i][j - 1] != '0' &&
		mass[i][j + 1] != '+' && mass[i][j + 1] != '0'


		&& mass[i + 2][j] != '+' && mass[i + 2][j] != '0' &&
		mass[i + 2][j + 2] != '+' && mass[i + 2][j + 2] != '0' &&
		mass[i + 2][j - 2] != '+' && mass[i + 2][j - 2] != '0' &&

		mass[i - 2][j] != '+' && mass[i - 2][j] != '0' &&
		mass[i - 2][j + 2] != '+' && mass[i - 2][j + 2] != '0' &&
		mass[i - 2][j - 2] != '+' && mass[i - 2][j - 2] != '0' &&

		mass[i][j - 2] != '+' && mass[i][j - 2] != '0' &&
		mass[i][j + 2] != '+' && mass[i][j + 2] != '0') {

		if (napravlenie == 0) {
			if (j <= 19 && j <= granitca_horisontal_max) {
				for (int b = 0; b < 1; b++) {
					if (i == granitca_vertical_min) {
						if (b == 0 && j != granitca_horisontal_min) {
							mass[i][j - 1] = '0';
							mass[i + 1][j - 1] = '0';
						}
						if (b == 0 && j != granitca_horisontal_max) {
							mass[i][j + 1] = '0';
							mass[i + 1][j + 1] = '0';
						}
						mass[i + 1][j] = '0';
					}
					if (i == granitca_vertical_max) {
						if (b == 0 && j != granitca_horisontal_min) {
							mass[i][j - 1] = '0';
							mass[i - 1][j - 1] = '0';
						}
						if (b == 0 && j != granitca_horisontal_max) {
							mass[i][j + 1] = '0';
							mass[i - 1][j + 1] = '0';
						}
						mass[i - 1][j] = '0';
					}
					if (i != granitca_vertical_min && i != granitca_vertical_max) {
						if (b == 0 && j != granitca_horisontal_min) {
							mass[i][j - 1] = '0';
							mass[i - 1][j - 1] = '0';
							mass[i + 1][j - 1] = '0';
						}
						if (b == 0 && j != granitca_horisontal_max) {
							mass[i][j + 1] = '0';
							mass[i + 1][j + 1] = '0';
							mass[i - 1][j + 1] = '0';
						}
						mass[i - 1][j] = '0';
						mass[i + 1][j] = '0';
					}
					mass[i][j++] = '+';
				}

			}
			else {
				CreateShip1(mass);
			}
		}
		else if (napravlenie == 1) {
			if (i <= 3 && i <= granitca_vertical_max) {
				for (int b = 0; b < 1; b++) {
					if (j == granitca_horisontal_min) {
						if (b == 0 && i != granitca_vertical_min) {
							mass[i - 1][j] = '0';
							mass[i - 1][j + 1] = '0';
						}
						if (b == 0 && i != granitca_vertical_max) {
							mass[i + 1][j] = '0';
							mass[i + 1][j + 1] = '0';
						}
						mass[i][j + 1] = '0';
					}
					if (j == granitca_horisontal_max) {
						if (b == 0 && i != granitca_vertical_min) {
							mass[i - 1][j] = '0';
							mass[i - 1][j - 1] = '0';
						}
						if (b == 0 && i != granitca_vertical_max) {
							mass[i + 1][j] = '0';
							mass[i + 1][j - 1] = '0';
						}
						mass[i][j - 1] = '0';
					}
					if (j != granitca_horisontal_min && j != granitca_horisontal_max) {
						if (b == 0 && i != granitca_vertical_min) {
							mass[i - 1][j] = '0';
							mass[i - 1][j - 1] = '0';
							mass[i - 1][j + 1] = '0';
						}
						if (b == 0 && i != granitca_vertical_max) {
							mass[i + 1][j] = '0';
							mass[i + 1][j - 1] = '0';
							mass[i + 1][j + 1] = '0';
						}
						mass[i][j + 1] = '0';
						mass[i][j - 1] = '0';
					}
					mass[i++][j] = '+';
				}
			}
			else {
				CreateShip1(mass);
			}
		}
	}
	else {
		if (count_for_ship < 2000) {
		CreateShip1(mass);
	}
	else {
		count_for_ship = 0;
		return;
		}
	}
}
void CreateBot(char mass[10][20]) {
	position.X = 50;
	position.Y = ++y_coordinat_panel;
	SetConsoleCursorPosition(hConsole, position);
	//cout << "Бот расставляет свои корабли...";
	cout << "Б"; Sleep(30); cout << "о"; Sleep(30); cout << "т"; Sleep(30); cout << " "; Sleep(30); cout << "р"; Sleep(30);
	cout << "а"; Sleep(30); cout << "с"; Sleep(30); cout << "с"; Sleep(30); cout << "т"; Sleep(30); cout << "а"; Sleep(30);
	cout << "в"; Sleep(30); cout << "л"; Sleep(30); cout << "я"; Sleep(30); cout << "е"; Sleep(30); cout << "т"; Sleep(30); cout << " "; Sleep(30);
	cout << "с"; Sleep(30); cout << "в"; Sleep(30); cout << "о"; Sleep(30); cout << "и"; Sleep(30); cout << " "; Sleep(30);
	cout << "к"; Sleep(30); cout << "о"; Sleep(30); cout << "р"; Sleep(30); cout << "а"; Sleep(30); cout << "б"; Sleep(30);
	cout << "л"; Sleep(30); cout << "и"; Sleep(30); cout << "."; Sleep(30); cout << "."; Sleep(30); cout << "."; Sleep(30);
	CreateShip4(mass);
	CreateShip3(mass);
	CreateShip3(mass);
	CreateShip2(mass);
	CreateShip2(mass);
	CreateShip2(mass);
	CreateShip2(mass);
	CreateShip1(mass);
	CreateShip1(mass);
	CreateShip1(mass);
	CreateShip1(mass);
	CreateShip1(mass);
	CreateShip1(mass);
	CreateShip1(mass);
	CreateShip1(mass);
	//cout << "Нанесите свой первый удар!";
	position.X = 50;
	position.Y = ++y_coordinat_panel;
	SetConsoleCursorPosition(hConsole, position);
	cout << "Н"; Sleep(30); cout << "а"; Sleep(30); cout << "н"; Sleep(30); cout << "е"; Sleep(30); cout << "с"; Sleep(30);
	cout << "и"; Sleep(30); cout << "т"; Sleep(30); cout << "е"; Sleep(30); cout << " "; Sleep(30); cout << "с"; Sleep(30);
	cout << "в"; Sleep(30); cout << "о"; Sleep(30); cout << "й"; Sleep(30); Sleep(30); cout << " "; Sleep(30);
	cout << "у"; Sleep(30); cout << "д"; Sleep(30); cout << "а"; Sleep(30); cout << "р"; Sleep(30); cout << "!"; Sleep(30);
}
void PlayerMove(char mass[10][20]) {
	position.X = positionX_for_PlayerMove;
	position.Y = positionY_for_PlayerMove;
	SetConsoleCursorPosition(hConsole, position);
	int x;
	int y;
	char key;
	setlocale(0, "");
	int x_for_mass = 0;
	int y_for_mass = 0;
	int count = 0;
	for (x = 1, y = 1; ; ) {
		key = _getch();
		switch (key) {
		case 77: //вправо
			if (x > 38) {
				x_for_mass -= 1;
				position.X = x - 2;
				x -= 2;
				position.Y = y;
				SetConsoleCursorPosition(hConsole, position);
			}
			x_for_mass += 1;
			position.X = x + 2;
			x += 2;
			position.Y = y;
			SetConsoleCursorPosition(hConsole, position);
			if (x_for_mass < 19)
				x_for_mass += 1;
			break;
		case 75: // влево
			if (x < 2) {
				x_for_mass -= 1;
				position.X = x + 2;
				x += 2;
				position.Y = y;
				SetConsoleCursorPosition(hConsole, position);
			}
			x_for_mass = -1;
			position.X = x - 2;
			x -= 2;
			position.Y = y;
			SetConsoleCursorPosition(hConsole, position);
			if (x_for_mass > 0)
				x_for_mass -= 1;
			break;
		case 80: //вниз
			if (y > 8) {
				y_for_mass -= 1;
				position.X = x;
				position.Y = y - 2;
				y -= 2;
				SetConsoleCursorPosition(hConsole, position);
			}
			y_for_mass += 1;
			position.X = x;
			position.Y = y + 2;
			y += 2;
			SetConsoleCursorPosition(hConsole, position);
			if (y_for_mass < 0)
				y_for_mass += 1;
			break;
		case 72: //вверх
			if (y <= 1) {
				y_for_mass += 1;
				position.X = x;
				position.Y = y + 2;
				y += 2;
				SetConsoleCursorPosition(hConsole, position);
			}
			y_for_mass -= 1;
			position.X = x;
			position.Y = y - 2;
			y -= 2;
			SetConsoleCursorPosition(hConsole, position);
			if (y_for_mass > 5)
				y_for_mass -= 1;
			break;
		case 13: 
			if (mass[y_for_mass][x_for_mass] == '+' && mass[y_for_mass][x_for_mass] != 'X' &&  mass[y_for_mass][x_for_mass] != '#') {
				position.X = x;
				position.Y = y;
				SetConsoleCursorPosition(hConsole, position);
				cout << "X";
				mass[y_for_mass][x_for_mass] = 'X';
				//PrintMass(mass);
				PlayerMove(mass);
			}
			else {
				position.X = x;
				position.Y = y;
				SetConsoleCursorPosition(hConsole, position);
				cout << "#";
				mass[y_for_mass][x_for_mass] = '#';
				position.X = 50;
				position.Y = ++y_coordinat_panel;
				SetConsoleCursorPosition(hConsole, position);
				//cout << "Вы не попали.";
				BotMove(mass);
			}
		}
	}
}
void BotMove(char mass[10][20]) {
	int y = rand() % 11 + 7;
	int x = rand() % 20;
	if (mass[y][x] == '*') {
		mass[y][x] = 'X';
		position.X = x;
		position.Y = y + 1;
		SetConsoleCursorPosition(hConsole, position);
		cout << "X";
		BotMove(mass);
	}
	else {
		position.X = 50;
		position.Y = ++y_coordinat_panel;
		SetConsoleCursorPosition(hConsole, position);
		//cout << "Бот не попал.";
		
		if (y >= 11 && y % 2 != 0) {
			position.X = (x * 2) - 1;
			position.Y = y;
			SetConsoleCursorPosition(hConsole, position);
			if (y == 11) {
				y = 6;
				mass[y - 1][x - 1] = '#';
				cout << "#";
			}
			else if (y == 13) {
				y = 7;
				mass[y - 1][x - 1] = '#';
				cout << "#";
			}
			else if (y == 15) {
				y = 8;
				mass[y - 1][x - 1] = '#';
				cout << "#";
			}
			else if (y == 17) {
				y = 9;
				mass[y - 1][x - 1] = '#';
				cout << "#";
			}
			else if (y == 19) {
				y = 10;
				mass[y - 1][x - 1] = '#';
				cout << "#";
			}
		}
		else if(y >= 11 && y % 2 == 0) {
			position.X = (x * 2) - 1;
			position.Y = --y;
			SetConsoleCursorPosition(hConsole, position);
			if (y == 11) {
				y = 6;
				mass[y - 1][x - 1] = '#';
				cout << "#";
			}
			else if (y == 13) {
				y = 7;
				mass[y - 1][x - 1] = '#';
				cout << "#";
			}
			else if (y == 15) {
				y = 8;
				mass[y - 1][x - 1] = '#';
				cout << "#";
			}
			else if (y == 17) {
				y = 9;
				mass[y - 1][x - 1] = '#';
				cout << "#";
			}
			else if (y == 19) {
				y = 10;
				mass[y - 1][x - 1] = '#';
				cout << "#";
			}
		}
		else {
			BotMove(mass);
		}
		//PrintMass(mass);
		PlayerMove(mass);
	}
}