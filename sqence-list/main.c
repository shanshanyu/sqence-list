#include "list.h"
int main() {
	sqlist la, lb;
	initlist(&la);
	initlist(&lb);
	int a[] = { 1,3,5,7,9 };
	int b[] = { 7,9,11,13,15 };
	int i;
	for (i = 1;i <= 5;i++)listinsert(&la, i, a[i - 1]);
	for (i = 1;i <= 5;i++)listinsert(&lb, i, b[i - 1]);
	for (i = 1;i <= lb.length;i++) {
		if(!locateelem(la,lb.elem[i-1],compare))  listinsert(&la, la.length+1,lb.elem[i-1]);
		
	}
	listtraverse(la, print);
	destroylist(&la);
	destroylist(&lb);
	system("pause");
	return 0;
}
