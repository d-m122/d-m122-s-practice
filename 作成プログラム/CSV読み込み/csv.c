//決められた形式のCSVを読み込むことができる

#include <stdio.h>

int main(void)
{
        FILE *fp;
        char *fname = "test.csv";
        char data1[100];
        float data2, data3;
        int ret;

        fp = fopen( fname, "r" );
        if( fp == NULL ){
                printf( "Not open %s?n", fname );
                return -1;
        }

        while( ( ret = fscanf( fp, "%[^,],%f,%f", data1, &data2, &data3) ) != EOF ){
                printf( "%s %f %f", data1, data2, data3 );
        }

        fclose( fp );
        return 0;
}
