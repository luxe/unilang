#include <iostream>
#include <iomanip>
#include "die.h"
#include "../jstd.h"

Die::Die()
{
  faces = 6;
  seeDie = false;
  setFile =false;
}

Die::Die(int faceIn)
{
  faces = faceIn;
  seeDie = false;
  setFile =false;
}

bool Die::PrintRoll(int roll)const
{
  if (setFile)
  {
    std::ofstream fout;
    fout.open(filename.c_str(), std::ios::app);
    fout << roll << del;
  }
  else
  {
    std::cout << roll << del;
  }
}

int Die::Roll()const
{
  int roll = jstd::Random(faces);
  if(seeDie)
  {
    if(setFile)
      PrintRoll(roll);
    else
      PrintRoll(roll);
  }
  return roll;
}

bool Die::SetDie(int num)
{
  faces = num;
  return true;
}



void Die::SetFile(std::string dieFile)
{
  filename = dieFile;
  setFile = true;
}

void Die::ResetFile()
{
  setFile = false;
}

void Die::SeeRolls()
{
  seeDie = true;
}

void Die::HideRolls()
{
  seeDie = false;
}


void Die::SetDel(char ch)
{
  del = ch;
}

float Die::AvgRoll()
{
  float avg;
  for (int i =0;i<faces;i++) 
    avg += ((i+1.0) * (1.0/faces));
  return avg;
}

void Die::PrintOdds(std::ostream& oddsOut)
{
  float avg =0.0;
  float temp = 0;
  oddsOut << std::left << std::setw(10) << "Roll";
  oddsOut << std::setw(10) << "Percent";
  oddsOut << std::endl;
  
  for (int i = 0; i < faces; i++)
  {
    oddsOut << std::setw(10) << i+1;
    oddsOut << std::setw(10) << (1 / float(faces) * 100);
    oddsOut << std::endl;
  }
  
  oddsOut << "Average roll = " << AvgRoll() <<std::endl;
  
  oddsOut << std::right;
}

int Die::GetFaces() const
{
  return faces;
}

int Die::Roll(int num)const
{
  return Roll() + num;
}

std::ostream& operator<<(std::ostream& out, const Die &d)
{
  out << 'd' << d.GetFaces();
}

Die& Die::operator++()
{
  faces++;
  return *this;
}

Die& Die::operator++(int)
{
  faces++;
  return *this;
}

Die& Die::operator--()
{
  faces--;
  return *this;
}

Die& Die::operator--(int)
{
  faces--;
  return *this;
}

bool Die::operator==(const Die& rhs)const
{
  return (faces == rhs.GetFaces());
}

bool Die::operator!=(const Die& rhs)const
{
  return (faces != rhs.GetFaces());
}

bool Die::operator<(const Die& rhs)const
{
  return (faces < rhs.GetFaces());
}

bool Die::operator<=(const Die& rhs)const
{
  return (faces <= rhs.GetFaces());
}

bool Die::operator>(const Die& rhs)const
{
  return (faces > rhs.GetFaces());
}

bool Die::operator>=(const Die& rhs)const
{
  return (faces >= rhs.GetFaces());
}