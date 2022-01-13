#include <stdlib.h>
#include <stdio.h>

#include "config.h"
#include "lexer_defs.h"
#include "lexer_priv.h"
#include "lexer.h"


#define BUFFER_SIZE 256

#define CURR_CHAR   _lxr->buffer[_lxr->offset]
#define RST_COL     _lxr->offset = 0; _lxr->col = 1
#define INC_LINE    _lxr->line++; RST_COL
#define INC_COL     _lxr->offset++; _lxr->col++


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
        lxr_lex_line(_lxr);
    }

    fclose(__fp);
    return 1;
}

void lxr_lex_line(lexer_s* _lxr) {
    do {
        if(CURR_CHAR == '\n') {
#if DEBUG_MODE
            printf("{char: \'\\n\', line: %d, col: %d, offset: %d}\n\n",
                _lxr->line, _lxr->col, _lxr->offset
            );
#endif // DEBUG_MODE
            INC_LINE;
            return;
        }

#if DEBUG_MODE
            printf("{char: \'%c', line: %d, col: %d, offset: %d}\n",
                CURR_CHAR, _lxr->line, _lxr->col, _lxr->offset
            );
#endif // DEBUG_MODE
        // todo: collect tokens
        INC_COL;
    } while(CURR_CHAR);
}

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
    _lxr->offset = 0;
    _lxr->line = 1;
    _lxr->col = 1;
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