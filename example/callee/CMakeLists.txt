set(SRC_LIST   getFriends.cc  ../friends.pb.cc)
add_executable(provider ${SRC_LIST})
target_link_libraries(provider rpc protobuf)