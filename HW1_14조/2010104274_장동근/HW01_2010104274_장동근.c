#pragma warning(disable:4996)		//fopen_s, scanf_s 오류 무시
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct wordlist{				//구조체 리스트 선언
	char word[30];
	struct wordlist* Next;
}wordlist;							

void Displaylist(wordlist* p);			//전체 리스트 출력함수
void Searchlist(wordlist* p);			//리스트 내 단어 검색 함수

int main()
{
	wordlist* head = (wordlist*)malloc(sizeof(wordlist));	//head 리스트 선언
	wordlist* tail = head;									//tail 리스트 선언
	head->Next = NULL;										//tail이 가리키는 곳 NULL

	FILE *fp = fopen("hw1.txt", "r");						//파일 읽기모드로 열기
	
	if (fp == NULL)											//파일 오픈 실패
	{
		puts("파일오픈 실패!");
		return -1;
	}

	while (!feof(fp)){						//파일 내 단어들 리스트를 추가하며 각각 저장
		
		fscanf(fp, "%s ",tail->word);
		tail->Next = (wordlist*)malloc(sizeof(wordlist));
		tail = tail->Next;
		tail->Next = NULL;

	}
	fclose(fp);				//파일 닫기
	Displaylist(head);		//리스트 내용 전체를 출력하기
	Searchlist(head);		//리스트 내 단어 검색 및 결과 출력하기

	return 0;
}

void Displaylist(wordlist* p)
{

	while (p->Next != NULL)	//리스트 끝까지 계속
	{
		printf("%s ", p->word);	//띄어쓰기로 구분하여 저장된 리스트 순서대로 출력
		p = p->Next;			//다음 리스트로 포인터 이동
	}
		
}
void Searchlist(wordlist* p)
{
	char findword[30];
	int sw = 0;
	int index = 1;
	int count = 0;

	printf("\n찾을 단어 입력 : ");
	fflush(stdin);		//표준입력 버퍼 비워줌
	scanf("%s", findword);		//찾을 단어 문자열로 입력받는다

	while (p->Next != NULL)		//리스트 끝까지 계속
	{
		if (stricmp(findword, p->word) == 0)			//대소문자 구분 없이 비교
		{
			count++;				//몇개의 단어를 찾았는지 알게하는 변수
			printf("리스트의 %d번째 index\n", index);	//몇번째 리스트에 있었는지 출력
			sw = 1;		//1개 이상 찾을시 1로
		}
		index++;		//리스트 번호 증가
		p = p->Next;		//다음 리스트로 포인터 이동
		
	}
	if (!sw)		//같은 단어 못 찾았을 시
	{
		printf("찾는 단어가 없습니다.\n");
	}
	printf("찾은 단어의 수는 총 %d개입니다.\n", count);


}