#include <stdio.h>
#include "./util.h"

int main(void)
{
    char *test = QuickAllocatedString("josha as da sd asd as dsa da sd sa dsa");
    free(test);

    StringArr *exploded_path = EveryoneExplodeNow("example arg arg arg --flag --flag", SPACE_CHAR);
    PrintStringArr(exploded_path);
    char **normal_char_array = StringArrToNormalStringArrShallow(exploded_path);
    for (int i = 0; i < exploded_path->num_strings; i++)
    {
        printf("%s\n", normal_char_array[i]);
    }
    free(normal_char_array);
    FreeStringArr(exploded_path);
    return 0;
}
