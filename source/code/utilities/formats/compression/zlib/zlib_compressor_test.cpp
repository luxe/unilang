#include "gtest/gtest.h"
#include "code/utilities/formats/compression/zlib/zlib_compressor.hpp"

TEST(TestGeneration, Zlib) {
  
  //what is compressed size?
  EXPECT_EQ(std::string("hello world").size(),11);
  EXPECT_EQ(Zlib_Compressor::Compress("hello world").size(),19);
  
  
  EXPECT_EQ(std::string("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa").size(),102);
  EXPECT_EQ(Zlib_Compressor::Compress("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa").size(),12);
  
  //does it compress to something different?
  EXPECT_NE(Zlib_Compressor::Compress("hello world"),"hello world");
  
  //is it idempotent?
  EXPECT_EQ(Zlib_Compressor::Decompress(Zlib_Compressor::Compress("hello world")),"hello world");
  
}

