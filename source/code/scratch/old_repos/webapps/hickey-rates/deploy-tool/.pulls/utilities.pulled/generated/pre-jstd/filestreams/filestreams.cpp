//file stream functions
std::vector<std::vector<std::string>> Get_And_Parse_Each_Line_Of_File(std::string const& file) {

	std::ifstream infile(file);
	std::string line;
	std::string part;
	std::vector<std::string> parts;
	std::vector<std::vector<std::string>> all_lines;
	std::getline(infile, line);
	while (infile) {

		//parse and store
		bool c_found = false;
		bool in_string = false;
		for (auto const& c: line) {

			//if we have a character or a space inside a string
			if (c != ' '  || in_string) {


				// record the start or end of a string
				if (c == '"') {
					if (in_string) {
						in_string = false;
					}else{
						in_string = true;
					}
				}else{

					//store the other non quote characters
					c_found = true;
					part += c;
				}

			}else{
				if (c_found) {
					parts.push_back(part);
					c_found = false;
					part.clear();
				}
			}
		}

		if (!part.empty()) {
			parts.push_back(part);
			c_found = false;
			part.clear();
		}

		all_lines.push_back(parts);
		parts.clear();


		std::getline(infile, line);
	}

	return all_lines;
}
std::vector<std::vector<std::string>> Continue_Getting_And_Parsing_Each_Line_Of_File(std::ifstream & infile) {

	std::string line;
	std::string part;
	std::vector<std::string> parts;
	std::vector<std::vector<std::string>> all_lines;
	std::getline(infile, line);
	while (infile) {

		//parse and store
		bool c_found = false;
		bool in_string = false;
		for (auto const& c: line) {

			//if we have a character or a space inside a string
			if (c != ' '  || in_string) {


				// record the start or end of a string
				if (c == '"') {
					if (in_string) {
						in_string = false;
					}else{
						in_string = true;
					}
				}else{

					//store the other non quote characters
					c_found = true;
					part += c;
				}

			}else{
				if (c_found) {
					parts.push_back(part);
					c_found = false;
					part.clear();
				}
			}
		}

		if (!part.empty()) {
			parts.push_back(part);
			c_found = false;
			part.clear();
		}

		all_lines.push_back(parts);
		parts.clear();


		std::getline(infile, line);
	}

	return all_lines;
}
