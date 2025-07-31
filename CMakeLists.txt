cmake_minimum_required(VERSION 3.20)


set(PROJECT_NAME main)

add_executable(${PROJECT_NAME} src/main.cpp)
#target_link_libraries(main PRIVATE sfml-graphics sfml-window sfml-system)