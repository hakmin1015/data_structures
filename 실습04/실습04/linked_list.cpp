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

	// �� ����
};

class node {
public:
	sinfo item;
	node* link;

	// �� ����
	void insert(sinfo item);
};

void node::insert(sinfo item) {
	// 1. ������ ��ġ�� ����
	node* curr = this;
	while (curr->link != NULL) {
		if (strcmp(curr->link->item.name, item.name) > 0)
			break;
		curr = curr->link;
	}

	// 2. ���ο� ��带 ����
	node* nnode = (node*)malloc(sizeof(node));
	nnode->item = item;

	// 3. ��ũ�� ����
	nnode->link = curr->link;
	curr->link = nnode;
}

class hnode {
public:
	node* link;
	// �� ����
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
	// �� �� ����Ʈ�� ó������ �߰��ϴ� ���
	if (link == NULL) {
		// 1. �� ��� ����
		node* nnode = (node*)malloc(sizeof(node));

		// 2. ���� ����
		strcpy(nnode->item.name, tok2);
		nnode->item.gender = tok3[0];
		strcpy(nnode->item.city, tok4);
		strcpy(nnode->item.dept, tok5);
		nnode->item.gpa = (float)atof(tok6);
		nnode->item.height = (int)atoi(tok7);
		nnode->item.weight = (int)atoi(tok8);

		// *�� ����� link�� NULL�� �ʱ�ȭ
		nnode->link = NULL;

		// 3. first�� link�� nnode�� ����
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
	// 0. ��ɾ� line �� ���� �Լ� �ʿ� ���� ����
	FILE* fp = fopen("input.txt", "r+t");
	char input[512];
	char tok1[32], tok2[32], tok3[32], tok4[32], tok5[32], tok6[32], tok7[32], tok8[32]; // ��ū ����

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