#ifndef LEXER_PRIV_H
#define LEXER_PRIV_H


#include "lexer_defs.h"


void lxr_init(lexer_t* _lxr);

int lxr_alloc_buffer(lexer_t* _lxr);
void lxr_dealloc_buffer(lexer_t* _lxr);

#endif // LEXER_PRIV_h