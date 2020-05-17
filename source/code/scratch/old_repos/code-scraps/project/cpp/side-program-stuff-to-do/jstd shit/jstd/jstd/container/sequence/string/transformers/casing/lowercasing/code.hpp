<----------------------------START---------------------------->
attributes
<----DELIM---->
templated
<----DELIM---->
std::string&
std::string&
str
<----DELIM---->
#mutate# <string> (to|into|) (lower|lowercase|undercase)
<mutate> (to|into|) (lower|lowercase|undercase) <string>
<mutate> (to|into|) (lower|lowercase|undercase) (the|this) #string#
<mutate> (to|into|) (lower|lowercase|undercase) (the|this|) (specified|indicated|passed in|given) #string#
<----DELIM---->
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}
<----DELIM---->
raw adds
raw adds
<----DELIM---->
raw deletes
raw deletes
<----DELIM---->
function base
<-----------------------------END----------------------------->