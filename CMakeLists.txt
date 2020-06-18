cmake_minimum_required(VERSION 3.0)
project(boost C CXX)
set(LIB_NAME boost)

# include directories
include_directories(${CMAKE_INCLUDE_PATH})
include_directories("include")

# initial variables
set(BOOST_LINKER_LIBS "")
set(BOOST_RUNTIME_LINKER_LIBS ${CMAKE_DL_LIBS})

# Generic compilation options
if(MSVC)
  add_definitions(-DWIN32_LEAN_AND_MEAN)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  add_definitions(-D_SCL_SECURE_NO_WARNINGS)
  add_definitions(-D_ENABLE_EXTENDED_ALIGNED_STORAGE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /bigobj")
  if(USE_MSVC_MT)
    foreach(flag_var
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
      if(${flag_var} MATCHES "/MD")
        string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
      endif(${flag_var} MATCHES "/MD")
    endforeach(flag_var)
  endif()
else(MSVC)
  if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    message("Build in Debug mode")
    set(CMAKE_C_FLAGS "-O0 -g -Wall -fPIC ${CMAKE_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "-O0 -g -Wall -fPIC ${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_C_FLAGS "-O2 -Wall -fPIC ${CMAKE_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "-O2 -Wall -fPIC ${CMAKE_CXX_FLAGS}")
    if (HIDE_PRIVATE_SYMBOLS)
      message(STATUS "Hide private symbols...")
      set(CMAKE_C_FLAGS "-fvisibility=hidden ${CMAKE_C_FLAGS}")
      set(CMAKE_CXX_FLAGS "-fvisibility=hidden ${CMAKE_CXX_FLAGS}")
    endif(HIDE_PRIVATE_SYMBOLS)
  endif ()
  if (CMAKE_CXX_COMPILER_ID MATCHES "GNU" AND
      CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 7.0)
    set(CMAKE_CXX_FLAGS "-faligned-new ${CMAKE_CXX_FLAGS}")
  endif()
endif(MSVC)


include_directories(
  kernel/antlr4-runtime/
  kernel/antlr4-runtime/misc
  kernel/antlr4-runtime/atn
  kernel/antlr4-runtime/dfa
  kernel/antlr4-runtime/tree
  kernel/antlr4-runtime/support
  kernel/
  kernel/libs/
)

# Source file
file(GLOB COMPILER_SRCS
    src/*.cc
    )

file(GLOB COMPILER_INCLUDES
    include/*.h
    )

file(GLOB KERNEL_SRCS
    kernel/antlr4-runtime/kernelLexer.cpp
    kernel/antlr4-runtime/kernelParser.cpp
    kernel/antlr4-runtime/kernelBaseVisitor.cpp
    kernel/antlr4-runtime/kernelVisitor.cpp
    )

if(NOT MSVC)
  include(CheckCXXCompilerFlag)
    check_cxx_compiler_flag("-std=c++11"    SUPPORT_CXX11)
    message(STATUS "Build with c++11")
    set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
endif()

add_library(${LIB_NAME} SHARED ${COMPILER_SRCS} ${COMPILER_INCLUDES})

target_link_libraries(${LIB_NAME} ${BOOST_LINKER_LIBS} ${BOOST_RUNTIME_LINKER_LIBS})

add_library(kernel SHARED ${KERNEL_SRCS})

if(WIN32)
  target_link_libraries(kernel "${PROJECT_SOURCE_DIR}/kernel/libs/antlr4-runtime.lib")
endif()

if(APPLE)
  target_link_libraries(kernel "${PROJECT_SOURCE_DIR}/kernel/libs/libantlr4-runtime.dylib")
elseif(UNIX)
  target_link_libraries(kernel "${PROJECT_SOURCE_DIR}/kernel/libs/libantlr4-runtime.so")
endif()  

if (HIDE_PRIVATE_SYMBOLS AND NOT ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(HIDE_SYMBOLS_LINKER_FLAGS "-Wl,--exclude-libs,ALL")
  # Note: 'target_link_options' with 'PRIVATE' keyword would be cleaner
  # but it's not available until CMake 3.13. Switch to 'target_link_options'
  # once minimum CMake version is bumped up to 3.13 or above.
  target_link_libraries(${LIB_NAME} ${HIDE_SYMBOLS_LINKER_FLAGS})
endif()

add_subdirectory(project2)

# JSON targets.
add_subdirectory("jsoncpp"
    ${CMAKE_CURRENT_BINARY_DIR}/jsoncpp-build
    EXCLUDE_FROM_ALL)

target_link_libraries(${LIB_NAME} jsoncpp_lib)