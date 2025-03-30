#include <stdio.h>
#include "./util.h"

int main(void)
{
    char *test = QuickAllocatedString("josha as da sd asd as dsa da sd sa dsa");
    free(test);

    StringArr *exploded_path = EveryoneExplodeNow("asdsad  asd  asdasda sdas dasd a a a a a a", SPACE_CHAR);
    FreeStringArr(exploded_path);

    return 0;
}
