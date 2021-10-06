// this program downloads c++ files from ideone and pastebin.
// It attempts to compile them before keeping them.  Multiple threads
// are involved in downloading,  testing,  organizing,  and deleting these files.

// STD HEADERS
#include <vector>
#include <cstdlib>

// MY HEADERS
#include "global.hpp"
#include "website.hpp"   /* enum class */
#include "web_feed.hpp"
#include "feed_reader.hpp"
#include "thread_starter.hpp"

//function declarations
auto Create_Feed_Readers() -> std::vector<Feed_Reader>;

int main() {
	try {
		
		//create a list of online feed readers
		auto feed_readers = Create_Feed_Readers();

		//this function runs forever, so just kill the process to end it
		Thread_Starter::Run_The_Never_Ending_Threads(feed_readers);
	}
	
	//an exception here has never been caught in my testing
	catch(...){
		std::cerr << "Exception Thrown!" << std::endl;
	}

	//main should not end
	return EXIT_FAILURE;
}

//function definitions
auto Create_Feed_Readers() -> std::vector<Feed_Reader>{

	//avoid scoping on feed reader parameters
	using namespace constant;

	//a list of "public source code pasting" feed readers.
	//(web feed) (starting delay between reads)
	std::vector<Feed_Reader> feed_readers{
	  Feed_Reader(IDEONE_CPP_11_FEED         , IDEONE_CPP_11_FEED_START_DELAY         )
	, Feed_Reader(IDEONE_CPP_4_8_1_FEED      , IDEONE_CPP_4_8_1_FEED_START_DELAY      )
	, Feed_Reader(IDEONE_CPP_4_3_2_FEED      , IDEONE_CPP_4_3_2_FEED_START_DELAY      )
	, Feed_Reader(PASTE_BIN_CPP_FEED         , PASTE_BIN_CPP_FEED_START_DELAY         )
    , Feed_Reader(PASTE_BIN_CPP_WITH_QT_FEED , PASTE_BIN_CPP_WITH_QT_FEED_START_DELAY )
	};

	return feed_readers;
}

