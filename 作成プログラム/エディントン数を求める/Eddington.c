//エディントン数を求め、出力するプログラム

#include <stdio.h>

#define Z 80

int main()
{
	
	int kisu;       //基数（２）
  	int exponent;   //指数（２５６）
	int cnt = 1;   //計算回数表示用
	int value;     //数（１３６）
	int value_tmp;
	int x = 0;
	int ans_str[Z] = {0};   //計算後配列
	int i = Z - 1;
	int flg = 0;
	int keta;
	int k;
	int work;
	
	printf("数を入力(136)：");        //入力
	scanf("%d",&value);
	value_tmp = value;
	printf("基数を入力(2)：");
	scanf("%d",&kisu);
	printf("指数を入力(256)：");
	scanf("%d",&exponent);
	
	if(exponent < 0 || kisu < 0 || value < 0){           //値が0未満の場合
		printf("0以上の値を入力してください\n");
		return 0;
	}
	
	if(exponent == 0){    //N>0の時で指数が2以上の時
		kisu = 1;
		exponent = 1;
	}
	
	if(kisu == 0){                         //定義できない
		printf("%dの%d乗 ≠ 0\n",kisu,exponent);
		printf("定義できません\n");
		return 0;
	}
	
	cnt += exponent;
	
	for(keta=1;value!=0 && keta<= Z;){  //桁あふれ防止＆１以上
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
			
			if(flg == 1){             //桁あがりの場合の処理
				x += work / 10;
				work = 0;
				flg = 0;
			}
			
			if(x < 10){
				ans_str[i] = x;  //計算結果が2桁かの判定
			}else{
				work = x;  //2桁だった場合
				ans_str[i] = x % 10;
				flg = 1;
			}
			
			x = 0;
			i--;
			
		}
		
		if(flg == 1){          //最後の桁が上がる場合の処理
			ans_str[i] = 1;
			keta++;
			flg = 0;
		}
		
		printf("%3d回目:",cnt-exponent);//計算回数表示
		printf("%d * %d ^ %3d = ",value_tmp,kisu,cnt-exponent);
		for(i=keta;i<Z;i++){             //右詰め処理
			printf(" ");
		}
		
		for(i=Z-keta ;i<Z;i++){      //計算結果表示
			printf("%d",ans_str[i]);
		}
		
		printf("\n");
		i = Z - 1;   //iの初期化
		
	}
	
}
