#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <cassert>
#include <functional>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


//copied from cppreference as possible implementation
namespace detail {
template <class F, class... Args>
inline auto INVOKE(F&& f, Args&&... args) ->
    decltype(std::forward<F>(f)(std::forward<Args>(args)...)) {
      return std::forward<F>(f)(std::forward<Args>(args)...);
}
 
template <class Base, class T, class Derived>
inline auto INVOKE(T Base::*pmd, Derived&& ref) ->
    decltype(std::forward<Derived>(ref).*pmd) {
      return std::forward<Derived>(ref).*pmd;
}
 
template <class PMD, class Pointer>
inline auto INVOKE(PMD pmd, Pointer&& ptr) ->
    decltype((*std::forward<Pointer>(ptr)).*pmd) {
      return (*std::forward<Pointer>(ptr)).*pmd;
}
 
template <class Base, class T, class Derived, class... Args>
inline auto INVOKE(T Base::*pmf, Derived&& ref, Args&&... args) ->
    decltype((std::forward<Derived>(ref).*pmf)(std::forward<Args>(args)...)) {
      return (std::forward<Derived>(ref).*pmf)(std::forward<Args>(args)...);
}
 
template <class PMF, class Pointer, class... Args>
inline auto INVOKE(PMF pmf, Pointer&& ptr, Args&&... args) ->
    decltype(((*std::forward<Pointer>(ptr)).*pmf)(std::forward<Args>(args)...)) {
      return ((*std::forward<Pointer>(ptr)).*pmf)(std::forward<Args>(args)...);
}
}

namespace custom{
  template< class F, class... ArgTypes>
  decltype(auto) invoke(F&& f, ArgTypes&&... args) {
      return detail::INVOKE(std::forward<F>(f), std::forward<ArgTypes>(args)...);
  }
}


//added to:
// - ignore the output from Catch's signal handler
// - ignore the message from assert
void Disable_Console_Output(){
   
   //close C file descriptors
   //this will prevent cout and cin as well
   fclose(stdout);
   fclose(stderr);
}

template<class F, class... Args>
bool Function_Aborts(F&& f, Args&&... args)
{
    //spawn a new process
    auto child_pid = fork();
    
    //if the fork succeeded
    if (child_pid >= 0){
    
      //if we are in the child process
      if (child_pid == 0){
        
         //call the function that we expect to abort
         Disable_Console_Output();
         custom::invoke(std::forward<F>(f),std::forward<Args>(args)...);
         
         //if the function didn't abort, we'll exit cleanly
         std::exit(EXIT_SUCCESS);
      }
    }
    
    //determine if the function aborted
    //**this does not work because of Catch's signal handler**
    int exit_status;
    wait(&exit_status);
    bool aborted = WEXITSTATUS(exit_status);
    return aborted;
}

void Test_Function(int n){
  assert(n != 7);
  return;
}

TEST_CASE("test"){
  CHECK(Function_Aborts(Test_Function,6)); //fails (no extraneous output)
  CHECK(Function_Aborts(Test_Function,7)); //passes
}

//data appears correctly in console
