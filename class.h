#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "grade.h"
#include "student.h"
#include <string.h>

typedef struct ClassList {//����� ������ �����
	struct Class* head; // ����� ������ ������
	struct Class* tail; // ����� ������ ������
}ClassList;

typedef struct Class {//����
	//struct StudentList* Students; // ����� ���������
	char name[30]; // �� �����
	int classNumber; // ���� �����
	int ClassAverage; // ����� ����
	int minimumGrade; // ���� ��� ����
	int maximumGrade; // ���� ��� �����
	int sumGrades; // ���� �� �������
	int sumOfStudents; // ���� �� ���������
	struct StudentListInClass* StudentL;
	struct Class* nextClass; // ����� ��� ������
	struct Class* prevClass; // ����� ����� ������
}Class;

ClassList* createListClass(); // ����� ����� ������
Class* createClass(char* name, int numC); // ����� ���� ���
void insertNewClass(ClassList* cl, Class* c); // ����� ���� ��� ������ ������
Class* searchInListClass(ClassList* CL, int key);
void updateNameClass(Class* c, char* name); // ����� �� �����
void insertNewStudentToClass(Class* c, char* name, int grade);
void printAllStudentsClass(Class* c);
//void printClass(Class* c); // ����� ���� ��� �� �������
//void printAllClasses(ClassList* cl); // ����� �� ������� �� �� ������� ��������