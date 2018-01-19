#ifdef __EMSCRIPTEN__

  #include "Point3d.hpp"
  #include "FloorplanJS.hpp"

  #include <emscripten.h>
  #include <emscripten/bind.h>
  using namespace emscripten;

  EMSCRIPTEN_BINDINGS(point3d_example) {
    class_<openstudio::Point3d>("Point3d")
      .constructor<double, double, double>()
      .function("x", &openstudio::Point3d::x)
      .function("y", &openstudio::Point3d::y)
      .function("z", &openstudio::Point3d::z)
      ;

    function("floorplanToThreeJS", &openstudio::floorplanToThreeJS);
  }

#endif