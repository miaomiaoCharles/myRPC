set(SRC_LIST 
    rpcApplication.cpp 
    rpcConfig.cpp
    rpcHeader.pb.cc 
    rpcProvider.cpp 
    rpcChannel.cpp
    rpcControler.cpp
    logger.cpp
    zookeeper.cpp)
add_library(rpc  ${SRC_LIST})
target_link_libraries(rpc  muduo_net muduo_base pthread zookeeper_mt)