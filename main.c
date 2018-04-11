#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
	// 测试程序
	SqList list;
	// 初始化
	InitList(&list);

	// 插入操作
	for (int i = 0; i < 10; ++i)
	{
		ListInsert(&list, i, i + 10);
	}

	// 遍历
	for (int i = 0; i < ListLength(list); ++i)
	{
		int tmp;
		GetElem(list, i, &tmp);
		printf("Elem value = %d\n", tmp);
	}

	// 删除 - 全部
	while (ListEmpty(list) != 1)
	{
		int tmp;
		ListDelete(&list, 0, &tmp);
		printf("Delete Elem value = %d\n", tmp);
	}

	system("pause");
}