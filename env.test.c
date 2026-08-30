#include "./util.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void testGetEnv()
{
    const char *test = GetEnv("missing", "default");
    assert(test != NULL);
    assert(strcmp(test, "default") == 0);

    assert(setenv("MY_VAR", "testing", 1) == 0);
    const char *have = GetEnv("MY_VAR", "not needed");
    assert(have != NULL);
    assert(strcmp(have, "testing") == 0);
}

extern void TestEnv()
{
    testGetEnv();
}
