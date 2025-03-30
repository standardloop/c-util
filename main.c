#include <stdio.h>
#include "./util.h"

int main(void)
{
    char *test = QuickAllocatedString("josha as da sd asd as dsa da sd sa dsa");
    printf("%s\n", test);
    free(test);

    StringArr *exploded_path = EveryoneExplodeNow(QuickAllocatedString("aayyayayyaya yayyaya y aya yay ayyaya "), SPACE_CHAR);
    PrintStringArr(exploded_path);
    FreeStringArr(exploded_path);

    return 0;
}
