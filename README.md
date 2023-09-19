# Text Editor Program

This C program provides basic text editing functionalities for files. It allows the user to perform operations like viewing, inserting, deleting lines, and saving the file.

## Code Explanation

### Struct `file`

- `struct file` holds information about a file, including its name and an array of lines.

```c
struct file {
    char filename[MAX_FILENAME_LEN];
    char lines[MAX_FILE_LINES][MAX_LINE_LEN];
    int num_lines;
};
```

# It performs the following steps:
1. Declares variables including a struct file and a command buffer.
2. Prompts the user for a filename and loads the file into memory.
3. Enters a main loop where the user can interact with the file.
4. Displays the file, prompts for a command, and executes the corresponding action based on the command

## Usage
1. Compile and run the program.
2. Enter the filename when prompted.
3. Follow the on-screen instructions to perform actions on the file.

## Commands
- q: Quit the program.
- i: Insert a new line at a specific position.
- d: Delete a line at a specific position.
- s: Save the file to disk.

# Building and Running
Compile and run the program using a C compiler. For example:

```c
Copy code
gcc text_editor.c -o text_editor
./text_editor
```

## Notes
The maximum line length and filename length are defined as constants (MAX_LINE_LEN and MAX_FILENAME_LEN respectively) in the program.
The maximum number of lines a file can have is defined by MAX_FILE_LINES.

## License

This project is licensed under the MIT License.
