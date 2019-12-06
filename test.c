#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    static char p;
    static int number;
    if (fork() == 0) /*子进程*/
    {
        p = 'c'; /*子进程对数据的修改*/
        printf("p = %c , number = %d \n ", p, number);
        exit(0);
    }
    /*父进程*/
    number = 14; /*父进程对数据修改*/
    printf("p = %c , number = %d \n ", p, number);
    exit(0);
}