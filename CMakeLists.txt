cmake_minimum_required(VERSION 3.22)

project(chess)

add_executable(${PROJECT_NAME} 
    src/main.cpp 
    src/board.cpp
    src/pieces.cpp
    src/move_parser.cpp
    )


find_package(X11 REQUIRED)

# 2. Create an imported target for the precompiled static library
add_library(raylib STATIC IMPORTED)

# 3. Specify the absolute path to the .a file
set_target_properties(raylib PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/libraylib.a"
)

# 4. Point to the folder containing the .h files
target_include_directories(raylib INTERFACE 
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# 5. Link the imported library to your main application
target_link_libraries(${PROJECT_NAME} PRIVATE raylib ${X11_LIBRARIES})
