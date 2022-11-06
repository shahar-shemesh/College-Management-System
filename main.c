#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include "mylinklist.h"
#include "class.h"
#include "student.h"
#include "grade.h"

/* Function declarations */
void color(char c)
{
	switch (c)
	{
		case 'r': printf("\033[1;31m"); break;//red
		case 'g': printf("\033[1;32m"); break;//green
		case 'y': printf("\033[1;33m"); break;//yellow
		case 'b': printf("\033[1;34m"); break;//blue
		case 'p': printf("\033[1;35m"); break;//purple
		case 'w': printf("\033[1;37m"); break;//white
		case 'bw': printf("\033[1m\033[37m"); break;//white
		default: printf("\033[0m"); break;
	}
}

void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();
void Ex6();
void Ex7();
void menu();
void removeSpaces(char* name);

void main()
{
	printf("Please select an operation:\n");
	color('p'); puts("\t1. Exit."); color(' ');
	puts("\t2. Insert or update a class.");
	puts("\t3. Insert or update a student.");
	puts("\t4. Remove a student from classes.");
	puts("\t5. Print a class.");
	puts("\t6. Print all classes with their computed scores.");
	puts("\t7. Print the menu."); 
	ClassList* CL = createListClass();
	StudentList* SL = createStudentsList();
	menu(CL, SL);
	return;
}

int check(char select)
{
	if (select >= '1' && select <= '7')
		return 1;
	else
	{
		color('r'); puts("\tError: unrecognized operation.\n"); color(' ');
		return 1;
	}
}
void menu(ClassList* CL, StudentList* SL)
{
	char select;
	scanf_s(" %c", &select);
	getchar();
	while (check(select))
	{
		switch (select)
		{
			case '1': Ex1(CL, SL); break;
			case '2': Ex2(CL); break;
			case '3': Ex3(CL,SL); break;
			case '4': Ex4(CL, SL); break;
			case '5': Ex5(CL, SL); break;
			case '6': Ex6(CL, SL); break;
			case '7': Ex7(); break;
		}
		color('g'); puts("\tSelect the next operation (insert 6 for the entire menu):"); color(' ');
		scanf(" %c", &select);
		getchar();
	}
	return;
}

void Ex1(ClassList* CL, StudentList* SL)
{
	if (CL->head == NULL && SL->head == NULL)
	{
		color('p'); puts("\t\tBye Bye.."); color(' ');
		exit(1);
	}
	else if (SL->head == NULL && CL->head != NULL)
	{
		Class* temp = CL->head;
		while (temp->nextClass != NULL)
		{
			Class* remove = temp;
			temp = temp->nextClass;
			free(remove);
		}
		if (temp != NULL)
		{
			free(temp);
		}
		free(CL);
		color('p'); puts("\t\tBye Bye.."); color(' ');
		exit(1);
	}
	else
	{
		Class* temp = CL->head;
		while (temp->nextClass != NULL)
		{
			Class* remove = temp;
			temp = temp->nextClass;
			free(remove);
		}
		if (temp != NULL)
		{
			free(temp);
		}
		free(CL);

		student* tmp = SL->head;
		while (tmp->nextStudent != NULL)
		{
			student* remove = tmp;
			tmp = tmp->nextStudent;
			free(remove);
		}
		if (tmp != NULL)
		{
			free(tmp);
		}
		free(SL);
		color('p'); puts("\t\tBye Bye.."); color(' ');
		exit(1);
	}
}

