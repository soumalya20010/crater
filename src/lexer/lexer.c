#include <stdlib.h>

#include "lexer_priv.h"
#include "lexer.h"


#define BUFFER_SIZE 256


void lxr_init(lexer_t* _lxr) {
    _lxr->filepath = NULL;
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