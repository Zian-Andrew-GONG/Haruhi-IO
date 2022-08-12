set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/cmake-build/bin)

include_directories(utils)
include_directories(include)

add_library(Haruhi Haruhi-loop.cpp Haruhi-timer.cpp epoll-wrapper.cpp Haruhi-epoll.cpp)