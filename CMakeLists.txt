cmake_minimum_required(VERSION 3.10)

project(SolarSystem)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GLUT_INCLUDE_DIR "C:/Program Files/Common Files/MinGW/freeglut/include")
set(GLUT_glut_LIBRARY "C:/Program Files/Common Files/MinGW/freeglut/lib/libfreeglut.a")

include_directories(
  ${GLUT_INCLUDE_DIR}
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/src
)

link_directories("C:/Program Files/Common Files/MinGW/freeglut/lib")

find_package(OpenGL REQUIRED)

add_executable(main src/main.cpp)

target_link_libraries(main
  ${OPENGL_gl_LIBRARY}
  ${GLUT_glut_LIBRARY}
  glu32
)

set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
