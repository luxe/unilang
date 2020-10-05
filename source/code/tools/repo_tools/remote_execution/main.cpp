#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include "build/bazel/remote/execution/v2/remote_execution.grpc.pb.h"
#include "code/utilities/formats/serialization/protobuf.hpp"
#include "code/tools/repo_tools/remote_execution/server/server_settings.hpp"
#include "code/tools/repo_tools/remote_execution/server/server.hpp"
#include "code/utilities/remote_execution/services/grpc_glue.hpp"



void RunServer() {
  
  //grpc settings
  Server_Settings x;
  x.enable_default_health_check_service = true;
  x.address = "0.0.0.0:50051";
  
  auto server = Server::BuildAndRun(x);
  
  
  std::cout << "Server listening on " << x.address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();

  return 0;
}
