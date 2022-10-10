set(SRC_LIST   call_getFriendsService.cc ../friends.pb.cc)
add_executable(rpcUser ${SRC_LIST})
target_link_libraries(rpcUser rpc protobuf)