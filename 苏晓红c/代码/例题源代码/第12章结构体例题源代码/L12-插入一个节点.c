#include <stdio.h>
#include <stdlib.h>
struct link *AppendNode(struct link *head);
void DisplyNode(struct link *head);
void DeleteMemory(struct link *head);
struct link *InsertNode(struct link *head, int nodeData);

struct link
{
	int data;
	struct link *next;
};
int main()
{
	int	i = 0;                
	char	c;		
	struct link *head = NULL;	  /* ����ͷָ�� */	
	printf("Do you want to append a new node(Y/N)?");
	scanf(" %c",&c);	           /* %cǰ����һ���ո� */
	while (c=='Y' || c=='y')
	{				
		head = AppendNode(head);
		DisplyNode(head);           /* ��ʾ��ǰ�����еĸ��ڵ���Ϣ */
		printf("Do you want to append a new node(Y/N)?");
		scanf(" %c",&c);	      /* %cǰ����һ���ո� */
	      i++;                       
	}	
	printf("%d new nodes have been apended!\n", i);	
	head = InsertNode(head, 20);
	DisplyNode(head);     
	DeleteMemory(head);           /* �ͷ����ж�̬������ڴ� */
	return 0;
}
/* �������ܣ��½�һ���ڵ㲢��ӵ�����ĩβ��������ӽڵ��������ͷָ�� */
struct link *AppendNode(struct link *head)
{
	struct link *p = NULL;
	struct link *pr = head;	
	int	data;
	p = (struct link *)malloc(sizeof(struct link)); /* ��pָ���½��ڵ� */
	if (p == NULL)      
	{
		printf("No enough memory to allocate!\n");
		exit(0);						
	}	
	if (head == NULL) 	           /* ��ԭ����Ϊ�ձ����½��ڵ���Ϊ�׽ڵ� */
	{				
		head = p; 		
	}
	else                  	           /* ��ԭ����Ϊ�ǿգ����½��ڵ���ӵ���β */
	{		
		while (pr->next != NULL)/* ��δ����β�����ƶ�prֱ��prָ���β */
		{
			pr = pr->next;     /* ��prָ����һ���ڵ� */
		}
		pr->next = p; 			 /* ���½��ڵ���ӵ������ĩβ */
	}
	pr = p;             			 /* ��prָ���½��ڵ� */
	printf("Input node data:");
	scanf("%d", &data);        	 /* ����ڵ����� */
	pr->data = data;
	pr->next = NULL;			 /* ���½��ڵ���Ϊ��β */	
	return head;               	 /* ������ӽڵ��������ͷ�ڵ�ָ�� */
}
/* 	�����Ĺ��ܣ���ʾ���������нڵ�Ľڵ�ź͸ýڵ������������� */
void DisplyNode(struct link *head)
{
	struct link *p = head;
	int	j = 1;
	while (p != NULL)        	           /* �����Ǳ�β����ѭ����ӡ */
	{
		printf("%5d%10d\n", j, p->data);/* ��ӡ��j���ڵ������ */
		p = p->next;             		  /* ��pָ����һ���ڵ� */
		j++;
	}                            
}
/*	�������ܣ��ͷ�headָ������������нڵ�ռ�õ��ڴ� */
void DeleteMemory(struct link *head)
{
	struct link *p = head, *pr = NULL;
	while (p != NULL)           	/* �����Ǳ�β�����ͷŽڵ�ռ�õ��ڴ� */
	{	
		pr = p;                  	/* ��pr�б��浱ǰ�ڵ��ָ�� */
		p = p->next;            	/* ��pָ����һ���ڵ� */
		free(pr);                	/* �ͷ�prָ��ĵ�ǰ�ڵ�ռ�õ��ڴ� */
	}            
}
/* �������ܣ����Ѱ���������������в���һ���ڵ㣬���ز���ڵ�������ͷָ�� */
struct link *InsertNode(struct link *head, int nodeData)
{
	struct link *pr = head, *p = head, *temp = NULL;
	p = (struct link *)malloc(sizeof(struct link));/* ��pָ�������ڵ� */
	if (p == NULL)    		/* ��Ϊ�½��ڵ������ڴ�ʧ�ܣ����˳����� */
	{
		printf("No enough memory!\n");
		exit(0);				
	}	
	p->next = NULL;		/* Ϊ������ڵ��ָ����ֵΪ��ָ�� */
	p->data = nodeData;	/* Ϊ������ڵ�������ֵΪnodeData */
	if (head == NULL)		/* ��ԭ����Ϊ�ձ� */
	{	
     	head = p;           /* ������ڵ���Ϊͷ�ڵ� */
  	}
	else 
	{ 	/* ��δ�ҵ�������ڵ��λ����δ����β��������� */
		while (pr->data < nodeData && pr->next != NULL)
       	{
				temp = pr;     /* ��temp�б��浱ǰ�ڵ��ָ�� */
				pr = pr->next;/* prָ��ǰ�ڵ����һ�ڵ� */	 
		}		
		if (pr->data >= nodeData)
		{
				if (pr == head)      /* ����ͷ�ڵ�ǰ�����½ڵ� */
				{
				p->next = head;/* ���½ڵ��ָ����ָ��ԭ�����ͷ�ڵ� */
				head = p;       /* ��headָ���½ڵ� */
				}
				else                   /* ���������м�����½ڵ� */
				{
					pr = temp;
					p->next = pr->next;/* ���½ڵ��ָ����ָ����һ�ڵ� */
					pr->next = p;       /* ��ǰһ�ڵ��ָ����ָ���½ڵ� */
				}
		}
		else                    /* ���ڱ�β�����½ڵ� */
		{
				pr->next = p;    /* ��ĩ�ڵ��ָ����ָ���½ڵ� */
		}
	}
	return head;			   /* ���ز����½ڵ�������ͷָ��head��ֵ */
}

