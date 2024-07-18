#ifndef STANDARDLOOP_UTIL_H
#define STANDARDLOOP_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALWAYS 1

#define QUESTION_CHAR '?'
#define EQUAL_CHAR '='
#define AND_CHAR '&'
#define DOLLAR_CHAR '$'
#define CARROT_CHAR '^'

#define SPACE_CHAR ' '
#define TAB_CHAR '\t'
#define NEWLINE_CHAR '\n'
#define CARRIAGE_CHAR '\r'
#define DASH_MINUS_CHAR '-'
#define PLUS_CHAR '+'

#define DOT_CHAR '.'
#define COMMA_CHAR ','
#define COLON_CHAR ':'

#define DOUBLE_QUOTES_CHAR '\"'

#define BACKSLASH_CHAR '\\'
#define FORWARDLASH_CHAR '/'

#define BRACKET_OPEN_CHAR '['
#define BRACKET_CLOSE_CHAR ']'

#define CURLY_OPEN_CHAR '{'
#define CURLY_CLOSE_CHAR '}'

#define NULL_CHAR '\0'

#define pass (void)0

// ————————— UTIL START —————————
// TODO: combine these 3 functions after library is built
extern void CopyString(char *, char *, size_t, size_t);
extern void CopyStringCanary(char *, char *, u_int64_t);
extern void CopyStringServer(char *, char *, size_t, size_t, bool);

extern bool IsCharInString(const char *, char);
extern size_t NumCharInString(const char *, char);
extern char *QuickAllocatedString(char *);
extern void PrintSpaces(int);
extern void PrintBuffer(char *, size_t, bool);

extern void StringToLower(char *);
extern void StringToUpper(char *);
// ————————— UTIL END —————————

// ————————— ENV START —————————
extern const char *GetEnv(char *, char *);
// ————————— ENV END —————————

// ————————— REGEX START —————————
extern bool RegexBoolMatch(char *, char *);
extern char *RegexReturnMatch(char *, char *, int *, int *);
// ————————— REGEX END —————————

// ————————— EXPLODE START —————————
typedef struct
{
    char **strings;
    int num_strings;
} StringArr;

extern StringArr *EveryoneExplodeNow(char *, char);
extern void FreeStringArr(StringArr *);
extern void PrintStringArr(StringArr *);
// ————————— EXPLODE END —————————

#endif
