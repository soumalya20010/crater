#include <stdlib.h>

#include "lexer_priv.h"
#include "lexer.h"


#define BUFFER_SIZE 256


int lxr_alloc_buffer(lexer_t* _lxr) {
    if(_lxr->buffer_live) return 1;

    _lxr->buffer = malloc(sizeof(char) * BUFFER_SIZE);
    if(!_lxr->buffer) return 0;

    _lxr->buffer_live = 1;
    return 1;
}

void lxr_dealloc_buffer(lexer_t* _lxr) {
    if(!_lxr->buffer_live) return;

    free(_lxr->buffer);
    _lxr->buffer_live = 0;
}

void lxr_init(lexer_t* _lxr) {
    _lxr->filepath = NULL;
    _lxr->buffer = NULL;
    _lxr->buffer_live = 0;
    _lxr->lex = &lxr_lex;
}

lexer_t* new_lexer(void) {
    lexer_t* lexer = malloc(sizeof(*lexer));
    if(!lexer) return NULL;

    lxr_init(lexer);
    return lexer;
}

void delete_lexer(lexer_t* _lxr) {
    free(_lxr);
}