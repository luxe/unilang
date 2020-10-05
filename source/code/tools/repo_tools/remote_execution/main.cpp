#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include "build/bazel/remote/execution/v2/remote_execution.grpc.pb.h"
#include "code/utilities/formats/serialization/protobuf.hpp"
#include "code/tools/repo_tools/remote_execution/server/server_settings.hpp"

// Logic and data behind the server's behavior.
class ExecutionService final : public build::bazel::remote::execution::v2::Execution::Service {

    grpc::Status Execute(grpc::ServerContext* context, const build::bazel::remote::execution::v2::ExecuteRequest* request, grpc::ServerWriter<google::longrunning::Operation>* writer){
        return grpc::Status::OK;
    }
    
    grpc::Status WaitExecution(grpc::ServerContext* context, const build::bazel::remote::execution::v2::WaitExecutionRequest* request, grpc::ServerWriter<google::longrunning::Operation>* writer){
        return grpc::Status::OK;
    }
};

class ActionCacheService final : public build::bazel::remote::execution::v2::ActionCache::Service {
    grpc::Status GetActionResult(grpc::ServerContext* context, const build::bazel::remote::execution::v2::GetActionResultRequest* request, build::bazel::remote::execution::v2::ActionResult* response){
        return grpc::Status::OK;
    }
    
    grpc::Status UpdateActionResult(grpc::ServerContext* context, const build::bazel::remote::execution::v2::UpdateActionResultRequest* request, build::bazel::remote::execution::v2::ActionResult* response){
        return grpc::Status::OK;
    }
};

template <
typename FindMissingBlobsFunImpl,
typename BatchUpdateBlobsFunImpl,
typename BatchReadBlobsFunImpl,
typename GetTreeFunImpl
>
class ContentAddressableStorageService final : public build::bazel::remote::execution::v2::ContentAddressableStorage::Service {
  
    //functions to implement
    public:
    FindMissingBlobsFunImpl FindMissingBlobsFun;
    BatchUpdateBlobsFunImpl BatchUpdateBlobsFun;
    BatchReadBlobsFunImpl BatchReadBlobsFun;
    GetTreeFunImpl GetTreeFun;
    
    //constructor
    ContentAddressableStorageService(FindMissingBlobsFunImpl FindMissingBlobsFun,
    BatchUpdateBlobsFunImpl BatchUpdateBlobsFun,
    BatchReadBlobsFunImpl BatchReadBlobsFun,
    GetTreeFunImpl GetTreeFun):
    FindMissingBlobsFun(FindMissingBlobsFun),
    BatchUpdateBlobsFun(BatchUpdateBlobsFun),
    BatchReadBlobsFun(BatchReadBlobsFun),
    GetTreeFun(GetTreeFun)
    {}
    
    grpc::Status FindMissingBlobs(grpc::ServerContext* context, const build::bazel::remote::execution::v2::FindMissingBlobsRequest* request, build::bazel::remote::execution::v2::FindMissingBlobsResponse* response){
        return FindMissingBlobsFun(context,request,response);
    }
    
    grpc::Status BatchUpdateBlobs(grpc::ServerContext* context, const build::bazel::remote::execution::v2::BatchUpdateBlobsRequest* request, build::bazel::remote::execution::v2::BatchUpdateBlobsResponse* response){
        return BatchUpdateBlobsFun(context,request,response);
    }
    
    grpc::Status BatchReadBlobs(grpc::ServerContext* context, const build::bazel::remote::execution::v2::BatchReadBlobsRequest* request, build::bazel::remote::execution::v2::BatchReadBlobsResponse* response){
        return BatchReadBlobsFun(context,request,response);
    }

    grpc::Status GetTree(grpc::ServerContext* context, const build::bazel::remote::execution::v2::GetTreeRequest* request, grpc::ServerWriter< build::bazel::remote::execution::v2::GetTreeResponse>* writer){
        return GetTreeFun(context,request,writer);
    }
};

template <typename GetCapabilitiesFunImpl>
class CapabilitiesService final : public build::bazel::remote::execution::v2::Capabilities::Service {
  
    //functions to implement
    public:
    GetCapabilitiesFunImpl GetCapabilitiesFun;
    
    //constructor
    CapabilitiesService(GetCapabilitiesFunImpl GetCapabilitiesFun):
    GetCapabilitiesFun(GetCapabilitiesFun)
    {}
    
    //forwarding calls
    grpc::Status GetCapabilities(grpc::ServerContext* context, const build::bazel::remote::execution::v2::GetCapabilitiesRequest* request, build::bazel::remote::execution::v2::ServerCapabilities* response){
        return GetCapabilitiesFun(context,request,response);
    }
};




void RunServer() {
  
  //grpc settings
  Server_Settings x;
  x.enable_default_health_check_service = true;
  x.address = "0.0.0.0:50051";
  
  
  //setup grpc
  grpc::EnableDefaultHealthCheckService(x.enable_default_health_check_service);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  
  
  grpc::ServerBuilder builder;
  builder.AddListeningPort(x.address, grpc::InsecureServerCredentials());
  
  
  //add all of the individual services from the proto definitions
  ExecutionService execution_service;
  ActionCacheService action_cache_service;
  
  
  ContentAddressableStorageService content_addressable_storage_service(
  [&](grpc::ServerContext* context, const build::bazel::remote::execution::v2::FindMissingBlobsRequest* request, build::bazel::remote::execution::v2::FindMissingBlobsResponse* response){
    return grpc::Status::OK;
  },
  [&](grpc::ServerContext* context, const build::bazel::remote::execution::v2::BatchUpdateBlobsRequest* request, build::bazel::remote::execution::v2::BatchUpdateBlobsResponse* response){
    return grpc::Status::OK;
  },
  [&](grpc::ServerContext* context, const build::bazel::remote::execution::v2::BatchReadBlobsRequest* request, build::bazel::remote::execution::v2::BatchReadBlobsResponse* response){
    return grpc::Status::OK;
  },
  [&](grpc::ServerContext* context, const build::bazel::remote::execution::v2::GetTreeRequest* request, grpc::ServerWriter< build::bazel::remote::execution::v2::GetTreeResponse>* writer){
    return grpc::Status::OK;
  }
  );
  
  
  CapabilitiesService capabilities_service([&](grpc::ServerContext* context, const build::bazel::remote::execution::v2::GetCapabilitiesRequest* request, build::bazel::remote::execution::v2::ServerCapabilities* response){
        std::cout << Protobuf_Message_To_Json(*request) << std::endl;
        return grpc::Status::OK;
  });
  
  builder.RegisterService(&execution_service);
  builder.RegisterService(&action_cache_service);
  builder.RegisterService(&content_addressable_storage_service);
  builder.RegisterService(&capabilities_service);
  
  // Finally assemble the server.
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << x.address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();

  return 0;
}
