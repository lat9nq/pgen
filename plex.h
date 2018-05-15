#ifndef PLEX_H
#define PLEX_H

#include <unistd.h>
#include <sys/types.h>

#include "plex_t.h"

typedef struct plex_token {
	char * lexeme;
	plex_t type;
} plex_token_t;

plex_token_t * plex_token_init();
void plex_token_destroy(plex_token_t * token);



plex_token_t * plex(int fd);

#endif
