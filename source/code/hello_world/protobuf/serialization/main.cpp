#include <iostream>
#include <fstream>
#include "code/hello_world/protobuf/serialization/message.pb.h"
int main(){

    //construct
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    demo::Message message;
    message.set_foo("hello world");
    
    //serialize
    std::ofstream ofs("/home/laptop/Desktop/sensor.data", std::ios_base::out | std::ios_base::binary);
    message.SerializeToOstream(&ofs);
    return 0;
}
