cmake_minimum_required(VERSION 3.8)

set (CMAKE_CXX_STANDARD 11)

#if (MSVC_VERSION GREATER_EQUAL "1900")
#    include(CheckCXXCompilerFlag)
#    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
#    if (_cpp_latest_flag_supported)
#        add_compile_options("/std:c++latest")
#    endif()
#endif()

# require these run time checks
add_definitions(-DBOOST_UBLAS_CHECK_ENABLE)
add_definitions(-DBOOST_UBLAS_TYPE_CHECK)
add_definitions(-DBOOST_UBLAS_NO_STD_CERR)

include_directories(dependencies)

set(test_lib_src
  src/utilities/data/Matrix.hpp
  src/utilities/data/Matrix.cpp
  src/utilities/data/Vector.hpp
  src/utilities/data/Vector.cpp
  src/utilities/geometry/BoundingBox.hpp
  src/utilities/geometry/BoundingBox.cpp
  src/utilities/geometry/EulerAngles.hpp
  src/utilities/geometry/EulerAngles.cpp
  src/utilities/geometry/Geometry.hpp
  src/utilities/geometry/Geometry.cpp
  src/utilities/geometry/Point3d.hpp
  src/utilities/geometry/Point3d.cpp
  src/utilities/geometry/Transformation.hpp
  src/utilities/geometry/Transformation.cpp
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