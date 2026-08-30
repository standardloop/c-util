#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./util.h"

static int32_t numberOfDigitsInInt64(int64_t);

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

extern void CopyStringServer(char *src, char *des, size_t len,
                             size_t des_offset, bool lower)
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

static int32_t numberOfDigitsInInt64(int64_t num)
{
    int32_t r = 1;
    if (num < 0)
    {
        num = (num == LLONG_MIN) ? LLONG_MAX : -num;
    }
    while (num > 9)
    {
        num /= 10;
        r++;
    }
    return r;
}

extern char *Int64ToString(int64_t num)
{
    int32_t num_digits = numberOfDigitsInInt64(num);
    if (num < 0)
    {
        num_digits++;
    }
    char *int64_as_string = malloc(sizeof(char) * (num_digits + 1));

    char *ptr = int64_as_string;
    char *ptr1 = int64_as_string;
    char tmp_char = NULL_CHAR;

    int64_t tmp_value = 0;
    do
    {
        tmp_value = num;
        num /= 10;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnop"
                 "qrstuvwxyz"[35 + (tmp_value - num * 10)];
    } while (num);

    if (tmp_value < 0)
    {
        *ptr++ = '-';
    }
    *ptr-- = '\0';

    while (ptr1 < ptr)
    {
        tmp_char = *ptr;
        *ptr-- = *ptr1;
        *ptr1++ = tmp_char;
    }
    return int64_as_string;
}
