#include<stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

int FindMaxSum2(std::vector<int> v)
{
  int x[2] {v[0],v[1]};
 
  for (int i = 2; i < v.size(); i++)
  {
     int temp = std::max(x[0],x[1]);
 
     x[1] = x[0] + v[i];
     x[0] = temp;
  }
 
   return std::max(x[0],x[1]);
}


struct A{

	void foo(){
		std::cout << "sdfsd" << std::endl;
	}
};

int main()
{
	A a();
	a.foo();


  std::vector<int> v{5, 5, 10, 100, 10, 5};
  //printf("%d \n", FindMaxSum(v));
	printf("%d \n", FindMaxSum2(v));
	//{100,1,2,100}
  return 0;
}