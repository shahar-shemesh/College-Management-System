#include "mylinklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int type;

list* getANewList() {
	list* l = (list*)malloc(sizeof(list));
	l->head = NULL;
	l->tail = NULL;
	return l;
}
node* getANewNode(type data)
{
	node* n = (node*)malloc(sizeof(node));
	n->key = data;
	n->next = NULL;
	n->prev = NULL;
	return n;
}
void insertToHead(list* l, type data)
{
	node* h = getANewNode(data);
	h->next = l->head;
	h->prev = NULL;
	l->head = h;

}

void insertToL(list* l, type data)
{
	node* t = getANewNode(data);
	if (l->head == NULL)
	{
		l->head = t;
		l->tail = t;
	}
	else
	{
		t->prev = l->tail;
		l->tail->next = t;
		l->tail = t;
		return;
	}
}

void insertAfterX(node* l, type data)
{
	node* n = getANewNode(data);
	n->next = l->next;
	l->next->prev = n;
	n->prev = l;
	l->next = n;
}
int isEmpty(list* l)
{
	return l->head == NULL;
}
void printmyList(list* l)
{
	if (l == NULL || l->head == NULL)
	{
		puts("List is empty\n");
		return;
	}
	else
	{
		node* tmp = l->head;
		while (tmp != NULL)
		{
			printf("%4d", tmp->key);
			tmp = tmp->next;
		}
		puts("\n");
	}
}
void deleteLinklist(list* l)
{
	//puts("Releses the link-list...\n\n");
	node* temp = l->head;
	while (temp != NULL)
	{
		node* d = temp;
		temp = temp->next;
		free(d);
	}
	free(l);
}
//void deleteNode(list* l, node* n)
//{
//	node* temp = n;
//	if (n->prev == NULL)
//	{
//		l->head = n->next;
//		free(temp);
//	}
//	else if (n->next == NULL)
//	{
//		l->tail = n->prev;
//		l->tail->next = NULL;
//		free(temp);
//	}
//	else
//	{
//		n->prev->next = n->next;
//		n->next->prev = n->prev;
//		free(temp);
//	}
//}
void deleteNode(list* l, node* n, node* prev)
{
	node* temp = n;
	if (n->next == NULL)
	{
		l->tail = prev;
		l->tail->next = NULL;
		free(temp);
	}
	else
	{
		prev->next = n->next;

		free(temp);
	}
}