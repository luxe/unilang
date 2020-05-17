#ifndef _DIE
#define _DIE

#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
class Die
{
  friend class Dice;
  public:
    Die();
    Die(int faceIn);
    int Roll()const;
    int Roll(int num)const;
    bool SetDie(int faceIn);
    void SeeRolls();
    void SetFile(std::string dieFile);
    void ResetFile();
    void HideRolls();
    void PrintOdds(std::ostream& oddsOut);
    friend std::ostream& operator<<(std::ostream& out, const Die &d);
    int GetFaces() const;
    float AvgRoll();
    Die& operator++();
    Die& operator++(int);
    Die& operator--();
    Die& operator--(int);
    bool operator==(const Die& rhs)const;
    bool operator!=(const Die& rhs)const;
    bool operator<(const Die& rhs)const;
    bool operator<=(const Die& rhs)const;
    bool operator>(const Die& rhs)const;
    bool operator>=(const Die& rhs)const;
    void SetDel(char ch);
  private:
    int faces;
    bool seeDie;
    bool setFile;
    bool PrintRoll(int roll)const;
    char del;
    std::string filename;
  
};


#endif