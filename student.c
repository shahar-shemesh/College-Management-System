#define _CRT_SECURE_NO_WARNINGS

#include "mylinklist.h"
#include "student.h"
#include "grade.h"
#include "class.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

StudentList* createStudentsList()
{
	StudentList* temp = (StudentList*)malloc(sizeof(StudentList));
	assert(temp);
	temp->head = NULL;
	temp->tail = NULL;
	return temp;
}
//student* createStudent(char* name, int numClass, int grade)//יצירת סטודנט בכללי
//{
//	student* temp = (student*)malloc(sizeof(student));
//	assert(temp);
//	strcpy(temp->name, name);
//	temp->gradesStudent = createGradesList();
//	assert(temp->gradesStudent);
//	insertNewGrade(temp->gradesStudent, numClass, grade);
//	return temp;
//}

void insertNewStudentSL(StudentList* SL, char* name, int numClass, int grade)//יצירת סטודנט בכללי
{
	student* temp = (student*)malloc(sizeof(student));
	assert(temp);
	strcpy(temp->name, name);
	temp->nextStudent = NULL;	
	temp->prevStudent = NULL;
	temp->gradesStudent = createGradesList();
	assert(temp->gradesStudent);
	insertNewGrade(temp->gradesStudent, numClass, grade);
	if (SL->head == NULL)
	{
		SL->head = temp;
		SL->tail = temp;
	}
	else
	{
		temp->prevStudent = SL->tail;
		SL->tail->nextStudent = temp;
		SL->tail = temp;
	}
	return;
}

StudentListInClass* createStudentListInClass()//יצירת רשימת סטודנטים לקורס ספציפי
{
	StudentListInClass* temp = (StudentListInClass*)malloc(sizeof(StudentListInClass));
	assert(temp);
	temp->head = NULL;
	temp->tail = NULL;
	return temp;
}
studentInClass* createstudentInClass(char* name, int score)//יצירת סטודנט לרשימת קורס
{
	studentInClass* temp = (studentInClass*)malloc(sizeof(studentInClass));
	assert(temp);
	strcpy(temp->name, name);
	temp->scoreInThisClass = score;
	temp->nextStudent = NULL;
	temp->prevStudent = NULL;
	return temp;
}
studentInClass* searchInClassListStudent(StudentListInClass* sl, char* key) // חיפוש סטודנט בקורס ספציפי
{
	if (sl->head == NULL)
	{
		return NULL;
	}
	studentInClass* temp = sl->head;
	while (temp->nextStudent != NULL)
	{
		if (temp->name == key)
		{
			return temp;
		}
		temp = temp->nextStudent;
	}
	if (*temp->name == *key)
	{
		return temp;
	}
	return NULL;
}
student* searchInListStudent(StudentList* SL, char* key)//חיפוש סטודנט ברשימה כללית
{
	if (SL->head == NULL)
	{
		return NULL;
	}
	else
	{
		student* temp = SL->head;
		while (temp->nextStudent != NULL)
		{
			if (*temp->name == *key)
			{
				return temp;
			}
			temp = temp->nextStudent;
		}
		if (*temp->name == *key)
		{
			return temp;
		}
	}
	return NULL;
}

void deleteStudentFromClass(StudentListInClass* lc, char* name, int numClass, char* nameClass)
{
	studentInClass* searchStudent = searchInClassListStudent(lc, name);
	if (searchStudent == NULL)
	{
		color('r'); printf("Error: student is not a member of class \"%d %s\".\n", numClass, nameClass); color(' ');
		return;
	}
	if (searchStudent->prevStudent == NULL)
	{
		lc->head = searchStudent->nextStudent;
		free(searchStudent);
	}
	else if (searchStudent->nextStudent == NULL)
	{
		lc->tail = searchStudent->prevStudent;
		lc->tail->nextStudent = NULL;
		free(searchStudent);
	}
	else
	{
		searchStudent->prevStudent->nextStudent = searchStudent->nextStudent;
		searchStudent->nextStudent->prevStudent = searchStudent->prevStudent;
		free(searchStudent);
	}
	color('b'); printf("Student \"%s\" removed from class \"%d %s\".\n", name, numClass, nameClass); color(' ');
}
int amountClassesStudent(student* s)
{
	int counter = 0;
	grade* temp = s->gradesStudent->head;
	while (temp->next != NULL)
	{
		counter++;
		temp = temp->next;
	}
	if (temp != NULL)
	{
		counter++;
	}
	return counter;
}
//void deleteStudentFromClass(student* s, Class* c);
//void StudentRegistrationForClass(student* s, Class* c);
//void updateGradeStudent(student* s, Class* c);
