#include <stdio.h>

#define Z 80

int main()
{
	
	int kisu;       //��i�Q�j
  	int exponent;   //�w���i�Q�T�U�j
	int cnt = 1;   //�v�Z�񐔕\���p
	int value;     //���i�P�R�U�j
	int value_tmp;
	int x = 0;
	int ans_str[Z] = {0};   //�v�Z��z��
	int i = Z - 1;
	int flg = 0;
	int keta;
	int k;
	int work;
	
	printf("�������(136)�F");        //����
	scanf("%d",&value);
	value_tmp = value;
	printf("������(2)�F");
	scanf("%d",&kisu);
	printf("�w�������(256)�F");
	scanf("%d",&exponent);
	
	if(exponent < 0 || kisu < 0 || value < 0){           //�l��0�����̏ꍇ
		printf("0�ȏ�̒l����͂��Ă�������\n");
		return 0;
	}
	
	if(exponent == 0){    //N>0�̎��Ŏw����2�ȏ�̎�
		kisu = 1;
		exponent = 1;
	}
	
	if(kisu == 0){                         //��`�ł��Ȃ�
		printf("%d��%d�� �� 0\n",kisu,exponent);
		printf("��`�ł��܂���\n");
		return 0;
	}
	
	cnt += exponent;
	
	for(keta=1;value!=0 && keta<= Z;){  //�����ӂ�h�~���P�ȏ�
		ans_str[Z-keta] = value % 10;
		value = value/10;
		if(value > 0){
			keta++;
		}
	}
	
	for(;exponent>0;exponent--){
		for(k = keta;k > 0;k--){
			x += ans_str[i];
			x = x * kisu;
			
			if(flg == 1){             //��������̏ꍇ�̏���
				x += work / 10;
				work = 0;
				flg = 0;
			}
			
			if(x < 10){
				ans_str[i] = x;  //�v�Z���ʂ�2�����̔���
			}else{
				work = x;  //2���������ꍇ
				ans_str[i] = x % 10;
				flg = 1;
			}
			
			x = 0;
			i--;
			
		}
		
		if(flg == 1){          //�Ō�̌����オ��ꍇ�̏���
			ans_str[i] = 1;
			keta++;
			flg = 0;
		}
		
		printf("%3d���:",cnt-exponent);//�v�Z�񐔕\��
		printf("%d * %d ^ %3d = ",value_tmp,kisu,cnt-exponent);
		for(i=keta;i<Z;i++){             //�E�l�ߏ���
			printf(" ");
		}
		
		for(i=Z-keta ;i<Z;i++){      //�v�Z���ʕ\��
			printf("%d",ans_str[i]);
		}
		
		printf("\n");
		i = Z - 1;   //i�̏�����
		
	}
	
}