#include <iostream>
#include <fstream>
#include <cstdlib>
#include <compile/lexer.hpp>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define COLOR_BOLD "\e[1m"
#define COLOR_OFF "\e[m"

int main(int argc, char * argv[], char * envp[], char * platp[])
{
    for(int i = 0; i != (argc + 1); i++)
    {
        if(argc >= 2)
        {
            if(strcmp(argv[i], "-c") == 0)
            {
                std::ifstream file1(argv[3]);
                if(!file1.good())
                {
                    std::fprintf(stderr, ANSI_COLOR_RED COLOR_BOLD "error: " ANSI_COLOR_RESET COLOR_OFF "cannot open file: \'%s\'\n", argv[2]);
                    file1.close();
                    exit(1);
                }
                else
                    file1.close();
                std::ifstream file2(argv[i--]);
                if(!file2.good())
                {
                    #ifdef __unix__
                    std::fprintf(stderr, ANSI_COLOR_RED COLOR_BOLD "error: " ANSI_COLOR_RESET COLOR_OFF "cannot open file: \'%s\'\n", argv[3]);
                    #endif//__unix__
                    std::fprintf(stderr, ANSI_COLOR_RED "error: " ANSI_COLOR_RESET "cannot open file: \'%s\'\n", argv[2]);
                    file2.close();
                    exit(1);
                }
                else
                    file2.close();
                lex(argv[3]);
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
    std::println("Test");
    return 0;
}
