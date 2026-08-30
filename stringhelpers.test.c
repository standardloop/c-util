#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./util.h"

static void testIsCharInString()
{
    assert(IsCharInString("test", 't') == true);
    assert(IsCharInString("test", 'x') == false);
}

static void testNumCharInString()
{
    assert(NumCharInString("aa", 'a') == 2);
    assert(NumCharInString("aa", 'b') == 0);
    assert(NumCharInString("testing testing 123", SPACE_CHAR) == 2);

    // TODO test for NULL_CHAR
}

static void testStringToLower()
{
    char *test = QuickAllocatedString("HI");
    StringToLower(test);
    assert(strcmp("hi", test) == 0);
}

static void testStringToUpper()
{
    char *test = QuickAllocatedString("hi");
    StringToUpper(test);
    assert(strcmp("HI", test) == 0);
    free(test);
}

static void testPutQuotesAroundString()
{
    char *test = "example";
    char *test_w_quotes = PutQuotesAroundString(test, false);

    assert(strcmp(test_w_quotes, "\"example\"") == 0);
}

extern void TestStringHelpers()
{
    testIsCharInString();
    testNumCharInString();
    testStringToLower();
    testStringToUpper();
    testPutQuotesAroundString();
}
