#include <stdio.h>
struct Employee {
int id;
char name[30];
float salary;
};
int main() {
int n;
printf("Enter number of employees: ");
scanf("%d", &n);
struct Employee emp;
FILE *fp;
fp = fopen("employee.dat", "wb");
if (fp == NULL) {
printf("Error opening file!\n");
return 1;
}
for (int i = 0; i < n; i++) {
printf("\nEmployee %d ID: ", i + 1);
scanf("%d", &emp.id);
printf("Name: ");
scanf("%s", emp.name);
printf("Salary: ");
scanf("%f", &emp.salary);
fwrite(&emp, sizeof(struct Employee), 1, fp);
}
fclose(fp);
fp = fopen("employee.dat", "rb+");
if (fp == NULL) {
printf("Error opening file!\n");
return 1;
}
for (int i = 0; i < n; i++) {
fseek(fp, i * sizeof(struct Employee), SEEK_SET);
fread(&emp, sizeof(struct Employee), 1, fp);
if (emp.salary > 50000)
emp.salary += emp.salary * 0.05;
else if (emp.salary > 20000 && emp.salary <= 50000)
emp.salary += emp.salary * 0.10;
else
emp.salary += emp.salary * 0.15;
fseek(fp, i * sizeof(struct Employee), SEEK_SET);
fwrite(&emp, sizeof(struct Employee), 1, fp);
}
fclose(fp);
fp = fopen("employee.dat", "rb");
printf("\n--- Updated Employee Records ---\n");
while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
printf("ID: %d | Name: %s | Updated Salary: %.2f\n",
emp.id, emp.name, emp.salary);
}
fclose(fp);
return 0;
}