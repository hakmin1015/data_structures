#include <iostream>
using namespace std;
#include <fstream>
// #define _CRT_SECURE_NO_WARNINGS

struct sinfo {
	char name[8];
	char gender;
	char city[8];
	char dept[16];
	float gpa;
	int height;
	int weight;
};

ifstream fcin;
int n;
int cnt = 0;
sinfo* slist;

int count_student()
{
	char str[256];
	int i = 0;
	while (fcin.getline(str, sizeof(str)))
		i++;
	return i;
}

void input_student()
{
	int i;
	for (i = 0; i < n; i++) {
		fcin >> slist[i].name >> slist[i].gender;
		fcin >> slist[i].city >> slist[i].dept >> slist[i].gpa;
		fcin >> slist[i].height >> slist[i].weight;
	}
}

void output_student()
{
	int i;
	for (i = 0; i < n; i++) {
		cout << slist[i].name << " " << slist[i].gender << " ";
			cout << slist[i].city << " " << slist[i].dept << " ";
			cout << slist[i].gpa << " " << slist[i].height << " ";
			cout << slist[i].weight << endl;
	}
}
void main()
{
	fcin.open("list.txt");
	// FILE *fp = fopen("list.txt", "r+t");

	n = count_student();	// 2. count the number of students in the file
	cout << n << endl;
	fcin.close();

	slist = new sinfo[n];	// 3. allocate the memory
	// slist = (sinfo *)calloc(n, sizeof(sinfo));

	fcin.open("list.txt");	// 4. read the list
	input_student();

	fcin.close();
	// fclose(fp);

	output_student();	//5. write the list
}