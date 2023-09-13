#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h> 
#include<time.h>
#include<string.h>
#pragma execution_character_set("utf-8")
#pragma warning(disable:4996)
struct player {
	char name[30];
	int win;
	int lose;
};
void loading(int)
{
	system("cls||clear");
	printf("\n\n\t\t please wait ...\n");
	printf("\n\t\033[107m");
	for (int i = 0; i < 31; i++)
		printf(" ");
	printf("\r\t");
	for (int i = 0; i < 31; i++) {
		printf("█");
		Sleep(40);
	}
	Sleep(100);
	printf("\033[47m\n");
	//Sleep(100);
	system("cls||clear");
}
void move(int[22][22], int, int, char, int*, int*, int, int, int, int*);
void play(player*, int, int, int);
void Showgame(int[22][22], int, int, int, int, int);
void buildfield(int[22][22], int, int, int);
void printbigletters(char*);
int main()
{
	SetConsoleOutputCP(65001);

	char a = 177, b = 219;
	system("color 71");
	loading(0);
	//return 0;
	player p1[10];
	int i = 0, j = -1;
	char ss[30];
tag2:
	j = -1;
	system("color 17");
	system("cls||clear");
	char ch[] = "MINEnnn1";
	char* CH = ch;

	printf("\n");
	printbigletters(CH);

	printf("\n");
	strcpy(ch, "SWEEPER");
	printbigletters(CH);

	if (i == 0) {
		system("color 17");
		Sleep(400);
		system("color 71");
		Sleep(400);
		system("color 17");
		Sleep(400);
		system("color 71");
		Sleep(400);
		system("color 17");
	}
	//2022
	//2580

	printf("\n \033[37m► please enter your name: ");


	if (i > 0)
		scanf("\n");
	gets_s(ss);
	system("color 71");
	loading(0);
	system("color 71");

	for (int k = 0; k < i; k++)
	{
		if (strcmp(p1[k].name, ss) == 0) {
			j = k;
			break;
		}
	}
	if (j == -1)
	{
		j = i;
		strcpy(p1[j].name, ss);
		p1[j].win = 0;
		p1[j].lose = 0;
	}
	//\x9658\x9658
	//++Func : mine sweeper
	system("color 71");
	while (1)
	{
	tag:
		system("cls||clear");
		system("color 71");
		printf("● %s\n► %d wins\n► %d losses\n\n", p1[j].name, p1[j].win, p1[j].lose);
		printf("1.Change Name\n2.Play!\n3.Back\n4.Exit\n\n");
		int flag;
		scanf("%d", &flag);
		//int Res = -1;
		system("cls||clear");
		switch (flag)
		{
		case 1:
			system("cls||clear");
			printf("Youn New Name : ");
			scanf("\n");
			gets_s(p1[j].name);
			system("color 72");
			printf("Your name changed seccesfully!\n");
			Sleep(800);
			goto tag;
			break;
		case 2:

			play(&p1[j], 0, 0, 0);

			break;
		case 3:
			i++;
			goto tag2;
			break;

		case 4:
			return 0;

		}

		//break;

	}

	return 0;
}

