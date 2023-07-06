
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

void add(uint32_t buf1, uint32_t buf2) {
    uint32_t n1 = ntohl(buf1);

    uint32_t n2 = ntohl(buf2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n1, n1, n2, n2, n1+n2, n1+n2);
}

int main(int argc, char *argv[]) {
    if(argc <= 2){
        printf("syntax : add-nbo <file1> <file2> \n");
        printf("sample : add-nbo a.bin c.bin \n");
        return 0;
    }
    uint32_t buffer1, buffer2; 
    FILE *f1, *f2;
    f1 = fopen(argv[1], "rb"); f2 = fopen(argv[2], "rb");
    fread(&buffer1, sizeof(uint32_t), 1, f1); fread(&buffer2, sizeof(uint32_t), 1, f2);

    add(buffer1, buffer2);
    fclose(f1); fclose(f2);
}
