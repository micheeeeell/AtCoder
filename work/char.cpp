#include <stdio.h>
#include <string.h>
 
int main()
{
    char array[7];
    char *ptr;
    /**
    　* char配列に、文字列をコピーする
    　*/
    strcpy(array, "abcdef");
    /**
    　* char ポインタに、char配列の先頭のアドレスをコピーする
    　*/
    ptr = &(array[0]);
    /**
    　* char ポインタに、文字列をコピーする
    　*/
    strcpy(ptr, "ghijkl");
    /**
    　* char 配列、char ポインタをそれぞれ文字列形式で表示する
    　*/
    printf(" array = %s\n ptr = %s\n", array, ptr);
}