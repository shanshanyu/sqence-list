#include "list.h"
status initlist(sqlist *l) {  //initial list
	l->elem = malloc(LIST_INIT_SIZE * sizeof(elemtype));
	if (!l->elem) return ERROR;
	l->length = 0;
	l->listsize = LIST_INIT_SIZE;
	return OK;
}

status destroylist(sqlist *l) {  //destroy list
	free(l->elem);
	l->elem = NULL;
	l->length = 0;
	l->listsize = 0;
	return OK;
}

status listinsert(sqlist *l, int i, elemtype e) {  //在i的位置插入一个元素e
	elemtype *p, *q, *new;//加一个new是有好处的，在内存分配失败的情况下不会影响原有的变量
	if (i<1 || i>l->length + 1) return ERROR;
	if (l->length >= l->listsize) {
		new = realloc(l->elem, (LISTINCREMENT + l->listsize) * sizeof(elemtype));
		if (!new) return ERROR;
		l->elem = new;
		l->listsize += LISTINCREMENT;
	}
	q = l->elem + i - 1;
	for (p =l->elem + l->length - 1;q <= p;p--)
		*(p + 1) = *p;
	*q = e;
	++l->length;
	return OK;
}
status listtraverse(sqlist l, void(*vi)(elemtype *)) {
	int i;
	elemtype *p = l.elem;
	for (i = 1;i <= l.length;i++)
		vi(p++);
	return OK;
}

void print(elemtype *p) {
	printf("%d\n", *p);
}

status compare(elemtype a, elemtype b) {
	if (a == b) return TRUE;
	else return FALSE;
}
int locateelem(sqlist l, elemtype e, status(*comp)(elemtype, elemtype)) {
	int i = 1;
	elemtype *p = l.elem;
	while (i <= l.length&&!comp(*p++, e))
		i++;
	if (i <= l.length) return i;
	else return 0;
}

