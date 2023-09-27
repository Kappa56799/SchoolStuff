/*
Program Description: A program which reads student inforrmation in and stores it in a linked list. There is a merge sort function and binary search function which allow the data to be stored as 1 big list sorted by surname and we can lookup all student data by using the binary search, 
we can also lookup all full-time students using a linear search that goes through the entire linked list.
Date: 13/04/2023
Author: Kacper Palka C22376553
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 50
#define clear while(getchar() != '\n');

//structuree to make a linked list
struct studentInfo {
    int year;
    char firstName[LENGTH];
    char surname[LENGTH];
    char module[LENGTH];
    char studentID[LENGTH];
    char programType[LENGTH];
    struct studentInfo* next;
};

//lets us use studentinfo without needing to declare it as a struct each time
typedef struct studentInfo studentInfo;

//function signatures
void PrintStudents(studentInfo *head);
void AddStudent(studentInfo **head, int *numStudents);
void RemoveStudent(studentInfo **head, int *numStudents);
void mergeSort(studentInfo **head, int low, int high);
void Merge(studentInfo **head, int low, int mid, int high);
void PrintFullTimeStudents(studentInfo *head);
void BinarySearch(studentInfo *students, int numStudents);

int main() { 
    //variables and  making studentrs in the structure
    int optionSelected, numStudents = 0;
    studentInfo *students = NULL;    

    do {
        //A menu to allow me to showcase the program and sorts
        printf("What do you want to do?:\n");
        printf("[1] List Student Information\n"); 
        printf("[2] Add student\n"); 
        printf("[3] Remove Student\n"); 
        printf("[4] Merge Sort\n");
        printf("[5] Binary Search\n");
        printf("[6] Show All Full Time Students\n");
        printf("[7] Exit Program\n");
        printf("Enter option here:");
        scanf("%d", &optionSelected);
        clear

        //switch statement to show all the functions
        switch (optionSelected) {
            case 1: 
                PrintStudents(students); //prints student information
                break;
            case 2:
                AddStudent(&students, &numStudents); //adds students into the linked list
                break;
            case 3:
                RemoveStudent(&students, &numStudents); //removes students from the linked list
                break;
            case 4:
                mergeSort(&students, 0, numStudents - 1); //merge sort  function to sort students by surname
                printf("Sorted data:\n");
                PrintStudents(students); //prints student data after sorting
                break;
            case 5:
                BinarySearch(students, numStudents);
                break;
            case 6:
                mergeSort(&students, 0, numStudents - 1); //to sort into 1 main list before looking for all full time students
                 PrintFullTimeStudents(students); //prints full-time student information
                break;
            case 7:
                printf("Exiting program...\n");
                free(students); // free memory before exiting program
                return 0; //exits the program
            default:
                printf("Not a valid input, please try again.\n");
                break;
        }
    } while (1);
}

//function to add a student to the linked list
void AddStudent(studentInfo **head, int *numStudents) {
    //allocates memory for a new student
    studentInfo *newStudent = malloc(sizeof(studentInfo) ); //allocate memory when a student is added to the linked list

    //user inputs information to be sotred in the linked list
    printf("Enter Year here:\n");
    scanf("%d", &newStudent->year);
    clear

    printf("Enter first name:\n");
    fgets(newStudent->firstName, LENGTH, stdin);
    newStudent->firstName[strcspn(newStudent->firstName, "\r\n")] = '\0'; //to remove the \n at the end of the string

    printf("Enter Second name:\n");
    fgets(newStudent->surname, LENGTH, stdin);
    newStudent->surname[strcspn(newStudent->surname, "\r\n")] = '\0';

    //Makes sure the user can only input the correct courses
    char module[LENGTH];
    printf("What module are they in (DT265A, DT265C, DT265B, or DT8900):\n");
    fgets(module, LENGTH, stdin);
    module[strcspn(module, "\r\n")] = '\0';
    
    while (strcmp(module, "DT265A") != 0 && strcmp(module, "DT265C") != 0 && strcmp(module, "DT265B") != 0 && strcmp(module, "DT8900") != 0) {
        printf("Invalid module. Please enter a valid module (DT265A, DT265C, DT265B, or DT8900):\n");
        fgets(module, LENGTH, stdin);
        module[strcspn(module, "\r\n")] = '\0';
    }


    // check if the course is full by first assigning how many students there should be in each course depending on what the user inputted
    int maxStudents;
    if (strcmp(module, "DT265A") == 0) {
        maxStudents = 13;
    } 
    else if (strcmp(module, "DT265C") == 0) {
        maxStudents = 9;
    } 
    else if (strcmp(module, "DT265B") == 0) {
        maxStudents = 14;
    } 
    else if (strcmp(module, "DT8900") == 0) {
        maxStudents = 6;
    }

    //counts how many students are in the course before adding
    int numModuleStudents = 0;
    studentInfo *curr = *head;
    while (curr != NULL) {
        if (strcmp(curr->module, module) == 0) {
            numModuleStudents++;
        }
        curr = curr->next; //goes to the next node in the linked list
    }
    if (numModuleStudents >= maxStudents) {
        printf("Course %s is full\n", module);
        free(newStudent);
        return;
    }

    //adds the students module if the course is not full
    strncpy(newStudent->module, module, LENGTH);

    //assigns programtype based on what course they do
    if(strcmp(newStudent->module, "DT265A") == 0 || strcmp(newStudent->module, "DT265C") == 0) {
        strcpy(newStudent->programType, "Part-Time");
    }
    else {
        strncpy(newStudent->programType, "Full-Time", LENGTH);
    }


    printf("Enter student ID:\n");
    fgets(newStudent->studentID, LENGTH, stdin);
    newStudent->studentID[strcspn(newStudent->studentID, "\r\n")] = '\0';

    newStudent->next = NULL; //makes next node NULL
    if (*head == NULL) { //checks if the linked list is empty       
        *head = newStudent;
    } else {
        studentInfo *curr = *head;  
        while (curr->next != NULL) { //goes through the loop until current is NULL
            curr = curr->next; 
        }
        curr->next = newStudent; //adds the newstudent to the end of the linked list
    }
    (*numStudents)++; //increment the student count
    printf("Student added\n");
    return;
}

//function to print student information
void PrintStudents(studentInfo* head) {
    //if the node is empty  print that there is no students
    if (head == NULL) { 
        printf("No students in record\n");
        return;
    }

    printf("%-10s %-15s %-15s %-10s %-10s %-10s\n", "Year", "First Name", "Surname", "Module", "ID","Course Type");

    studentInfo *current = head;
    while (current != NULL) { //goes through the linked list until current reaches NULL which is the end
        printf("%-10d %-15s %-15s %-10s %-10s %-10s\n", current->year, current->firstName, current->surname, current->module, current->studentID, current->programType);
        current = current->next; //moves to the next node in the linked list
    }
}

//function to remove a student from the linked list
void RemoveStudent(studentInfo **head, int *numStudents) {
    char studentID[LENGTH];
    int found = 0;
    printf("Enter student ID to remove: ");
    fgets(studentID, LENGTH, stdin);
    studentID[strcspn(studentID, "\r\n")] = '\0';

    studentInfo *current = *head;
    studentInfo *prev = NULL;

    //goes through the linked list until the module is found or not found
    while (current != NULL) {
        if (strcmp(current->studentID, studentID) == 0) {
            // unlink the node from the list
            if (prev == NULL) {
                *head = current->next; // update head if the first node is removed
            } else {
                prev->next = current->next; 
            }
            free(current); //free memory that was used by that student
            (*numStudents)--; //reduce the number of students by 1
            found = 1;
            printf("Student removed\n");
            break;
        }
        //moves the values down by 1
        prev = current;
        current = current->next;
    }
    //if the student id is not found print a message
    if (!found) {
        printf("Student not found\n");
    }
}

//A function to sort the merged linked list from earlier by surname in alphabetical order
void mergeSort(studentInfo **head, int low, int high) {
    // If there is more than one element to sort
    struct studentInfo *current = *head;
    if (low < high) {

        // Divide the range into two halves
        int mid = (low + high) / 2;

        // Recursively sort the left half
        mergeSort(head, low, mid);

        // Recursively sort the right half
        mergeSort(head, mid + 1, high);

         // Merge the two sorted halves together
        Merge(head, low, mid, high);
    }   
}

// A function to merge two sorted lists by surname
void Merge(studentInfo **head, int low, int mid, int high) {
    // Calculate the size of the left and right lists
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    // Allocate memory for the left and right lists that will be used to merge
    studentInfo **left = malloc(leftSize * sizeof(studentInfo *));
    studentInfo **right = malloc(rightSize * sizeof(studentInfo *));

    // Set a pointer to the current node to the head of the list
    studentInfo *current = *head;

    // Fill the left list using the information from the linked list
    for (int i = 0; i < leftSize; i++) {                    
        left[i] = current;
        current = current->next;
    }
    // Fill the right list using the information from the linked list
    for (int i = 0; i < rightSize; i++) {
        right[i] = current;
        current = current->next;
    }

    // Initialize loop variables
    int i = 0, j = 0, k = low;

    // Merge left and right lists together into one sorted list by surname
    while (i < leftSize && j < rightSize) {
        // Compare the surnames of the two students being merged iin the list and place them in order in alphabetical order
        if (strcmp(left[i]->surname, right[j]->surname) <= 0) {
            *head = left[i];
            i++;
        } else {
            *head = right[j];
            j++;
        }

        // Set the next pointer to NULL and add the merged node to the linked list
        (*head)->next = NULL;
        if (k > low) {
            studentInfo *prev = *head;
            while (prev->next != NULL) {
                prev = prev->next;
            }
        prev->next = current;
        }

        // Increment loop variables 
        k++;
        head = &((*head)->next); // move the head to the next node in the list
    }

    // Add any remaining nodes from the left list to the merged list
    while (i < leftSize) {
        *head = left[i];
        i++;
        (*head)->next = NULL;                               
        if (k > low) {
            studentInfo *prev = *head;
            while (prev->next != NULL) {
                prev = prev->next;
            }
            prev->next = current;
        }
        k++;
        head = &((*head)->next);
    }

    // Add any remaining nodes from the right list to the merged list
    while (j < rightSize) {
        *head = right[j];
        j++;
        (*head)->next = NULL;
        if (k > low) {
            studentInfo *prev = *head;
            while (prev->next != NULL) {
                prev = prev->next;
            }
            prev->next = current;
        }
        k++;
        head = &((*head)->next); // move the head to the next node in the list
    }

    // Free the memory allocated for the left and right lists
    free(left);
    free(right);
}

//function to print all full time students attending
void PrintFullTimeStudents(studentInfo *head) {
    studentInfo *current = head;
    int found = 0; //variable to keep track of if any full-time students were found

    //Formatting thats why we use %-10s
    printf("%-10s %-15s %-15s %-10s %-10s\n", "Year", "First Name", "Surname", "Module", "ID");
    while (current != NULL) {
        if (strcmp(current->module, "DT265B") == 0 || strcmp(current->module, "DT8900") == 0) {
            printf("%-10d %-15s %-15s %-10s %-10s\n", current->year, current->firstName, current->surname, current->module, current->studentID);
            found = 1; //at least one full-time student was found
        }
        current = current->next; //moves to the next node until it reaches the end
    }

    if (!found) {
        printf("No full-time students found.\n");
    }
}

//function for binary search
void BinarySearch(studentInfo *students, int numstudents) {
    //user inputs the surname they want to search
    char surname[LENGTH];
    printf("Enter the surname you want to lookup:\n");
    fgets(surname, LENGTH, stdin);
    surname[strcspn(surname, "\r\n")] = '\0';

    //We use mergesort to allow the binary search to work
    mergeSort(&students, 0, numstudents - 1);
    // Search the linked list using binary search
    int left = 0, right = numstudents - 1;
    while (left <= right) {
        int mid = (left + right) / 2;

        // Traverse the linked list to the middle node
        studentInfo *current = students;
        for (int i = 0; i < mid; i++) {
            current = current->next;            
        }

        // Compare the surname of the middle node with the surname
        int cmp = strcmp(current->surname, surname);
        if (cmp == 0) {  // Found the student with the surname
            printf("%-10s %-15s %-15s %-10s %-10s\n", "Year", "First Name", "Surname", "Module", "ID");
            printf("%-10d %-15s %-15s %-10s %-10s\n", current->year, current->firstName, current->surname, current->module, current->studentID);
            return;
        } 
        else if (cmp < 0) {  // surname is in the right half 
            left = mid + 1;
        } 
        else {  // surname is in the left half
            right = mid - 1;
        }   
    }

    // surname not found in the linked list
    printf("Student with surname '%s' not found.\n", surname);
}   


