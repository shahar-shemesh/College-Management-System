#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "class.h"
#include "grade.h"
#include <string.h>

typedef struct StudentList {// ����� �������� �����
	struct student* head; // ������ ����� ������
	struct student* tail; // ������ ����� ������
}StudentList;

typedef struct student {//������ �����
	char name[30]; // �� �������
	struct ListGrades* gradesStudent; // ����� ����� �������
	struct student* nextStudent; // ������� ��� ������
	struct student* prevStudent; // ������� ����� ������
}student;

StudentList* createStudentsList();
//student* createStudent();
void insertNewStudentSL(StudentList* SL, char* name, int numClass, int grade);
student* searchInListStudent(StudentList* SL, char* key);

//void deleteStudentFromClass(student* s, Class* c);
//void StudentRegistrationForClass(student* s, Class* c);
//void updateGradeStudent(student* s, Class* c);



/**********************************/

typedef struct StudentListInClass {//����� �������� ����� ������
	struct studentInClass* head; // ������ ����� ������
	struct studentInClass* tail; // ������ ����� ������
}StudentListInClass;

typedef struct studentInClass {//������ �����
	char name[30]; // �� �������
	int scoreInThisClass; // ���� ������� ����� ������� ���
	struct studentInClass* nextStudent; // ������� ��� ������
	struct studentInClass* prevStudent; // ������� ����� ������
}studentInClass;

StudentListInClass* createStudentListInClass();//����� ����� �������� ����� ������
studentInClass* createstudentInClass(char* name, int score);//����� ������ ������ ����
studentInClass* searchInClassListStudent(StudentListInClass* sl, char* key); // ����� ������ ����� ������
void deleteStudentFromClass(StudentListInClass* lc, char* name, int numClass, char* nameClass);

