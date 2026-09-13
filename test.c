#include "./util.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    printf("starting tests\n");
    TestExplode();
    TestEnv();
    TestStringHelpers();
    printf("done!\n");
    return 0;
}
