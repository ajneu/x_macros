cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

set(target go)
set(src    go.cpp)



#add_library(target EXCLUDE_FROM_ALL go.cpp)
add_executable(${target} ${src})


add_custom_command(
  OUTPUT   go.preprocess.cpp
  DEPENDS  ${PROJECT_SOURCE_DIR}/go.cpp
  COMMAND "${CMAKE_CXX_COMPILER}" -D PREPROCESS_FOR_HUMANS -E ${PROJECT_SOURCE_DIR}/go.cpp > go.preprocess.cpp
  COMMENT "Preprocessing go.cpp (with -D PREPROCESS_FOR_HUMANS) to go.preprocess.cpp"
  VERBATIM)


add_custom_target(
  Preprocess ALL
  DEPENDS go.preprocess.cpp
#  COMMENT "Proprocess"
  VERBATIM)
