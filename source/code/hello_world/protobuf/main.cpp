#include "code/hello_world/protobuf/hello.pb.h"

int main(){

	GOOGLE_PROTOBUF_VERIFY_VERSION;
	demo::Message message;
	message.set_foo("hello world");
	std::cout << message.foo() << std::endl;

  return 0;
}