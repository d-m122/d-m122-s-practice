#include <stdio.h>
#include "struct.h"
#include "ext.h"


double average_check(int *test)
{
	int i;
	int sum = 0;
	double average2;
	for(i=0;i<6;i++){
		sum += *test;
		test++;
	}
	average2 = (double)sum / 6;
	return average2;
}

char rank_check(double average3)
{
	char rank;
	
	if(average3 >= 95){
		rank = 'S';
		return rank;
	}else if(average3 >= 85){
		rank = 'A';
		return rank;
	}else if(average3 >= 70){
		rank = 'B';
		return rank;
	}else if(average3 >= 60){
		rank = 'C';
		return rank;
	}else{
		rank = 'D';
		return rank;
	}
}