/*Ex 2*/
void removeSpaces(char* name)
{
	int count = 0;
	int i = 1;
	if (name[0] != ' ')
	{
		i = 0;
	}
	for (int j = 0; name[i]; i++)
	{
		if (!(name[i-1] == ' ' && name[j+1] == ' '))
			name[count++] = name[i];
		j++;
	}
	name[count] = '\0';
	return;
} 
int checkDetails(char* name)
{
	for (int i = 0; name[i] ; i++)
	{
		if (!((name[i] == ' ') || ((name[i] >= '0' && name[i] <= '9') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z'))))
		{
			return 0;
		}
	}
	return 1;
}
void Ex2(ClassList* CL)
{
	char name[30];
	int numClass;
	color('g'); puts("Enter a class number and class name [class number, class name]: \n"); color(' ');
	scanf_s(" %d", &numClass); getchar();
	gets(name); removeSpaces(name);
	/*check*/
	if ((checkDetails(name)) && (numClass >= 10000 && numClass <= 99999))
	{
		Class* update = searchInListClass(CL, numClass);
		if (update != NULL)
		{
			updateNameClass(update, name);
			color('y');  printf("Class \"%d %s\" updated.\n", numClass, name); color(' ');
		}
		else
		{
			Class* temp = createClass(name, numClass);
			if (!temp)
			{
				color('r'); puts("\tUnfortunately, there is no room for more classes.\n"); color(' ');
			}
			insertNewClass(CL, temp);
			color('b');  printf("Class \"%d %s\" added.\n", numClass, name); color(' ');
		}
	}
	else
	{
		color('r'); puts("\tError: invalid class number or name.\n"); color(' ');
	}
}


//EX 3
void setName(char* name)
{
	int i;
	for (i = 0; name[i - 1] != ':'; i++)
	{
		scanf_s("%c", &name[i]);
	}
	name[i - 1] = '\0';
	removeSpaces(name);
	return;
}
void registerStudent(ClassList* CL, StudentList* SL)
{
	char name[20];
	int numClass;
	int grade;
	char flag = ' ';
	setName(name);
	while (flag != '\n')
	{
		scanf_s(" %d", &numClass); getchar();
		scanf_s(" %d", &grade); getchar(); scanf_s("%c", &flag);
		Class *searchClass = searchInListClass(CL, numClass);
		if ((checkDetails(name)) && (searchClass != NULL))
		{
			insertNewStudentToClass(searchClass, name, grade);
		}
		else
		{
			color('r'); puts("\tError: invalid name, class number or grade.\n"); color(' ');
		}
		student* searchStudent = searchInListStudent(SL, name);
		if (searchStudent != NULL && (searchClass != NULL))
		{
			insertNewGrade(searchStudent->gradesStudent, numClass, grade);
		}
		else if ((searchClass != NULL))
		{
			insertNewStudentSL(SL, name, numClass, grade);
		}
	}
}
void Ex3(ClassList* CL, StudentList* SL)
{
	color('g'); puts("Enter a student name, classes numbers and grades. Finally inserted \';\' [student name: class number, grade;]: \n"); color(' ');
	registerStudent(CL, SL);
}

//EX 4
int ifStudentIn(StudentListInClass* sl, char* name)
{
	studentInClass* searchStudent = searchInClassListStudent(sl, name);
	if (searchStudent)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void removeStudent(ClassList* CL, StudentList* SL)
{
	char name[20];
	int numClass;
	char flag = ' ';
	setName(name);
	list* count = getANewList();
	int counterC = 0, counterS = 0;
	student* searchStudent = searchInListStudent(SL, name);

	while (flag != '\n')
	{
		scanf_s(" %d", &numClass); getchar();
		scanf_s("%c", &flag); //getchar(); //scanf_s("%c", &flag);
		
		Class* searchClass = searchInListClass(CL, numClass);
		if (searchClass == NULL)
		{
			color('r'); puts("\tError: invalid name or class number.\n"); color(' ');
		}
		else
		{
			counterS += ifStudentIn(searchClass->StudentL, name);
			insertToL(count, numClass);
		}
	}
	counterC = amountClassesStudent(searchStudent);
	if (counterC == counterS)
	{
		color('r'); puts("\tError: student cannot be removed from all classes.\n"); color(' ');
		return;
	}
	node* temp = count->head;
	while (temp->next != NULL)
	{
		Class* searchClass = searchInListClass(CL, temp->key);
		if ((searchClass != NULL) && (searchStudent != NULL))
		{
			studentInClass* searchStudentGrade = searchInClassListStudent(searchClass->StudentL, name);
			searchClass->sumGrades -= searchStudentGrade->scoreInThisClass;
			searchClass->sumOfStudents--;
			searchClass->ClassAverage = searchClass->sumOfStudents > 0 ? (searchClass->sumGrades / searchClass->sumOfStudents) : 0;
			deleteStudentFromClass(searchClass->StudentL, name, temp->key, searchClass->name);
			deleteGradeFromList(searchStudent->gradesStudent, temp->key);
		}
		else
		{
			color('r'); puts("\tError: invalid name or class number.\n"); color(' ');
		}
		temp = temp->next;
	}
	if (temp != NULL)
	{
		Class* searchClass = searchInListClass(CL, temp->key);
		if ((searchClass != NULL) && (searchStudent != NULL))
		{
			studentInClass* searchStudentGrade = searchInClassListStudent(searchClass->StudentL, name);
			searchClass->sumGrades -= searchStudentGrade->scoreInThisClass;
			searchClass->sumOfStudents--;
			searchClass->ClassAverage = searchClass->sumOfStudents > 0 ? (searchClass->sumGrades / searchClass->sumOfStudents) : 0;
			deleteStudentFromClass(searchClass->StudentL, name, temp->key, searchClass->name);
			deleteGradeFromList(searchStudent->gradesStudent, temp->key);
		}
		else
		{
			color('r'); puts("\tError: invalid name or class number.\n"); color(' ');
		}
	}
	deleteLinklist(count);
}
void Ex4(ClassList* CL, StudentList* SL)
{
	color('g'); puts("Enter a student name and classes numbers with \',\' to delete the student. [student name: class number, class number]: \n"); color(' ');
	removeStudent(CL, SL);
}


//Ex 5
void printStudentList(CL, SL)
{
	int numClass;
	scanf_s(" %d", &numClass);
	Class* searchClass = searchInListClass(CL, numClass);
	if ((numClass >= 10000 && numClass <= 99999) && searchClass != NULL)
	{
		printAllStudentsClass(searchClass);
	}
	else
	{
		color('r'); puts("\tError: invalid class number.\n"); color(' ');
		return;
	}
}
void Ex5(ClassList* CL, StudentList* SL)
{
	color('g'); puts("Enter a class number to print the students list. [class number]: \n"); color(' ');
	printStudentList(CL, SL);
}


/*Ex 6*/
void printAllClasses(ClassList* CL, char select) {
	if (select == '0')
	{
		return;
	}
	Class* temp = CL->head;
	while (temp->nextClass != NULL)
	{
		printf("%d %s, ", temp->classNumber, temp->name);
		switch (select)
		{
		case 'a': printf("%d", temp->ClassAverage);   break;
		case 'b': printf("%d", temp->maximumGrade);   break;
		case 'c': printf("%d", temp->minimumGrade);   break;
		case 'd': printf("%d", temp->sumGrades);   break;
		case 'e': printf("%d", temp->sumOfStudents);   break;
		}
		puts("\n");
		temp = temp->nextClass;
	}
	if (temp != NULL)
	{
		printf("%d %s, ", temp->classNumber, temp->name);
		switch (select)
		{
		case 'a': printf("%d", temp->ClassAverage);   break;
		case 'b': printf("%d", temp->maximumGrade);   break;
		case 'c': printf("%d", temp->minimumGrade);   break;
		case 'd': printf("%d", temp->sumGrades);   break;
		case 'e': printf("%d", temp->sumOfStudents);   break;
		}
		puts("\n");
	}
}
void Ex6(ClassList* CL, StudentList* SL)
{
	if (CL->head == NULL)
	{
		color('g'); puts("Error: there are no classes.\n"); color(' ');
	}
	else
	{
		char select;
		puts("Please select the aggregation method:\n");
		puts("\ta.Average Grade.");
		puts("\tb.Maximal Grade.");
		puts("\tc.Minimal Grade.");
		puts("\td.Sum.");
		puts("\te.Count.");
		puts("\t0. Return to the main menu.\n");
		scanf(" %c", &select);
		getchar();
		printAllClasses(CL, select);
	}
}

/*Ex 7*/
void Ex7()
{
	printf("Please select an operation:\n");
	puts("\t1. Exit.");
	puts("\t2. Insert or update a class.");
	puts("\t3. Insert or update a student.");
	puts("\t4. Remove a student from classes.");
	puts("\t5. Print a class.");
	puts("\t6. Print all classes with their computed scores.");
	puts("\t7. Print the menu.");
	return;
}