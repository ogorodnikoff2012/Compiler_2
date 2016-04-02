#include <iostream>
#include <vector>
#include <string>
#include <locale>

#include "lexer.h"

using namespace std;

locale unicode("en_US.UTF-8");
locale ascii("C");

bool readIdentifier(wistream &i, Token &t) {
    wchar_t ch;
    ch = i.peek();
    if (!isalpha(ch, unicode) && ch != L'_') {
        t.type = ERROR;
        return false;
    }
    t.data.push_back(ch);
    i.get();
    do {
        ch = i.peek();
        if (isalnum(ch, unicode) || ch == L'_') {
            t.data.push_back(ch);
            i.get();
        } else {
            break;
        }
    } while (i.good());
    t.type = IDENTIFIER;
    return true;
}

bool readNumericLiteral(wistream &i, Token &t) {
    wchar_t ch;
    auto pos = i.tellg();
    ch = i.peek();
    if (ch == L'+' || ch == L'-') {
        t.data.push_back(ch);
        i.get();
        ch = i.peek();
    }
    if (isdigit(ch, ascii)) {
        t.data.push_back(ch);
        i.get();
        ch = i.peek();
    } else {
        i.seekg(pos);
        t.type = ERROR;
        return false;
    }
    while (isdigit(ch, ascii)) {
        t.data.push_back(ch);
        i.get();
        ch = i.peek();
    }
    if (ch == L'.') {
        t.data.push_back(ch);
        i.get();
        ch = i.peek();
    }
    while (isdigit(ch, ascii)) {
        t.data.push_back(ch);
        i.get();
        ch = i.peek();
    }
    t.type = NUMERIC_LITERAL;
    return true;
}

wistream &operator >>(wistream &i, Token &t) {
    readIdentifier(i, t) || readNumericLiteral(i, t);
    return i;
}
