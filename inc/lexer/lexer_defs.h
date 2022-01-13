#ifndef LEXER_DEFS_H
#define LEXER_DEFS_H


#include "defs.h"


typedef struct lexer_s lexer_s;


struct lexer_s {
    cstr_t filepath;
    str_t buffer;
    int offset;
    int line;
    int col;
    int buffer_live: 1;

    int (*lex) (lexer_s* _lxr);
};

#endif // LEXER_DEFS_H