#define _CRT_SECURE_NO_WARNINGS

#include "mylinklist.h"
#include "student.h"
#include "grade.h"
#include "class.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

ListGrades* createGradesList()
{
	ListGrades* temp = (ListGrades*)malloc(sizeof(ListGrades));
	assert(temp);
	temp->head = NULL;
	temp->tail = NULL;
	return temp;
}
grade* createGrades()
{
	grade* temp = (grade*)malloc(sizeof(grade));
	assert(temp);
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

//grade* createGrade(int classNum, int score)
//{
//	grade* temp = (grade*)malloc(sizeof(grade));
//	assert(temp);
//	temp->classNumOfStudentGrade = classNum;
//	temp->score = score;
//	temp->next = NULL;
//	temp->prev = NULL;
//	return temp;
//}

grade* searchInListGrade(ListGrades* lg, int classNum)
{
	if (lg->head == NULL)
	{
		return NULL;
	}
	grade* temp = lg->head;
	while (temp->next != NULL)
	{
		if (temp->classNumOfStudentGrade == classNum)
		{
			return temp;
		}
		temp = temp->next;
	}
	if (temp->classNumOfStudentGrade == classNum)
	{
		return temp;
	}
	return NULL;
}

void insertNewGrade(ListGrades* lg, int classNum, int score)
{
	if (lg->head == NULL)
	{
		grade* temp = createGrades();
		assert(temp);
		temp->classNumOfStudentGrade = classNum;
		temp->score = score;
		lg->head = temp;
		lg->tail = temp;
	}
	else
	{
		grade* searchGrade = searchInListGrade(lg, classNum);
		if (searchGrade == NULL)
		{
			grade* temp = createGrades();
			assert(temp);
			temp->classNumOfStudentGrade = classNum;
			temp->score = score;
			temp->prev = lg->tail;
			lg->tail->next = temp;
			lg->tail = temp;
		}
		else
		{
			searchGrade->score = score;
		}
	}
}

void deleteGradeFromList(ListGrades* LG, int numClass)
{
	grade* searchGrade = searchInListGrade(LG, numClass);
	if (searchGrade->prev == NULL)
	{
		LG->head = searchGrade->next;
		free(searchGrade);
	}
	else if (searchGrade->next == NULL)
	{
		LG->tail = searchGrade->prev;
		LG->tail->next = NULL;
		free(searchGrade);
	}
	else
	{
		searchGrade->prev->next = searchGrade->next;
		searchGrade->next->prev = searchGrade->prev;
		free(searchGrade);
	}
}