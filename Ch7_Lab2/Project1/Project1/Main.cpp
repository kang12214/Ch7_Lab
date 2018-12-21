#include <stdio.h>
#include <stdlib.h>

struct clientData
{
	int acctNum;
	char lastName[20];
	char firstName[20];
	double balance;
};

int main(void)
{
	FILE *pRead, *pWrite;
	FILE *cfPtr;
	int cnt = 0,q,w,e;
	struct clientData client = { 0,"","",0.0};

	q = fopen_s(&pRead,"C://code/credit.txt", "r");
	if (pRead == NULL)
	{
		return 0;
	}
	
	w = fopen_s(&pWrite,"C://code/credit_bin.txt", "wb");
	if (pWrite == NULL)
	{
		fclose(pWrite);
		return 0;
	}
	

	while (!feof(pRead))
	{
		fscanf_s(pRead, "%d",&client.acctNum);
		fscanf_s(pRead, "%s",client.lastName, 20);
		fscanf_s(pRead, "%s",client.firstName, 20);
		fscanf_s(pRead, "%lf",&client.balance);

		fwrite(&client, sizeof(struct clientData), 1, pWrite);
		
		printf("%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance);
	}

	fclose(pRead);
	fclose(pWrite);
	printf("Already read ACSII from txt, and turn into binarry type file\n\n");
	system("pause");

	printf("\nRead binarry type file and output: \n");
	if ((e = fopen_s(&cfPtr, "C://code/credit_bin.txt", "rb")) == 1)
	{
		printf("File could not be opened. \n");
	}
	else
	{
		printf("%-6s%-16s%-11s%-10s\n","Acct","Last Name","First Name", "Balance");

		cnt = fread(&client,sizeof(struct clientData),1,cfPtr);

			while (cnt > 0)
			{
				printf("%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance);
				cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);
			}
		fclose(cfPtr);
	}
	system("pause");
	return 0;
}