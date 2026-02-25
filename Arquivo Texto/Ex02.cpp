#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <conio2.h>

void VerificaArquivo(char NomeArquivo[20])
{
	FILE *PtrArq = fopen(NomeArquivo, "r");
	if(PtrArq == NULL)
	{
		printf("Arquivo nao encontrado, deseja criar?\n");
		if(toupper(getche()) == 'S')
		{
			PtrArq = fopen(NomeArquivo, "w");
			printf("Arquivo criado com sucesso!\n");
			fclose(PtrArq);
			getch();
		}
	}
	else
	{
		printf("Arquivo pronto para uso!\n");
		fclose(PtrArq);
		getch();
	}
}

void VasculharArquivo(char NomeArquivo[20])
{
	FILE *PtrArq = fopen(NomeArquivo, "r");
	int letras = 0, espacos = 0, linhas = 0;
	char caractere;
	caractere = fgetc(PtrArq);
	while(!feof(PtrArq))
	{
		if(caractere == ' ')
			espacos++;
		else if(isalpha(caractere))
			letras++;
		else if(caractere == '\n')
			linhas++;
		caractere = fgetc(PtrArq);
	}
	fclose(PtrArq);
}

int main(void)
{

	return 0;
}
