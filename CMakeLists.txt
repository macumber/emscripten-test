cmake_minimum_required(VERSION 3.8)

set (CMAKE_CXX_STANDARD 11)

#if (MSVC_VERSION GREATER_EQUAL "1900")
#    include(CheckCXXCompilerFlag)
#    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
#    if (_cpp_latest_flag_supported)
#        add_compile_options("/std:c++latest")
#    endif()
#endif()

include_directories(dependencies)

set(test_lib_src
  src/utilities/geometry/Point3d.hpp
  src/utilities/geometry/Point3d.cpp
  src/utilities/geometry/Vector3d.hpp
  src/utilities/geometry/Vector3d.cpp
)

add_library(test_lib STATIC
  ${test_lib_src}
)

add_executable(test_exe
  src/main.cpp
)

target_link_libraries(test_exe test_lib)