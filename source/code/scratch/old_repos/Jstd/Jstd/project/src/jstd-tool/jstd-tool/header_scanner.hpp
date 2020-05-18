#include <iostream>
#include <string>
#include <vector>
#include "warn_machine.hpp"
#include "scan_stats.hpp"

class Header_Scanner {

public:
	static bool Scan(Warn_Machine & warn_machine);

private:
	static bool Complain_About_Header_Duplicates(Warn_Machine & warn_machine, std::vector<std::string> const& header_lines,std::string const& file_name);
	static bool Complain_About_Source_Duplicates(Warn_Machine & warn_machine, std::vector<std::string> const& header_lines, std::vector<std::string> const& source_lines,std::string const& file_name);
  };
