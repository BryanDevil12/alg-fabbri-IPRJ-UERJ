#include <gtest/gtest.h>
#include "../sort.h"
#include <cstring>

TEST(SortCharTest, SortsSimpleString) {
    char str[] = "hello";
    sortChar(str);
    ASSERT_STREQ(str, "ehllo");
}

TEST(SortCharTest, HandlesEmptyArray) {
    char str[] = "";
    sortChar(str);
    ASSERT_STREQ(str, "");
}

TEST(SortCharTest, HandlesSingleElementArray) {
    char str[] = "a";
    sortChar(str);
    ASSERT_STREQ(str, "a");
}

TEST(SortCharTest, HandlesAlreadySorted) {
    char str[] = "abcde";
    sortChar(str);
    ASSERT_STREQ(str, "abcde");
}

TEST(SortCharTest, HandlesReverseSorted) {
    char str[] = "edcba";
    sortChar(str);
    ASSERT_STREQ(str, "abcde");
}

TEST(SortCharTest, SortsWithDuplicates) {
    char str[] = "hello world";
    sortChar(str);
    ASSERT_STREQ(str, " dehllloorw");
}

TEST(SortCharTest, SortsAllSameCharacters) {
    char str[] = "aaaaa";
    sortChar(str);
    ASSERT_STREQ(str, "aaaaa");
}
