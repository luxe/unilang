#include "gtest/gtest.h"
#include "code/transcompilers/unilang/tokens/get_tokens.hpp"
#include "code/transcompilers/unilang/tokens/uniqueness/unique_tokens_checker.hpp"

TEST(Unilang_Tokens, Are_Unique) {
    
    auto tokens = Get_Tokens::Get();
    EXPECT_TRUE(Unique_Tokens_Checker::All_Token_Characters_Are_Unique(tokens));
}

