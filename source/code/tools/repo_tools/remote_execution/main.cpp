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
class ExecutionServiceImpl final : public build::bazel::remote::execution::v2::Execution::Service {

    grpc::Status Execute(grpc::ServerContext* context, const build::bazel::remote::execution::v2::ExecuteRequest* request, grpc::ServerWriter< ::google::longrunning::Operation>* writer){
        return grpc::Status::OK;
    }
    
    grpc::Status WaitExecution(grpc::ServerContext* context, const build::bazel::remote::execution::v2::WaitExecutionRequest* request, grpc::ServerWriter< ::google::longrunning::Operation>* writer){
        return grpc::Status::OK;
    }
};

int main(){
}