void Showgame(int arr[22][22], int n, int m, int flag, int finaal, int bomb)//more needs: profile  + finalresultmode
{
	// wprintf(L"\033[4m"); (underline text)
	 // show some more things
	printf("\n ► Flag : %d ♠ \n", flag);
	printf(" ► Bomb : %d Ơ \n", bomb);
	printf("\n    ");
	for (int i = 1; i <= m; i++)
	{
		if (i < 10) {
			printf("_%d_ ", i);
		}
		else
			printf("%d_ ", i);
	}
	printf("\n");
	//printf("\033[m\n");

	for (int i = 1; i <= n; i++)
	{

		if (i < 10) {
			printf("%d  ", i);
		}
		else
			printf("%d ", i);

		printf("\033[107m|");

		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] >= 10)
				//printf("_");
				printf("_%d_|", arr[i][j] % 10);
			else if (arr[i][j] < -10)
			{

				printf("_♠_|");
			}
			else if (arr[i][j] != -1 && arr[i][j] != -2 || finaal == 0)
				printf("___|");
			if (finaal == 1)
			{
				if (arr[i][j] == -1)
					printf("_Ơ_|");
				if (arr[i][j] == -2)
					printf("\033[41m_\033[97mƠ\033[31m_\033[107m|");
			}

		}
		printf("\033[47m\n");
	}
	if (finaal == 0) {
		printf("Enter your input as row number ♦ space ♦ column number ♦ space ♦ L or R click\n");
		printf("● row between 1 and %d ● column between 1 and %d ●\n", n, m);
	}
	//printf("\033[47m");
}
void buildfield(int arr[22][22], int n, int m, int bomb)
{
	int temp[22] = { 0 };
	int tempp = bomb;
	srand(time(0));
	while (bomb > 0)
	{
		int i = rand() % n + 1;
		int j = rand() % m + 1;
		if (arr[i][j] != -1 && temp[j] < 3)
		{
			arr[i][j] = -1;
			bomb--;
			temp[j]++;
			for (int x = i - 1; x <= i + 1; x++)
			{
				for (int y = j - 1; y <= j + 1; y++)
				{
					if (arr[x][y] != -1)
						arr[x][y] += 1;
				}
			}
		}
	}
	//printf("do you need cheat?!!\n1.no           2.yes\n");
	printf("enter any key to continue :)\n");
	//here is the secret code for cheat -> character '2'
	int k = 0;
	k = getch();
	//scanf("%d", &k);
	if (k == '2') {
		printf("\033[35mthis is a cheat!:)\n");
		Showgame(arr, n, m, tempp, 1, tempp);
		printf("\033[34mEnter any key to continue");
		getch();
	}
}
void move(int arr[22][22], int x, int y, char LR, int* flags, int* result, int wat, int n, int m, int* bombb)
{
	if (x > n || x < 1 || y>m || y < 1)
	{
		if (wat == 1) {
			printf("invalid numbers! try again");
			Sleep(900);
		}

	}
	else if (LR != 'l' && LR != 'L' && LR != 'r' && LR != 'R')
	{
		if (wat == 1) {
			printf("invalid! try again");
			Sleep(900);
		}
	}
	else if (LR == 'L' || LR == 'l')
	{
		if (arr[x][y] == -1)
		{
			system("color 74");
			printf("YOU LOST :(\n");
			*result = 0;
			arr[x][y] = -2;

			Sleep(1000);
			//system("color 75");
		}
		else if (arr[x][y] < -10)
		{
			if (wat == 1) {
				printf("remove the flag first\n");
				Sleep(900);
			}
			if (wat == 0 && arr[x][y] == -20)
			{
				if (arr[x - 1][y] == 0)
					move(arr, x - 1, y, 'L', flags, result, 0, n, m, bombb);
				if (arr[x + 1][y] == 0)
					move(arr, x + 1, y, 'L', flags, result, 0, n, m, bombb);
				if (arr[x][y - 1] == 0)
					move(arr, x, y - 1, 'L', flags, result, 0, n, m, bombb);
				if (arr[x][y + 1] == 0)
					move(arr, x, y + 1, 'L', flags, result, 0, n, m, bombb);
				// move(arr, i, j, 'L', flags, result, 0, n, m);
			}
		}
		else if (arr[x][y] >= 10)
		{
			if (wat == 1) {
				printf("try again\n");
				Sleep(900);
			}
		}
		else if (arr[x][y] >= 0)
		{
			arr[x][y] += 10;
			if (wat == 1) {
				system("color 72");
				Sleep(800);
				system("color 71");
			}
			if (arr[x][y] == 10)
			{

				if (arr[x - 1][y] == 0 || arr[x - 1][y] == -20)
					move(arr, x - 1, y, 'L', flags, result, 0, n, m, bombb);
				if (arr[x + 1][y] == 0 || arr[x + 1][y] == -20)
					move(arr, x + 1, y, 'L', flags, result, 0, n, m, bombb);
				if (arr[x][y - 1] == 0 || arr[x][y - 1] == -20)
					move(arr, x, y - 1, 'L', flags, result, 0, n, m, bombb);
				if (arr[x][y + 1] == 0 || arr[x][y + 1] == -20)
					move(arr, x, y + 1, 'L', flags, result, 0, n, m, bombb);
				// move(arr, i, j, 'L', flags, result, 0, n, m);

			}
		}
	}
	else if (LR == 'R' || LR == 'r')
	{
		if (arr[x][y] == -1)
		{
			//put flag of bomb
			if (*flags > 0) {
				arr[x][y] = -11;
				*flags = *flags - 1;
				*bombb = *bombb - 1;
				printf("flaged\n");
				system("color 72");
				Sleep(800);
				system("color 71");
			}
			else
			{
				printf("No more flag\n");
				Sleep(900);


			}
		}
		else if (arr[x][y] == -11)
		{
			//remove flag of bomb
			arr[x][y] = -1;
			*flags = *flags + 1;
			*bombb = *bombb + 1;
			printf("flag removed\n");
			system("color 72");
			Sleep(800);
			system("color 71");
		}
		else if (arr[x][y] <= -20)
		{
			//remove flag of nonbomb
			arr[x][y] = -arr[x][y] - 20;
			*flags = *flags + 1;
			printf("flag removed\n");
			system("color 72");
			Sleep(800);
			system("color 71");
		}
		else if (arr[x][y] >= 10)
		{
			printf("try again\n");
			Sleep(900);
		}
		else if (arr[x][y] >= 0)
		{
			//put flag in nunbomb
			if (*flags > 0) {
				arr[x][y] = -arr[x][y] - 20;
				printf("flaged\n");
				*flags = *flags - 1;
				system("color 72");
				Sleep(800);
				system("color 71");
			}
			else
			{
				printf("No more flag\n");
				Sleep(900);
			}
		}
	}
	//check win
	if (*bombb == 0)
	{
		*result = 1;
		printf("YOU WON! :)\n");
		system("color 72");
		Sleep(1000);
	}
	/*int p = 0;
	if (*flags == 0)
	{

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (arr[i][j] == -1)
					p = 1;
			}
		}
		if (p == 0) {
			*result = 1;
			printf("you won! :)\n");
			system("color 72");
			Sleep(1000);
		}
	}*/

}
void play(player * playerr, int flag1, int n, int ff)
{
tag3:
	//system("color 71");
	printf("\033[34m");
	int m = 0;
	int bombhelp = 0;
	char natije[20];
	char* NAT = natije;
	if (ff == 0)
	{
		system("cls||clear");
		printf("● %s\n► %d wins\n► %d losses\n\n", (*playerr).name, (*playerr).win, (*playerr).lose);
	}
	if (flag1 == 0) {
		printf(" ► choose the field :\n1.Easy      9*9\n2.Normal   12*12\n3.Hard     15*20\n4.Custom\n5.Back\n");
	}
	printf("\n");
	int arr[22][22] = { 0 };
	//int flag1;
	int result = -1;//0 lose ,1 win
	int contnu = 0;
	if (flag1 == 0) {
		scanf("%d", &flag1);
	}
	printf("\n");
	int numbomb = 0;

	if (flag1 == 1) {
		numbomb = 10;
		n = 9;
		m = 9;
		buildfield(arr, 9, 9, 10);
	}
	else if (flag1 == 2) {
		numbomb = 20;
		n = 12;
		m = 12;
		buildfield(arr, 12, 12, 20);
	}
	else if (flag1 == 3)
	{
		numbomb = 40;
		n = 15;
		m = 20;
		buildfield(arr, 15, 20, 40);
	}
	else if (flag1 == 4)
	{

		if (n == 0) {
			while (1) {

				printf("Row : ");
				scanf("%d", &n);
				if (n > 1 && n <= 20)
					break;
				else if (n <= 1)
					printf("too small!\n");
				else if (n > 20)
					printf("too big!\n");
			}

			while (1) {
				printf("Column : ");
				scanf("%d", &m);
				if (m > 1 && m <= 20)
					break;
				else if (m <= 1)
					printf("too small!\n");
				else if (m > 20)
					printf("too big!\n");
			}
			while (1) {
				printf("Bomb : ");
				scanf("%d", &numbomb);
				if (numbomb <= m * 3 - m / 2)
					break;
				else
					printf("too much bomb!\n");
			}
		}
		buildfield(arr, n, m, numbomb);
	}
	else if (flag1 == 5)
	{
		goto tagb;
	}
	else {
		flag1 = 0;
		n = 0;
		goto tag3;
	}
	system("cls||clear");

	bombhelp = numbomb;
	//start game


	system("color 71");
	loading(0);
	system("color 71");


	while (result == -1) {
		system("cls||clear");
		system("color 71");

		printf("● %s\n► %d wins\n► %d losses\n", (*playerr).name, (*playerr).win, (*playerr).lose);
		Showgame(arr, n, m, numbomb, 0, bombhelp);
		int x = 0, y = 0;
		char LR = 'z';
		scanf("%d%d", &x, &y);
		scanf("\n%c", &LR);
		//b for back: (secret code)
		if (LR == 'B' || LR == 'b')
		{
			printf(" ► Are you sure?\n1.end\n2.continue\n");
			int bb = 0;
			scanf("%d", &bb);
			printf("\n");
			if (bb == 1)
			{
				flag1 = 0;
				n = 0;
				ff = 1;
				goto tag3;
			}
			else if (bb == 2)
				continue;
		}


		//R is for flagg
		//L is for click 
		move(arr, x, y, LR, &numbomb, &result, 1, n, m, &bombhelp);
		//break;

	}
	if (result == 0)
		(*playerr).lose++;
	else if (result == 1)
		(*playerr).win++;

	system("cls||clear");

	printf("● %s\n► %d wins\n► %d losses\n", (*playerr).name, (*playerr).win, (*playerr).lose);
	Showgame(arr, n, m, numbomb, 1, bombhelp);

	if (result == 1)
		strcpy(natije, "YOUnnnnWON");
	else if (result == 0)
		strcpy(natije, "YOUnnnnLOST");
	wprintf(L"\n");
	printbigletters(NAT);


	printf("\033[34m");
	printf("\n ► Play again?\n1.YES\n2.NO\n");
	printf("\n");

	scanf("%d", &contnu);
	printf("\n");
	if (contnu == 1)
		play(playerr, 0, 0, 1);
tagb:


	if (ff == 0) {
		system("color 71");
		loading(0);
		system("color 71");
	}


}

