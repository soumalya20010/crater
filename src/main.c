#include "defs.h"
#include "lexer.h"


int main(int _argc, str_t* _argv) {
    if(_argc == 1) return 0;

    lexer_s* lexer = new_lexer();
    if(!lexer) return 1;

    lexer->filepath = _argv[1];
    if(!lexer->lex(lexer)) return 1;

    delete_lexer(lexer);
    return 0;
}