set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/cmake-build/bin)

# aux_source_directory(. DIREXAMPLE)

include_directories(../include)
# add_subdirectory(../include)

add_executable(timer timer.cpp)
target_link_libraries(timer haruhi)