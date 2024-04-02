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
    char buf[100] = "Let's go!\n";  // 배열의 크기[100]를 문자열 보다 크게 설정한 경우

    fd = open("data3.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
    if(fd == -1)
        error_handling("open() error!");
    
    printf("file descriptor: %d, strlen: %ld \n", fd, strlen(buf));

    size = write(fd, buf, sizeof(buf));     // 문자열의 길이와 상관없이  buf[100]의 길이만큼 저장(sizeof(buf): 100bytes)
    printf("write size: %d\n", size);
    if(size == -1)
        error_handling("write() error!");

    close(fd);
    return 0;
}

void error_handling(char* message)
{
    fputs(message, stderr);
    fputc('\n',stderr);
    exit(1);
}