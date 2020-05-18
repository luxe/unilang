//STD Libraries
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstring>

//BOOST
//can replace boost with STD chrono, utility->function, and random
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/function.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>


using namespace std;

bool DEBUG = 0;

void TimeRoutine(string name,boost::function<int(int,int)>fun, 
            int arg1,int arg2, bool doTime);
void SetAB(int, int & , int & );
bool Test(int a, int b, int d);

void args(string progname) {
   cout << progname << " [-l n -r -R n -t -d -a n -b n -h]" << endl;
   cout << endl;
   cout << "\t" << " -l n " << "\t" << " use a preset input" << endl;
   cout << "\t\t" << 0 << "\t  Book's Example " << endl;
   cout << "\t\t" << 1 << "\t  Two factorable numbers " << endl;
   cout << "\t\t" << 2 << "\t  Book's Problem " << endl;
   cout << "\t\t" << 3 << "\t  Medium Sized Numbers " << endl;
   cout << "\t\t" << 4 << "\t  Large Numbers " << endl;
   cout << "\t\t" << 5 << "\t  Very Large Numbers " << endl;
   cout << "\t" << " -r " << "\t" << " Generate random numbers" << endl;
   cout << "\t" << " -R n "<< "\t" << " Generate random numbers 2 to n" << endl;
   cout << "\t" << " -d " << "\t" << " Debug output" << endl;
   cout << "\t" << " -h " << "\t" << " This menu" << endl;
   cout << "\t" << " -t " << "\t" << " Show Timing" << endl;
   cout << "\t" << " -a n " << "\t" << " Set first number to be n" << endl;
   cout << "\t" << " -b n " << "\t" << " Set second number to be n" << endl;
   return;
}
 
int main(int argc, char * argv[]) {
    int a = 12;
    int b = 15;
    bool doTime = false;
    int arg;

    int i = 1; 
    while (i < argc) {
        if (strcmp(argv[i],"-l")==0) {
	   i++;
	   if (i < argc) {
	       arg = -1;
               arg = atoi(argv[i]); 
               SetAB(arg, a,b);
	       i++;
	   } else {
	       cout << "-l requires an integer level, using default " << endl;
	   }
	} else if (!strcmp(argv[i],"-a")) {
	   i++;
	   a = atoi(argv[i]);
	   if (a < 2) {
	      a = 12;
	   }
	   i++;
	} else if (!strcmp(argv[i],"-b")) {
	   i++;
	   b = atoi(argv[i]);
	   if (b < 2) {
	      b = 15;
	   }
	   i++;
	} else if (!strcmp(argv[i],"-t")) {
	   doTime = true;
	   i++;
	} else if (!strcmp(argv[i],"-r")) {

	   boost::mt19937 rng;
	   boost::uniform_int<> dist(2,1<<30);
	   boost::variate_generator<boost::mt19937&, boost::uniform_int<> >
	         bigDie(rng,dist);

	   rng.seed(static_cast<unsigned int>(std::time(0)));

	   a = bigDie(); 
	   b = bigDie();
	   i++;
	} else if (!strcmp(argv[i],"-R")) {
	   int upperLimit;

	   i++;
	   upperLimit = atoi(argv[i]);
	   i++;

	   if (upperLimit < 2) {
	      upperLimit = 1 << 30;
	   }

	   boost::mt19937 rng;
	   boost::uniform_int<> dist(2,upperLimit);
	   boost::variate_generator<boost::mt19937&, boost::uniform_int<> >
	         bigDie(rng,dist);

	   rng.seed(static_cast<unsigned int>(std::time(0)));

	   a = bigDie(); 
	   b = bigDie();

	} else if (!strcmp(argv[i],"-h")) {
	   args(argv[0]);
	   i++;
	} else if (!strcmp(argv[i],"-d")) {
	   DEBUG = true;
	   i++;
	} else {
	   cout << "unknown argument " << argv[i] << endl;
	   args(argv[0]);
	   i++;
	}
    }

    cout << endl;
    cout << "A = " << a << " and has " << int(log(a)/log(2)) << " bits" << endl;
    cout << "B = " << b << " and has " << int(log(b)/log(2)) << " bits" << endl;
    cout << endl;

    TimeRoutine("Euclid", Euclid_Recursive, a,b,doTime);
    TimeRoutine("Brute ", Brute, a,b,doTime);
    TimeRoutine("School", OldSchool, a,b,doTime);

    return 0;
}



void SetAB(int arg, int & a, int & b) {
       switch(arg) {
          case 0:
             // the book's example
             a = 60;
	     b = 24;
	     break;
	  case 1:
             // 2^2 x 3^3 x 5^5 x 7   and 2^2 x 3^2 x 5^4 (to test factoring)
             a = 45000;
	     b = 787500;
	     break;
	  case 2:
             // an exercise in the book
             a=31415;
	     b= 14142;
	     break;
	  case 3:
             // not to big prime number, look out old school!
             a = 80147*2*3*3;
             b = 21011*2*3*3;
	     break;
	  case 4:
             // two bigger prime numbers
             a=  4095036*2*3*5;
             b = 4095043*2*3*5;
	     break;
	  default:
	     a = 40950391 * 2 * 3;
	     b = 40950401 * 2 * 3;
       }
       return;
}



void TimeRoutine(string name, boost::function < int (int, int)> fun, 
                   int arg1,int arg2, bool doTime){

    int gcd;
    boost::posix_time::ptime startTime, endTime;
    boost::posix_time::time_duration totalTime;

    startTime = boost::posix_time::microsec_clock::local_time();
    gcd = fun(arg1, arg2);
    endTime = boost::posix_time::microsec_clock::local_time();
    cout <<"\t" << name << ": " << setw(15) << gcd;
    if (doTime) {
       totalTime = endTime-startTime;
       cout << "\tTime: " << totalTime;
    }
    cout << endl;
    if (!Test(arg1, arg2, gcd)) {
        cout << endl;
        cout << "ERROR ERROR ERROR ERROR ERROR ERROR " << endl;
        cout << endl << endl << endl;
    }

    return;
}
