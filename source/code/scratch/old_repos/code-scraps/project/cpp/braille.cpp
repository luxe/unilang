#include <iostream>
#include <string>
#include <cstdlib>

struct{
	bool[6] dots;
	/* +---+
	 1 |O O| 4
	 2 |O O| 5
	 3 |O O| 6
	   +---+ */
};

class enum BrailleMode: char { NUMBER, LETTER, CAPITAL
int main(){
	
	std::string str{L"⠅"};
	std::cout << str << std::endl;
	return EXIT_SUCCESS;
}


/*
 
 
 
progtam settings
grade1 or grade2 braille?
print type

1,a 1,0,0,0,0,0 | (a)
2,b 1,1,0,0,0,0 | (but)
3,c 1,0,0,1,0,0 | (can)
4,d 1,0,0,1,1,0 | (do)
5,e 1,0,0,0,1,0 | (every)
6,f 1,1,0,1,0,0 | (from)
7,g 1,1,0,1,1,0 | (go)
8,h 1,1,0,0,1,0 | (have)
9,i 0,1,0,1,0,0 | (I)
0,j 0,1,0,1,1,0 | (just)
k   1,0,1,0,0,0 | (knowledge)
l   1,1,1,0,0,0 | (like)
m   1,0,1,1,0,0 | (more)
n   1,0,1,1,1,0 | (not)
o   1,0,1,0,1,0 | (O)
p   1,1,1,1,0,0 | (people)
q   1,1,1,1,1,0 | (quite)
r   1,1,1,0,1,0 | (rather)
s   0,1,1,1,0,0 | (so)
t   0,1,1,1,1,0 | (that)
u   1,0,1,0,0,1 | (us)
v   1,1,1,0,0,1 | (very)
x   1,0,1,1,0,1 | (it)
y   1,0,1,1,1,1 | (you)
z   1,0,1,0,1,1 | (as)

w/will 0,1,0,1,1,1

and  1,1,1,1,0,1
for  1,1,1,1,1,1
of   1,1,1,0,1,1
the  0,1,1,1,0,1
with 0,1,1,1,1,1

  0,0,1,1,1,1 //turn on numbers (if at the end of a word, it represents "ble") terminated by space or letter_mode
  0,0,0,0,1,1 //turn on letters
  0,0,0,0,0,1 //next character is capital (two together, means the rest of the word is capitalized)
  0,0,0,1,0,0 //numerical index
  0,0,0,1,1,0 //literal index
  0,0,0,1,0,1 //italic sign  (if two are used, every word is italic until another italic sign ends it)
  
ea/,  0,1,0,0,0,0
be/;  0,1,1,0,0,0 //full word    (bb if used in the middle of a word)
con/:  0,1,0,0,1,0               (cc if used in the middle of a word)
dis/.  0,1,0,0,1,1 //period      (dd if used in the middle of a word)
en/enough    0,1,0,0,0,1
to/!  0,1,1,0,1,0 //ful word     (ff if used in the middle of a word)
where/() 0,1,1,0,1,1             (gg if used in the middle of a word)
his/"/? 0,1,1,0,0,1 //open quotes
in/*  0,0,1,0,1,0 (two of these together must be used before you can read it as an astriks)
was/by/"  0,0,1,0,1,1  //closed quotes
.  0,0,0,1,0,1 //decimal point
-  0,0,1,0,0,1 //hyphon


words when used by themselves-- otherwize contractions
ch/child 1,0,0,0,0,1
gh 1,1,0,0,0,1
sh/shall 1,0,0,1,0,1
th/this 1,0,0,1,1,1
wh/which 1,0,0,0,1,1
ed 1,1,0,1,0,1
er 1,1,0,1,1,1
ou/out 1,1,0,0,1,1
ow 0,1,0,1,0,1

' 0,0,1,0,0,0 //apostrophe
com 0,0,1,0,0,1
ing 0,0,1,1,0,1
0,0,0,1,0,0 //accent
st/still 0,0,1,1,0,0
ar 0,0,1,1,1,0
0,0,0,0,1,0
0,0,0,1,1,0
0,0,0,1,1,1
0,0,0,0,0,0 //space











*/