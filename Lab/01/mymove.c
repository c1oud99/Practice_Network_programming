#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 10

int main(int argc, char* argv[])
{
    int src_fd, dst_fd;
    int read_count;
    int total_count;
    char buf[BUF_SIZE];

    if(argc != 3){
        printf("[Error] mymove Usage: ./%s src_file dest_file", argv[0]);
        exit(1);
    }

    src_fd = open(argv[1], O_RDONLY);
    dst_fd = open(argv[2], O_CREAT|O_WRONLY|O_TRUNC, 0644);
    if(src_fd == -1 || dst_fd== -1){
        printf("open() error!\n");
        exit(1);
    }
    
    while((read_count= read(src_fd, buf, BUF_SIZE)) != 0)
    {
        write(dst_fd, buf, read_count);
        total_count += read_count;
    }
    printf("read size: %d\nfile data: %s\n\n", read_count, buf);
    printf("write size: %d\n\n", total_count);
    printf("move from %s to %s (bytes: %d) finished.\n", argv[1], argv[2], total_count);
    
    close(src_fd);
    close(dst_fd);
    remove(argv[1]);
    return 0;
}