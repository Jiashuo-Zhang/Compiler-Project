cmake_minimum_required(VERSION 2.8)

project("antlr4-test")

set(CMAKE_CXX_STANDARD 11)

set(antlr4-GENERATED_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-runtime/kernelLexer.cpp 
  ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-runtime/kernelParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-runtime/kernelBaseVisitor.cpp   
  ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-runtime/kernelVisitor.cpp   
 )

foreach( src_file ${antlr4-GENERATED_SRC} )
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          GENERATED TRUE
          )
endforeach( src_file ${antlr4-GENERATED_SRC} )

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-runtime/
  ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-runtime/misc
  ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-runtime/atn
  ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-runtime/dfa
  ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-runtime/tree
  ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-runtime/support
  ${CMAKE_CURRENT_SOURCE_DIR}/
  ${CMAKE_CURRENT_SOURCE_DIR}/libs/
  ${CMAKE_CURRENT_SOURCE_DIR}/../include/
)

set(IRPrinter-SRC 
  ${CMAKE_CURRENT_SOURCE_DIR}/../src/IR.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/../src/IRMutator.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/../src/IRPrinter.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/../src/IRVisitor.cc
)

set(antlr4-SRC 
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Kernel2IRVisitor.cpp
  ${antlr4-GENERATED_SRC}
  ${IRPrinter-SRC}
)

if (NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  set (flags_1 "-Wno-overloaded-virtual")
else()
  set (flags_1 "-MP /wd4251")
endif()

foreach( src_file ${antlr4-SRC} )
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          COMPILE_FLAGS "${COMPILE_FLAGS} ${flags_1}"
          )
endforeach( src_file ${antlr4-SRC} )

add_executable(antlr4-test
  ${antlr4-SRC}
)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")  
  # see https://github.com/antlr/antlr4/issues/1874
  target_compile_options(antlr4-test PUBLIC "$<$<CONFIG:DEBUG>:/MT>")
endif()

if(WIN32)
  target_link_libraries(antlr4-test "${CMAKE_CURRENT_SOURCE_DIR}/libs/antlr4-runtime.lib")
endif()

if(APPLE)
  target_link_libraries(antlr4-test "${CMAKE_CURRENT_SOURCE_DIR}/libs/libantlr4-runtime.dylib")
elseif(UNIX)
  target_link_libraries(antlr4-test "${CMAKE_CURRENT_SOURCE_DIR}/libs/libantlr4-runtime.so")
endif()  

target_link_libraries(antlr4-test ${SYSTEM_LIBS})

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
add_custom_command(TARGET antlr4-test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${CMAKE_CURRENT_SOURCE_DIR}/libs/libantlr4-runtime.so"
  $<TARGET_FILE_DIR:antlr4-test>)
endif()

if(WIN32)
add_custom_command(TARGET antlr4-test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${CMAKE_CURRENT_SOURCE_DIR}/libs/antlr4-runtime.dll"
  $<TARGET_FILE_DIR:antlr4-test>)
endif()

if(APPLE)
add_custom_command(TARGET antlr4-test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${CMAKE_CURRENT_SOURCE_DIR}/libs/libantlr4-runtime.dylib"
  $<TARGET_FILE_DIR:antlr4-test>)
endif()

# copy the input file next to the generated executable
add_custom_command(TARGET antlr4-test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${CMAKE_CURRENT_SOURCE_DIR}/input.kernel"
  $<TARGET_FILE_DIR:antlr4-test>)

# necessary because the default working directory of Visual Studio
# is not the same as the one in which the binary is created
# so we copy the input file twice:
# one for when you launch the executale in Visual Studio (CTRL+F5)
# one for when you launch it normally
if (WIN32)
add_custom_command(TARGET antlr4-test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${CMAKE_CURRENT_SOURCE_DIR}/input.kernel"
  $<TARGET_FILE_DIR:antlr4-test>/../)
endif()
