#include <stdio.h>
#include <stdlib.h>
#include "./util.h"

int main(void)
{
    // char *test = QuickAllocatedString("josha as da sd asd as dsa da sd sa dsa");
    // printf("%s\n", test);
    // free(test);

    StringArr *exploded_path = EveryoneExplodeNowHandleQuotes("git commit -m \"foo bar foo bar foo bar\"", SPACE_CHAR, DOUBLE_QUOTES_CHAR);
    if (exploded_path == NULL)
    {
        printf("??\n");
    }
    PrintStringArr(exploded_path);
    FreeStringArr(exploded_path);
    return 0;
}
