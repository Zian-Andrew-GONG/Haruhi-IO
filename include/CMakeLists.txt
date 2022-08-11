set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/cmake-build/bin)

include_directories(utils)

add_library(Haruhi Haruhi-loop.cpp Haruhi-timer.cpp)