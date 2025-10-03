/* R. Fabbri, 2024 */
#include "big_string.h"
#include <string.h>

bool
big_string_cat(
    const char *str1, 
    const char *str2, 
    char *out
    )
{
    strcpy(out, str1);
    strcat(out, str2);
    return true;
}
