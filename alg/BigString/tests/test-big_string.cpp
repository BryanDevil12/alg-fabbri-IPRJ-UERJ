/* R. Fabbri, 2024 */
#include <gtest/gtest.h>
#include <string.h>
#include "big_string.h"

TEST(BigStringTest, Concatenation) {
    const char* str1 = "Hello, ";
    const char* str2 = "world!";
    char out[14];

    bool res = big_string_cat(str1, str2, out);

    ASSERT_TRUE(res);
    ASSERT_STREQ(out, "Hello, world!");
}
