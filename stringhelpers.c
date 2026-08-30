#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./util.h"

extern bool IsCharInString(const char *input_str, char checker)
{
    while (*input_str != NULL_CHAR)
    {
        if (*input_str == checker)
        {
            return true;
        }
        input_str++;
    }
    return false;
}

extern size_t NumCharInString(const char *input_str, char checker)
{
    size_t count = 0;
    while (*input_str != NULL_CHAR)
    {
        if (*input_str == checker)
        {
            count++;
        }
        input_str++;
    }
    return count;
}

// I made this function before I knew about strdup
// I want to deprecate this in favor of that
extern char *QuickAllocatedString(char *copy)
{
    if (copy == NULL)
    {
        return NULL;
    }
    size_t true_len = strlen(copy) + 1;
    char *allocated_string = malloc(sizeof(char) * true_len);
    if (allocated_string == NULL)
    {
        return NULL;
    }

    strcpy(allocated_string, copy);
    return allocated_string;
}

extern void StringToLower(char *s)
{
    for (; *s; ++s)
    {
        *s = tolower(*s);
    }
}
extern void StringToUpper(char *s)
{
    for (; *s; ++s)
    {
        *s = toupper(*s);
    }
}

extern char *PutQuotesAroundString(char *input_str, bool free_input)
{
    if (input_str == NULL)
    {
        return NULL;
    }
    size_t input_str_real_len = strlen(input_str) + 1;
    size_t new_str_len = input_str_real_len + 2;
    char *new_string = malloc(sizeof(char) * new_str_len);
    new_string[0] = DOUBLE_QUOTES_CHAR;

    for (size_t i = 0; i < input_str_real_len - 1; i++)
    {
        new_string[i + 1] = input_str[i];
    }
    new_string[new_str_len - 2] = DOUBLE_QUOTES_CHAR;
    new_string[new_str_len - 1] = NULL_CHAR;
    if (free_input)
    {
        free(input_str);
    }

    return new_string;
}
