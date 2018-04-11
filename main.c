#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
	// ���Գ���
	SqList list;
	// ��ʼ��
	InitList(&list);

	// �������
	for (int i = 0; i < 10; ++i)
	{
		ListInsert(&list, i, i + 10);
	}

	// ����
	for (int i = 0; i < ListLength(list); ++i)
	{
		int tmp;
		GetElem(list, i, &tmp);
		printf("Elem value = %d\n", tmp);
	}

	// ɾ�� - ȫ��
	while (ListEmpty(list) != 1)
	{
		int tmp;
		ListDelete(&list, 0, &tmp);
		printf("Delete Elem value = %d\n", tmp);
	}

	system("pause");
}