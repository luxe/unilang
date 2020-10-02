#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "build/bazel/remote/execution/v2/remote_execution.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

// Logic and data behind the server's behavior.
// class GreeterServiceImpl final : public Greeter::Service {
//   Status SayHello(ServerContext* context, const HelloRequest* request,
//                   HelloReply* reply) override {
//     std::string prefix("Hello ");
//     reply->set_message(prefix + request->name());
//     return Status::OK;
//   }
// };

int main(){
}