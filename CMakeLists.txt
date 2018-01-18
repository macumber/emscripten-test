
set(test_lib_src
  src/utilities/geometry/Point3d.hpp
  src/utilities/geometry/Point3d.cpp
)

add_library(test_lib
  ${test_lib_src}
)