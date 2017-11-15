#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
struct telefon_t {    //��������� ���� ���������� �����
	char name[20];
	char se_name[20];
	char number[20];
	char adr_name[20];
	char home_num[10];
	char kv_num[10];
};

struct telefon_t* fun_resize(int* kol_kon,struct telefon_t* kontact) {
	struct telefon_t *kontact_2 = (struct telefon_t*)realloc(kontact,*kol_kon * sizeof(struct telefon_t));
	return kontact_2;
}

void fun_new(struct telefon_t* kontact, int* index) {

	printf("\n ������� ��� : \n");
	while (getchar() != '\n');
	gets_s(kontact[*index].name, 100);
	printf("\n ������� ������� \n");
	gets_s(kontact[*index].se_name, 100);
	printf("\n ������� ����� ��������  \n");
	gets_s(kontact[*index].number, 20);
	printf("\n ������� ����� (�����)  \n");
	gets_s(kontact[*index].adr_name, 100);
	printf("\n ������� ����� ����  \n");
	gets_s(kontact[*index].home_num, 10);
	printf("\n ������� ����� ��������  \n");
	gets_s(kontact[*index].kv_num, 10);
	
}

void fun_print(struct telefon_t* kontact, int* index) {
	printf("\n ������ ��������� \n");
	for (int i = 0; i < *index; i++) {
		printf("%d - %s %s %s %s %s %s \n", i, kontact[i].name, kontact[i].se_name, kontact[i].number, kontact[i].adr_name, kontact[i].home_num, kontact[i].kv_num);
	}
}

void fun_serth( struct telefon_t* kontact,int* type,int* index) {
	char buff_name[20];
	if (*type == 1) {
		printf("\n ������� ������� �������: \n");
		while (getchar() != '\n');
		gets_s(buff_name, 20);
		for (int i = 0; i < *index; i++) {
			if (strcmp(buff_name, kontact[i].name) == 0) {
				printf("%d - %s %s %s %s %s %s \n", i, kontact[i].name, kontact[i].se_name, kontact[i].number, kontact[i].adr_name, kontact[i].home_num, kontact[i].kv_num);
			}
		}
	}
	if (*type == 2) {
		printf("\n ������� ������� �����: \n");
		while (getchar() != '\n');
		gets_s(buff_name, 20);
		for (int i = 0; i < *index; i++) {
			if (strcmp(buff_name, kontact[i].number) == 0) {
				printf("%d - %s %s %s %s %s %s \n", i, kontact[i].name, kontact[i].se_name, kontact[i].number, kontact[i].adr_name, kontact[i].home_num, kontact[i].kv_num);
			}
		}

	}
	if (*type == 3) {
		printf("\n ������� ������� �����: \n");
		while (getchar() != '\n');
		gets_s(buff_name, 20);
		for (int i = 0; i < *index; i++) {
			if (strcmp(buff_name, kontact[i].adr_name) == 0) {
				printf("%d - %s %s %s %s %s %s \n", i, kontact[i].name, kontact[i].se_name, kontact[i].number, kontact[i].adr_name, kontact[i].home_num, kontact[i].kv_num);
			}
		}


	}
	if (*type == 4) {
		int flag_index = 0;
		int buff_kol_sosedi = 0;
		char buff_adr_sosedi_name[20];
		printf("\n ������� ���������� �������: \n");
		//while (getchar() != '\n');
		scanf_s("%d", &buff_kol_sosedi);
		printf("\n ������� ������� �����: \n");
		while (getchar() != '\n');
		gets_s(buff_adr_sosedi_name, 20);
		for (int i = 0; i < *index; i++) {
			if (flag_index >= buff_kol_sosedi) {
				break;
				}
			if (strcmp(buff_adr_sosedi_name, kontact[i].adr_name) == 0) {
				flag_index++;
				printf("%d - %s %s %s %s %s %s \n", i, kontact[i].name, kontact[i].se_name, kontact[i].number, kontact[i].adr_name, kontact[i].home_num, kontact[i].kv_num);
				}
			}

	}
	

}


