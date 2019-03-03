#include "gtest/gtest.h"
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include "cereal/archives/binary.hpp"
#define _LIBCPP_ENABLE_CXX17_REMOVED_AUTO_PTR
#define BOOST_NO_AUTO_PTR
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

TEST(HelloTest, CerealInt) {
	
	std::stringstream ss;
	{
		cereal::BinaryOutputArchive oarchive(ss);
		int i = 5;
		oarchive(i);
	}
	{
		cereal::BinaryInputArchive iarchive(ss);
		int i = 0;
		iarchive(i);
		EXPECT_EQ(i,5);
	}
}

TEST(HelloTest, BoostInt) {
	
	std::stringstream ss;
	{
		boost::archive::text_oarchive oarchive(ss);
		int i = 5;
		oarchive << i;
	}
	{
		boost::archive::text_iarchive iarchive(ss);
		int i = 0;
		iarchive >> i;
		EXPECT_EQ(i,5);
	}
}

