#include "code/utilities/types/strings/observers/hex/lib.hpp"
#include "boost/algorithm/hex.hpp"
#include <sstream>
#include <stdexcept>


std::vector<std::string> Get_All_2_Width_Hex_For_1_Byte(){
    unsigned char i = 0;
    std::vector<std::string> results;
    results.emplace_back("00");
    i++;
    while (i != 0){
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << (unsigned int)i;
        results.emplace_back(ss.str());
        ++i;
    }
    
    return results;
    
}
std::vector<std::string> Get_All_Hex_Chars(){
    std::vector<std::string> x;
    x.emplace_back("0");
    x.emplace_back("1");
    x.emplace_back("2");
    x.emplace_back("3");
    x.emplace_back("4");
    x.emplace_back("5");
    x.emplace_back("6");
    x.emplace_back("7");
    x.emplace_back("8");
    x.emplace_back("9");
    x.emplace_back("A");
    x.emplace_back("B");
    x.emplace_back("C");
    x.emplace_back("D");
    x.emplace_back("E");
    x.emplace_back("F");
    return x;
}

std::string AsHexString(int c){
  std::ostringstream s;
  s << std::hex << std::uppercase << c;
  return s.str();
}

std::string AsCapital2WidthHexString(int c){
  std::ostringstream s;
  s << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << c;
  return s.str();
}

std::string to_caps_hex(unsigned char *s){
    std::stringstream ss;
    for(int i=0; i<32; ++i)
        ss << std::hex << std::uppercase << (unsigned int)s[i];
    std::string mystr = ss.str();
    return mystr;
}

std::string to_caps_hex(std::string const& str){
    std::stringstream ss;
    for(int i=0; i<str.size(); ++i)
        ss << std::hex << std::uppercase << (unsigned int)str[i];
    std::string mystr = ss.str();
    return mystr;
}

std::string to_caps_hex_p2(std::string const& str){
    std::stringstream ss;
    for(int i=0; i<str.size(); ++i)
        ss << std::hex << std::setfill('0') << std::setw(2)  << static_cast<unsigned int>(static_cast<unsigned char>(str[i]));
    std::string mystr = ss.str();
    return mystr;
}

std::string unhex(std::string const& str){
    std::string new_str;
    boost::algorithm::unhex ( str, std::back_inserter (new_str));
    return new_str;
}

std::string string_to_hex(const std::string& input)
{
    static const char hex_digits[] = "0123456789ABCDEF";

    std::string output;
    output.reserve(input.length() * 2);
    for (unsigned char c : input)
    {
        output.push_back(hex_digits[c >> 4]);
        output.push_back(hex_digits[c & 15]);
    }
    return output;
}

int hex_value(unsigned char hex_digit)
{
    static const signed char hex_values[256] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
         0,  1,  2,  3,  4,  5,  6,  7,  8,  9, -1, -1, -1, -1, -1, -1,
        -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    };
    int value = hex_values[hex_digit];
    if (value == -1) throw std::invalid_argument("invalid hex digit");
    return value;
}

std::string hex_to_string(const std::string& input)
{
    const auto len = input.length();
    if (len & 1) throw std::invalid_argument(std::string("odd length= ") + std::to_string(input.length()) + "/" + std::to_string(input.size()));

    std::string output;
    output.reserve(len / 2);
    for (auto it = input.begin(); it != input.end(); )
    {
        int hi = hex_value(*it++);
        int lo = hex_value(*it++);
        output.push_back(hi << 4 | lo);
    }
    return output;
}


std::string hextobin(const std::string &s){
    std::string out;
    for(auto i: s){
        uint8_t n;
        if(i <= '9' and i >= '0')
            n = i - '0';
        else
            n = 10 + i - 'A';
        for(int8_t j = 3; j >= 0; --j)
            out.push_back((n & (1<<j))? '1':'0');
    }

    return out;
}

std::string bintohex(const std::string &s){
    std::string out;
    for(uint i = 0; i < s.size(); i += 4){
        int8_t n = 0;
        for(uint j = i; j < i + 4; ++j){
            n <<= 1;
            if(s[j] == '1')
                n |= 1;
        }

        if(n<=9)
            out.push_back('0' + n);
        else
            out.push_back('A' + n - 10);
    }

    return out;
}

std::string As_Caps_Hex_Reversed(std::string const& str){
        std::string result;
	for (auto const& it: str){
                  if (it == '0') { result += 'F';}
             else if (it == '1') { result += 'E';}
             else if (it == '2') { result += 'D';}
             else if (it == '3') { result += 'C';}
             else if (it == '4') { result += 'B';}
             else if (it == '5') { result += 'A';}
             else if (it == '6') { result += '9';}
             else if (it == '7') { result += '8';}
             else if (it == '8') { result += '7';}
             else if (it == '9') { result += '6';}
             else if (it == 'A') { result += '5';}
             else if (it == 'B') { result += '4';}
             else if (it == 'C') { result += '3';}
             else if (it == 'D') { result += '2';}
             else if (it == 'E') { result += '1';}
             else if (it == 'F') { result += '0';}
	}
        return result;
}