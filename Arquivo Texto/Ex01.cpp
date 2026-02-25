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

void CriarNovoArquivo(char NomeArquivo[20])
{
	FILE *PtrArq = fopen(NomeArquivo, "r");
	FILE *PtrNovoArq = fopen("arquivonovo.txt", "w");
	
	char caractere;
	caractere = fgetc(PtrArq);
	while(!feof(PtrArq))
	{
		caractere = toupper(caractere);
		fputc(caractere,PtrNovoArq);
		
		caractere = fgetc(PtrArq);
	}
	
	fclose(PtrArq);
	fclose(PtrNovoArq);
}

int main(void)
{

	return 0;
}
