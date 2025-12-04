# Maze Escape Game - Complete Color Tutorial

A colorful C-based maze game where you navigate through a 20x20 maze while avoiding enemies!

## Table of Contents
- [How to Play](#how-to-play)
- [Color System Explained](#color-system-explained)
- [Customizing Your Own Colors](#customizing-your-own-colors)
- [Creating Your Own Maze](#creating-your-own-maze)
- [Advanced Customization](#advanced-customization)

---

## How to Play
- Use **W, A, S, D** to move up, left, down, right
- Avoid the enemies (E1, E2, E3)
- Reach the goal ($) to win!
- Press **E** to exit anytime

---

## Color System Explained

### Windows Console Colors
Our game uses Windows console colors through the `SetConsoleTextAttribute()` function.

#### Available Colors (0-15):
```
0  = Black          8  = Dark Gray
1  = Blue           9  = Light Blue
2  = Green          10 = Light Green
3  = Aqua           11 = Light Aqua
4  = Red            12 = Light Red
5  = Purple         13 = Light Purple
6  = Yellow         14 = Light Yellow
7  = White          15 = Bright White
```

### The setColor Function

Here's the function we use to change colors:
```c
#include <windows.h>

void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
```

**How it works:**
1. `GetStdHandle(STD_OUTPUT_HANDLE)` - Gets the console window handle
2. `SetConsoleTextAttribute()` - Changes the text color
3. Color stays active until you change it again

---

## Customizing Your Own Colors

### Example 1: Change Player Color

**Default (Green):**
```c
if (x == playerX && y == playerY)
{
    setColor(10);  // Bright Green
    printf("P ");
    setColor(7);   // Reset to white
}
```

**Make Player Blue:**
```c
if (x == playerX && y == playerY)
{
    setColor(9);   // Light Blue
    printf("P ");
    setColor(7);
}
```

**Make Player Purple:**
```c
if (x == playerX && y == playerY)
{
    setColor(13);  // Light Purple
    printf("P ");
    setColor(7);
}
```

### Example 2: Change Wall Colors

**Default (Blue):**
```c
else if (maze[y][x] == 1)
{
    setColor(9);   // Blue
    printf("##");
    setColor(7);
}
```

**Make Walls Green:**
```c
else if (maze[y][x] == 1)
{
    setColor(2);   // Dark Green
    printf("##");
    setColor(7);
}
```

**Make Walls Red (Danger!):**
```c
else if (maze[y][x] == 1)
{
    setColor(12);  // Bright Red
    printf("##");
    setColor(7);
}
```

### Example 3: Change Enemy Colors

**Make Each Enemy a Different Color:**
```c
else if (x == enemies[0].x && y == enemies[0].y)
{
    setColor(12);  // Red for Enemy 1
    printf("E1");
    setColor(7);
}
else if (x == enemies[1].x && y == enemies[1].y)
{
    setColor(13);  // Purple for Enemy 2
    printf("E2");
    setColor(7);
}
else if (x == enemies[2].x && y == enemies[2].y)
{
    setColor(6);   // Yellow for Enemy 3
    printf("E3");
    setColor(7);
}
```

### Example 4: Change Goal Color

**Default (Yellow):**
```c
else if (maze[y][x] == 3)
{
    setColor(14);  // Yellow
    printf("$$");
    setColor(7);
}
```

**Make Goal Cyan (Aqua):**
```c
else if (maze[y][x] == 3)
{
    setColor(11);  // Light Aqua
    printf("$$");
    setColor(7);
}
```

### Example 5: Change Path Dots

**Default (Dark Gray):**
```c
else
{
    setColor(8);   // Dark Gray
    printf(". ");
    setColor(7);
}
```

**Make Paths Invisible (Black):**
```c
else
{
    setColor(0);   // Black (invisible on black background)
    printf(". ");
    setColor(7);
}
```

**Make Paths More Visible (White):**
```c
else
{
    setColor(7);   // White
    printf(". ");
    setColor(7);
}
```

---

## Creating Your Own Maze

### Understanding the Maze Array

The maze is a 2D array where:
- **1** = Wall
- **0** = Path (walkable)
- **3** = Goal
```c
int maze[HEIGHT][WIDTH] = {
    {1, 1, 1, 1, 1},  // Row 0: All walls
    {1, 0, 0, 0, 1},  // Row 1: Walls with path
    {1, 0, 1, 0, 1},  // Row 2: Path with wall in middle
    {1, 0, 0, 3, 1},  // Row 3: Path leading to goal
    {1, 1, 1, 1, 1}   // Row 4: All walls
};
```

### Example: Create a Simple 10x10 Maze
```c
#define WIDTH 10
#define HEIGHT 10

int maze[HEIGHT][WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 3, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
```

**Remember to update:**
- Player starting position: `int playerX = 1, playerY = 1;`
- Enemy positions in the `enemies[]` array

### Tips for Maze Design:
1. **Always surround with walls** (1's on all edges)
2. **Make sure there's a path** from start to goal
3. **Leave space for enemies** to move around
4. **Test your maze** before finalizing

---

## Advanced Customization

### Complete Color Theme Example: "Dark Mode"
```c
void displayMaze(void)
{
    system("cls");
    
    setColor(8);  // Dark gray title
    printf("\n");
    printf("  ================================================\n");
    printf("  |        ** DARK MAZE ESCAPE **                |\n");
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
                setColor(11);  // Cyan player
                printf("P ");
                setColor(7);
            }
            else if (x == enemies[0].x && y == enemies[0].y)
            {
                setColor(4);   // Dark red enemy
                printf("E1");
                setColor(7);
            }
            else if (x == enemies[1].x && y == enemies[1].y)
            {
                setColor(4);
                printf("E2");
                setColor(7);
            }
            else if (x == enemies[2].x && y == enemies[2].y)
            {
                setColor(4);
                printf("E3");
                setColor(7);
            }
            else if (maze[y][x] == 1)
            {
                setColor(8);   // Dark gray walls
                printf("##");
                setColor(7);
            }
            else if (maze[y][x] == 3)
            {
                setColor(10);  // Green goal
                printf("$$");
                setColor(7);
            }
            else
            {
                printf("  ");  // No dots, pure black
            }
        }
        printf("\n");
    }
    
    printf("\n");
    setColor(11); printf("  [P]");
    setColor(7); printf(" = You    ");
    setColor(4); printf("[E1][E2][E3]");
    setColor(7); printf(" = Enemies    ");
    setColor(10); printf("[$]");
    setColor(7); printf(" = Goal\n\n");
}
```

### Complete Color Theme Example: "Neon Mode"
```c
void displayMaze(void)
{
    system("cls");
    
    setColor(13);  // Bright purple
    printf("\n");
    printf("  ================================================\n");
    printf("  |        ** NEON MAZE ESCAPE **                |\n");
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
                setColor(14);  // Bright yellow player
                printf("P ");
                setColor(7);
            }
            else if (x == enemies[0].x && y == enemies[0].y)
            {
                setColor(13);  // Bright purple
                printf("E1");
                setColor(7);
            }
            else if (x == enemies[1].x && y == enemies[1].y)
            {
                setColor(13);
                printf("E2");
                setColor(7);
            }
            else if (x == enemies[2].x && y == enemies[2].y)
            {
                setColor(13);
                printf("E3");
                setColor(7);
            }
            else if (maze[y][x] == 1)
            {
                setColor(11);  // Cyan walls
                printf("##");
                setColor(7);
            }
            else if (maze[y][x] == 3)
            {
                setColor(10);  // Green goal
                printf("$$");
                setColor(7);
            }
            else
            {
                setColor(5);   // Dark purple dots
                printf(". ");
                setColor(7);
            }
        }
        printf("\n");
    }
    
    printf("\n");
    setColor(14); printf("  [P]");
    setColor(7); printf(" = You    ");
    setColor(13); printf("[E1][E2][E3]");
    setColor(7); printf(" = Enemies    ");
    setColor(10); printf("[$]");
    setColor(7); printf(" = Goal\n\n");
}
```

### Complete Color Theme Example: "Forest Mode"
```c
void displayMaze(void)
{
    system("cls");
    
    setColor(2);  // Green
    printf("\n");
    printf("  ================================================\n");
    printf("  |       ** FOREST MAZE ESCAPE **               |\n");
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
                setColor(14);  // Yellow (like sun)
                printf("P ");
                setColor(7);
            }
            else if (x == enemies[0].x && y == enemies[0].y)
            {
                setColor(4);   // Red (danger)
                printf("E1");
                setColor(7);
            }
            else if (x == enemies[1].x && y == enemies[1].y)
            {
                setColor(4);
                printf("E2");
                setColor(7);
            }
            else if (x == enemies[2].x && y == enemies[2].y)
            {
                setColor(4);
                printf("E3");
                setColor(7);
            }
            else if (maze[y][x] == 1)
            {
                setColor(2);   // Green trees/walls
                printf("##");
                setColor(7);
            }
            else if (maze[y][x] == 3)
            {
                setColor(6);   // Brown/yellow (treasure)
                printf("$$");
                setColor(7);
            }
            else
            {
                setColor(10);  // Light green grass
                printf(". ");
                setColor(7);
            }
        }
        printf("\n");
    }
    
    printf("\n");
    setColor(14); printf("  [P]");
    setColor(7); printf(" = You    ");
    setColor(4); printf("[E1][E2][E3]");
    setColor(7); printf(" = Enemies    ");
    setColor(6); printf("[$]");
    setColor(7); printf(" = Goal\n\n");
}
```

---

## Quick Reference: Change Everything at Once

Here's a template to quickly customize all colors:
```c
// In displayMaze() function, find these lines and change the numbers:

// TITLE COLOR
setColor(14);  // Change this number (0-15)
printf("Title here");

// PLAYER COLOR
setColor(10);  // Change this number
printf("P ");

// ENEMY COLORS
setColor(12);  // Change this number
printf("E1");

// WALL COLOR
setColor(9);   // Change this number
printf("##");

// GOAL COLOR
setColor(14);  // Change this number
printf("$$");

// PATH DOTS COLOR
setColor(8);   // Change this number
printf(". ");

// Always reset to white after!
setColor(7);
```

---

## Additional Resources

### BGI (Borland Graphics Interface)
For more advanced graphics and colors:
- [BGI setcolor() Documentation](https://home.cs.colorado.edu/~main/bgi/doc/setcolor.html)
- [Full BGI Documentation](https://home.cs.colorado.edu/~main/bgi/doc/)

### Windows Console Colors
- Our method uses: `<windows.h>` and `SetConsoleTextAttribute()`
- Works on all Windows systems
- Compatible with modern C compilers

---

## Compilation
```bash
gcc maze.c -o maze.exe
```

Or use Visual Studio / Code::Blocks

---

## Requirements
- Windows OS (for color support)
- C Compiler (GCC, MinGW, Visual Studio, etc.)
- `<windows.h>` library (included in most Windows C compilers)

---

## Share Your Creations!

Made a cool color theme or maze design? Share it with us!
- Open an issue with your code
- Submit a pull request
- Tag us with your screenshots

---

Made with ❤️ for learning C programming

**Happy Coding! 🎮**
