/**
 * @file util.h
 * @headerfile util.h <standardloop/util.h>
 * @brief A C library random utility functions.
 */

#ifndef STANDARDLOOP_UTIL_H
#define STANDARDLOOP_UTIL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @cond INTERNAL
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
#define SINGLE_QUOTES_CHAR '\''

#define BACKSLASH_CHAR '\\'
#define FORWARDLASH_CHAR '/'

#define BRACKET_OPEN_CHAR '['
#define BRACKET_CLOSE_CHAR ']'

#define CURLY_OPEN_CHAR '{'
#define CURLY_CLOSE_CHAR '}'

#define NULL_CHAR '\0'
#define EOT_CHAR 4

#define pass (void)0
/// @endcond

/// @cond INTERNAL
// ————————— TEMP START —————————
// TODO: combine these 3 functions after library is built
extern void CopyString(char *, char *, size_t, size_t);
extern void CopyStringCanary(char *, char *, u_int64_t);
extern void CopyStringServer(char *, char *, size_t, size_t, bool);
/// @endcond

extern char *Int64ToString(int64_t);

extern char *QuickAllocatedString(char *);
extern void PrintSpaces(int);
extern void PrintBuffer(char *, size_t, bool);
// ————————— TEMP END —————————

// ————————— STRING HELPERS START —————————
extern void StringToLower(char *);
extern void StringToUpper(char *);
extern bool IsCharInString(const char *, char);
extern size_t NumCharInString(const char *, char);
extern char *PutQuotesAroundString(char *, bool);

/// @cond INTERNAL
extern void TestStringHelpers();
/// @endcond

// ————————— STRING HELPERS END —————————

// ————————— ENV START —————————
extern const char *GetEnv(char *, char *);
/// @cond INTERNAL
extern void TestEnv();
/// @endcond

// ————————— ENV END —————————

// ————————— REGEX START —————————
/// @cond INTERNAL
extern bool RegexBoolMatch(char *, char *);
extern char *RegexReturnMatch(char *, char *, int *, int *);
/// @endcond
// ————————— REGEX END —————————

// ————————— EXPLODE START —————————
/**
 * @brief The StringArr struct, contains an array of strings and the variable
 * holding the number of strings in the array.
 */
typedef struct
{
    /** The number of strings in the array. */
    int num_strings;
    /** The array of strings. */
    char **strings;
} StringArr;

/**
 * @brief Creates a StringArr based on an input string and a delimiter. For
 * example, `EveryoneExplodeNow("hello world", ' ')` will return `["hello",
 * "world"]`
 * @param input_str The input string.
 * @param delim What character to break the string about from.
 * @return The StringArr
 */
extern StringArr *EveryoneExplodeNow(char *input_str, char delim);

/**
 * @brief Creates a StringArr based on an input string and a delimiter. For
 * example, `EveryoneExplodeNow("hello world", ' ')` will return `["hello",
 * "world"]` but also handle quotes, so delim characters in quotes will not be
 * exploded
 * @param input_str The input string.
 * @param delim What character to break the string about from.
 * @param quotes_char Which quote character to ignore from.
 * @return The StringArr
 */
extern StringArr *EveryoneExplodeNowHandleQuotes(char *input_str, char delim,
                                                 char quotes_char);

/**
 * @brief Free all Strings inside a StringArr and the StringArr itself.
 * @param string_arr The StringArr to free.
 */
extern void FreeStringArr(StringArr *string_arr);
/**
 * @brief Pretty Print a StringArr for debugging.
 * @param string_arr The StringArr to print.
 */
extern void PrintStringArr(StringArr *string_arr);

/// @cond INTERNAL
extern void TestExplode();
/// @endcond
// ————————— EXPLODE END —————————

#endif
