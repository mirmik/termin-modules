cmake_minimum_required(VERSION 3.16)
project(termin_modules LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/TerminModule.cmake)

find_package(Python COMPONENTS Interpreter Development REQUIRED)

if(NOT TARGET tcbase::termin_base)
    set(TERMIN_BASE_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(TERMIN_BUILD_PYTHON OFF CACHE BOOL "" FORCE)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../termin-base ${CMAKE_CURRENT_BINARY_DIR}/termin-base)
    if(TARGET termin_base AND NOT TARGET tcbase::termin_base)
        add_library(tcbase::termin_base ALIAS termin_base)
    endif()
endif()

add_library(termin_modules STATIC
    src/module_cpp_backend.cpp
    src/module_descriptor_parser.cpp
    src/module_python_backend.cpp
    src/module_runtime.cpp
)

target_compile_features(termin_modules PUBLIC cxx_std_20)

target_include_directories(termin_modules
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(termin_modules
    PUBLIC
        tcbase::termin_base
        Python::Python
        ${CMAKE_DL_LIBS}
)

add_executable(termin_modules_example
    examples/basic/main.cpp
)

target_link_libraries(termin_modules_example PRIVATE termin_modules)
target_compile_definitions(termin_modules_example PRIVATE
    TERMIN_MODULES_EXAMPLE_PROJECT_DIR="${CMAKE_CURRENT_SOURCE_DIR}/examples/basic/project"
)
