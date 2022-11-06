#pragma once
typedef int type;

typedef struct node {
	type key;
	struct node* next;
	struct node* prev;
}node;

typedef struct List {
	struct node* head;
	struct node* tail;
}list;

list* getANewList();
node* getANewNode();
void insertToL(list* l, type data);
void insertToHead(list* l, type data);
void insertAfterX(node* l, type data);
void printmyList(list* l);
void deleteLinklist(list* l);
void deleteNode(list* l, node* n);
int isEmpty(list* l);