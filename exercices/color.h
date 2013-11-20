#ifndef __COLOR_H__
#define __COLOR_H__

#define VERSION     1.1

#define FG_BLACK    "\033[0;30m"
#define FG_RED      "\033[0;31m"
#define FG_GREEN    "\033[0;32m"
#define FG_YELLOW   "\033[0;33m"
#define FG_BLUE     "\033[0;34m"
#define FG_MAGENTA  "\033[0;35m"
#define FG_CYAN     "\033[0;36m"
#define FG_WHITE    "\033[0;37m"

#define FG_LTBLACK   "\033[1;30m"
#define FG_LTRED     "\033[1;31m"
#define FG_LTGREEN   "\033[1;32m"
#define FG_LTYELLOW  "\033[1;33m"
#define FG_LTBLUE    "\033[1;34m"
#define FG_LTMAGENTA "\033[1;35m"
#define FG_LTCYAN    "\033[1;36m"
#define FG_LTWHITE   "\033[1;37m"

#define BG_BLACK    "\033[0;40m"
#define BG_RED      "\033[0;41m"
#define BG_GREEN    "\033[0;42m"
#define BG_YELLOW   "\033[0;43m"
#define BG_BLUE     "\033[0;44m"
#define BG_MAGENTA  "\033[0;45m"
#define BG_CYAN     "\033[0;46m"
#define BG_WHITE    "\033[0;47m"

#define FG_BOLD     "\033[1m"
#define FG_UL       "\033[4m"
#define NOCOLOR     "\033[0m"

/**
 * Essai pour combiner les couleurs.
 * Utiliser plutôt au-dessus
 */

#define COLOR "\033["
#define AND ";"
#define END "m"
#define RED "31"
#define BGREEN "42"
#define BOLD "1"
#define UNDER "4"
#define CLIGN "5"

#endif
