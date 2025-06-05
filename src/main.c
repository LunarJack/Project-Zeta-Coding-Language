#include <stdio.h>
#include <string.h>

void help(void);

int main(int argc, char * argv[], char * envp[], char * platp[])
{
    for(int i = 0; i != argc; i++)
    {
        if(argc >= 2)
        {
            if(strcmp(argv[i], "-h"))
                help();
        }
        else
            printf("Test\n");
    }
    return 0;
}

void help(void)
{
    printf("Test2\n");
}
