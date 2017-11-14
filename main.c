#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main() {
	int flag_de = 0;
	setlocale(LC_ALL, "Rus");
	printf("\n Телефонная книга! \n");
	int flag_menu = 0;
	int index = 0;
	char str_buffer[1000];
	char buffer[100];
	int index_3 = 0;
	int index_2=0;
	struct telefon_t {    //структура смой телефонной книги
		char name[100];
		char se_name[100];
		char number[20];
		char adr_name[100];
		char home_num[10];
		char kv_num[10];
	};

	struct telefon_t kontact[100];  //макс количество записей в книге


	FILE *fp;
	fopen_s(&fp, "file.txt", "r+");
	if (fp != NULL) {
		printf("\n Файл с базой данных был подключен, можете начать работать!! \n");   //подключение бд из файла
		fseek(fp, 0, SEEK_SET);
		while (!feof(fp)) {   //записть всей инфы в память
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
		printf("\n Ошибка открытия базы данных телефонной книги\n");
		do {
			printf("\n Выберите действие : \n 1-Создать новую!! \n 2- Выйти из телефонной книги!\n");
			scanf_s("%d", &flag_de);
			if (flag_de == 1) {
				fopen_s(&fp, "file.txt", "w+");
				if (fp != NULL) {
					printf("Новая база данных создана!\n");   //создание новой бд ели нету другой
				}
				else {
					printf("Програмная ошибка , невозможно создать файд бд!!\n");
				}
			}
			if (flag_de == 2) {
				break;
			}
		} while (flag_de!=0);
	}



	do {
		printf("\n Меню книги :\n 1-Вывести список контактов \n 2-Поиск контактов \n 3-Добавление контактов \n 4-Вызов по номеру \n 5- Выбрать(редактировать) контакт \n 0-Выход \n");
		scanf_s("%d", &flag_menu);
		if (flag_menu == 1) {
			printf("\n Список контактов \n");
			for (int i = 0; i < index; i++) {
				printf("%d - %s %s %s %s %s %s \n",i, kontact[i].name,kontact[i].se_name,kontact[i].number,kontact[i].adr_name,kontact[i].home_num,kontact[i].kv_num);
			}
		}
		if (flag_menu == 2) {
			//printf("\n Введите критерий поиска \n 1-По имени \n 2- По номеру \n 3-По адресу \n 4-поиск соседий контакта \n");
			int flga_id = 0;
			char buff_name[20];
			char buff_number[15];
			char buff_adr[20];
			int buff_kol_sosedi;
			char buff_adr_sosedi_name[20];
			do {
				printf("\n Введите критерий поиска \n 1-По имени \n 2- По номеру \n 3-По адресу \n 4-поиск соседий контакта \n 0-выход \n");
				while (getchar() != '\n');
				scanf_s("%d", &flga_id);
				if (flga_id == 0) {
					break;
				}
				if (flga_id == 1) {
					printf("\n Введите искомый контакт: \n");
					while (getchar() != '\n');
					gets_s(buff_name, 20);
					for (int i = 0; i < index; i++) {
						if (strcmp(buff_name,kontact[i].name)==0) {
							printf("%d - %s %s %s %s %s %s \n", i, kontact[i].name, kontact[i].se_name, kontact[i].number, kontact[i].adr_name, kontact[i].home_num, kontact[i].kv_num);
						}
					}
				}
				if (flga_id == 2) {
					printf("\n Введите искомый номер: \n");
					while (getchar() != '\n');
					gets_s(buff_number, 20);
					for (int i = 0; i < index; i++) {
						if (strcmp(buff_number, kontact[i].number) == 0) {
							printf("%d - %s %s %s %s %s %s \n", i, kontact[i].name, kontact[i].se_name, kontact[i].number, kontact[i].adr_name, kontact[i].home_num, kontact[i].kv_num);
						}
					}

				}
				if (flga_id == 3) {
					printf("\n Введите искомый адрес: \n");
					while (getchar() != '\n');
					gets_s(buff_number, 20);
					for (int i = 0; i < index; i++) {
						if (strcmp(buff_adr, kontact[i].adr_name) == 0) {
							printf("%d - %s %s %s %s %s %s \n", i, kontact[i].name, kontact[i].se_name, kontact[i].number, kontact[i].adr_name, kontact[i].home_num, kontact[i].kv_num);
						}
					}

				}
				if (flga_id == 4) {
					int flag_index = 0;
					printf("\n Введите количество соседий: \n");
					while (getchar() != '\n');
					scanf_s("%d", &buff_kol_sosedi);
					printf("\n Введите искомый адрес: \n");
					while (getchar() != '\n');
					gets_s(buff_adr_sosedi_name, 20);
					for (int i = 0; i < index; i++) {
						if (flag_index >= buff_kol_sosedi) {
							break;
						}
						if (strcmp(buff_adr_sosedi_name, kontact[i].adr_name) == 0) {
							flag_index++;
							printf("%d - %s %s %s %s %s %s \n", i, kontact[i].name, kontact[i].se_name, kontact[i].number, kontact[i].adr_name, kontact[i].home_num, kontact[i].kv_num);
						}
					}

				}
			} while (flga_id != 0);
		}
		if (flag_menu == 3) {
			
			printf("\n Введите имя : \n");
			while (getchar() != '\n');
			gets_s(kontact[index].name, 100);
			printf("\n Введите фамилию \n");
			gets_s(kontact[index].se_name, 100);
			printf("\n Введите номер телефона  \n");
			gets_s(kontact[index].number, 20);
			printf("\n Введите адерс (улица)  \n");
			gets_s(kontact[index].adr_name, 100);
			printf("\n Введите номер дома  \n");
			gets_s(kontact[index].home_num, 10);
			printf("\n Введите номер квартиры  \n");
			gets_s(kontact[index].kv_num, 10);
			index++;
		}

		if (flag_menu == 4) {
			char coll_num[20];
			char cool_name[20];
			int index_coll_name=101;
			printf("\n Наберите номер для вызова!! \n");
			while (getchar() != '\n');
			gets_s(coll_num, 20);
			for (int i = 0; i < index; i++) {
				if (strcmp(coll_num,kontact[i].number) == 0) {
					index_coll_name = i;
					printf("Calling %s %s \n", kontact[index_coll_name].name, kontact[index_coll_name].se_name);
					system ("Pause");
					break;
				}
			}
			if (index_coll_name == 101) {
				printf("\n Идет звонок  неопределеному контакту \n ");
				system("Pause");
			}
			
		}
		if (flag_menu == 5) {
			int tek_index = 0;
			printf("\n Выберите контакт : \n");
			scanf_s("%d", &tek_index);
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
