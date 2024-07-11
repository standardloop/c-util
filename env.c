#include <stdlib.h>

#include "./util.h"

extern const char *GetEnv(char *name, char *fallback)
{
    const char *env_var = getenv(name);
    if (env_var == NULL)
    {
        return fallback;
    }
    return env_var;
}
