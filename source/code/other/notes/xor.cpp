#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

//EN5 messages are encoded by:
// - first creating the base message.
// - xoring the string for a checksum
// - wrapping the base in delimeters and appending the checksum
// From what I can tell, EuroNav is lenient on spaces and casing.
// A verified example would be (89,-18,20,0) -> "$PEANF,89,-18,20,0,,,,*4B"

//applied to the base string of a EN5 message
int XorCheckSum(std::string const& s){
  int x = 0;
  for (auto const& it: s){
    x ^= it;
  }
  return x;
}

//convert the checksum to a printable string for message transmit
std::string AsHexString(int c){
  std::ostringstream s;
  s << std::hex << std::uppercase << c;
  return s.str();
}

std::string EncodeCameraMessage(int azimuth, int elevation, int openingAngle, int sensor){
  
  //the base string of the EuroNav Camera Slew message
  std::string base = "PEANF," 
  + std::to_string(azimuth) + "," 
  + std::to_string(elevation) + "," 
  + std::to_string(openingAngle) + "," 
  + std::to_string(sensor) + ",,,,";
  
  //the checksum of the base message
  unsigned char checksum = XorCheckSum(base);
  
  //combine base with checksum for entire message
  return "$" + base + "*" + AsHexString(checksum);
}

int main(){
std::cout << EncodeCameraMessage(89,-18,20,0) << std::endl;


}  

