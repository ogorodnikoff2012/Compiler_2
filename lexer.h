#ifndef __XENON_COMPILER_LEXER_H__
#define __XENON_COMPILER_LEXER_H__

#include <string>
#include <iostream>

enum TokenType {
    IDENTIFIER, OPERATOR, NUMERIC_LITERAL, STRING_LITERAL, PARENTESIS, ERROR
};

struct Token {
    TokenType type;
    std::wstring data;
};

std::wistream &operator >>(std::wistream &i, Token &t);

#endif//__XENON_COMPILER_LEXER_H__
