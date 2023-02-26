set(SRC_LIST 
    rpcApplication.cpp 
    rpcConfig.cpp
    rpcHeader.pb.cc 
    rpcProvider.cpp 
    rpcChannel.cpp
    rpcControler.cpp
    rpcLogger.cpp
    zookeeper.cpp)
add_library(rpc  ${SRC_LIST})
target_link_libraries(rpc  libmyMuduo.so pthread zookeeper_mt)