file(GLOB test_src "*.cc")

include_directories("../include")

foreach(src IN LISTS test_src)
    get_filename_component(exe_name ${src} NAME_WE)
    add_executable(${exe_name} ${src})
    target_link_libraries(${exe_name} ${LIB_NAME})
    target_link_libraries(${exe_name} kernel)
endforeach(src)
