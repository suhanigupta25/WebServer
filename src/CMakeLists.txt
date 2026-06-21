file(GLOB_RECURSE PROJECT_SOURCES
        "*.cpp"
        "*.h"
)

add_library(project_core STATIC ${PROJECT_SOURCES})
target_include_directories(project_core PUBLIC .)
target_link_directories(project_core PUBLIC .)
add_executable(project main.cpp)
target_link_libraries(project PRIVATE project_core)

if(MSVC)
    target_compile_options(project_core PRIVATE /W4)
else()
    target_compile_options(project_core PRIVATE -Wall -Wextra -Wpedantic)
endif()