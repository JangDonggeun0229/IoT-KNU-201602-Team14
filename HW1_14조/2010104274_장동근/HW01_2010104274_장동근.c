#pragma warning(disable:4996)		//fopen_s, scanf_s ���� ����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct wordlist{				//����ü ����Ʈ ����
	char word[30];
	struct wordlist* Next;
}wordlist;							

void Displaylist(wordlist* p);			//��ü ����Ʈ ����Լ�
void Searchlist(wordlist* p);			//����Ʈ �� �ܾ� �˻� �Լ�

int main()
{
	wordlist* head = (wordlist*)malloc(sizeof(wordlist));	//head ����Ʈ ����
	wordlist* tail = head;									//tail ����Ʈ ����
	head->Next = NULL;										//tail�� ����Ű�� �� NULL

	FILE *fp = fopen("hw1.txt", "r");						//���� �б���� ����
	
	if (fp == NULL)											//���� ���� ����
	{
		puts("���Ͽ��� ����!");
		return -1;
	}

	while (!feof(fp)){						//���� �� �ܾ�� ����Ʈ�� �߰��ϸ� ���� ����
		
		fscanf(fp, "%s ",tail->word);
		tail->Next = (wordlist*)malloc(sizeof(wordlist));
		tail = tail->Next;
		tail->Next = NULL;

	}
	fclose(fp);				//���� �ݱ�
	Displaylist(head);		//����Ʈ ���� ��ü�� ����ϱ�
	Searchlist(head);		//����Ʈ �� �ܾ� �˻� �� ��� ����ϱ�

	return 0;
}

void Displaylist(wordlist* p)
{

	while (p->Next != NULL)	//����Ʈ ������ ���
	{
		printf("%s ", p->word);	//����� �����Ͽ� ����� ����Ʈ ������� ���
		p = p->Next;			//���� ����Ʈ�� ������ �̵�
	}
		
}
void Searchlist(wordlist* p)
{
	char findword[30];
	int sw = 0;
	int index = 1;
	int count = 0;

	printf("\nã�� �ܾ� �Է� : ");
	fflush(stdin);		//ǥ���Է� ���� �����
	scanf("%s", findword);		//ã�� �ܾ� ���ڿ��� �Է¹޴´�

	while (p->Next != NULL)		//����Ʈ ������ ���
	{
		if (stricmp(findword, p->word) == 0)			//��ҹ��� ���� ���� ��
		{
			count++;				//��� �ܾ ã�Ҵ��� �˰��ϴ� ����
			printf("����Ʈ�� %d��° index\n", index);	//���° ����Ʈ�� �־����� ���
			sw = 1;		//1�� �̻� ã���� 1��
		}
		index++;		//����Ʈ ��ȣ ����
		p = p->Next;		//���� ����Ʈ�� ������ �̵�
		
	}
	if (!sw)		//���� �ܾ� �� ã���� ��
	{
		printf("ã�� �ܾ �����ϴ�.\n");
	}
	printf("ã�� �ܾ��� ���� �� %d���Դϴ�.\n", count);


}