void fun_redact(struct telefon_t* kontact, int* tek_index,int* ide_i,int* index) {
	if (*ide_i == 1) {
		printf("\n ������� ��� : \n");
		while (getchar() != '\n');
		gets_s(kontact[*tek_index].name, 100);
	}
	if (*ide_i == 2) {
		printf("\n ������� ������� \n");
		while (getchar() != '\n');
		gets_s(kontact[*tek_index].se_name, 100);
	}
	if (*ide_i == 3) {
		printf("\n ������� ����� ��������  \n");
		while (getchar() != '\n');
		gets_s(kontact[*tek_index].number, 20);
	}
	if (*ide_i == 4) {
		printf("\n ������� ����� (�����)  \n");
		while (getchar() != '\n');
		gets_s(kontact[*tek_index].adr_name, 100);
	}
	if (*ide_i == 5) {
		printf("\n ������� ����� ����  \n");
		while (getchar() != '\n');
		gets_s(kontact[*tek_index].home_num, 10);
	}
	if (*ide_i == 6) {
		printf("\n ������� ����� ��������  \n");
		while (getchar() != '\n');
		gets_s(kontact[*tek_index].kv_num, 10);
	}
	if (*ide_i == 7) { //��������� ������� � ������ �������
		for (int i = 0; i < strlen(kontact[*tek_index].name); i++) {
			kontact[*index].name[i] = kontact[*tek_index].name[i];
		}
		kontact[*index].name[strlen(kontact[*tek_index].name)] = '\0';
		for (int i = 0; i < strlen(kontact[*tek_index].se_name); i++) {
			kontact[*index].se_name[i] = kontact[*tek_index].se_name[i];
		}
		kontact[*index].se_name[strlen(kontact[*tek_index].se_name)] = '\0';
		for (int i = 0; i < strlen(kontact[*tek_index].adr_name); i++) {
			kontact[*index].adr_name[i] = kontact[*tek_index].adr_name[i];
		}
		kontact[*index].adr_name[strlen(kontact[*tek_index].adr_name)] = '\0';
		for (int i = 0; i < strlen(kontact[*tek_index].home_num); i++) {
			kontact[*index].home_num[i] = kontact[*tek_index].home_num[i];
		}
		kontact[*index].home_num[strlen(kontact[*tek_index].home_num)] = '\0';
		for (int i = 0; i < strlen(kontact[*tek_index].kv_num); i++) {
			kontact[*index].kv_num[i] = kontact[*tek_index].kv_num[i];
		}
		kontact[*index].kv_num[strlen(kontact[*tek_index].kv_num)] = '\0';
		printf("\n ������� ����� \n");
		while (getchar() != '\n');
		gets_s(kontact[*index].number, 20);
		
	}

}

