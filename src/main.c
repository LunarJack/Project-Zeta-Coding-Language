#include <stdio.h>
#include <string.h>
#ifdef __WIN32__
#include <windows.h>
#endif//__WIN32__

void help();

int main(int argc, char * argv[], char * envp[], char * platp[])
{
    for(int i = 0; i != argc; i++)
    {
        if(strcmp(argv[i], "-h"))
            help();
        
    }
    printf("Test\n");
    return 0;
}

void help(void)
{
    printf("Test2\n");
}
