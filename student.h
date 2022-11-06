#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "class.h"
#include "grade.h"
#include <string.h>

typedef struct StudentList {// רשימת סטודנטים בכללי
	struct student* head; // סטודנט ראשון ברשימה
	struct student* tail; // סטודנט אחרון ברשימה
}StudentList;

typedef struct student {//סטודנט בכללי
	char name[30]; // שם הסטודנט
	struct ListGrades* gradesStudent; // רשימת ציוני הסטודנט
	struct student* nextStudent; // הסטודנט הבא ברשימה
	struct student* prevStudent; // הסטודנט הקודם ברשימה
}student;

StudentList* createStudentsList();
//student* createStudent();
void insertNewStudentSL(StudentList* SL, char* name, int numClass, int grade);
student* searchInListStudent(StudentList* SL, char* key);

//void deleteStudentFromClass(student* s, Class* c);
//void StudentRegistrationForClass(student* s, Class* c);
//void updateGradeStudent(student* s, Class* c);



/**********************************/

typedef struct StudentListInClass {//רשימת סטודנטים בקורס ספציפי
	struct studentInClass* head; // סטודנט ראשון ברשימה
	struct studentInClass* tail; // סטודנט אחרון ברשימה
}StudentListInClass;

typedef struct studentInClass {//סטודנט בקורס
	char name[30]; // שם הסטודנט
	int scoreInThisClass; // ציון הסטודנט בקורס הספציפי הזה
	struct studentInClass* nextStudent; // הסטודנט הבא ברשימה
	struct studentInClass* prevStudent; // הסטודנט הקודם ברשימה
}studentInClass;

StudentListInClass* createStudentListInClass();//יצירת רשימת סטודנטים לקורס ספציפי
studentInClass* createstudentInClass(char* name, int score);//יצירת סטודנט לרשימת קורס
studentInClass* searchInClassListStudent(StudentListInClass* sl, char* key); // חיפוש סטודנט בקורס ספציפי
void deleteStudentFromClass(StudentListInClass* lc, char* name, int numClass, char* nameClass);

