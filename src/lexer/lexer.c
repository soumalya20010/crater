#include <stdlib.h>
#include <stdio.h>

#include "lexer_defs.h"
#include "lexer_priv.h"
#include "lexer.h"


#define BUFFER_SIZE 256


int lxr_lex(lexer_s* _lxr) {
    if(!lxr_alloc_buffer(_lxr)) {
        printf("Error: Failed to allocate buffer\n");
        return 0;
    }

    return lxr_lex_file(_lxr);
}

int lxr_lex_file(lexer_s* _lxr) {
    FILE* __fp = fopen(_lxr->filepath, "r");
    if(!__fp) {
        printf("Error: Failed to open file '%s'\n", _lxr->filepath);
        return 0;
    }

    while(fgets(_lxr->buffer, BUFFER_SIZE, __fp)) {
        printf("%s", _lxr->buffer);
    }

    fclose(__fp);
    return 1;
}

void lxr_lex_line(lexer_s* _lxr) {
int lxr_alloc_buffer(lexer_s* _lxr) {
    if(_lxr->buffer_live) return 1;

    _lxr->buffer = malloc(sizeof(char) * BUFFER_SIZE);
    if(!_lxr->buffer) return 0;

    _lxr->buffer_live = 1;
    return 1;
}

void lxr_dealloc_buffer(lexer_s* _lxr) {
    if(!_lxr->buffer_live) return;

    free(_lxr->buffer);
    _lxr->buffer_live = 0;
}

void lxr_init(lexer_s* _lxr) {
    _lxr->filepath = NULL;
    _lxr->buffer = NULL;
    _lxr->buffer_live = 0;
    _lxr->lex = &lxr_lex;
}

lexer_s* new_lexer(void) {
    lexer_s* lexer = malloc(sizeof(*lexer));
    if(!lexer) return NULL;

    lxr_init(lexer);
    return lexer;
}

void delete_lexer(lexer_s* _lxr) {
    lxr_dealloc_buffer(_lxr);
    free(_lxr);
}