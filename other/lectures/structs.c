#include <stdio.h>
#include <stdlib.h>

struct Person{
        char name[5]; //5 bytes
        int age; // 4 bytes
        char gender; // 1 byte
    };

int main(){
    struct Person p2;
    struct Person p1 = {"Dave", 10, 'm'};
    p3=(struct Person*)malloc(sizeof(struct Person));
    printf("bytes: %ld\n", sizeof(p3));
    free(p3);

    /*
    printf("%s\n", p1.name);
    printf("%d\n", p1.age);
    printf("%c\n", p1.gender);
    */
    return 0;
}