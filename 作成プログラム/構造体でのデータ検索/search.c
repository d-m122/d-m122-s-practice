#include <stdio.h>
#include "struct.h"
#include "ext.h"

int search_Student(Student *pd, int max, int class,int number)
{
	int i;
	
	for(i=0;i<max;i++){
		if(pd[i].class == class){
			if(pd[i].number == number){
				return i;
			}
		}
	}
	return -1;
}