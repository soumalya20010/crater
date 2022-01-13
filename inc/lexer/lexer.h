#ifndef LEXER_H
#define LEXER_H


#include "lexer_defs.h"


lexer_s* new_lexer(void);
void delete_lexer(lexer_s* _lxr);

#endif // LEXER_H