#ifndef LEXER_H
#define LEXER_H


#include "lexer_defs.h"


lexer_t* new_lexer(void);
void delete_lexer(lexer_t* _lxr);

#endif // LEXER_H