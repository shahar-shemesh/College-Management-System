#define _CRT_SECURE_NO_WARNINGS

#include "mylinklist.h"
#include "class.h"
#include "student.h"
#include "grade.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

ClassList* createListClass() // יצירת רשימת קורסים
{
	ClassList* temp = (ClassList*)malloc(sizeof(ClassList));
	assert(temp);
	temp->head = NULL;
	temp->tail = NULL;
	return temp;
}

Class* createClass(char* name, int numC) // יצירת קורס חדש
{
	Class* temp = (Class*)malloc(sizeof(Class));
	assert(temp);
	strcpy(temp->name, name);
	temp->classNumber = numC;
	temp->StudentL = createStudentListInClass(); // יוצר רשימת סטודנטים של הקורס

	/**/
	temp->ClassAverage = 0;
	temp->minimumGrade = 100;
	temp->maximumGrade = 0;
	temp->sumGrades = 0;
	temp->sumOfStudents = 0;
	/**/
	temp->prevClass = NULL;
	temp->nextClass = NULL;
	return temp;
}

void insertNewClass(ClassList* CL, Class* c)
{
	if (CL->head == NULL)
	{
		CL->head = c;
		CL->tail = c;
	}
	else
	{
		c->prevClass = CL->tail;
		CL->tail->nextClass = c;
		CL->tail = c;
		return;
	}
}

Class* searchInListClass(ClassList* CL, int key)
{
	if (CL->head == NULL)
	{
		return NULL;
	}
	Class* temp = CL->head;
	while (temp->nextClass != NULL)
	{
		if (temp->classNumber == key)
		{
			return temp;
		}
		temp = temp->nextClass;
	}
	if (temp->classNumber == key)
	{
		return temp;
	}
	return NULL;
}

void updateNameClass(Class* c, char* name) // עדכון שם לקורס
{
	strcpy(c->name, name);
}

void insertNewStudentToClass(Class* c, char* name, int grade)//הכנסת סטודנט חדש לקורס הנל
{
	if (c->StudentL->head == NULL)
	{
		studentInClass* temp = createstudentInClass(name, grade);
		c->StudentL->head = temp;
		c->StudentL->tail = temp;
		if (grade < c->minimumGrade)
		{
			c->minimumGrade = grade;
		}
		if (grade > c->maximumGrade)
		{
			c->maximumGrade = grade;
		}
		c->sumOfStudents++;
		c->sumGrades += grade;
		c->ClassAverage = c->sumGrades / c->sumOfStudents;
		color('b'); printf("Student \"%s\" added to class \"%d %s\" with grade %d.\n", name, c->classNumber, c->name, grade); color(' ');
		return;
	}
	else
	{
		studentInClass* search = searchInClassListStudent(c->StudentL, name);
		if (search != NULL)
		{
			search->scoreInThisClass = grade;
			if (grade < c->minimumGrade)
			{
				c->minimumGrade = grade;
			}
			if (grade > c->maximumGrade)
			{
				c->maximumGrade = grade;
			}
			c->sumOfStudents++;
			c->sumGrades += grade;
			c->ClassAverage = c->sumGrades / c->sumOfStudents;
			color('b'); printf("Student \"%s\" updated on class \"%d %s\" with grade %d.\n", name, c->classNumber, c->name, grade); color(' ');
			return;
		}
		else
		{
			studentInClass* temp = createstudentInClass(name, grade);
			temp->prevStudent = c->StudentL->tail;
			c->StudentL->tail->nextStudent = temp;
			c->StudentL->tail = temp;
			if (grade < c->minimumGrade)
			{
				c->minimumGrade = grade;
			}
			if (grade > c->maximumGrade)
			{
				c->maximumGrade = grade;
			}
			c->sumOfStudents++;
			c->sumGrades += grade;
			c->ClassAverage = (c->sumGrades) / (c->sumOfStudents);
			color('b'); printf("Student \"%s\" added to class \"%d %s\" with grade %d.\n", name, c->classNumber, c->name, grade); color(' ');
			return;
		}
	}
}

void printAllStudentsClass(Class* c)
{
	if (c->StudentL->head == NULL)
	{
		color('g'); printf("Class \"%d %s\" has no students.\n", c->classNumber, c->name); color(' ');
		return;
	}
	else
	{
		color('g'); printf("Class: \"%d %s\" students:\n", c->classNumber, c->name); color(' ');
		studentInClass* student = c->StudentL->head;
		while (student->nextStudent != NULL)
		{
			color('b'); printf("%s, %d\n", student->name, student->scoreInThisClass); color(' ');
			student = student->nextStudent;
		}
		if (student != NULL)
		{
			color('b'); printf("%s, %d\n", student->name, student->scoreInThisClass); color(' ');
		}
	}
	return;
}