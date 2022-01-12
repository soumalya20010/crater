#include "defs.h"
#include "lexer.h"



int main(int _argc, str_t* _argv) {
    lexer_t* lexer = new_lexer();
    if(!lexer) return 1;

    lexer->filepath = _argv[1];
    delete_lexer(lexer);
    return 0;
}