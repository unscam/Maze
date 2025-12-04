#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 20

int maze[HEIGHT][WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 3, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int playerX = 1, playerY = 1;

struct Enemy
{
    int  x, y;
    int  speed;
    char direction;
};

struct Enemy enemies[3] =
{
    {3, 1, 1, 1},
    {10, 5, 2, 1},
    {15, 7, 1, -1}
};

void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void displayMaze(void)
{
    system("cls");

    setColor(14);
    printf("\n");
    printf("  ================================================\n");
    printf("  |        ** Maze Lession 4 **           |\n");
    printf("  ================================================\n");
    setColor(7);

    printf("\n  Controls: [W] Up  [S] Down  [A] Left  [D] Right  [E] Exit\n");
    printf("  -------------------------------------------------------\n\n");

    for (int y = 0; y < HEIGHT; y++)
    {
        printf("    ");
        for (int x = 0; x < WIDTH; x++)
        {
            if (x == playerX && y == playerY)
            {
                setColor(10);
                printf("P ");
                setColor(7);
            }
            else if (x == enemies[0].x && y == enemies[0].y)
            {
                setColor(12);
                printf("E1");
                setColor(7);
            }
            else if (x == enemies[1].x && y == enemies[1].y)
            {
                setColor(12);
                printf("E2");
                setColor(7);
            }
            else if (x == enemies[2].x && y == enemies[2].y)
            {
                setColor(12);
                printf("E3");
                setColor(7);
            }
            else if (maze[y][x] == 1)
            {
                setColor(9);
                printf("##");
                setColor(7);
            }
            else if (maze[y][x] == 3)
            {
                setColor(14);
                printf("$$");
                setColor(7);
            }
            else
            {
                setColor(8);
                printf(". ");
                setColor(7);
            }
        }
        printf("\n");
    }

    printf("\n");
    setColor(10); printf("  [P]");
    setColor(7); printf(" = You    ");
    setColor(12); printf("[E1][E2][E3]");
    setColor(7); printf(" = Enemies    ");
    setColor(14); printf("[$]");
    setColor(7); printf(" = Goal\n\n");
}

void moveEnemies(void)
{
    for (int i = 0; i < 3; i++)
    {
        int newX = enemies[i].x + enemies[i].speed * enemies[i].direction;
        if (newX < 0 || newX >= WIDTH || maze[enemies[i].y][newX] == 1)
        {
            enemies[i].direction = -enemies[i].direction;
            newX = enemies[i].x + enemies[i].speed * enemies[i].direction;
        }
        enemies[i].x = newX;
    }
}

int movePlayer(char input)
{
    int newX = playerX, newY = playerY;
    if (input == 'w' || input == 'W')
        newY--;
    else if (input == 's' || input == 'S')
        newY++;
    else if (input == 'a' || input == 'A')
        newX--;
    else if (input == 'd' || input == 'D')
        newX++;
    else
        return 0;

    if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT && maze[newY][newX] != 1)
    {
        playerX = newX;
        playerY = newY;
        for (int i = 0; i < 3; i++)
        {
            if (playerX == enemies[i].x && playerY == enemies[i].y)
                return -1;
        }
        if (maze[playerY][playerX] == 3)
            return 1;
    }
    return 0;
}

int main(void)
{
    char input;
    while (1)
    {
        displayMaze();
        setColor(11);
        printf("  >> Your move: ");
        setColor(7);
        scanf(" %c", &input);
        if (input == 'e' || input == 'E')
        {
            system("cls");
            printf("\n\n");
            setColor(14);
            printf("  ================================================\n");
            printf("  |         Thanks for playing!                  |\n");
            printf("  ================================================\n\n");
            setColor(7);
            break;
        }
        int result = movePlayer(input);
        if (result == -1)
        {
            system("cls");
            displayMaze();
            printf("\n");
            setColor(12);
            printf("  ================================================\n");
            printf("  |              GAME OVER!                      |\n");
            printf("  |        You were caught by enemy!             |\n");
            printf("  ================================================\n\n");
            setColor(7);
            break;
        }
        if (result == 1)
        {
            system("cls");
            displayMaze();
            printf("\n");
            setColor(10);
            printf("  ================================================\n");
            printf("  |           CONGRATULATIONS!                   |\n");
            printf("  |         You escaped the maze!                |\n");
            printf("  ================================================\n\n");
            setColor(7);
            break;
        }
        moveEnemies();
    }
    getchar();
    return 0;
}