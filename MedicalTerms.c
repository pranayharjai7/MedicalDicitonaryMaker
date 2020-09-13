#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct med
{
	char word[20];
	char meaning[150];
};
int main()
{
	int i=0;
	char ch;
	struct med wordsave[10];
	FILE *f;
	f = fopen("med.dat","a");
	if(!f)
	{
		printf("Error!");
		exit(0);
	}
	
	do
	{
		printf("Enter word: ");
		scanf(" %[^\n]%*c",&wordsave[i].word);
		printf("Enter it's meaning: ");
		scanf(" %[^\n]%*c",&wordsave[i].meaning);
		fwrite(&wordsave[i],1,sizeof(wordsave[i]),f);
		printf("\nSaved in file!\n");
		i++;
		printf("Do you want to enter more?(y/n): ");
		scanf(" %c",&ch);
		if(i==10)
		{
			printf("You cannot enter more.\n");
			ch='n';
		}
	}while(ch=='y'||ch=='Y');
	
	fclose(f);
	
	return 0;
}
