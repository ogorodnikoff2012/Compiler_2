#include <iostream>

#include "lexer.h"

using namespace std;

int main() {
    Token t;
    wcin >> t;
    wcout << t.type << ' ' << t.data << endl;
    return 0;
}
