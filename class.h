#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "grade.h"
#include "student.h"
#include <string.h>

typedef struct ClassList {//רשימת קורסים בכללי
	struct Class* head; // הקורס הראשון ברשימה
	struct Class* tail; // הקורס האחרון ברשימה
}ClassList;

typedef struct Class {//קורס
	//struct StudentList* Students; // רשימת הסטודנטים
	char name[30]; // שם הקורס
	int classNumber; // מספר הקורס
	int ClassAverage; // ממוצע קורס
	int minimumGrade; // ציון הכי נמוך
	int maximumGrade; // ציון הכי גבוהה
	int sumGrades; // סכום כל הציונים
	int sumOfStudents; // סכום כל הסטודנטים
	struct StudentListInClass* StudentL;
	struct Class* nextClass; // הקורס הבא ברשימה
	struct Class* prevClass; // הקורס הקודם ברשימה
}Class;

ClassList* createListClass(); // יצירת רשימת קורסים
Class* createClass(char* name, int numC); // יצירת קורס חדש
void insertNewClass(ClassList* cl, Class* c); // הכנסת קורס חדש לרשימת קורסים
Class* searchInListClass(ClassList* CL, int key);
void updateNameClass(Class* c, char* name); // עדכון שם לקורס
void insertNewStudentToClass(Class* c, char* name, int grade);
void printAllStudentsClass(Class* c);
//void printClass(Class* c); // הדפסת קורס יחד עם משתתפיו
//void printAllClasses(ClassList* cl); // הדפסת כל הקורסים עם כל משתתפיו וציוניהם