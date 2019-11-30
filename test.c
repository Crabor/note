#if sizeof(int) == 2
typedef long int32;
#else
typedef int int32;
#endif

int main(void)
{
    return 0;
}