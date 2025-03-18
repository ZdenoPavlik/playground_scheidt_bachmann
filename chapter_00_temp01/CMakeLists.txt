cmake_minimum_required(VERSION 3.28)
set(APPNAME ${SUBDIR}) #Appname is the name of subdirectory
set (CMAKE_CXX_STANDARD 26)

set (SOURCES
    src/main.cpp
)

set(HEADERS
)

project(${APPNAME}  LANGUAGES CXX)
add_executable(${APPNAME} ${HEADERS} ${SOURCES} )
target_compile_options(${APPNAME} PRIVATE -Wall -Wcast-align -Wconversion -Wctor-dtor-privacy -Werror -Wextra -Wpedantic -Wshadow -Wsign-conversion)  #Enable warning

include_directories(src)



#testing
set(test_binary_name ${APPNAME}_tests)
find_library(GTEST_LIB gtest REQUIRED)
find_library(GTEST_MAIN gtest_main REQUIRED)
find_library(GMOCK_LIB gmock REQUIRED)
find_package(Threads REQUIRED)

# enable testing functionality
enable_testing()

add_executable(${test_binary_name} tst/dummy_test_gtest.cpp)
target_link_libraries(${test_binary_name}
    PRIVATE
        ${GTEST_LIB}
        ${GTEST_MAIN}
        ${GMOCK_LIB}
        Threads::Threads
)

# define tests name and test binary name
add_test(NAME ${APPNAME}_tests COMMAND ${test_binary_name})

#automatically execute unit tests after build
add_custom_command(TARGET ${test_binary_name}
    POST_BUILD
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    COMMENT "Running unit tests after build..."
)