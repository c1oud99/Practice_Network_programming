#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[])
{
    char msg1[BUF_SIZE];
    char msg2[BUF_SIZE];

    memset(msg1, -1, sizeof(msg1));
    memset(msg2, -1, sizeof(msg2));
    
    // scanf() 사용
    printf("Input string1 -> ");
    scanf("%s", msg1);
    printf("msg1: %s, len: %ld\n", msg1, strlen(msg1));
    getchar();

    // fgets() 사용    
    printf("Input string2 -> ");
    fgets(msg2, BUF_SIZE, stdin);
    printf("msg2: %s, len: %ld\n", msg2, strlen(msg2));

    return 0;
}