#include <stdio.h>
#include <stdlib.h>

struct Employee {
  char name[20];
  int id;
  struct Employee *next;
};

typedef struct Employee Employee;
int main() {
  Employee *newEmployee = malloc(sizeof(struct Employee));

  printf("Enter employee name: ");
  scanf("%s", newEmployee->name);

  printf("%s", newEmployee->name);
}
