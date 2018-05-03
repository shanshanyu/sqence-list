#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 2
typedef int status;
typedef int elemtype;
typedef struct {
	elemtype *elem;
	int length;
	int listsize;
}sqlist;
extern status initlist(sqlist *);
extern status destroylist(sqlist *);
extern status listinsert(sqlist *, int, elemtype);
extern status listtraverse(sqlist, void(*vi)(elemtype *));
extern void print(elemtype *);
extern status compare(elemtype, elemtype);
extern int locateelem(sqlist, elemtype, status(*comp)(elemtype, elemtype));
#endif
