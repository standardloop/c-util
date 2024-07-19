#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

#include "./util.h"

extern void PrintBuffer(char *buffer, size_t buffer_size, bool print_code)
{
    char *buffer_ptr = buffer;
    size_t i = 0;
    while (i < buffer_size && buffer_ptr != NULL)
    {
        if (print_code)
        {
            printf("%d ", *buffer_ptr);
        }
        else
        {
            printf("%c", *buffer_ptr);
        }

        i++;
        buffer_ptr++;
    }
}

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

extern char *QuickAllocatedString(char *copy)
{
    size_t true_len = strlen(copy) + 1;
    char *allocated_string = malloc(sizeof(char) * true_len);
    strcpy(allocated_string, copy);
    return allocated_string;
}

extern void PrintSpaces(int depth)
{
    for (int i = 0; i < depth; i++)
    {
        printf(" ");
    }
}

// TODO combine these 3 functions
extern void CopyString(char *src, char *des, size_t len, size_t src_offset)
{
    if (src == NULL || des == NULL || len <= 0)
    {
        return;
    }

    char *src_it = src + src_offset;
    size_t size = 0;
    while (size < len)
    {
        *des = *src_it;
        des++;
        src_it++;
        size++;
    }
}

extern void CopyStringCanary(char *des, char *src, u_int64_t des_offset)
{
    char *des_iterator = des + des_offset;

    while (src != NULL && *src != NULL_CHAR)
    {
        *des_iterator++ = *src++;
    }
}

extern void CopyStringServer(char *src, char *des, size_t len, size_t des_offset, bool lower)
{
    if (src == NULL || des == NULL || len <= 0)
    {
        return;
    }

    char *src_it = src;
    char *dest_it = des + des_offset;
    size_t size = 0;
    while (size < len)
    {
        if (lower)
        {
            *dest_it = tolower(*src_it);
        }
        else
        {
            *dest_it = *src_it;
        }

        dest_it++;
        src_it++;
        size++;
    }
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
