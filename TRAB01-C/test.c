#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


typedef struct
{
    char *name;
    int rg;
} UserData;

void print_list(UserData *list)
{
	int i = 0;
	while(list[i].name != NULL)
	{
		printf("Nome: %s, RG: %i \n", list[i].name, list[i].rg);
		i++;
	}
}
void insert_node_list(UserData **list, UserData data, int pos)
{
	int i = 0, lenght = 0;

	if((*list) == NULL)
	{
		(*list) = (UserData *)malloc(sizeof(UserData) * 2);
		(*list)[0] = (UserData){data.name, data.rg};
		(*list)[1] = (UserData){NULL, 0};
		return;
	}

	while((*list)[lenght].name != NULL)
		lenght++;

	if(pos > lenght)
	{
		printf("posicao invalida\n");
		exit(1);
	}

	*list = (UserData *)realloc(*list, sizeof(UserData) * (lenght + 2));
	if(pos == 0)
	{
		while(i <= lenght)
		{
			(*list)[i + 1] = (UserData){(*list)[i].name, (*list)[i].rg};
			i++;
		}
		(*list)[0] = (UserData){data.name, data.rg};
	}

	else if(pos == -1)
		(*list)[lenght] = (UserData){data.name, data.rg};

	else
	{
		while((*list)[i].name != NULL)
		{
			if(i == pos)
			{
				int j = lenght;
				while(j >= i)
				{
					(*list)[j + 1] = (UserData){(*list)[j].name, (*list)[j].rg};
					j--;
				}
				(*list)[i] = (UserData){data.name, data.rg};
				break;
			}
			i++;
		}
	}
	(*list)[lenght + 1] = (UserData){NULL, 0};
}


int	ft_atoi(const char *nptr)
{
	int	i = 0;
	int	num = 0;

	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		num = (num * 10) + (nptr[i] - 48);
		i++;
	}
	return (num);
}

size_t	ft_strlen(const char *s)
{
	size_t	i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

UserData serach_rg_list(UserData *list, int rg)
{
	int i = 0;
	while(list[i].name != NULL)
	{
		if(list[i].rg == rg)
			return list[i];
		i++;
	}
	return (UserData){NULL, 0};
}


void read_file_to_list(UserData *list, char *file)
{
	FILE *fp;
	fp = fopen(file, "r");
	if(fp == NULL)
	{
		printf("erro ao abrir o arquivo\n");
		exit(1);
	}
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while((read = getline(&line, &len, fp)) != EOF)
	{

		if(ft_strlen(line) < 9)
			continue;
		UserData newUser;
		char *rg = (char *)malloc(sizeof(char) * 9);
		char *name = (char *)malloc(sizeof(char) * (ft_strlen(line) - 8));

		int i = 0, j = 0, flag = 0;
		while (line[i] != '\0')
		{
			if(line[i] == ',')
			{
				flag = 1;
				j = 0;
			} else
			{
				if(flag)
					rg[j++] = line[i];
				else
					name[j++] = line[i];
			}
			i++;
		}
		newUser = (UserData){name, ft_atoi(rg)};
		insert_data_on_list(&list, newUser, -1);
	}
}



int main()
{
    UserData *data;
	data = NULL;
	char *file = "./db/NomeRG10.txt";

	read_file_to_list(data, file);

    // data = (UserData *)malloc(sizeof(UserData) * 3);
    // data[0] = (UserData){"maria", 9999};
	// data[1] = (UserData){"lucas", 4444};
	// data[2] = (UserData){NULL, 0};
    // insert_data_on_list(data, (UserData){"joao", 19999}, 1);
	// UserData data1 = serach_rg_list(data, 9999);

	printf("Nome: %s, RG: %i \n", data[0].name, data[0].rg);
	// printf("Nome: %s, RG: %i \n", data1.name, data1.rg);
    // print_list(data);
}

void insert_node_listOriginal(UserData **list, UserData data, int pos)
{
	int i = 0, lenght = 0;

	if((*list) == NULL)
	{
		(*list) = (UserData *)malloc(sizeof(UserData) * 2);
		(*list)[0] = (UserData){data.name, data.rg};
		(*list)[1] = (UserData){NULL, 0};
		return;
	}

	while((*list)[lenght].name != NULL)
		lenght++;

	if(pos > lenght)
	{
		printf("posicao invalida\n");
		exit(1);
	}

	*list = (UserData *)realloc(*list, sizeof(UserData) * (lenght + 2));
	if(pos == 0)
	{
		while(i <= lenght)
		{
			(*list)[i + 1] = (UserData){(*list)[i].name, (*list)[i].rg};
			i++;
		}
		(*list)[0] = (UserData){data.name, data.rg};
	}

	else if(pos == -1)
		(*list)[lenght] = (UserData){data.name, data.rg};

	else
	{
		while((*list)[i].name != NULL)
		{
			if(i == pos)
			{
				int j = lenght;
				while(j >= i)
				{
					(*list)[j + 1] = (UserData){(*list)[j].name, (*list)[j].rg};
					j--;
				}
				(*list)[i] = (UserData){data.name, data.rg};
				break;
			}
			i++;
		}
	}
	(*list)[lenght + 1] = (UserData){NULL, 0};
}