cmake_minimum_required(VERSION 3.2)
project(DeaneryProject)

# используем C++17
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# используем Boost.Program_options
# дабы не переусложнять, в качестве статической библиотеки
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${BOOST_INCLUDE_DIRS})

# исполняемый файл нашего приложения
add_executable(deanery_app main.cpp Student.h Group.h Deanery.h Student.cpp Group.cpp Deanery.cpp)
target_link_libraries(deanery_app ${Boost_LIBRARIES})
