set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/cmake-build/bin)

include_directories(../src/include)

add_executable(timer timer.cpp)
target_link_libraries(timer Haruhi)