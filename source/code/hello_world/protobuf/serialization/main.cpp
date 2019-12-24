
#include <iostream>
#include "code/hello_world/protobuf/serialization/message.pb.h"
int main(){

    GOOGLE_PROTOBUF_VERIFY_VERSION;
    demo::Message message;
    message.set_foo("hello world");
    return 0;
}
