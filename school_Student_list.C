#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[20];
    char last_name[20];
    int unique_id;
    int class;
};

struct student* students;
int num_students;

void add_user(char* name, char* last_name, int class) {
    struct student* new_student = malloc(sizeof(struct student));
    strcpy(new_student->name, name);
    strcpy(new_student->last_name, last_name);
    new_student->unique_id = num_students + 1;
    new_student->class = class;

    students = realloc(students, sizeof(struct student) * (num_students + 1));
    students[num_students++] = *new_student;
}

void list_students() {
    for (int i = 0; i < num_students; i++) {
        printf("%-5d | %-10s | %-10s | %-5d\n", students[i].unique_id, students[i].name, students[i].last_name, students[i].class);
    }
}

void search_by_id(int id) {
    for (int i = 0; i < num_students; i++) {
        if (students[i].unique_id == id) {
            printf("%-5d | %-10s | %-10s | %-5d\n", students[i].unique_id, students[i].name, students[i].last_name, students[i].class);
            return;
        }
    }

    printf("No student found with ID %d\n", id);
}

int main() {
    students = NULL;
    num_students = 0;

    while (1) {
        printf("Enter a command: ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "adduser") == 0) {
            char name[20];
            char last_name[20];
            int class;
            printf("Enter the name of the student: ");
            scanf("%s", name);

            printf("Enter the last name of the student: ");
            scanf("%s", last_name);

            printf("Enter the class of the student: ");
            scanf("%d", &class);

            add_user(name, last_name, class);
        } else if (strcmp(command, "list") == 0) {
            list_students();
        } else if (strcmp(command, "search") == 0) {
            int id;
            printf("Enter the ID of the student: ");
            scanf("%d", &id);

            search_by_id(id);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}