int main() {
	int flag_de = 0;
	setlocale(LC_ALL, "Rus");
	printf("\n ���������� �����! \n");
	int flag_menu = 0;
	int index = 0;
	char str_buffer[1000];
	char buffer[100];
	int index_3 = 0;
	int flag_dell = 0;
	int index_2=0;
	
	
	
	int kol_kon = 100;
	struct telefon_t *kontact = (struct telefon_t*)malloc(kol_kon*sizeof(struct telefon_t)); //������������ ��������� ������
	

	
	FILE *fp;
	fopen_s(&fp, "file.txt", "r+");
	if (fp != NULL) {
		printf("\n ���� � ����� ������ ��� ���������, ������ ������ ��������!! \n");   //����������� �� �� �����
		fseek(fp, 0, SEEK_SET);
		while (!feof(fp)) {   //������� ���� ���� � ������
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
					printf("����� ���� ������ �������!\n");   //�������� ����� �� ��� ���� ������
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
		printf("\n ���� ����� :\n 1-������� ������ ��������� \n 2-����� ��������� \n 3-���������� ��������� \n 4-����� �� ������ \n 5- �������(�������������) ������� \n 0-����� \n");
		scanf_s("%d", &flag_menu);
		if (flag_menu == 1) {
			fun_print(kontact, &index);
		}
		if (flag_menu == 2) { //����� ��������� � ���������� ���������
			//printf("\n ������� �������� ������ \n 1-�� ����� \n 2- �� ������ \n 3-�� ������ \n 4-����� ������� �������� \n");
			int flga_id = 0;
			
			do {
				printf("\n ������� �������� ������ \n 1-�� ����� \n 2- �� ������ \n 3-�� ������ \n 4-����� ������� �������� \n 0-����� \n");
				while (getchar() != '\n');
				scanf_s("%d", &flga_id);
				if (flga_id == 0) {
					break;
				}
				if (flga_id == 1) {
					fun_serth(kontact, &flga_id, &index);
					
				}
				if (flga_id == 2) {
					fun_serth(kontact, &flga_id, &index);

				}
				if (flga_id == 3) {
					fun_serth(kontact, &flga_id, &index);
					
				}
				if (flga_id == 4) {  //����� �� ���������� ������� �� ������
					fun_serth(kontact, &flga_id, &index);

				}
			} while (flga_id != 0);
		}
		if (flag_menu == 3) { //���������� ������ ��������
			fun_new(kontact, &index);
			index++;
		}

		if (flag_menu == 4) {
			char coll_num[20];
			char cool_name[20];
			int index_coll_name=101;
			printf("\n �������� ����� ��� ������!! \n");
			while (getchar() != '\n');
			gets_s(coll_num, 20);
			for (int i = 0; i < index; i++) {
				if (strcmp(coll_num,kontact[i].number) == 0) {
					index_coll_name = i;
					printf("\n Calling %s %s \n", kontact[index_coll_name].name, kontact[index_coll_name].se_name);
					system ("Pause");
					break;
				}
			}
			if (index_coll_name == 101) {
				printf("\n ���� ������  �������������� �������� \n ");
				system("Pause");
				int dob_rez = 0;
				
				printf("\n������ �������� ���� �������? 1-�� 2-���\n");
				scanf_s("%d", &dob_rez);
				if (dob_rez == 1) {
					for (int i = 0; i < strlen(coll_num); i++) {
						kontact[index].number[i] = coll_num[i];
					}
					kontact[index].number[strlen(coll_num)] = '\0';
					printf("\n ������� ��� : \n");
					while (getchar() != '\n');
					gets_s(kontact[index].name, 100);
					printf("\n ������� ������� \n");
					gets_s(kontact[index].se_name, 100);
					
					printf("\n ������� ����� (�����)  \n");
					gets_s(kontact[index].adr_name, 100);
					printf("\n ������� ����� ����  \n");
					gets_s(kontact[index].home_num, 10);
					printf("\n ������� ����� ��������  \n");
					gets_s(kontact[index].kv_num, 10);
					index++;
				}
			}
			
		}
		if (flag_menu == 5) {
			int tek_index = 0;
			int flag_ide = 0;
			printf("\n �������� ������� : \n");
			scanf_s("%d", &tek_index);
			if (tek_index > index) {
				printf("\n�� ������ ����\n");
				printf("\n �������� ������� : \n");
				scanf_s("%d", &tek_index);
			}
			do {
				printf("\n �������� ��������: \n 1-��������� \n 2-������������� \n 3-������� \n 0-����� \n");
				while (getchar() != '\n');
				scanf_s("%d", &flag_ide);
				if (flag_ide == 1) {
					
					printf("\n Calling %s %s \n", kontact[tek_index].name, kontact[tek_index].se_name);
					system("Pause");
				}
				if (flag_ide == 2) {
					int ide_i = 0;
					do {
						printf("\n �������� ��� ������������� :\n 1-��� \n 2-�������  \n 3-�����  \n 4-����� \n 5-��� \n 6 -�������� \n 7-�������� ��� 1 ����� \n 0-����� \n ");
						scanf_s("%d", &ide_i);
						fun_redact(kontact, &tek_index, &ide_i, &index);
						if(ide_i==7){
							index++;
						}
						if (ide_i == 0) {
							break;
						}
					} while (ide_i != 0);
				}
				if (flag_ide == 3) {  //������� �������
					kontact[tek_index].name[0] = '\0';
					kontact[tek_index].se_name[0] = '\0';
					kontact[tek_index].home_num[0] = '\0';
					kontact[tek_index].adr_name[0] = '\0';
					kontact[tek_index].kv_num[0] = '\0';
					kontact[tek_index].number[0] = '\0';
					flag_dell++;
					printf("\n ������� ������� ������ \n");
				}

			} while (flag_ide != 0);
		}
		
		
	} while (flag_menu != 0);
	
	index_2 = 0;
	fseek(fp, 0, SEEK_SET);
	str_buffer[0] = '\0';
	for (int i = 0; i < index; i++) {   //������ ������ � ����!!!
		if (kontact[i].name[0] == '\0') {
			continue;
		}
		strcat_s(str_buffer,1000,kontact[i].name);
		strcat_s(str_buffer, 1000," ");
		strcat_s(str_buffer, 1000,kontact[i].se_name);
		strcat_s(str_buffer, 1000, " ");
		strcat_s(str_buffer, 1000,kontact[i].number);
		strcat_s(str_buffer, 1000, " ");
		strcat_s(str_buffer, 1000, kontact[i].adr_name);
		strcat_s(str_buffer, 1000, " ");
		strcat_s(str_buffer, 1000, kontact[i].home_num);
		strcat_s(str_buffer, 1000, " ");
		strcat_s(str_buffer, 1000,kontact[i].kv_num);
		strcat_s(str_buffer, 1000, "\n");
		fputs(str_buffer, fp);
		str_buffer[0] = '\0';
	}
	if (flag_dell > 0) {
		for (int i = 0; i < flag_dell; i++) {
			str_buffer[0] = '\0';
			fputs(str_buffer, fp);
		}
		
	}
	//fseek(fp, 0, SEEK_END);

	fclose(fp);
}
