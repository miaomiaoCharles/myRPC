set(SRC_LIST   call_userService.cc ../user.pb.cc)
add_executable(rpcUser ${SRC_LIST})
target_link_libraries(rpcUser rpc protobuf)