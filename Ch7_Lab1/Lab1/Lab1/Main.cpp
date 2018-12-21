#include <stdio.h>
#include <stdlib.h>

typedef struct _student
{
	char name[5];
	int chinese;
	int english;
	int math;
	int sum;
	double avg;
}student;

int main(void)
{
	student data[6];
	FILE *stream1;
	FILE *stream2;
	int i, q, w;

	q = fopen_s(&stream1,"C://code/gradedata.txt", "r");
	w = fopen_s(&stream2,"C://code/gradeoutput.txt", "w");

	if (stream1 == NULL || stream2 == NULL)
	{
		printf("File open fail!");
	}
	else
	{
		fprintf(stream2, "Name\tChinese\tEnglish\tMath\tSum\tAverage\n");
		for (i = 0; i < 5; i++)
		{
			fscanf_s(stream1, "%s", &data[i].name,6);
			fscanf_s(stream1, "%d", &data[i].chinese);
			fscanf_s(stream1, "%d", &data[i].english);
			fscanf_s(stream1, "%d", &data[i].math);

			data[i].sum = data[i].chinese + data[i].english + data[i].math;
			data[i].avg = data[i].sum / 3;
			fprintf(stream2, "%s\t%d\t%d\t%d\t%d\t%.2f\n", data[i].name, data[i].chinese, data[i].english, data[i].math, data[i].sum, data[i].avg);
		}
		fclose(stream1);
		fclose(stream2);
	}
	system("pause");
	return 0;
}