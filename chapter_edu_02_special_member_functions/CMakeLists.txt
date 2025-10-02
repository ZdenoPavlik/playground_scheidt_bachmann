cmake_minimum_required(VERSION 3.28)
set(APPNAME ${SUBDIR}) #Appname is the name of subdirectory
set (CMAKE_CXX_STANDARD 26)

set (SOURCES
    src/main.cpp
)

set(HEADERS
)

project(${APPNAME} LANGUAGES CXX)
add_executable(${APPNAME} ${HEADERS} ${SOURCES} )

# Windows specific settings
if (MSVC)
    message(STATUS "Compiling using MSVC (Visual studio) compiler")
    target_compile_options(${APPNAME} PRIVATE -W4)
else()
  message(STATUS "Clang detected: now compiling with style, grace, and slightly smug optimism...")
  target_compile_options(${APPNAME} PRIVATE -Wall -Wcast-align -Wconversion -Wctor-dtor-privacy -Werror -Wextra -Wpedantic -Wshadow -Wsign-conversion)  #Enable warning
endif()

include_directories(src)
include_directories(inc)
target_include_directories(${APPNAME} 
PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)


#automatically generate documentation after build
add_custom_command(TARGET ${APPNAME} 
    POST_BUILD
    COMMAND pandoc 
           -t beamer
           "${CMAKE_CURRENT_SOURCE_DIR}/doc/slideshow_02_special_member_functions.md" -o "${CMAKE_CURRENT_SOURCE_DIR}/doc/slideshow_02_special_member_functions.pdf"
    COMMENT "Generating documentation..."
)