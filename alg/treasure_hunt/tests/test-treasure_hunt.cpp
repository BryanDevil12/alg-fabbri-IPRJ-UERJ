/* R. Fabbri, 2024 */
#include <gtest/gtest.h>
#include "treasure_hunt.h"

TEST(TreasureHuntTest, WorldCreation) {
    No* mundo = criar_mundo();
    ASSERT_TRUE(mundo != NULL);
    ASSERT_STREQ(mundo->nome, "Inicio 1");
    destruir_mundo(mundo);
}

TEST(TreasureHuntTest, Busca) {
    No* mundo = criar_mundo();
    No* boss = mundo->busca((char*)"Boss", mundo);
    ASSERT_TRUE(boss != NULL);
    ASSERT_STREQ(boss->nome, "Boss");
    destruir_mundo(mundo);
}
