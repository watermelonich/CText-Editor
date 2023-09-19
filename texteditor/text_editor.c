#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FILENAME_LEN 256
#define MAX_FILE_LINES 1000

// Define a structure to hold a file
struct file {
    char filename[MAX_FILENAME_LEN];
    char lines[MAX_FILE_LINES][MAX_LINE_LEN];
    int num_lines;
};

// Print the contents of a file to the console
void print_file(struct file* f) {
    printf("%s:\n", f->filename);
    for (int i = 0; i < f->num_lines; i++) {
        printf("%s", f->lines[i]);
    }
    printf("\n");
}

// Load a file into memory
void load_file(struct file* f) {
    // Open the file
    FILE* fp = fopen(f->filename, "r");
    if (!fp) {
        printf("Error: failed to open file %s\n", f->filename);
        return;
    }

    // Read in each line of the file
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)) {
        if (strlen(line) > 0 && line[strlen(line)-1] == '\n') {
            line[strlen(line)-1] = '\0';
        }
        strncpy(f->lines[f->num_lines], line, MAX_LINE_LEN);
        f->num_lines++;
    }

    // Close the file
    fclose(fp);
}

// Save a file to disk
void save_file(struct file* f) {
    // Open the file
    FILE* fp = fopen(f->filename, "w");
    if (!fp) {
        printf("Error: failed to open file %s\n", f->filename);
        return;
    }

    // Write each line of the file
    for (int i = 0; i < f->num_lines; i++) {
        fprintf(fp, "%s\n", f->lines[i]);
    }

    // Close the file
    fclose(fp);
}

// Insert a new line at a specific position in the file
void insert_line(struct file* f, int pos) {
    // Shift all lines below the position down by one
    for (int i = f->num_lines-1; i >= pos; i--) {
        strncpy(f->lines[i+1], f->lines[i], MAX_LINE_LEN);
    }

    // Clear the new line
    memset(f->lines[pos], '\0', MAX_LINE_LEN);

    // Increment the number of lines in the file
    f->num_lines++;
}

// Delete a line at a specific position in the file
void delete_line(struct file* f, int pos) {
    // Shift all lines below the position up by one
    for (int i = pos+1; i < f->num_lines; i++) {
        strncpy(f->lines[i-1], f->lines[i], MAX_LINE_LEN);
    }

    // Decrement the number of lines in the file
    f->num_lines--;
}

int main() {
    // Declare variables
    struct file f;
    char command[MAX_LINE_LEN];

    // Get the filename from the user
    printf("Enter filename: ");
    fgets(f.filename, MAX_FILENAME_LEN, stdin);
    if (strlen(f.filename) > 0 && f.filename[strlen(f.filename)-1] == '\n') {
        f.filename[strlen(f.filename)-1] = '\0';
    }

    // Load the file into memory
    load_file(&f);

    // Main loop
    while (1) {
            // Print the file to the console
    print_file(&f);

    // Get a command from the user
    printf("Enter command: ");
    fgets(command, MAX_LINE_LEN, stdin);
    if (strlen(command) > 0 && command[strlen(command)-1] == '\n') {
        command[strlen(command)-1] = '\0';
    }

    // Parse the command
    if (strcmp(command, "q") == 0) {
        // Quit the program
        break;
    } else if (strcmp(command, "i") == 0) {
        // Insert a new line at a specific position
        int pos;
        printf("Enter line number: ");
        scanf("%d", &pos);
        getchar();
        insert_line(&f, pos);
    } else if (strcmp(command, "d") == 0) {
        // Delete a line at a specific position
        int pos;
        printf("Enter line number: ");
        scanf("%d", &pos);
        getchar();
        delete_line(&f, pos);
    } else if (strcmp(command, "s") == 0) {
        // Save the file to disk
        save_file(&f);
    } else {
        // Unknown command
        printf("Unknown command\n");
    }
}

return 0;
}
