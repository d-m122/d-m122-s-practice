#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "ext.h"





void main(void)
{ 
	Student student[12] = {
		{1,1,"�d�q�@���Y",80,65,67,78,92,67},
		{1,2,"�������@��Y",55,62,78,32,55,43},
		{1,3,"���ˁ@�Ԏq",92,54,48,73,80,87},
		{2,1,"�d�q�@���Y",43,90,98,87,66,89},
		{2,2,"�������@��Y",77,67,43,34,56,64},
		{2,3,"���ˁ@�~�q",90,98,76,84,92,100},
		{3,1,"�d�q�@�N�v",55,32,26,43,56,72},
		{3,2,"�������@�O�Y",92,94,89,98,84,90},
		{3,3,"���ˁ@���q",75,78,90,65,78,82},
		{4,1,"�d�q�@�O����",43,56,80,43,78,65},
		{4,2,"�������@�l�Y",56,67,71,76,74,80},
		{4,3,"���ˁ@�|�q",87,55,89,30,55,54}
	};
	int conf;
	int flg = 0;
	int fclass;
	int fnumber;
	int find;
	int max = 12;
	
	while(flg == 0) {
		printf("����I��( ����: 1, �����I��: 9)\n");
		scanf("%d",&conf);
		
		switch(conf) {          
		case 1: 
			printf("�N���X����͂��Ă�������(1:2:3:4)\n");          
			scanf("%d",&fclass);
			printf("�o�Ȕԍ�����͂��Ă�������(1:2:3)\n");
			scanf("%d",&fnumber);
			
			find = search_Student(student,max,fclass,fnumber);  
			
			if(find != -1){
				print_Student(&student[find]);
			}else{
				printf("�Y�����鐶�k��񂪑��݂��܂���\n");
			}
	 	   break;
		case 9:
			flg = 1;
			break;
		}
	}
	exit(0);
}