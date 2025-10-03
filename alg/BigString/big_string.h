/* R. Fabbri, 2024 */
#ifndef BIG_STRING_H
#define BIG_STRING_H

#include <stdbool.h>



bool
big_string_cat(
    const char *str1, 
    const char *str2, 
    char *out
    );

#endif 
