#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main() {
	int flag_de = 0;
	setlocale(LC_ALL, "Rus");
	printf("\n ���������� �����! \n");
	int flag_menu = 0;
	int index = 0;
	char str_buffer[1000];
	char buffer[100];
	int index_3 = 0;
	int index_2=0;
	struct telefon_t {
		char name[100];
		char se_name[100];
		char number[20];
		char adr_name[100];
		char home_num[10];
		char kv_num[10];
	};

	struct telefon_t kontact[100];


	FILE *fp;
	fopen_s(&fp, "file.txt", "r+");
	if (fp != NULL) {
		printf("\n ���� � ����� ������ ��� ���������, ������ ������ ��������!! \n");
		fseek(fp, 0, SEEK_SET);
		while (!feof(fp)) {
			fgets(str_buffer, 1000, fp);
			if (str_buffer[0]==-52) {
				index = 0;
				break;
			}
			if (str_buffer[0] == '\0') {
				break;
			}
			if (strlen(str_buffer) == 0) {
				break;
			}
			index_2 = 0;
			for (int i = 0; i < strlen(str_buffer); i++) {
				if (str_buffer[i] != ' ') {
					kontact[index].name[index_2] = str_buffer[i];
					index_2++;
				}
				else {
					kontact[index].name[index_2 ] = '\0';
					index_3 = i;
					break;
				}
				
			}
			index_2 = 0;
			for (int i = index_3 + 1; i < strlen(str_buffer); i++) {
				if (str_buffer[i] != ' ') {
					kontact[index].se_name[index_2] = str_buffer[i];
					index_2++;
				}
				else {
					kontact[index].se_name[index_2 ] = '\0';
					index_3 = i;
					break;
				}
			}
			index_2 = 0;
			for (int i = index_3 + 1; i < strlen(str_buffer); i++) {
				if (str_buffer[i] != ' ') {
					kontact[index].number[index_2] = str_buffer[i];
					index_2++;
				}
				else {
					kontact[index].number[index_2] = '\0';
					index_3 = i;
					break;
				}
			}
			index_2 = 0;
			for (int i = index_3 + 1; i < strlen(str_buffer); i++) {
				if (str_buffer[i] != ' ') {
					kontact[index].adr_name[index_2] = str_buffer[i];
					index_2++;
				}
				else {
					kontact[index].adr_name[index_2] = '\0';
					index_3 = i;
					break;
				}
			}
			index_2 = 0;
			for (int i = index_3 + 1; i < strlen(str_buffer); i++) {
				if (str_buffer[i] != ' ') {
					kontact[index].home_num[index_2] = str_buffer[i];
					index_2++;
				}
				else {
					kontact[index].home_num[index_2] = '\0';
					index_3 = i;
					break;
				}
			}
			index_2 = 0;
			for (int i = index_3 + 1; i < strlen(str_buffer); i++) {
				if (str_buffer[i] != '\n') {
					kontact[index].kv_num[index_2] = str_buffer[i];
					index_2++;
				}
				else {
					kontact[index].kv_num[index_2] = '\0';
					index_3 = i;
					break;
				}
			}
			kontact[index].kv_num[index_2] = '\0';
			index_2 = 0;
			index++;
			for (int i = 0; i < strlen(str_buffer); i++) {
				str_buffer[i] = '\0';
			}
		}
	}
	else {
		printf("\n ������ �������� ���� ������ ���������� �����\n");
		do {
			printf("\n �������� �������� : \n 1-������� �����!! \n 2- ����� �� ���������� �����!\n");
			scanf_s("%d", &flag_de);
			if (flag_de == 1) {
				fopen_s(&fp, "file.txt", "w+");
				if (fp != NULL) {
					printf("����� ���� ������ �������!\n");
				}
				else {
					printf("���������� ������ , ���������� ������� ���� ��!!\n");
				}
			}
			if (flag_de == 2) {
				break;
			}
		} while (flag_de!=0);
	}



	do {
		printf("\n ���� ����� :\n 1-������� ������ ��������� \n 2-����� ��������� \n 3-���������� ��������� \n 4-����� �� ������ \n 0-����� \n");
		scanf_s("%d", &flag_menu);
		if (flag_menu == 1) {
			printf("\n ������ ��������� \n");
			for (int i = 0; i < index; i++) {
				printf("%s %s %s %s %s %s \n", kontact[i].name,kontact[i].se_name,kontact[i].number,kontact[i].adr_name,kontact[i].home_num,kontact[i].kv_num);
			}
		}
		if (flag_menu == 3) {
			
			printf("\n ������� ��� : \n");
			while (getchar() != '\n');
			gets_s(kontact[index].name, 100);
			printf("\n ������� ������� \n");
			gets_s(kontact[index].se_name, 100);
			printf("\n ������� ����� ��������  \n");
			gets_s(kontact[index].number, 20);
			printf("\n ������� ����� (�����)  \n");
			gets_s(kontact[index].adr_name, 100);
			printf("\n ������� ����� ����  \n");
			gets_s(kontact[index].home_num, 10);
			printf("\n ������� ����� ��������  \n");
			gets_s(kontact[index].kv_num, 10);
			index++;
		}
		

	} while (flag_menu != 0);
	index_2 = 0;
	fseek(fp, 0, SEEK_SET);
	for (int i = 0; i < index; i++) {
		
		for (int j = 0; j < strlen(kontact[i].name); j++) {
			if (kontact[i].name[j] != '\0') {
				str_buffer[index_2] = kontact[i].name[j];
				index_2++;
			}
		
		}
		str_buffer[index_2] = ' ';
		index_2++;
		for (int j = 0; j < strlen(kontact[i].se_name); j++) {
			if (kontact[i].se_name[j] != '\0') {
				str_buffer[index_2] = kontact[i].se_name[j];
				index_2++;
			}

		}
		str_buffer[index_2] = ' ';
		index_2++;
		for (int j = 0; j < strlen(kontact[i].number); j++) {
			if (kontact[i].number[j] != '\0') {
				str_buffer[index_2] = kontact[i].number[j];
				index_2++;
			}
	
		}
		str_buffer[index_2] = ' ';
		index_2++;
		for (int j = 0; j < strlen(kontact[i].adr_name); j++) {
			if (kontact[i].adr_name[j] != '\0') {
				str_buffer[index_2] = kontact[i].adr_name[j];
				index_2++;
			}
	
		}
		str_buffer[index_2] = ' ';
		index_2++;
		for (int j = 0; j < strlen(kontact[i].home_num); j++) {
			if (kontact[i].home_num[j] != '\0') {
				str_buffer[index_2] = kontact[i].home_num[j];
				index_2++;
			}
	
		}
		str_buffer[index_2] = ' ';
		index_2++;
		for (int j = 0; j < strlen(kontact[i].kv_num); j++) {
			if (kontact[i].kv_num[j] != '\0') {
				str_buffer[index_2] = kontact[i].kv_num[j];
				index_2++;
			}

		}
		
		str_buffer[index_2] = '\0';
		if (index > 1) {
			str_buffer[index_2] = '\n';
			str_buffer[index_2+1] = '\0';
		}
		index_2 = 0;
		fputs(str_buffer, fp);
		
	}
	fseek(fp, 0, SEEK_END);

	fclose(fp);
}