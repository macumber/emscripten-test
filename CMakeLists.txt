cmake_minimum_required(VERSION 3.10)

if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
    if (_cpp_latest_flag_supported)
        add_compile_options("/std:c++latest")
        message("yay!")
    endif()
endif()

set(test_lib_src
  src/utilities/geometry/Point3d.hpp
  src/utilities/geometry/Point3d.cpp
)

add_library(test_lib
  ${test_lib_src}
)