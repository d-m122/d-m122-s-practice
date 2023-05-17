#include <stdio.h>
#include "struct.h"
#include "ext.h"

void print_Student(Student *spd)
{
	double average1;
	char rank;
	
	printf("クラス:%d\n",spd->class);
	printf("出席番号:%d\n",spd->number);
	printf("名前:%s\n",spd->name);
	printf("国語:%d\n",spd->test[0]);
	printf("数学:%d\n",spd->test[1]);
	printf("理科:%d\n",spd->test[2]);
	printf("社会:%d\n",spd->test[3]);
	printf("英語:%d\n",spd->test[4]);
	printf("情報:%d\n",spd->test[5]);
	
	average1 = average_check((*spd).test);
	rank = rank_check(average1); 
	
	average1 += 0.01;   
	printf("平均点:%.1f\n",average1);
	printf("ランク:%c\n",rank);
}