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
# Linux-specific settings
if(UNIX AND NOT APPLE)
    message(STATUS "Compiling on Linux")
    target_compile_options(${APPNAME} PRIVATE -Wall -Wcast-align -Wconversion -Wctor-dtor-privacy -Werror -Wextra -Wpedantic -Wshadow -Wsign-conversion)  #Enable warning
endif()

# Windows-specific settings
if(WIN32)
    message(STATUS "Compiling on Windows")
    target_compile_options(${APPNAME} PRIVATE -W4)  #Enable warning
endif()

include_directories(src)
include_directories(inc)
target_include_directories(${APPNAME} 
PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)

#testing
include(FetchContent)

# Fetch GoogleTest
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Make available
FetchContent_MakeAvailable(googletest)

set(test_binary_name ${APPNAME}_tests)
#find_library(GTEST_LIB gtest REQUIRED)
#find_library(GTEST_MAIN gtest_main REQUIRED)
#find_library(GMOCK_LIB gmock REQUIRED)
find_package(Threads REQUIRED)

if(WIN32)
    message(STATUS "Adding googletest as /MTd")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

# enable testing functionality
enable_testing()

set(TEST_SRC
  tst/sw.cpp 
  tst/swCopyCtorMissing.cpp
  tst/swCopyCtorProper.cpp
)

add_executable(${test_binary_name} ${TEST_SRC})
target_link_libraries(${test_binary_name}
    PRIVATE
        gtest 
        gtest_main
        gmock
        gmock_main
        Threads::Threads
)
target_include_directories(${test_binary_name} 
PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)

# define tests name and test binary name
add_test(NAME ${APPNAME}_tests COMMAND ${test_binary_name})

#automatically execute unit tests after build
add_custom_command(TARGET ${test_binary_name}
    POST_BUILD
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    COMMENT "Running unit tests after build..."
)