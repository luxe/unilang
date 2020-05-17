<----------------------------START---------------------------->
attributes
<----DELIM---->
templated
<----DELIM---->
std::string&
std::string&
str
<----DELIM---->
#mutate# <string> (to|into|) (upper|uppercase)
<mutate> (to|into|) (upper|uppercase) <string>
<mutate> (to|into|) (upper|uppercase) (the|this) #string#
<mutate> (to|into|) (upper|uppercase) (the|this|) (specified|indicated|passed in|given) #string#
<----DELIM---->
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
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