#include<string.h>
#define DUMBCOPY                \
    for (i = 0; i < 65536; i++) \
    destination[i] = source[i]
#define SMARTOPY memcpy(destination, source, 65535)

int main()
{
    char source[65535], destination[65535];
    int i, j;
    for (j = 0; j < 65535; j++)
        DUMBCOPY;
}