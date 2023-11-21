#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_RECORDS 10

typedef struct {
    int id;
    char name[100];
    float salary;
} Employee;

void readEmployee(FILE *file, int pos, Employee *emp) {
    fseek(file, pos * sizeof(Employee), SEEK_SET);
    fread(emp, sizeof(Employee), 1, file);
}

void writeEmployee(FILE *file, int pos, Employee *emp) {
    fseek(file, pos * sizeof(Employee), SEEK_SET);
    fwrite(emp, sizeof(Employee), 1, file);
}

int main() {
    Employee emp;
    int id, pos;
    char name[100];
    float salary;

    FILE *file = fopen("employees.bin", "rb+");
    if (file == NULL) {
        file = fopen("employees.bin", "wb+");
    }

    printf("Enter employee ID: ");
    scanf("%d", &id);
    printf("Enter employee name: ");
    scanf("%s", name);
    printf("Enter employee salary: ");
    scanf("%f", &salary);

    pos = id - 1;
    readEmployee(file, pos, &emp);

    if (emp.id == 0) {
        emp.id = id;
        strncpy(emp.name, name, sizeof(emp.name) - 1); // Use strncpy instead of strcpy
        emp.name[sizeof(emp.name) - 1] = '\0'; // Manually add null-terminator
        emp.salary = salary;
        writeEmployee(file, pos, &emp);
        printf("Employee added successfully.\n");
    } else {
        printf("Employee already exists.\n");
    }

    fclose(file);
    return 0;
}
