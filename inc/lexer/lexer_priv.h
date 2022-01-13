#ifndef LEXER_PRIV_H
#define LEXER_PRIV_H


#include "lexer_defs.h"


void lxr_init(lexer_s* _lxr);

int lxr_alloc_buffer(lexer_s* _lxr);
void lxr_dealloc_buffer(lexer_s* _lxr);

int lxr_lex(lexer_s* _lxr);
int lxr_lex_file(lexer_s* _lxr);
void lxr_lex_line(lexer_s* _lxr);

#endif // LEXER_PRIV_H