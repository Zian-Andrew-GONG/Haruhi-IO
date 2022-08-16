set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/cmake-build/bin)

include_directories(../src/include)

add_executable(timer timer.cpp)
target_link_libraries(timer Haruhi)

add_executable(pipe pipe.cpp)
target_link_libraries(pipe Haruhi)

add_executable(epoll-server epoll-server.cpp)
target_link_libraries(epoll-server Haruhi)

add_executable(epoll-client epoll-client.cpp)

add_executable(signal signal.cpp)
target_link_libraries(signal Haruhi)

