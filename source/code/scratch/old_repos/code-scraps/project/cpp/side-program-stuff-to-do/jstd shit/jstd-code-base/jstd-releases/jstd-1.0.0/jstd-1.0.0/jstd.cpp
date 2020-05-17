//The J standard
#include "jstd.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <sstream>

const std::string TITLE = "title.in";
const std::string TITLE_ERROR = "title file not found\n";
static std::vector<std::string> titles = {"the","a","to","on","at","an","by","down",
"with","over","and","yet","but","of","for"};
namespace jstd
{
  std::string Upper(std::string str)
  {
    for (int i = 0; i<str.length(); i++)
    {
      str[i] = toupper(str[i]);
    }
    return str;
  }
  
  std::string Lower(std::string str)
  {
    for (int i =0; i<str.length(); i++)
    {
      str[i] = tolower(str[i]);
    }
    return str;
  }
  
  std::string Title(std::string str)
  {
    bool exception = false;
    std::vector <std::string> tempVec;
    std::string temp;                //julie -- "strawberry seeds dominated my mouth"
    int titleLen = titles.size();
    int strLen = str.length();
    for(int i = 0; i <= strLen; i++)
    {
      if (str[i] == ' ' || i == strLen)
      {
	tempVec.push_back(temp);
	temp = "";
      }
      else
      {
	temp += str[i];
      }
    }
      str = "";
      int len = tempVec.size();
      for (int k = 0;k<len; k++ )
      {
        if(k== 0)
        {
	  for (int x = 0; x<tempVec[k].length(); x++)
	  {
	  if (x == 0)
	    tempVec[k][x] = toupper(tempVec[k][x]);
	  else
	    tempVec[k][x] = tolower(tempVec[k][x]);
	  }
	}
	else if (k == (len -1)&& Upper(tempVec[k]) == "TO")
	{
	  tempVec[k] = "To";
        }
        else
	{
	  for (int y = 0; y < titleLen && !exception; y++)
	  {
	    if (tempVec[k] == titles[y])
	      exception = true;
	  }
	  if (exception)
	  {
	    tempVec[k] = Lower(tempVec[k]);
	  }
	  else
	  {
	    for (int a = 0; a<tempVec[k].length(); a++)
	    {
	    if (a == 0)
	      tempVec[k][a] = toupper(tempVec[k][a]);
	    else
	      tempVec[k][a] = tolower(tempVec[k][a]);
	    }
	  }
	}
	     
      }
      
    int tempVecLen = tempVec.size();
    for (int i =0; i < tempVecLen; i++)
      {
	str += tempVec[i];
	str += " ";
      }
    return str;
  }
  
  int Random(const int& num)
  {
    int randNum = 0;
    static bool seed = false;
    if (!seed)
    {
     srand(time(NULL));
     seed = true;
    }
    if (num > 0)
      randNum = (1+(rand() % num));
    return randNum;
  }
  
  int Random(const int& num1,  const int& num2)
  {
    int randNum = 0;
    static bool seed = false;
    if (!seed)
    {
     srand(time(NULL));
     seed = true;
    }
    if (num2 > 0)
    {
    //num2 -= (num1 - 1);
    randNum = (num1+(rand() % (num2 - (num1 - 1) ) ) );
    }
    return randNum;
  }

  int StringToInt(const std::string& str)
  {
    return atoi(str.c_str() );
  }

  std::string IntToString(const int& num)
  {
    std::stringstream sin;
    std::string str;
    sin << num;
    sin >> str;
    return str;
  }
}