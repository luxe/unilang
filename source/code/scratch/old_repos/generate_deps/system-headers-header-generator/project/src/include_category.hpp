#include <string>
#include <vector>

class Include_Category{

	public:

	//constructor
	Include_Category(std::string const& name_in,std::vector<std::string> const& lines_in);

	//observers
	std::vector<std::string> Lines() const;
	std::string Name() const;

	private:

	//data members
	std::string name;
	std::vector<std::string> lines;
};
