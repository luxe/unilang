#pragma once
#include "web_feed.hpp"
#include "utilities.hpp"

namespace constant{

	//+--------------------+
	//| WEB FEED CONSTANTS |
	//+--------------------+
	const auto IDEONE_CPP_11_FEED         =Web_Feed("c++11"     , Website::IDEONE    , "http://ideone.com/recent/44-cpp"    );
	const auto IDEONE_CPP_4_8_1_FEED      =Web_Feed("c++4.8.1"  , Website::IDEONE    , "http://ideone.com/recent/1-cpp"     );
	const auto IDEONE_CPP_4_3_2_FEED      =Web_Feed("c++4.3.2"  , Website::IDEONE    , "http://ideone.com/recent/41-cpp"    );
	const auto PASTE_BIN_CPP_FEED         =Web_Feed("c++"       , Website::PASTE_BIN , "http://pastebin.com/archive/cpp"    );
	const auto PASTE_BIN_CPP_WITH_QT_FEED =Web_Feed("c++-qt"    , Website::PASTE_BIN , "http://pastebin.com/archive/cpp-qt" );

	//+--------------------+
	//| DELAY CONSTANTS    |
	//+--------------------+
	//starting feed delay constants.
	//these values may change part way through the program,  and that is why they are saved and pulled from files
	//feed delays are expressed in seconds
	const auto IDEONE_CPP_11_FEED_START_DELAY         =Get_Unsigned_Int_From_File("src/getter-src/data/IDEONE_CPP_11_FEED_START_DELAY.constant"         );
	const auto IDEONE_CPP_4_8_1_FEED_START_DELAY      =Get_Unsigned_Int_From_File("src/getter-src/data/IDEONE_CPP_4_8_1_FEED_START_DELAY.constant"      );
	const auto IDEONE_CPP_4_3_2_FEED_START_DELAY      =Get_Unsigned_Int_From_File("src/getter-src/data/IDEONE_CPP_4_3_2_FEED_START_DELAY.constant"      );
	const auto PASTE_BIN_CPP_FEED_START_DELAY         =Get_Unsigned_Int_From_File("src/getter-src/data/PASTE_BIN_CPP_FEED_START_DELAY.constant"         );
	const auto PASTE_BIN_CPP_WITH_QT_FEED_START_DELAY =Get_Unsigned_Int_From_File("src/getter-src/data/PASTE_BIN_CPP_WITH_QT_FEED_START_DELAY.constant" );

	//delays expressed in minutes
	constexpr unsigned int DELAY_BETWEEN_COMMITS{60};
	constexpr unsigned int DELAY_BETWEEN_DELETES{60};
	constexpr unsigned int DELAY_BETWEEN_STAGES{5};

	//+--------------------+
	//| BUILD CONSTANTS    |
	//+--------------------+
	//lanaguage standards to compile against when trying to stage files
	const std::vector<std::string> language_standards
	{ "c++98"
	, "gnu++98"
	, "c++0x"
	, "gnu++0x"
	, "c++11"
	, "gnu++11"
	, "c++1y"
	//, "c++14"
	};

	//libraries to compile against when trying to stage files
	//doing combinations of a ton of libraries might prove impossible if the
	//number of combinations are too large.  Might have to think of a better solution
	const std::vector<std::string> linkable_libraries
	{
		"pthread"
		//"boost_program_options"
		//"boost_filesystem"
		//"boost_system"
	};

	//+------------------------+
	//| DIRECTORY CONSTANTS    |
	//+------------------------+
	const std::string TESTING_DIRECTORY = "Downloaded/Testing/";
	const std::string DELETED_DIRECTORY = "Downloaded/Deleted/";
		const std::string NOT_COMPILED_DIRECTORY = "Downloaded/Deleted/no_compile/";
		const std::string NOT_INTERESTING_DIRECTORY = "Downloaded/Deleted/not_interesting/";
	const std::string STAGED_DIRECTORY = "Downloaded/Staged/";

	//+------------------------+
	//| FILE CONSTANTS         |
	//+------------------------+
	const std::string IDEONE_API_USERNAME =
	#include "data/private/ideone_username.hpp"
	;

	const std::string IDEONE_API_PASSWORD =
	#include "data/private/ideone_password.hpp"
	;

	const std::string PASTE_BIN_API_USERNAME =
	#include "data/private/paste_bin_username.hpp"
	;

	const std::string PASTE_BIN_API_PASSWORD =
	#include "data/private/paste_bin_password.hpp"
	;
	
	const std::string DELETED_NOT_BUILDABLE = "stats/deleted_not_buildable";
	const std::string DELETED_NOT_INTERESTING = "stats/deleted_not_interesting";
	const std::string KEPT = "stats/kept";

	const std::string INFO_DUMP_DIRECTORY = "src/getter-src/data/info_dump/ideone/";
	const std::string DUMP_OF_SOURCE_CODE = INFO_DUMP_DIRECTORY + "source_code";
	const std::string DUMP_OF_STDIN = INFO_DUMP_DIRECTORY  + "stdin"  ;
	const std::string DUMP_OF_STDOUT = INFO_DUMP_DIRECTORY + "stdout" ;
	const std::string DUMP_OF_STDERR = INFO_DUMP_DIRECTORY + "stderr" ;
	const std::string DUMP_OF_ERROR = INFO_DUMP_DIRECTORY  + "error"  ;
	const std::string DUMP_OF_STATUS = INFO_DUMP_DIRECTORY + "status" ;
	const std::string DUMP_OF_SIGNAL = INFO_DUMP_DIRECTORY + "signal" ;
	const std::string DUMP_OF_RESULT = INFO_DUMP_DIRECTORY + "result" ;
	
	//+------------------------+
	//| IDEONE API PULLER      |
	//+------------------------+
	const std::string IDEONE_API_PULLER = "src/getter-src/dump_all_ideone.py ";


}
