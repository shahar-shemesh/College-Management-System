#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "class.h"
#include "student.h"
#include <string.h>

typedef struct ListGrades {//רשימת ציונים
	struct grade* head; // הציון הראשון ברשימה
	struct grade* tail; // הציון האחרון ברשימה
}ListGrades;

typedef struct grade {//ציון
	int classNumOfStudentGrade; // מספר הקורס שבו הסטודנט קיבל ציון
	int score; // הציון
	struct grade* next; // הציון הבא של הסטודנט
	struct grade* prev; // הציון הקודם של הסטודנט
}grade;

ListGrades* createGradesList();
grade* createGrades();
void insertNewGrade(ListGrades* lg, int classNum, int score);
grade* searchInListGrade(ListGrades* LG, int numClass);
void deleteGradeFromList(ListGrades* LG, int numClass);