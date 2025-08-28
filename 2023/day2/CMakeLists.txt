
add_executable(2023-2-pt1 pt1.cpp)
add_executable(2023-2-pt2 pt2.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)