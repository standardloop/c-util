#include <stdio.h>
#include "./util.h"

int main(void)
{
    char *test = QuickAllocatedString("josha as da sd asd as dsa da sd sa dsa");
    free(test);

    StringArr *exploded_path = EveryoneExplodeNow("example arg arg arg --flag --flag", SPACE_CHAR);
    PrintStringArr(exploded_path);
    return 0;
}