//mine sweeper2 the emtiyazy ok
//voroodi format unhandled
//doesnt show the number of bomb
void printbigletters(char* s)
{
	const int p = 20;
	int a = 0;
	int b = 1;
	for (b = 1; b <= 5; b++) {
		a = 0;
		while (*(s + a) != '\0') {
			char c = *(s + a);
			if (c == 'M')
			{

				if (b == 1)
				{
					printf(" ██");
					Sleep(p);
					printf("██     ");
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██  ");
					Sleep(p);

				}
				else if (b == 2)
				{
					printf(" ██ ");
					Sleep(p);
					printf("██   ");
					Sleep(p);
					printf("██ ");
					Sleep(p);
					printf("██  ");
					Sleep(p);
				}
				else if (b == 3)
				{
					printf(" ██  ");
					Sleep(p);
					printf("██ ");
					Sleep(p);
					printf("██  ");
					Sleep(p);
					printf("██  ");
					Sleep(p);
				}
				else if (b == 4)
				{
					printf(" ██   ");
					Sleep(p);
					Sleep(p);
					printf("███   ");
					Sleep(p);
					Sleep(p);
					printf("██  ");
					Sleep(p);
				}
				else if (b == 5)
				{
					printf("██");
					Sleep(p);
					printf("██       ");
					Sleep(p);
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██ ");
					Sleep(p);
				}
				a++;
				continue;
			}
			if (c == 'I')
			{
				if (b == 1 || b == 5)
				{
					printf("██");
					Sleep(p);
					printf("██ ");
					Sleep(p);
				}
				else if (b == 2 || b == 3 || b == 4)
				{
					printf(" ██  ");
					Sleep(p);
				}

				a++;
				continue;
			}
			if (c == 'N')
			{
				if (b == 1)
				{
					printf(" ██");
					Sleep(p);
					printf("██   ");
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██ ");
					Sleep(p);
				}
				else if (b == 2)
				{
					printf(" ██ ");
					Sleep(p);
					printf("██   ");
					Sleep(p);
					printf("██  ");
					Sleep(p);
				}
				else if (b == 3)
				{
					printf(" ██  ");
					Sleep(p);
					printf("██  ");
					Sleep(p);
					printf("██  ");
					Sleep(p);
				}
				else if (b == 4)
				{
					printf(" ██   ");
					Sleep(p);
					printf("██ ");
					Sleep(p);
					printf("██  ");
					Sleep(p);
				}
				else if (b == 5)
				{
					printf("██");
					Sleep(p);
					printf("██   ");
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██  ");
					Sleep(p);
				}
				a++;
				continue;
			}
			if (c == 'E')
			{

				if (b == 1 || b == 5)
				{
					printf("██");
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██ ");
					Sleep(p);
				}
				else if (b == 2 || b == 4)
				{
					printf("██       ");
					Sleep(p);
					Sleep(p);
					Sleep(p);
				}
				else if (b == 3)
				{
					printf("██");
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██   ");
					Sleep(p);

				}


				a++;
				continue;
			}
			if (c == 'S')
			{

				if (b == 1 || b == 3 || b == 5)
				{
					printf("██");
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██ ");
					Sleep(p);
				}
				else if (b == 2)
				{
					printf("██     ");
					Sleep(p);
					Sleep(p);
					Sleep(p);
				}

				else if (b == 4)
				{
					Sleep(p);
					Sleep(p);
					printf("    ██ ");
					Sleep(p);
				}

				a++;
				continue;
			}
			if (c == 'W')
			{

				if (b == 1)
				{
					printf("██");
					Sleep(p);
					printf("██       ");
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██ ");
					Sleep(p);
				}
				else if (b == 2)
				{
					printf(" ██   ");
					Sleep(p);
					printf("███   ");
					Sleep(p);
					printf("██  ");
					Sleep(p);
				}
				else if (b == 3)
				{
					printf(" ██  ");
					Sleep(p);
					printf("██ ");
					Sleep(p);
					printf("██  ");
					Sleep(p);
					printf("██  ");
					Sleep(p);
				}
				else if (b == 4)
				{
					printf(" ██ ");
					Sleep(p);
					printf("██   ");
					Sleep(p);
					printf("██ ");
					Sleep(p);
					printf("██  ");
					Sleep(p);
				}
				else if (b == 5)
				{
					printf(" ██");
					Sleep(p);
					printf("██     ");
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██  ");
					Sleep(p);
				}
				a++;
				continue;
			}
			if (c == 'P')
			{

				if (b == 1 || b == 3)
				{
					printf("██");
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██ ");
					Sleep(p);
				}
				else if (b == 2)
				{
					printf("██  ");
					Sleep(p);
					printf("██ ");
					Sleep(p);
				}

				else if (b == 4 || b == 5)
				{
					printf("██     ");
					Sleep(p);
					Sleep(p);
					Sleep(p);
				}

				a++;
				continue;
			}
			if (c == 'R')
			{

				if (b == 1 || b == 3)
				{
					printf("██");
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██ ");
					Sleep(p);
				}
				else if (b == 2 || b == 5)
				{
					printf("██  ");
					Sleep(p);
					printf("██ ");
					Sleep(p);
				}

				else if (b == 4)
				{
					printf("██ ");
					Sleep(p);
					printf("██  ");
					Sleep(p);
				}

				a++;
				continue;
			}

			if (c == 'O')
			{
				if (b == 1 || b == 5)
				{
					printf(" ██");
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██  ");
					Sleep(p);
				}
				else if (b == 2 || b == 3 || b == 4)
				{
					printf("██    ");
					Sleep(p);
					Sleep(p);
					printf("██ ");
					Sleep(p);
				}


				a++;
				continue;
			}
			if (c == 'L')
			{
				if (b == 1 || b == 2 || b == 3 || b == 4)
				{
					printf("██     ");
					Sleep(p);
					Sleep(p);
					Sleep(p);
				}

				else if (b == 5)
				{
					printf("██");
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██ ");
					Sleep(p);
				}
				a++;
				continue;
			}
			if (c == 'T')
			{
				if (b == 1)
				{
					printf("██");
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██ ");
					Sleep(p);
				}
				else if (b == 2 || b == 3 || b == 4 || b == 5)
				{
					Sleep(p);
					Sleep(p);
					printf("    ██     ");
					Sleep(p);
					Sleep(p);
				}

				a++;
				continue;
			}
			if (c == 'Y')
			{
				if (b == 1)
				{
					printf("███    ");
					Sleep(p);
					printf("███");
					Sleep(p);
				}
				else if (b == 2)
				{
					printf("  ██  ");
					Sleep(p);
					printf("██  ");
					Sleep(p);
				}
				else if (b == 3)
				{
					printf("   ██");
					Sleep(p);
					printf("██   ");
					Sleep(p);
				}
				else if (b == 4 || b == 5)
				{
					Sleep(p);
					printf("    ██    ");
					Sleep(p);
				}

				a++;
				continue;
			}
			if (c == 'U')
			{
				if (b == 1 || b == 2 || b == 3 || b == 4)
				{
					printf("██    ");
					Sleep(p);
					Sleep(p);
					printf("██ ");
					Sleep(p);
				}

				else if (b == 5)
				{
					printf(" ██");
					Sleep(p);
					printf("██");
					Sleep(p);
					printf("██  ");
					Sleep(p);
				}
				a++;
				continue;
			}

			if (c == '1')
			{
				//bomb
				if (b == 1)
				{
					printf("     ██");
					Sleep(p);
					printf("██  ");
					Sleep(p);
				}
				else if (b == 2 || b == 5)
				{
					printf("  ██");
					Sleep(p);
					printf("██     ");
					Sleep(p);
				}
				else if (b == 3 || b == 4)
				{
					printf("██    ");
					Sleep(p);

					printf("██   ");
					Sleep(p);
				}


				a++;
				continue;
			}
			if (c == 'n')
			{
				printf(" ");
			}
			a++;

		}
		printf("\n");
	}


}