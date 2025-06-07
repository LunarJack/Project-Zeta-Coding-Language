#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[], char * envp[], char * platp[])
{
    for(int i = 0; i != argc; i++)
    {
        if(argc >= 2)
        {
            if(strcmp(argv[i], "-h"))
                printf("Test2\n");
        }
        else
            printf("Test\n");
    }
    return 0;
}
