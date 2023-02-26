set(SRC_LIST  userService.cc ../user.pb.cc)
add_executable(provider ${SRC_LIST})
target_link_libraries(provider rpc protobuf)