# Maze Solver in C

This project is a simple Maze Solver implemented in C using a recursive backtracking algorithm. The program takes a 2D maze grid as input and finds a path from the top-left corner to the bottom-right corner if it exists.

## Features
- Recursive backtracking to explore all possible paths.
- Prints the solution path if one exists.
- Handles mazes represented as a 2D array with walls and open paths.

## Maze Representation
- The maze is represented as a 2D grid where:
  - `0` indicates a passable cell.
  - `1` indicates a wall.

Example:
```plaintext
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0
1 1 0 0 0
0 0 0 1 0
```

## Algorithm
The algorithm uses recursive backtracking to explore the maze:
1. Starts at the top-left corner of the maze.
2. Marks the current cell as part of the solution path.
3. Recursively tries to move in four directions: right, down, left, and up.
4. Backtracks if no valid path is found.
5. Stops when it reaches the bottom-right corner.

## How to Run the Project
1. Clone the repository:
   ```bash
   git clone https://github.com/stephenombuya/Maze-Solver
   ```

2. Navigate to the project directory:
   ```bash
   cd maze-solver-c
   ```

3. Compile the program:
   ```bash
   gcc maze_solver.c -o maze_solver
   ```

4. Run the program:
   ```bash
   ./maze_solver
   ```

## Example Output
For the input maze:
```plaintext
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0
1 1 0 0 0
0 0 0 1 0
```

The output will be:
```plaintext
Solution:
1 0 0 0 0
1 0 0 0 0
1 1 1 0 0
0 0 1 1 1
0 0 0 0 1
```

## Customization
- Modify the maze grid in the `maze` array to test different scenarios.
- Adjust the `N` constant to change the maze dimensions.

## File Structure
- `maze_solver.c`: The main program file containing the Maze Solver logic.

## Requirements
- GCC compiler or any C compiler.
- Basic understanding of C programming.

## Future Enhancements
- Support for larger mazes dynamically.
- Implement GUI for visualizing the maze-solving process.
- Add support for user-input mazes.

## License
This project is licensed under the [Apache 2.0 License](LICENSE).

## Contributing
Contributions are welcome! Please create a pull request or open an issue to suggest changes.

## Contact
For any queries or issues, feel free to contact:
- **GitHub:** [stephenombuya](https://github.com/stephenombuya)
