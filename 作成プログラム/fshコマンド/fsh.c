#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 1024
#define L 32

//�v���g�^�C�v�錾
void check_option(char*); //�I�v�V�����̏����`�F�b�N
int check_str(char*,char*,int);  //�����񌟍�
char lower(char);//�������ϊ�

void main(int argc ,char *argv[]) //main�֐�
{
	char filename[N];
	int flg = 0;
	
	if(argc == 3){  //�����̐��iargc�j�̊m�F
		strcpy(filename,argv[2]);
		check_str(argv[1],filename,flg);
	}else if(argc == 4){
		check_option(argv[1]);
		strcpy(filename,argv[3]);
		flg = 1;
		check_str(argv[2],filename,flg);
	}else {
		printf("�R�}���h���C�������𐳂������͂��Ă�������\n");
		exit(0);
	}
}

	
void check_option(char *opt) //�I�v�V�����̏����`�F�b�N
{	
	int i = 0;
	int flag = 0;
	char str[N];
	char ans[] = "/I";
	strcpy(str,opt);
	while(str[i]!='\0' && ans[i]!='\0'){
		if(str[i]!=ans[i]){
			flag = 1;
			break;
		}
		i++;
	}
	if(flag == 1){
		printf("�I�v�V�����̏������Ⴂ�܂�\n�ēx���͂��Ă�������\n");
		exit(0);
	}
	return;
}
	
	
int check_str(char *f_str ,char *filename,int flg) //������v����
{
	FILE *fp;
	char str[N];                          //str ���͂��ꂽ������
	char *find;
	char low_str[N];
	int strnum; //�����Ώە�����
	int f_strnum; //����������
	int i;
	int flg2 = 0;
	
	if( (fp = fopen(filename, "r")) == NULL){
		printf("�I�[�v���G���[\n");
		fclose(fp);
		return -1;
	}
	if(flg == 1){
		f_strnum = strlen(f_str);
		for(i=0; i<f_strnum; i++){
			f_str[i] = tolower(f_str[i]);
		}
		while(fgets(str, N, fp) != NULL) {        //�����񒊏o
			strnum = strlen(str);
			strcpy(low_str,str);
			for(i=0; i<strnum; i++){
				low_str[i] = tolower(low_str[i]);
			}
			find = strstr(low_str,f_str);
			if(find != NULL){
				flg2 = 1;
				printf("%s", str); //��v�����s�̏o��
			} 
			
		}
	} else {
		while(fgets(str, N, fp) != NULL) {        //�����񒊏o
			find = strstr(str,f_str);
			if(find != NULL){
				flg2 = 1;
				printf("%s", str); //��v�����s�̏o��
			}
		}
	}
	if(flg2 == 0){
		printf("������܂���ł���\n");
	}
	fclose(fp);
	return 0;
}
	
/*
char* import_filename(char *filename)
{
	char name[N];
	strcpy(name,filename);
	return name;
}
*/

/*
int lower(int c)       //�������ϊ�
{
	if('A' <= c && c <= 'Z'){
        c += L;
    }
    return c;
}
*/

/*
char check_str(char *str1, char *str2)  //������v
{
  int i, j, k;

  if(*str2 == '\0')
    return NULL;
  else
    {
      for(i = 0;*(str1 + i) != '\0';i++)
	{
	  if(*(str1 + i) == *str2)
	    {
	      for(j = i, k = 0;*(str1 + j) == *(str2 + k);j++, k++);
	      if(*(str2 + k) == '\0')
		return 1;
	    }
	}
      return NULL;
    }
}
*/	