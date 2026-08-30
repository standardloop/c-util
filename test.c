#include "./util.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testEveryoneExplodeNow()
{
    StringArr *test = EveryoneExplodeNow("the quick brown fox", SPACE_CHAR);
    assert(test != NULL);
    assert(test->num_strings == 4);
    assert(strcmp(test->strings[0], "the") == 0);
    assert(strcmp(test->strings[1], "quick") == 0);
    assert(strcmp(test->strings[2], "brown") == 0);
    assert(strcmp(test->strings[3], "fox") == 0);
    FreeStringArr(test);
}
void testEveryoneExplodeNowHandleQuotes()
{
    StringArr *test = EveryoneExplodeNowHandleQuotes(
        "git commit -m \"foo bar foo bar foo bar\"", SPACE_CHAR,
        DOUBLE_QUOTES_CHAR);
    assert(test != NULL);
    assert(test->num_strings == 4);
    assert(strcmp(test->strings[0], "git") == 0);
    assert(strcmp(test->strings[1], "commit") == 0);
    assert(strcmp(test->strings[2], "-m") == 0);
    assert(strcmp(test->strings[3], "\"foo bar foo bar foo bar\"") == 0);
    FreeStringArr(test);
}

void testExplode()
{
    testEveryoneExplodeNow();
    testEveryoneExplodeNowHandleQuotes();
}

void testGetEnv()
{
    const char *test = GetEnv("missing", "default");
    assert(test != NULL);
    assert(strcmp(test, "default") == 0);

    assert(setenv("MY_VAR", "testing", 1) == 0);
    const char *have = GetEnv("MY_VAR", "not needed");
    assert(have != NULL);
    assert(strcmp(have, "testing") == 0);
}

void testEnv()
{
    testGetEnv();
}

int main(void)
{
    testExplode();
    testEnv();
    return 0;
}
