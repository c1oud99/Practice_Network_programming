#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
    char *addr1 = "1.2.3.4";
    char *addr2 = "1.2.3.256";
    uint32_t conv_addr;

    conv_addr = inet_addr(addr1);
    if(conv_addr == INADDR_NONE)
        printf("Error occurred! \n");
    else
        printf("Network ordered integer addr1: %#x \n", conv_addr);

    conv_addr = inet_addr(addr2);
    if(conv_addr == INADDR_NONE)
        printf("Error occurred! \n");
    else
        printf("Network ordered integer addr2: %#x \n\n", conv_addr);
    
    return 0;
}