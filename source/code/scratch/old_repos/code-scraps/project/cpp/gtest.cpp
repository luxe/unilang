#include "gtest/gtest.h"

int stay (const int i){
    return i;
}
  

TEST(SquareRootTest, PositiveNos) { 
    EXPECT_EQ (18, stay (18));
    EXPECT_EQ (25, stay (25));
    EXPECT_EQ (3,  stay (3 ));
}

TEST (SquareRootTest, ZeroAndNegativeNos) { 
    ASSERT_EQ (0, stay (0));
    ASSERT_EQ (-1, stay (-1));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
