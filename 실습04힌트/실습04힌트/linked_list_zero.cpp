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
	void print() {
		printf("%s %c ", name, gender);
		printf("%s %s ", city, dept);
		printf("%.1f %d %d \n", gpa, height, weight);
	}

	// … 생략
	void set(char* tok2, char* tok3, char* tok4, char* tok5, char* tok6, char* tok7, char* tok8);
};

void sinfo::set(char* tok2, char* tok3, char* tok4, char* tok5, char* tok6, char* tok7, char* tok8){
	strcpy(name, tok2);
	gender = tok3[0];
	strcpy(city, tok4);
	strcpy(dept, tok5);
	gpa = (float)atof(tok6);
	height = (int)atoi(tok7);
	weight = (int)atoi(tok8);
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

	nnode->item.print();
}

class hnode {
public:
	node* link;
	// … 생략
	void process_create();
	void process_insert(sinfo item);
};

void hnode::process_create() {
	link = NULL;
}

void hnode::process_insert(sinfo item) {
	// 텅 빈 리스트에 처음으로 추가하는 경우
	if (link == NULL){
		// 1. 새 노드 생성
		node* nnode = (node*)malloc(sizeof(node));
		
		// 2. 정보 삽입
		nnode->item = item;
		// *새 노드의 link를 NULL로 초기화
		nnode->link = NULL;

		// 3. first의 link에 nnode를 연결
		link = nnode;

		nnode->item.print();
	}

	else {
		link->insert(item);
	}

}

void main()
{
	// 0. 명령어 line 수 세기 함수 필요 없는 버전
	FILE* fp = fopen("input0.txt", "r+t");
	char input[512];
	char tok1[32], tok2[32], tok3[32], tok4[32], tok5[32], tok6[32], tok7[32], tok8[32]; // 토큰 선언
	
	hnode first;

	while (fgets(input, 512, fp) != NULL) {
		sscanf(input, "%s%s%s%s%s%s%s%s", tok1, tok2, tok3, tok4, tok5, tok6, tok7, tok8);
		if (strcmp(tok1, "CREATE") == 0) {
			//process_create();
			first.process_create();
			printf("%s done ==================================================\n\n", tok1);
		}
		else if (strcmp(tok1, "INSERT") == 0) {
			//process_insert(tok2, tok3, tok4, tok5, tok6, tok7, tok8);
			sinfo temp;
			temp.set(tok2, tok3, tok4, tok5, tok6, tok7, tok8);
			first.process_insert(temp);
			printf("%s done ==================================================\n\n", tok1);
		}
		// … 생략
		else {
			printf("%s is not a keyword.\n", tok1);
		}
	}
	fclose(fp);
}