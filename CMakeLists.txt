cmake_minimum_required(VERSION 3.12.1)
project(fdf C)

set(CMAKE_C_STANDARD 99)

aux_source_directory(libft LBFT_SRC)
aux_source_directory(src SOURCES)
add_library(ft STATIC ${LBFT_SRC})
include_directories(libft/includes)
include_directories(inc)

add_executable(${CMAKE_PROJECT_NAME}
                ${SOURCES}  src/control.c)

#set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
target_link_libraries(${CMAKE_PROJECT_NAME} ft "-lmlx -framework OpenGL -framework AppKit")