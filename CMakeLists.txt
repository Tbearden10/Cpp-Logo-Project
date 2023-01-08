cmake_minimum_required(VERSION 3.21)
project(CPP-Logo LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(CPP-Logo src/Triangle.cpp src/Triangle.h src/Coordinate.h src/main.cpp)
target_link_libraries(CPP-Logo PRIVATE sfml-graphics)
target_compile_features(CPP-Logo PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET CPP-Logo POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:CPP-Logo> $<TARGET_FILE_DIR:CPP-Logo> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS CPP-Logo)
