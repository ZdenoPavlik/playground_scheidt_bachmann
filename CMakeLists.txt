cmake_minimum_required(VERSION 3.5)
project("LinuxPlayground"  LANGUAGES CXX)

#cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..


# Define the prefix to search for
set(SUBPROJECT_PREFIX "chapter_")

# Get all directories in the root directory starting with the prefix
file(GLOB ROOT_CHILDREN RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/${SUBPROJECT_PREFIX}*)

# Loop through each found directory
foreach(SUBDIR ${ROOT_CHILDREN})
    # Make sure it's a directory
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
        # Optional: Ensure it contains a CMakeLists.txt
        if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/CMakeLists.txt)
            message(STATUS "Adding subdirectory: ${SUBDIR}")
            add_subdirectory(${SUBDIR})
        else()
            message(WARNING "Skipping ${SUBDIR} (no CMakeLists.txt found)")
        endif()
    endif()
endforeach()






