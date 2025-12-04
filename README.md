# Maze Escape Game

A colorful C-based maze game where you navigate through a 20x20 maze while avoiding enemies!

## Features
- 20x20 maze with challenging pathways
- Colorful graphics using Windows console colors
- 3 enemies with different movement patterns
- WASD controls for movement

## How to Play
- Use **W, A, S, D** to move up, left, down, right
- Avoid the enemies (E1, E2, E3)
- Reach the goal ($) to win!
- Press **E** to exit anytime

## Color Information

This project uses Windows console colors. For more advanced color options and BGI (Borland Graphics Interface) implementation, check out these resources:

### BGI Color Reference
Visit [BGI setcolor() documentation](https://home.cs.colorado.edu/~main/bgi/doc/setcolor.html) to find color numbers and more information about BGI graphics.

### Current Color Scheme
- **Player (P)** = Bright Green (10)
- **Enemies (E1, E2, E3)** = Bright Red (12)
- **Walls (##)** = Blue (9)
- **Goal ($$)** = Yellow (14)
- **Paths (.)** = Dark Gray (8)

### Windows Console Color Codes
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

## Customizing Colors

To change colors in the game, modify the `setColor()` function calls:
```c
setColor(10);  // Change 10 to any color code (0-15)
printf("P ");
setColor(7);   // Reset to white
```

## Compilation

Compile with any C compiler that supports Windows:
```bash
gcc maze.c -o maze.exe
```

Or use Visual Studio / Code::Blocks

## Requirements
- Windows OS (for color support)
- C Compiler (GCC, MinGW, Visual Studio, etc.)

## Want to Learn More?

Check out the [BGI Documentation](https://home.cs.colorado.edu/~main/bgi/doc/) for advanced graphics programming in C!

---

Made with ❤️ for school project
