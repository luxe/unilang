
#pragma once
#include <string>
#include <unordered_map>

//TODO: include measurement information LENGTH,VELOCITY, etc
//we'll have to think about rates.
//also look at what the units tool does in linux.  It says:
//```
//Currency exchange rates from finance.yahoo.com on 2017-10-31 
//3045 units, 109 prefixes, 109 nonlinear units
//```
static const std::unordered_map<std::string,std::string> UNITS_TO_VARIABLE_SUFFIX_LOOKUP_TABLE

  //length
  {{"nanometers","nm"}
  ,{"micrometers","um"}
  ,{"millimeters","mm"}
  ,{"centimeters","cm"}
  ,{"decimeters","dm"}
  ,{"meters","m"}
  ,{"dekameters","dam"}
  ,{"hectometers","hm"}
  ,{"kilometers","km"}
  ,{"inches","in"}
  ,{"feet","ft"}
  ,{"yards","yd"}
  ,{"miles","mi"}
  ,{"nautical miles","nmi"}
  ,{"nautical leagues","n_leag"}
  ,{"fathoms","fath"}
  ,{"cable length","cbl"}
  
  //data transfer rate
  //bits
  ,{"bit / second","bts"}
  ,{"kilobit / second","kbts"}
  ,{"megabit / second","Mbts"}
  ,{"gigabit / second","Gbts"}
  ,{"terabit / second","Tbts"}
  ,{"kibibit / second","Kibts"}
  ,{"mebibit / second","Mibts"}
  ,{"gibibit / second","Gibts"}
  ,{"tebibit / second","Tibts"}
  ,{"petabit / second","Pibts"}
  ,{"pebibit / second","Pibts"}
  
  //byte
  ,{"byte / second","Bs"}
  ,{"kilobyte / second","KBs"}
  ,{"megabyte / second","MBs"}
  ,{"gigabyte / second","GBs"}
  ,{"terabyte / second","TBs"}
  ,{"kibibyte / second","KiBs"}
  ,{"mebibyte / second","MiBs"}
  ,{"gibibyte / second","GiBs"}
  ,{"tebibyte / second","TiBs"}
  ,{"petabyte / second","PiBs"}
  ,{"pebibyte / second","PiBs"}
  
  //digital storage
  //bits
  ,{"bit","b"}
  ,{"kilobit","kb"}
  ,{"megabit","Mb"}
  ,{"gigabit","Gb"}
  ,{"terabit","Tb"}
  ,{"kibibit","Kib"}
  ,{"mebibit","Mib"}
  ,{"gibibit","Gib"}
  ,{"tebibit","Tib"}
  ,{"petabit","Pib"}
  ,{"pebibit","Pib"}
  
  //bytes
  ,{"byte","B"}
  ,{"kilobyte","kB"}
  ,{"megabyte","MB"}
  ,{"gigabyte","GB"}
  ,{"terabyte","TB"}
  ,{"kibibyte","KiB"}
  ,{"mebibyte","MiB"}
  ,{"gibibyte","GiB"}
  ,{"tebibyte","TiB"}
  ,{"petabyte","PiB"}
  ,{"pebibyte","PiB"}
  
   //velocity
  ,{"feet / minute","fpm"}
  ,{"feet / second","fps"}
  ,{"meters / second","mps"}
  ,{"knots","kts"}
  ,{"mach","mach"}
  ,{"miles / hour","mph"}
  ,{"kilometer / hour","kmph"}
  
  //angular velocity
  ,{"revolutions / minute","rpm"}
  ,{"degrees / second","degps"}
  
  //acceleration
  ,{"degrees / second^2","degpss"}
  ,{"meters / second^2","mpss"}
  
  //force
  ,{"newtons", "n"}
  
  //flow rate
  ,{"pounds / minute","ppm"}
  ,{"pounds / hour","pph"}
  
  //area
  ,{"square inches","sqin"}
  ,{"square feet","sqft"}
  ,{"square miles","sqmi"}
  ,{"square centimeters","cm2"}
  ,{"square meters","m2"}
  ,{"square kilometers","km2"}
  ,{"square yard","sqy"}
  ,{"acre","acre"}
  ,{"hectare","ha"}
  
  //volume
  ,{"cubic meters","m3"}
  ,{"acre-foot","ac ft"}
  ,{"barrel (Imperial)","bl"}
  ,{"barrel (petroleum)","bl"}
  ,{"barrel (U.S. dry)","bl"}
  ,{"barrel (U.S. fluid)","bl"}
  ,{"bushel (Imperial)","bu"}
  ,{"bushel (U.S. dry)","bu"}
  ,{"cord (firewood)","cord"}
  ,{"cubic foot","ft3"}
  ,{"cubic inch","in3"}
  ,{"cubic centimeter","cm3"}
  ,{"cubic mile","mi3"}
  ,{"cubic yard","yd3"}
  ,{"cup (breakfast)","c"}
  ,{"cup (Canadian)","c"}
  ,{"cup (U.S.)","c"}
  ,{"ounce (Imperial fluid)","oz"}
  ,{"ounce (U.S. fluid)","oz"}
  ,{"gallon (Imperial)","gal"}
  ,{"gallon (U.S. dry)","gal"}
  ,{"gallon (U.S. fluid)","gal"}
  ,{"gill (Imperial)","gi"}
  ,{"gill (U.S.)","gi"}
  ,{"hogshead (Imperial)","hhd"}
  ,{"hogshead (U.S.)","hhd"}
  ,{"liter","L"}
  ,{"milliliter","mL"}
  ,{"peck (Imperial)","pk"}
  ,{"peck (U.S. dry)","pk"}
  ,{"pint (Imperial)","pt"}
  ,{"pint (U.S. dry)","pt"}
  ,{"pint (U.S. fluid)","pt"}
  ,{"quart (Imperial)","qt"}
  ,{"quart (U.S. dry)","qt"}
  ,{"quart (U.S. fluid)","qt"}
  ,{"tablespoon (Canadian)","tbsp"}
  ,{"tablespoon (Imperial)","tbsp"}
  ,{"tablespoon (U.S.)","tbsp"}
  ,{"teaspoon (Canadian)","tsp"}
  ,{"teaspoon (Imperial)","tsp"}
  ,{"teaspoon (U.S.)","tsp"}
  
  //currency
  ,{"united states dollars","usd"}
  ,{"euro","e"}
  ,{"yen","y"}
  
  //weight
  ,{"milligrams","mg"}
  ,{"centigrams","cg"}
  ,{"decigrams","dg"}
  ,{"grams","g"}
  ,{"dekagrams","dekg"}
  ,{"hectograms","hecg"}
  ,{"kilograms","kg"}
  ,{"metric tons","mtn"}
  ,{"ounces","oz"}
  ,{"pounds","lbs"}
  ,{"tons","tn"}
  ,{"microgram","mg"}
  ,{"imperial ton","impt"}
  ,{"stone","stone"}
  
  //time
  ,{"yoctoseconds","ys"}
  ,{"zeptoseconds","zs"}
  ,{"attoseconds","as"}
  ,{"femtoseconds","fs"}
  ,{"picoseconds","ps"}
  ,{"nanoseconds","ns"}
  ,{"shakes","shakes"}
  ,{"microseconds","us"}
  ,{"milliseconds","ms"}
  ,{"centiseconds","cs"}
  ,{"deciseconds","ds"}
  ,{"seconds","s"}
  ,{"decaseconds","decs"}
  ,{"minutes","min"}
  ,{"hectoseconds","hecs"}
  ,{"hours","hrs"}
  ,{"days","d"}
  ,{"weeks","w"}
  ,{"megaseconds","megas"}
  ,{"fortnights","frt_nght"}
  ,{"lunar months","lun_mon"}
  ,{"years","yrs"}
  ,{"decades","decs"}
  ,{"centuries","cents"}
  ,{"millennium","millen"}
  ,{"eons","eons"}
  ,{"ticks","ticks"}
  
  //temperature
  ,{"fahrenheit","degf"}
  ,{"celsius","degc"}
  ,{"kelvin","degk"}
  
  //angles
  ,{"degrees","deg"}
  ,{"angular mil","ang_m"}
  ,{"gradian","gdn"}
  ,{"minute of arc","m_of_arc"}
  ,{"second of arc","s_of_arc"}
  ,{"radian","rad"}
  
  //torque
  ,{"newton meters","Nm"}
  
  //energy
  ,{"joules","j"}
  ,{"kilojoules","kj"}
  ,{"gram calorie","gc"}
  ,{"kilocalorie","kc"}
  ,{"watt hour","wh"}
  ,{"kilowatt hour","kwh"}
  ,{"british thermal unit","btu"}
  ,{"US therm","us_thm"}
  
  //electrical
  ,{"volts","v"}
  ,{"amps","amp"}
  
  //power
  ,{"horse power","hp"}
  ,{"watts","w"}
  ,{"deciwatt","dW"}
  ,{"centiwatt","cW"}
  ,{"milliwatt","mW"}
  ,{"microwatt","uW"}
  ,{"nanowatt","nW"}
  ,{"picowatt","pW"}
  ,{"femtowatt","fW"}
  ,{"attowatt","aW"}
  ,{"zeptowatt","zW"}
  ,{"yoctowatt","yW"}
  ,{"decawatt","daW"}
  ,{"hectowatt","hW"}
  ,{"kilowatt","kW"} 
  ,{"megawatt","MW"} 
  ,{"gigawatt","GW"}
  ,{"terawatt","TW"}
  ,{"petawatt","PW"}
  ,{"exawatt","EW"} 
  ,{"zettawatt","ZW"} 
  ,{"yottawatt","YW"} 
  
  //pressure
  ,{"inches of mercury","inHg"}
  ,{"pascal","pa"}
  ,{"pounds / square inch","psi"}
  ,{"pounds / square foot","psf"}
  ,{"atmosphere","atm_p"}
  ,{"bar","bar"}
  ,{"torr","torr"}
  
  //electrical resistance
  ,{"abohm","abohm"}
  ,{"gigaohm","gigaohm"}
  ,{"kiloohm","kohm"}
  ,{"megaohm","mohm"}
  ,{"milliohm","mohm"}
  ,{"nanoohm","nohm"}
  ,{"ohms","ohm"}
  ,{"v/a","v_per_a"}
  
  //electrical charge
  ,{"abcoulomb","ac"}
  ,{"ampere-hour","ah"}
  ,{"coulombs","c"}
  ,{"elementary charge","e"}
  ,{"faraday","f"}
  ,{"kilocoulomb","kc"}
  ,{"megacoulomb","Mc"}
  ,{"microcoulomb","mc"}
  ,{"milliampere-hour","mh"}
  ,{"millicoulomb","mc"}
  ,{"nanocoulomb","nc"}
  ,{"statcoulomb","sc"}
  
  //capacitance
  ,{"abfarad","abF"}
  ,{"attofarad","aF"}
  ,{"centifarad","cF"}
  ,{"coulomb per volt","CpV"}
  ,{"decafarad","daF"}
  ,{"decifarad","dF"}
  ,{"exafarad","EF"}
  ,{"farad","F"}
  ,{"femtofarad","fF"}
  ,{"gigafarad","GF"}
  ,{"hectofarad","hF"}
  ,{"kilofarad","kF"}
  ,{"megafarad","MF"}
  ,{"microfarad","uF"}
  ,{"millifarad","mF"}
  ,{"nanofarad","nF"}
  ,{"petafarad","PF"}
  ,{"picofarad","pF"}
  ,{"statfarad","statF"}
  ,{"terafarad","TF"}
  ,{"yoctofarad","yF"}
  ,{"yottafarad","YF"}
  ,{"zeptofarad","zF"}
  ,{"zettafarad","ZF"}
  
  //work
  ,{"foot pounds","lbf"}
  ,{"newton meters","Nm"}
  
  //uncategorized
  ,{"percentage","pct"}
  ,{"percent","pct"} //should we allow more than one name for the same measurement?
//maybe but we would need to specify that they are actually the same somehow
//that way during analysis we dont think we are comparing two different measurements
  
  //frequency
  ,{"hertz","Hz"}
  ,{"kilohertz","Khz"}
  ,{"megahertz","Mhz"}
  ,{"gigahertz","Ghz"}
  
  //fuel economy
  ,{"us miles per gallon","mpg"}
  ,{"miles per gallon","mpg"}
  ,{"kilometer per liter","kpl"}
  ,{"liter per 100 kilometers","lpkmtrs"}
  
  //inductance
,{"henry","H"}
,{"exahenry","EH"}
,{"petahenry","PH"}
,{"terahenry","TH"}
,{"gigahenry","GH"}
,{"megahenry","MH"}
,{"kilohenry","kH"}
,{"hectohenry","hH"}
,{"dekahenry","daH"}
,{"decihenry","dH"}
,{"centihenry","cH"}
,{"millihenry","mH"}
,{"microhenry","uH"}
,{"nanohenry","nH"}
,{"picohenry","pH"}
,{"femtohenry","fH"}
,{"attohenry","aH"}
,{"weber/ampere","WbA"}
,{"abhenry","abH"}
,{"stathenry","stH"}
  
  //I don't know
  ,{"milimeters per hour","mmphr"}

};

