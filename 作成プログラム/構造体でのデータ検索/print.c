#include <stdio.h>
#include "struct.h"
#include "ext.h"

void print_Student(Student *spd)
{
	double average1;
	char rank;
	
	printf("�N���X:%d\n",spd->class);
	printf("�o�Ȕԍ�:%d\n",spd->number);
	printf("���O:%s\n",spd->name);
	printf("����:%d\n",spd->test[0]);
	printf("���w:%d\n",spd->test[1]);
	printf("����:%d\n",spd->test[2]);
	printf("�Љ�:%d\n",spd->test[3]);
	printf("�p��:%d\n",spd->test[4]);
	printf("���:%d\n",spd->test[5]);
	
	average1 = average_check((*spd).test);
	rank = rank_check(average1); 
	
	average1 += 0.01;   
	printf("���ϓ_:%.1f\n",average1);
	printf("�����N:%c\n",rank);
}