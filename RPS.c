#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

void gotoxy(int x, int y);
void cursorview();
int rpsMenu();
int rpsGame();
int rpsRule();
void playerRock(int x, int y);
void playerPaper(int x, int y);
void playerScissors(int x, int y);
void computerRock();
void computerPaper();
void computerScissors();
int main()
{
    system("cls");
    srand(time(NULL));
    SetConsoleTitle("Rock Paper Scissors");
    system("mode con: cols=80 lines=40");
    cursorview();

    rpsMenu();
    
    return 0;
}

void gotoxy(int x, int y)
{
    COORD Pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void cursorview()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int rpsMenu()
{
    system("cls");

    gotoxy(0, 4); printf("────────────────────────────────────────────────────────────────────────────────");
    gotoxy(4, 5); printf("███ ███ ███ █ █   ███ ███ ███ ███ ███   ███ ███ ███ ███ ███ ███ ███ ███");
    gotoxy(4, 6); printf("█ █ █ █ █   ██    █ █ █ █ █ █ █   █ █   █   █    █  █   █   █ █ █ █ █  ");
    gotoxy(4, 7); printf("███ █ █ █   █     ███ ███ ███ ███ ███   ███ █    █  ███ ███ █ █ ███ ███");
    gotoxy(4, 8); printf("██  █ █ █   ██    █   █ █ █   █   ██      █ █    █    █   █ █ █ ██    █");
    gotoxy(4, 9); printf("█ █ ███ ███ █ █   █   █ █ █   ███ █ █   ███ ███ ███ ███ ███ ███ █ █ ███");
    gotoxy(0, 10);printf("────────────────────────────────────────────────────────────────────────────────");
    
    gotoxy(38, 20); printf("START");
    gotoxy(38, 23); printf("RULE");
    gotoxy(38, 26); printf("EXIT");

    int input;
    int cursor = 20;
    int num = 0;
    int i;
    
    while (1)
    {
        for (i = 0; i < 10; i++)
        {
            if (kbhit())
            {
                input = getch();

                if (input == ENTER)
                {
                    if (cursor == 20)
                    {
                        for (i = 0; i < 5; i++)
                        {
                            gotoxy(38, 20);
                            printf("        ");
                            Sleep(100);
                            gotoxy(38, 20);
                            printf("START");
                            Sleep(100);
                        }
                        system("cls");
                        return rpsGame();
                    }

                    else if (cursor == 23)
                    {
                        for (i = 0; i < 5; i++)
                        {
                            gotoxy(38, 23);
                            printf("    ");
                            Sleep(100);
                            gotoxy(38, 23);
                            printf("RULE");
                            Sleep(100);
                        }
                        system("cls");
                        return rpsRule();
                    }

                    else
                    {
                        exit(0);
                    }
                }

                else if (input == 224)
                {
                    input = getch();

                    switch (input)
                    {
                        case UP:
                        {
                            gotoxy(35, cursor);
                            printf("  ");
                            if (cursor != 20)
                                cursor -= 3;
                            else
                                cursor = 26;
                            break;
                        }

                        case DOWN:
                        {
                            gotoxy(35, cursor);
                            printf("  ");
                            if (cursor != 26)
                                cursor += 3;
                            else
                                cursor = 20;
                            break;
                        }
                    }
                }
            }
            Sleep(10);
        }

        if (num == 0)
        {
            gotoxy(35, cursor);
            printf(">>");
            num = 1;
        }

        else
        {
            gotoxy(35, cursor);
            printf("  ");
            num = 0;
        }
    }
}

int rpsGame()
{
    int player, computer;
    int money = 50;
    int input;
    int cursor = 5;
    int num = 0;
    int i;

    gotoxy(0, 30); printf("────────────────────┬───────────────────┬───────────────────┬───────────────────");
    for (i = 0; i < 9; i++)
    {
        gotoxy(20, i + 31); printf("│");
        gotoxy(40, i + 31); printf("│");
        gotoxy(60, i + 31); printf("│");
    }

    gotoxy(8, 35); printf("ROCK");
    gotoxy(28, 35); printf("PAPER");
    gotoxy(48, 35); printf("SCISSORS");
    gotoxy(68, 35); printf("EXIT");

while (1)
    {
        for (i = 0; i < 10; i++)
        {
            if (kbhit())
            {
                input = getch();

                if (input == ENTER)
                {
                    computer = rand() % 3 + 1;

                    switch(computer)
                    {
                        case 1: computerRock();
                        break;
                        case 2: computerPaper();
                        break;
                        case 3: computerScissors();
                        break;
                    }

                    if (cursor == 5)
                    {
                        player == 1;
                        playerRock(30, 18);

                        if (computer == 1)
                        {
                            gotoxy(3, 29);
                            printf("draw");
                            Sleep(500);
                            gotoxy(3, 29);
                            printf("    ");
                        }

                        else if (computer == 2)
                        {
                            money -= 50;
                            gotoxy(3, 29);
                            printf("lose");
                            Sleep(500);
                            gotoxy(3, 29);
                            printf("    ");
                        }
                        else
                        {
                            money += 50;
                            gotoxy(3, 29);
                            printf("win");
                            Sleep(500);
                            gotoxy(3, 29);
                            printf("    ");  
                        }
                    }

                    else if (cursor == 25)
                    {
                        player == 2;
                        playerPaper(30, 18);

                        if (computer == 1)
                        {
                            money += 50;
                            gotoxy(3, 29);
                            printf("win");
                            Sleep(500);
                            gotoxy(3, 29);
                            printf("    ");
                        }

                        else if (computer == 2)
                        {
                            gotoxy(3, 29);
                            printf("draw");
                            Sleep(500);
                            gotoxy(3, 29);
                            printf("    ");  
                        }
                        else
                        {
                            money -= 50;
                            gotoxy(3, 29);
                            printf("lose");
                            Sleep(500);
                            gotoxy(3, 29);
                            printf("    ");
                        }
                    }

                    else if (cursor == 45)
                    {
                        player == 3;
                        playerScissors(30, 18);

                        if (computer == 1)
                        {
                            money -= 50;
                            gotoxy(3, 29);
                            printf("lose");
                            Sleep(500);
                            gotoxy(3, 29);
                            printf("    ");
                        }

                        else if (computer == 2)
                        {
                            money += 50;
                            gotoxy(3, 29);
                            printf("win");
                            Sleep(500);
                            gotoxy(3, 29);
                            printf("    ");
                        }
                        else
                        {
                            gotoxy(3, 29);
                            printf("draw");
                            Sleep(500);
                            gotoxy(3, 29);
                            printf("    ");  
                        }
                    }

                    else
                    {
                        rpsMenu();
                    }
                }

                else if (input == 224)
                {
                    input = getch();

                    switch (input)
                    {
                        case LEFT:
                        {
                            gotoxy(cursor, 35);
                            printf("  ");
                            if (cursor != 5)
                                cursor -= 20;
                            else
                                cursor = 65;
                            break;
                        }

                        case RIGHT:
                        {
                            gotoxy(cursor, 35);
                            printf("  ");
                            if (cursor != 65)
                                cursor += 20;
                            else
                                cursor = 5;
                            break;
                        }
                    }
                }
            }
            Sleep(10);
        }

        if (num == 0)
        {
            gotoxy(cursor, 35);
            printf(">>");
            num = 1;
        }

        else
        {
            gotoxy(cursor, 35);
            printf("  ");
            num = 0;
        }

        gotoxy(72,29); printf("  %d$  ", money);
    }

    return 0;
}

int rpsRule()
{
    playerRock(33, 5);
    playerPaper(8, 22);
    playerScissors(57, 22);
    gotoxy(52, 18); printf("↘");
    gotoxy(40, 28); printf("←");
    gotoxy(28, 18); printf("↗");
    gotoxy(2, 38); printf("press any key to continue...");
    getch();
    return rpsMenu();
}

void playerRock(int x, int y)
{
    gotoxy(x, y);   printf("  ███████████  ");
    gotoxy(x, y+1); printf(" █████████████ ");
    gotoxy(x, y+2); printf("███████████████");
    gotoxy(x, y+3); printf("███████████████");
    gotoxy(x, y+4); printf("███████████████");
    gotoxy(x, y+5); printf(" █████████████ ");
    gotoxy(x, y+6); printf("  ███████████  ");
    gotoxy(x, y+7); printf("     █████     ");
    gotoxy(x, y+8); printf("     █████     ");
    gotoxy(x, y+9); printf("     █████     ");
    gotoxy(x, y+10);printf("     █████     ");
    gotoxy(x, y+11);printf("     █████     ");
}
void playerPaper(int x, int y)
{

    gotoxy(x, y);   printf("    █  █  █  █ ");
    gotoxy(x, y+1); printf("█   █  █  █  █ ");
    gotoxy(x, y+2); printf("██  ██ ██ ██ ██");
    gotoxy(x, y+3); printf("███████████████");
    gotoxy(x, y+4); printf("███████████████");
    gotoxy(x, y+5); printf(" █████████████ ");
    gotoxy(x, y+6); printf("  ███████████  ");
    gotoxy(x, y+7); printf("     █████     ");
    gotoxy(x, y+8); printf("     █████     ");
    gotoxy(x, y+9); printf("     █████     ");
    gotoxy(x, y+10);printf("     █████     ");
    gotoxy(x, y+11);printf("     █████     ");
}
void playerScissors(int x, int y)
{
    gotoxy(x, y);   printf("    ███ ███    ");
    gotoxy(x, y+1); printf("    ███ ███    ");
    gotoxy(x, y+2); printf("    ███ ███    ");
    gotoxy(x, y+3); printf("  ███████████  ");
    gotoxy(x, y+4); printf(" █████████████ ");
    gotoxy(x, y+5); printf(" █████████████ ");
    gotoxy(x, y+6); printf("  ███████████  ");
    gotoxy(x, y+7); printf("     █████     ");
    gotoxy(x, y+8); printf("     █████     ");
    gotoxy(x, y+9); printf("     █████     ");
    gotoxy(x, y+10);printf("     █████     ");
    gotoxy(x, y+11);printf("     █████     ");
}

void computerRock()
{
    gotoxy(30, 0); printf("     █████     ");
    gotoxy(30, 1); printf("     █████     ");
    gotoxy(30, 2); printf("     █████     ");
    gotoxy(30, 3); printf("     █████     ");
    gotoxy(30, 4); printf("     █████     ");
    gotoxy(30, 5); printf("  ███████████  ");
    gotoxy(30, 6); printf(" █████████████ ");
    gotoxy(30, 7); printf("███████████████");
    gotoxy(30, 8); printf("███████████████");
    gotoxy(30, 9); printf("███████████████");
    gotoxy(30, 10);printf(" █████████████ ");
    gotoxy(30, 11);printf("  ███████████  ");
}
void computerPaper()
{
    gotoxy(30, 0); printf("     █████     ");
    gotoxy(30, 1); printf("     █████     ");
    gotoxy(30, 2); printf("     █████     ");
    gotoxy(30, 3); printf("     █████     ");
    gotoxy(30, 4); printf("     █████     ");
    gotoxy(30, 5); printf("  ███████████  ");
    gotoxy(30, 6); printf(" █████████████ ");
    gotoxy(30, 7); printf("███████████████");
    gotoxy(30, 8); printf("███████████████");
    gotoxy(30, 9); printf("██ ██ ██ ██  ██");
    gotoxy(30, 10);printf(" █  █  █  █   █");
    gotoxy(30, 11);printf(" █  █  █  █     ");
}
void computerScissors()
{
    gotoxy(30, 0); printf("     █████     ");
    gotoxy(30, 1); printf("     █████     ");
    gotoxy(30, 2); printf("     █████     ");
    gotoxy(30, 3); printf("     █████     ");
    gotoxy(30, 4); printf("     █████     ");
    gotoxy(30, 5); printf("  ███████████  ");
    gotoxy(30, 6); printf(" █████████████ ");
    gotoxy(30, 7); printf(" █████████████ ");
    gotoxy(30, 8); printf("  ███████████  ");
    gotoxy(30, 9); printf("    ███ ███    ");
    gotoxy(30, 10);printf("    ███ ███    ");
    gotoxy(30, 11);printf("    ███ ███    ");
}