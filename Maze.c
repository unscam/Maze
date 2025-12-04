#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Define the size of the maze
#define WIDTH 20
#define HEIGHT 20

// Maze layout: 1 = wall, 0 = walkable path, 3 = goal
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

// Player starting position (x = column, y = row)
int playerX = 1, playerY = 1;

// Enemy structure to store enemy information
struct Enemy
{
    int  x, y;          // Position of enemy
    int  speed;         // How fast enemy moves (spaces per turn)
    char direction;     // Direction: 1 = right, -1 = left
};

// Create 3 enemies with different speeds and starting positions
struct Enemy enemies[3] =
{
    {3, 1, 1, 1},      // Enemy 1: starts at (3,1), speed 1, moving right
    {10, 5, 2, 1},     // Enemy 2: starts at (10,5), speed 2, moving right
    {15, 7, 1, -1}     // Enemy 3: starts at (15,7), speed 1, moving left
};

// Function to change console text color
void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Get console handle
    SetConsoleTextAttribute(hConsole, color);           // Set the color
}

// Function to display the entire maze on screen
void displayMaze(void)
{
    system("cls");  // Clear the console screen

    // Print title banner in yellow
    setColor(14);
    printf("\n");
    printf("  ================================================\n");
    printf("  |        ** Maze Lession 4 **           |\n");
    printf("  ================================================\n");
    setColor(7);  // Reset to white

    // Print game instructions
    printf("\n  Controls: [W] Up  [S] Down  [A] Left  [D] Right  [E] Exit\n");
    printf("  -------------------------------------------------------\n\n");

    // Loop through each row of the maze
    for (int y = 0; y < HEIGHT; y++)
    {
        printf("    ");  // Indent for better appearance
        
        // Loop through each column in the row
        for (int x = 0; x < WIDTH; x++)
        {
            // Check if this position is the player
            if (x == playerX && y == playerY)
            {
                setColor(10);  // Bright green for player
                printf("P ");
                setColor(7);   // Reset to white
            }
            // Check if this position is Enemy 1
            else if (x == enemies[0].x && y == enemies[0].y)
            {
                setColor(12);  // Bright red for enemies
                printf("E1");
                setColor(7);
            }
            // Check if this position is Enemy 2
            else if (x == enemies[1].x && y == enemies[1].y)
            {
                setColor(12);
                printf("E2");
                setColor(7);
            }
            // Check if this position is Enemy 3
            else if (x == enemies[2].x && y == enemies[2].y)
            {
                setColor(12);
                printf("E3");
                setColor(7);
            }
            // Check if this position is a wall
            else if (maze[y][x] == 1)
            {
                setColor(9);   // Blue for walls
                printf("##");
                setColor(7);
            }
            // Check if this position is the goal
            else if (maze[y][x] == 3)
            {
                setColor(14);  // Yellow for goal
                printf("$$");
                setColor(7);
            }
            // Otherwise it's an empty path
            else
            {
                setColor(8);   // Dark gray for paths
                printf(". ");
                setColor(7);
            }
        }
        printf("\n");  // Move to next row
    }

    // Print legend at bottom
    printf("\n");
    setColor(10); printf("  [P]");
    setColor(7); printf(" = You    ");
    setColor(12); printf("[E1][E2][E3]");
    setColor(7); printf(" = Enemies    ");
    setColor(14); printf("[$]");
    setColor(7); printf(" = Goal\n\n");
}

// Function to move all enemies
void moveEnemies(void)
{
    // Loop through each enemy
    for (int i = 0; i < 3; i++)
    {
        // Calculate new position based on speed and direction
        int newX = enemies[i].x + enemies[i].speed * enemies[i].direction;
        
        // Check if enemy hit a wall or edge of maze
        if (newX < 0 || newX >= WIDTH || maze[enemies[i].y][newX] == 1)
        {
            // Reverse direction if hit obstacle
            enemies[i].direction = -enemies[i].direction;
            // Recalculate new position in opposite direction
            newX = enemies[i].x + enemies[i].speed * enemies[i].direction;
        }
        
        // Update enemy position
        enemies[i].x = newX;
    }
}

// Function to move player and check for collisions
// Returns: 0 = normal move, 1 = reached goal, -1 = hit enemy
int movePlayer(char input)
{
    int newX = playerX, newY = playerY;  // Store current position
    
    // Determine new position based on input key
    if (input == 'w' || input == 'W')
        newY--;  // Move up (decrease y)
    else if (input == 's' || input == 'S')
        newY++;  // Move down (increase y)
    else if (input == 'a' || input == 'A')
        newX--;  // Move left (decrease x)
    else if (input == 'd' || input == 'D')
        newX++;  // Move right (increase x)
    else
        return 0;  // Invalid input, don't move

    // Check if new position is valid (in bounds and not a wall)
    if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT && maze[newY][newX] != 1)
    {
        // Update player position
        playerX = newX;
        playerY = newY;
        
        // Check if player hit any enemy
        for (int i = 0; i < 3; i++)
        {
            if (playerX == enemies[i].x && playerY == enemies[i].y)
                return -1;  // Game over - caught by enemy
        }
        
        // Check if player reached the goal
        if (maze[playerY][playerX] == 3)
            return 1;  // Win - reached goal
    }
    
    return 0;  // Normal move, continue game
}

// Main game loop
int main(void)
{
    char input;  // Store player input
    
    // Infinite game loop
    while (1)
    {
        displayMaze();  // Show current game state
        
        // Prompt for player move in cyan
        setColor(11);
        printf("  >> Your move: ");
        setColor(7);
        scanf(" %c", &input);  // Read one character
        
        // Check if player wants to exit
        if (input == 'e' || input == 'E')
        {
            system("cls");
            printf("\n\n");
            setColor(14);
            printf("  ================================================\n");
            printf("  |         Thanks for playing!                  |\n");
            printf("  ================================================\n\n");
            setColor(7);
            break;  // Exit game loop
        }
        
        // Try to move player and get result
        int result = movePlayer(input);
        
        // Check if player was caught by enemy
        if (result == -1)
        {
            system("cls");
            displayMaze();  // Show final maze state
            printf("\n");
            setColor(12);  // Red for game over
            printf("  ================================================\n");
            printf("  |              GAME OVER!                      |\n");
            printf("  |        You were caught by enemy!             |\n");
            printf("  ================================================\n\n");
            setColor(7);
            break;  // End game
        }
        
        // Check if player reached goal
        if (result == 1)
        {
            system("cls");
            displayMaze();  // Show final maze state
            printf("\n");
            setColor(10);  // Green for victory
            printf("  ================================================\n");
            printf("  |           CONGRATULATIONS!                   |\n");
            printf("  |         You escaped the maze!                |\n");
            printf("  ================================================\n\n");
            setColor(7);
            break;  // End game
        }
        
        // If game continues, move the enemies
        moveEnemies();
    }
    
    getchar();  // Wait for Enter key before closing
    return 0;   // Exit program successfully
}
