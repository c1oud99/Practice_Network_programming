#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void error_handling(char* message);

int main(void)
{
    int fd;
    int size;
    char buf[10] = "Let's go!\n";   // 배열의 크기를 문자열의 길이만큼 배정

    fd = open("data2.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
    if(fd == -1)
        error_handling("open() error!");
    
    printf("file descriptor: %d, strlen: %ld \n", fd, strlen(buf));

    size = write(fd, buf, sizeof(buf)); // sizeof(buf)=10 크기만큼 저장
    printf("write size: %d\n", size);
    if(size == -1)
        error_handling("write() error!");
    
    close(fd);
    return 0;
}

void error_handling(char* message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}