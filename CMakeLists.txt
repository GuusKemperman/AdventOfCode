cmake_minimum_required(VERSION 4.0.2)

message("Version: ${CMAKE_VERSION}")

project(AOC LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(/W4 /WX)

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

function(add_year_day_part year day part)
    add_executable(${year}-${day}-pt${part} pt${part}.cpp)

    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

    add_test(
    NAME "${year}.${day}.part ${part}"
    COMMAND $<TARGET_FILE:${year}-${day}-pt${part}>
    )

    set(generated_file 
"#pragma once\n"
"#include <string_view>\n"
"\n"
"static constexpr std::string_view get_input()\n"
"{\n"
"	std::string_view input =\n"
"	{\n"
		)
    

    file(READ input.txt input_content)

    string(REPLACE "\\" "\\\\" input_content ${input_content})
    string(REPLACE "\n" "\\n\"\n\t\t\"" input_content ${input_content})


    list(APPEND generated_file "\t\t\"")
    list(APPEND generated_file ${input_content})
    list(APPEND generated_file "\\n\"")


    list(APPEND generated_file
"\n"
"	}\;\n"
"	return input\;\n"
})

    file(WRITE "input.h"
    ${generated_file})


endfunction()

add_subdirectory(2023)

