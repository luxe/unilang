#include <iostream>
#include    


EM_JS(int, canvas_get_width, (), {
  return Module.canvas.width;
});

int main(){
    std::cout << canvas_get_width() << std::endl;
    std::cout << "sdfsdfdfsdfdf" << std::endl;
}