#include <iostream>
using namespace std;
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS

// 1. �л� ������ ������ ����ü(Ŭ����) �����ϱ�
struct StudentInfo {
	char name[10];
	char gender;
	char city[10];
	char dept[20];
	float gpa;
	int height;
	int weight;
};
int n; // �迭�� ũ��
int cnt = 0; // �迭�� ������ ����
StudentInfo* std_list;

int count_lines(const char fn[]) {
	char str[256];
	int cnt_lines = 0; // �� ��
	ifstream fcin;
	fcin.open(fn);
	// null �� �ƴ� ���� ����
	while (fcin.getline(str, sizeof(str)))
		cnt_lines++;
	fcin.close();
	return cnt_lines;
}

void process_create() {
	n = 100;
	std_list = new StudentInfo[n];
}

void process_insert(StudentInfo tinfo)
{
	if (cnt == 0) {
		std_list[cnt++] = tinfo;
		return;
	}
	int i, j;
	for (i = 0; i < cnt; i++) {
		if (strcmp(tinfo.name, std_list[i].name) <= 0)
			break;
	}
	for (j = cnt - 1; j >= i; j--)
		std_list[j + 1] = std_list[j];
	std_list[i] = tinfo;
	cnt++;
}

void process_load(const char fn[]) {
	int n = count_lines(fn); // �� �� ����
	ifstream fcin;
	fcin.open(fn);
	StudentInfo tinfo;
	for (int i = 0; i < n; i++) {
		fcin >> tinfo.name >> tinfo.gender;
		fcin >> tinfo.city >> tinfo.dept;
		fcin >> tinfo.gpa >> tinfo.height >> tinfo.weight;
		process_insert(tinfo);
	}
	fcin.close();
}

void process_insert(char* tok2, char* tok3, char* tok4, char* tok5, char* tok6, char* tok7, char* tok8) {
	StudentInfo tinfo;
	strcpy_s(tinfo.name, tok2);
	tinfo.gender = tok3[0];
	strcpy_s(tinfo.city, tok4);
	strcpy_s(tinfo.dept, tok5);
	tinfo.gpa = atof(tok6);
	tinfo.height = atoi(tok7);
	tinfo.weight = atoi(tok8);
	process_insert(tinfo);
}

void process_delete(char* tok2)
{
	int i;
	for (i = 0; i < cnt; i++) {
		if (strcmp(std_list[i].name, tok2) == 0)
			break;
	}
	if (i == cnt) {
		cout << "No " << tok2 << "in the list.\n";
		return;
	}
	int j;
	for (j = i; j < cnt - 1; j++)
		std_list[j] = std_list[j + 1];
	cnt--;
	cout << tok2 << "is deleted.\n";
}

void process_search(char* tok2) {
	int i;
	for (i = 0; i < cnt; i++) {
		if (strcmp(std_list[i].name, tok2) == 0) {
			cout << tok2 << " found: ";
			cout << std_list[i].name << " " << std_list[i].gender << " ";
			cout << std_list[i].city << " " << std_list[i].dept << " ";
			cout << std_list[i].gpa << " " << std_list[i].height << " " << std_list[i].weight << endl; return;
		}
	}
	printf("%s not found.\n", tok2);
}

void process_print() {
	for (int i = 0; i < cnt; i++) {
		cout << "[" << i << "] ";
		cout << std_list[i].name << " " << std_list[i].gender << " ";
		cout << std_list[i].city << " " << std_list[i].dept << " ";
		cout << std_list[i].gpa << " " << std_list[i].height << " " << std_list[i].weight << endl;
	}
}

void main()
{
	// 0. ��ɾ� line �� ����
	int nlines = count_lines("input.txt");
	cout << nlines << endl;
	ifstream fcin;
	fcin.open("input.txt");
	// ��ū ����
	char tok1[32], tok2[32], tok3[32], tok4[32], tok5[32], tok6[32], tok7[32], tok8[32];

	for (int i = 0; i < nlines; i++) {
		fcin >> tok1;
		if (strcmp(tok1, "CREATE") == 0) {
			process_create();
		}
		else if (strcmp(tok1, "LOAD") == 0) {
			fcin >> tok2;
			process_load(tok2);
		}
		else if (strcmp(tok1, "PRINT") == 0) {
			process_print();
		}
		else if (strcmp(tok1, "INSERT") == 0) {
			fcin >> tok2 >> tok3 >> tok4 >> tok5 >> tok6 >> tok7 >> tok8;
			process_insert(tok2, tok3, tok4, tok5, tok6, tok7, tok8);
		}
		else if (strcmp(tok1, "DELETE") == 0) {
			fcin >> tok2;
			process_delete(tok2);
		}
		else if (strcmp(tok1, "SEARCH") == 0) {
			fcin >> tok2;
			process_search(tok2);
		}
		else {
			cout << tok1 << "is not a keyword.\n";
		}
		cout << tok1 << " done ===============\n\n";
	}
	fcin.close();
}