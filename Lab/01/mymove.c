#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 10
void error_handling(char* message);

int main(int argc, char* argv[])
{
    int source_fd;
    int destination_fd;
    int source_size;
    int destination_size;
    char buf[BUF_SIZE];

    if(argc != 3)
        printf("[Error] mymove Usage: ./%s src_file dest_file", argv[0]);

    source_fd = open(argv[1], O_RDONLY);
    if(source_fd == -1)
        error_handling("open() error!");
    
    source_size= read(source_fd, buf, sizeof(buf));
    if(source_size == -1)
        error_handling("read() error!");
    printf("read size: %d\n", source_size);
    printf("file data: %s\n\n", buf);

    destination_fd = open(argv[2], O_CREAT|O_WRONLY|O_TRUNC, 0644);
    if(destination_fd == -1)
        error_handling("open() error!");
    destination_size = write(destination_fd, buf, sizeof(buf));
    printf("write size: %d\n\n", destination_size);
    if(destination_size == -1)
        error_handling("write() error!"); 

    printf("move from %s to %s (bytes: %d) finished.\n", argv[1], argv[2], destination_size);
    
    close(source_fd);
    close(destination_fd);
    remove(argv[1]);
    return 0;
}

void error_handling(char* message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}