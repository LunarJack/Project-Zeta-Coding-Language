#include <iostream>
#include <fstream>
#include <cstdlib>
#include <compile/lexer.hpp>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main(int argc, char * argv[], char * envp[], char * platp[])
{
    for(int i = 0; i != (argc + 1); i++)
    {
        if(argc >= 2)
        {
            if(strcmp(argv[i], "-c") == 0)
            {
                std::ifstream file1(argv[1]);
                if(!file1.good())
                {
                    std::fprintf(stderr, ANSI_COLOR_RED "error: " ANSI_COLOR_RESET "cannot open file: \'%s\'\n", argv[2]);
                    file1.close();
                    exit(1);
                }
                else
                    file1.close();
                std::ifstream file2(argv[3]);
                if(!file2.good())
                {
                    std::fprintf(stderr, ANSI_COLOR_RED "error: " ANSI_COLOR_RESET "cannot open file: \'%s\'\n", argv[2]);
                    file2.close();
                    exit(1);
                }
                else
                    file2.close();
                lex(argv[1]);
                break;
            }
            else if(strcmp(argv[i], "-h") == 0)
            {
                std::println("Placeholder");
                break;
            }
        }
        else
            break;
    }
    return 0;
}
