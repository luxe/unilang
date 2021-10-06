#include<iostream>
#include <iomanip>
#include "sqlite_modern_cpp.h"
#include "code/utilities/filesystem/paths/lib.hpp"
#include "code/utilities/data_structures/sql_hashset/sql_hashset.hpp"




int main() {

   try {
      
      
      
      
      //create
      Sql_Hashset_Settings settings;
      settings.name = "test_sql_db";
      settings.make_unique_name = false;
      settings.load_file = "/home/luxe/Desktop/some_addresses.txt";
      settings.file_persistence = Persistence::PERSISTENT;
      Sql_Hashset x(settings);
      
      
      
      
      
      //test
      std::cout << x.Size() << std::endl;
      std::cout << std::boolalpha << x.does_value_exist("24323424456") << std::endl;
      std::cout << std::boolalpha << x.does_value_exist("24323424456x") << std::endl;
      std::cout << std::boolalpha << x.does_value_exist("65767567") << std::endl;
      std::cout << std::boolalpha << x.does_value_exist("18VkRiDhFu2Z17AvtpU3vL2LbTXDzCvDV") << std::endl;
      
   }
      
   catch (std::exception& e) {
      std::cerr << e.what() << std::endl;
   }
}


