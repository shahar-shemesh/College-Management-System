#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "class.h"
#include "student.h"
#include <string.h>

typedef struct ListGrades {//����� ������
	struct grade* head; // ����� ������ ������
	struct grade* tail; // ����� ������ ������
}ListGrades;

typedef struct grade {//����
	int classNumOfStudentGrade; // ���� ����� ��� ������� ���� ����
	int score; // �����
	struct grade* next; // ����� ��� �� �������
	struct grade* prev; // ����� ����� �� �������
}grade;

ListGrades* createGradesList();
grade* createGrades();
void insertNewGrade(ListGrades* lg, int classNum, int score);
grade* searchInListGrade(ListGrades* LG, int numClass);
void deleteGradeFromList(ListGrades* LG, int numClass);