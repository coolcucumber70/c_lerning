#include<stdio.h>
#include<stdlib.h>
#define N 12
//首先定义相关的结构体
typedef struct HNode {
	int key;
	struct HNode *next;
}Hnode;
/*
	创建哈希表
		heahLink哈希表，里面存储的为指针变量
		key关键字列表
		n关键字数目
*/
void createHB(Hnode *heahLink[], int key[], int n) {
	for (int i = 0; i < n; i++) {
		Hnode *head = (Hnode *)malloc(sizeof(Hnode));
		if (!head) {
			printf("error\n");
			return;
		}
		head->key = 0;
		head->next = NULL;
		heahLink[i] = head;
	}
	//插入操作
	for (int i = 0; i < n; i++) {
		Hnode *p, *H,*s;
		int j = key[i] % 11;
		H = p = heahLink[j];
		while (p->next != NULL) {
			p = p->next;
		}
		s = (Hnode *)malloc(sizeof(Hnode));
		s->key = key[i];
		s->next = NULL;
		p->next = s;
		H->key++;
	}
}
/**
	删除某个关键字
		heahLink为哈希表
		key为要删除的关键字
*/
void deleteNode(Hnode *heahLink[], int key) {
	Hnode *h, *p,*q;
	h = q = heahLink[key % 11];
	p = q->next;
	while (p->next != NULL && p->key !=key) {
		q = p;
		p = p->next;
	}
	if (!p->next) {
		printf("the key does't exist!!\n");
	}
	else {
		q->next = p->next;
		h->key--;
		free(p);
	}
}

/*
	释放内存空间
*/
void FreeNode(Hnode *heahLink[],int n) {
	Hnode *h, *p;
	for (int i = 0; i < n; i++) {
		h = p = heahLink[i];
		while (p->next != NULL) {
			p = p->next;
			free(h);
			h = p;
		}
		free(h);
	}
}
void print(Hnode *heahLink[],int n) {
	Hnode *p;
	printf("下标 个数\n");//%-d左对齐 %d右对齐
	for (int i = 0; i < n; i++) {
		p = heahLink[i];
		printf("  %-2d  ", i);//%-d左对齐 %d右对齐
		while (p->next != NULL) {
			printf("%-2d  ", p->key);
			p = p->next;
		}
		printf("%-2d \n", p->key);
	}
}
//测试程序
int main() {
	int key[] = { 13,28,72,5,16,8,7,9,34,24,18,25 };
	Hnode *heahLink[N];
	createHB(heahLink, key, N);
	printf("..before deleting..\n");
	print(heahLink, N);
	deleteNode(heahLink, key[1]);//删除key[1]，即28
	printf("..after deleting..\n");
	print(heahLink, N);
	FreeNode(heahLink, N);
	getchar();
	return 0;
}
