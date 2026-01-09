cmake_minimum_required(VERSION 3.18)
project(libft VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)          # or 17, 23 …

# 2.a  Collect every .c file under src/ automatically
file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS
        "${PROJECT_SOURCE_DIR}/src/*.c")

# 2.b  Build the library (static by default; very portable)
add_library(libft STATIC ${LIB_SOURCES})

target_include_directories(libft
        PUBLIC                               # <- users of the lib see this dir
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

# 2.c  Small example program that links against the library
#add_executable(example examples/example.c)
#target_link_libraries(example PRIVATE libft)

# 2.d  Optional tests (CTest)
enable_testing()
add_executable(test_runner tests/test_main.c)
target_link_libraries(test_runner PRIVATE libft)
add_test(NAME unit COMMAND test_runner)

# 2.e  Install rules – useful if you `make install`
install(TARGETS libft
        EXPORT libftTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        INCLUDES DESTINATION include)
install(DIRECTORY include/ DESTINATION include)
