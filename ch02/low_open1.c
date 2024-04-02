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
    char buf[] = "Let's go!\n"; //배열의 크기를 지정하지 않음

    fd = open("data1.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
    if(fd == -1)
        error_handling("open() error!");
    
    printf("file descriptor: %d \n", fd);
    size = write(fd,buf, sizeof(buf));
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
