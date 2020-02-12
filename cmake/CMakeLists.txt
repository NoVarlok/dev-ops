cmake_minimum_required(VERSION 3.13.4)
project(myproject_app)

set(CMAKE_CXX_STANDARD 14)

add_executable(project_app main.cpp Deanery.cpp Group.cpp Student.cpp main.cpp Deanery.h Group.h Student.h)
# target_link_libraries(hello_world_app ${Boost_LIBRARIES})