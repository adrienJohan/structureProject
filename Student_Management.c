#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <math.h>
#include "./struct_student.h"

void title_test(FILE * pointfile);

int main () 
{
	FILE * info_student = fopen("./student_management.csv", "a+");
	FILE * test_student = fopen("./student_management.csv", "r");
	if (info_student == NULL)
	{
		printf("Error while opening file\n");
		return 1;
	}
	
	
	int number = 0, testBelong = 0; 
	char * contain = malloc(500);
	printf("How many student do you want to register?:\n");
	scanf("%d", &number);
	Information * student;
	student = (Information*)malloc(number* sizeof(Information));
	for(int i = 0 ; i< number ; i++)
	{
		printf("Student N°%d:\n", i+1);
		printf("First name : \n");
		scanf("%s", student[i].firstname);
		printf("Last name : \n");
		scanf("%s", student[i].lastname);
		printf("Age : \n");
		scanf("%d", &student[i].age);
		printf("Phone number : \n");
		scanf("%s", student[i].num);
		printf("date of birth : \n");
		scanf("%s", student[i].date_birth);
		printf("Place of birth : \n");
		scanf("%s", student[i].place_birth);
		printf("E-mail:\n");
		scanf("%s", student[i].mail);
		printf("Gender :\n");
		scanf("%s", student[i].gender);
		printf("address : \n");
		scanf("%s", student[i].address);
		printf("git url : \n");
		scanf("%s", student[i].url);
		testBelong = 0;
		while(fgets(contain, 500 , test_student) != NULL)
		{
			if(strstr(contain, student[i].firstname) != NULL && strstr(contain, student[i].lastname)!= NULL)
			{
                printf("This student is already registered\n");
                testBelong = 1;
                break;
            }
		}
		 if (testBelong != 1) {
           
            fprintf(info_student, "%s;%s;%d;;%s;%s;%s;%s;%s;%s;%s\n", student[i].firstname, student[i].lastname, student[i].age, student[i].num, student[i].date_birth, student[i].place_birth, student[i].mail, student[i].gender, student[i].address, student[i].url);
            printf("Student %d fully registered\n", i + 1);
        }
	
	}
	
	
	return 0;
}



