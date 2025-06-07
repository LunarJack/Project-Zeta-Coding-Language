#ifndef LEXER_HPP
#define LEXER_HPP
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iterator>
#include <unordered_map>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define COLOR_BOLD "\e[1m"
#define COLOR_OFF "\e[m"
enum TokenType
{
    KEYWORD,
    IDENTIFIER,
    STRING,
    OPERATOR,
    INTEGER,
    BIN_INTEGER,
    HEX_INTEGER,
    FLOAT,
    DOUBLE,
    TYPE,
    CHARACTER,
    PUNCTUATOR,
    UNKNOWN
};

class Number
{
    public:
        std::string value;
        bool isDouble;
        bool isFloat;
        bool isHex;
        bool isBin;
        Number(std::string value, bool isDouble, bool isFloat, bool isHex, bool isBin);
};

struct Token
{
    TokenType type;
    std::string value;

    Token(TokenType t, const std::string& v) : type(t), value(v)
    {
    }
};

class Lexer
{
    private:
        std::string input;
        size_t position;
        std::unordered_map<std::string, TokenType> keywords;
        std::unordered_map<std::string, TokenType> types;

        void initKeywords();

        bool isWhitespace(char c);

        bool isAlpha(char c);

        bool isDigit(char c);

        bool isAlphaNumeric(char c);

        std::string getNextWord();

        Number getNextNumber();

        void initTypes();

    public:
        Lexer(const std::string &source) : input(source), position(0)
        {
            this->initKeywords();
            this->initTypes();
        }

        std::vector<Token> tokenize();
};

std::vector<Token> lex(char srcFilePath[]);

std::string getTokenTypeName(TokenType type);
#endif//LEXER_HPP
