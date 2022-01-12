#ifndef LEXER_DEFS_H
#define LEXER_DEFS_H


#include "defs.h"


typedef struct lexer_t lexer_t;


struct lexer_t {
    cstr_t filepath;
    str_t buffer;
    int buffer_live: 1;
};

#endif // LEXER_DEFS_H