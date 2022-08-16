set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/cmake-build/bin)

include_directories(../src/include)

add_executable(timer timer.cpp)
target_link_libraries(timer Haruhi)

add_executable(epoll-listen epoll-listen-server.cpp)
target_link_libraries(epoll-listen Haruhi)

add_executable(epoll-client epoll-client.cpp)
