// 3. Write a program to input array of structures for an employee and store it In a file one structure at a time also, read the salary input of every employee and update it in the file using the following rule	1.salary>50000: increment 5%	2.salary>20000 and <50000 : increment 10%
// 	3. Otherwise, increment : 3%

#include <stdio.h>

struct Employee{
        int salary;
        char name[20];
        int increment;
    };

int main(void) {
    printf("Hello, World!\n");
    struct Employee employees[5];
    FILE* fptr;

    fptr = fopen("employees.txt", "r");
    for(int i=0;i<5;i++){
        scanf("%d",employees[i].salary);
        scanf("%s",employees[i].name);
        if((employees[i].salary)>50000){
            employees[i].increment=5;
        }
        else if(employees[i].salary>50000 && employees[i].salary<50000){
            employees[i].increment=5;
        }
        else{
            employees[i].increment=15;
        }
        fwrite(&employees[i], sizeof(struct Employee), 1, fptr);
    }

    return 0;
}
