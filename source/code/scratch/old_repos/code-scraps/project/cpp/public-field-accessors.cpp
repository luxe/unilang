#include <iostream>

// a little trick to fool compiler we are not accessing NULL pointer here
#define property_offset(type, name) \
  (((char*)&((type*)(0xffff))->name) - (char*)(0xffff))

#define property_parent(type, name) \
  ((type*)((char*)(this) - property_offset(type, name)))

// macro defining property
#define property(type, name, parent)                                         \
  struct name##_property {                                                   \
    operator type() { return property_parent(parent, name)->get_##name(); }  \
    void operator=(type v) { property_parent(parent, name)->set_##name(v); } \
                                                                             \
   private:                                                                  \
    char zero[0];                                                            \
  } name

// our main class
struct Node {
  property(int, visitCount, Node);
  
  int get_visitCount(){
    std::cout << "Oh, here. ;)\n";
    return 123;
  }
  void set_visitCount(int n){
    std::cout << "Oh, I set it. ;)\n";
  }
};


int main(){
  
  Node n;
  n.visitCount = 5;
  std::cout << n.visitCount << std::endl;
  
  //n.visitCount += (open to extend)
  
}