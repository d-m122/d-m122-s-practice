#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 1024
#define L 32

//プロトタイプ宣言
void check_option(char*); //オプションの書式チェック
int check_str(char*,char*,int);  //文字列検索
char lower(char);//小文字変換

void main(int argc ,char *argv[]) //main関数
{
	char filename[N];
	int flg = 0;
	
	if(argc == 3){  //引数の数（argc）の確認
		strcpy(filename,argv[2]);
		check_str(argv[1],filename,flg);
	}else if(argc == 4){
		check_option(argv[1]);
		strcpy(filename,argv[3]);
		flg = 1;
		check_str(argv[2],filename,flg);
	}else {
		printf("コマンドライン引数を正しく入力してください\n");
		exit(0);
	}
}

	
void check_option(char *opt) //オプションの書式チェック
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
		printf("オプションの書式が違います\n再度入力してください\n");
		exit(0);
	}
	return;
}
	
	
int check_str(char *f_str ,char *filename,int flg) //部分一致検索
{
	FILE *fp;
	char str[N];                          //str 入力された文字列
	char *find;
	char low_str[N];
	int strnum; //検索対象文字列
	int f_strnum; //検索文字列
	int i;
	int flg2 = 0;
	
	if( (fp = fopen(filename, "r")) == NULL){
		printf("オープンエラー\n");
		fclose(fp);
		return -1;
	}
	if(flg == 1){
		f_strnum = strlen(f_str);
		for(i=0; i<f_strnum; i++){
			f_str[i] = tolower(f_str[i]);
		}
		while(fgets(str, N, fp) != NULL) {        //文字列抽出
			strnum = strlen(str);
			strcpy(low_str,str);
			for(i=0; i<strnum; i++){
				low_str[i] = tolower(low_str[i]);
			}
			find = strstr(low_str,f_str);
			if(find != NULL){
				flg2 = 1;
				printf("%s", str); //一致した行の出力
			} 
			
		}
	} else {
		while(fgets(str, N, fp) != NULL) {        //文字列抽出
			find = strstr(str,f_str);
			if(find != NULL){
				flg2 = 1;
				printf("%s", str); //一致した行の出力
			}
		}
	}
	if(flg2 == 0){
		printf("見つかりませんでした\n");
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
int lower(int c)       //小文字変換
{
	if('A' <= c && c <= 'Z'){
        c += L;
    }
    return c;
}
*/

/*
char check_str(char *str1, char *str2)  //部分一致
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