#include "plex.h"

plex_token_t * plex_token_init() {
	plex_token_t * ret = (plex_token_t *)malloc(sizeof(*ret));
	ret->lexeme = NULL;
	ret->type = T_ERR;

	return ret;
}

void plex_token_destroy(plex_token_t * token) {
	if (token == NULL)
		return;
	free(token);
}

plex_token_t * plex(int fd) {
	int accept = 0;
	int state  = 0;
	int consume = 1;

	char word[256];
	int v = 0;

	char c;

	while (!accept) {
		if (consume) {
			read(fd, &c, 1);

			word[v] = c;
			v++;
			word[v] = 0;
		}
		consume = 0;

		switch (state) {
			case 0:
				if (isalnum(c) || c == '_') {
					state = 1;
				}
				else if (c == '<')
					state = 3;
				else if (c == '>')
					state = 4;
				else if (c == ':') {
					consume = 1;
					state = 5;
				}
				else if (c == '=')
					state = 7;
				else if (c == '/')
					state = 8;
			break;
			case 1:
				if (isalnum(c) || c == '_') {
					consume = 1;
				}
				else {
					state = 2;
				}
			break;
			case 2:
				
			break;
		}
	}

}
