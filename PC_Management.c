#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "./struct_PC.h"

void title_test(FILE * pointfile1, FILE * pointfile2);

int main () 
{
	FILE * student_PC = fopen("./PC.csv", "a+");
	FILE * test_PC = fopen("./PC.csv", "r");
	if(student_PC == NULL)
	{
		printf("error while opening file.\n");
        return 1;
	}
	if(test_PC == NULL)
	{
		printf("error while opening file.\n");
        return 1;
	} 

	char* contain = malloc(500);
	int number = 0, testBelong = 0; 
	printf("How many student do you want to register?\n:");
	scanf("%d", &number);
	PC * Student;
	Student = (PC*) malloc(number*sizeof(PC));
	for(int i = 0; i<number; i++)
	{
		printf("STUDENT N°%d\n", i+1);
		printf("PC's brand:\n");
		scanf("%s", Student[i].Marque);
		printf("Label:\n");
		scanf("%s", Student[i].Label);
		printf("MAC address:\n");
		scanf("%s", Student[i].MAC); 
		//fseek(register_test, 0, SEEK_SET);
        testBelong = 0;
        while (fgets(contain, 500, test_PC) != NULL) {
            if (strstr(contain, Student[i].Label) != NULL && strstr(contain, Student[i].Marque) != NULL && strstr(contain, Student[i].MAC) != NULL) 
            {
                printf("This student is already registered\n");
                testBelong = 1;
                break;
            }
        }

        if (testBelong != 1) {
            //fprintf(register_test, "%s;%s;%s\n", Student[i].Label, Student[i].Marque, Student[i].MAC);
            fprintf(student_PC, "%s;%s;%s\n", Student[i].Label, Student[i].Marque, Student[i].MAC);
            printf("Student %d fully registered\n", i + 1);
        }

        printf("--------------------------------------------------------\n");
        fseek(student_PC, 0, SEEK_SET);
        fseek(test_PC, 0, SEEK_SET);
    }

    fclose(student_PC);
    //fclose(register_test);
    free(Student);
	return 0;
}

 
/*void title_test(FILE * pointfile1, FILE* pointfile2)
{
	char* test = malloc(500);
	char* title = malloc(500);
	title = "LABEL;BRAND;MAC";
	int i = 0;
	
	
	while(fgets(test, 500 , pointfile2) != NULL)
	{
		if(strstr(title, test) != NULL){ 
		i++;
		break;
		}
	fseek(pointfile2, 0 , SEEK_SET);
	if( i  == 0) fprintf(pointfile1, "LABEL;BRAND;MAC\n");
	}
}*/
