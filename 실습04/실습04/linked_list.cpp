#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class sinfo {
public:
	char name[10];
	char gender;
	char city[10];
	char dept[20];
	float gpa;
	int height;
	int weight;

	// … 생략
};

class node {
public:
	sinfo item;
	node* link;

	// … 생략
	void insert(sinfo item);
};

void node::insert(sinfo item) {
	// 1. 적절한 위치를 결정
	node* curr = this;
	while (curr->link != NULL) {
		if (strcmp(curr->link->item.name, item.name) > 0)
			break;
		curr = curr->link;
	}

	// 2. 새로운 노드를 생성
	node* nnode = (node*)malloc(sizeof(node));
	nnode->item = item;

	// 3. 링크를 갱신
	nnode->link = curr->link;
	curr->link = nnode;
}

class hnode {
public:
	node* link;
	// … 생략
	void process_create();
	void process_insert(char* tok2, char* tok3, char* tok4, char* tok5, char* tok6, char* tok7, char* tok8);
	void process_load(char* fn);
	void process_print();
	void process_delete(char* tok2);
	void process_search(char* tok2);
};

void hnode::process_create() {
	link = NULL;
}

void hnode::process_insert(char* tok2, char* tok3, char* tok4, char* tok5, char* tok6, char* tok7, char* tok8) {
	// 텅 빈 리스트에 처음으로 추가하는 경우
	if (link == NULL) {
		// 1. 새 노드 생성
		node* nnode = (node*)malloc(sizeof(node));

		// 2. 정보 삽입
		strcpy(nnode->item.name, tok2);
		nnode->item.gender = tok3[0];
		strcpy(nnode->item.city, tok4);
		strcpy(nnode->item.dept, tok5);
		nnode->item.gpa = (float)atof(tok6);
		nnode->item.height = (int)atoi(tok7);
		nnode->item.weight = (int)atoi(tok8);

		// *새 노드의 link를 NULL로 초기화
		nnode->link = NULL;

		// 3. first의 link에 nnode를 연결
		link = nnode;

	}

	else {
		//link->insert(item);
	}

}

void hnode::process_load(char* fn) {

}

void hnode::process_print() {

}

void hnode::process_delete(char* tok2) {

}

void hnode::process_search(char* tok2) {

}

void main()
{
	// 0. 명령어 line 수 세기 함수 필요 없는 버전
	FILE* fp = fopen("input.txt", "r+t");
	char input[512];
	char tok1[32], tok2[32], tok3[32], tok4[32], tok5[32], tok6[32], tok7[32], tok8[32]; // 토큰 선언

	hnode first;
	//node* curr;

	while (fgets(input, 512, fp) != NULL) {
		sscanf(input, "%s%s%s%s%s%s%s%s", tok1, tok2, tok3, tok4, tok5, tok6, tok7, tok8);
		if (strcmp(tok1, "CREATE") == 0) {
			first.process_create();
			printf("%s done ==================================================\n\n", tok1);
		}
		else if (strcmp(tok1, "LOAD") == 0) {
			first.process_load(tok2);
			printf("%s done ==================================================\n\n", tok1);
		}
		else if (strcmp(tok1, "PRINT") == 0) {
			first.process_print();
			printf("%s done ==================================================\n\n", tok1);
		}
		else if (strcmp(tok1, "INSERT") == 0) {
			first.process_insert(tok2, tok3, tok4, tok5, tok6, tok7, tok8);
			printf("%s done ==================================================\n\n", tok1);
		}
		else if (strcmp(tok1, "DELETE") == 0) {
			first.process_delete(tok2);
			printf("%s done ==================================================\n\n", tok1);
		}
		else if (strcmp(tok1, "SEARCH") == 0) {
			first.process_search(tok2);
			printf("%s done ==================================================\n\n", tok1);
		}
		else {
			printf("%s is not a keyword.\n", tok1);
		}
	}
	fclose(fp);
}