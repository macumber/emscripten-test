#ifdef __EMSCRIPTEN__

  #include "Point3d.hpp"
  #include "Vector3d.hpp"
  #include "Geometry.hpp"

  #include "FloorplanJS.hpp"

  #include <emscripten.h>
  #include <emscripten/bind.h>
  using namespace emscripten;

  EMSCRIPTEN_BINDINGS(point3d_example) {

        class_<std::vector<T>> register_vector(const char* name) {
        typedef std::vector<T> VecType;

        void (VecType::*push_back)(const T&) = &VecType::push_back;
        void (VecType::*resize)(const size_t, const T&) = &VecType::resize;
        return class_<std::vector<T>>(name)
            .template constructor<>()
            .function("push_back", push_back)
            .function("resize", resize)
            .function("size", &VecType::size)
            .function("get", &internal::VectorAccess<VecType>::get)
            .function("set", &internal::VectorAccess<VecType>::set)
            ;
    }


    class_<boost::optional<double>>("OptionalDouble")
      .constructor<>()
      .function<double>("get", &boost::optional<double>::get)
      .function<bool>("is_initialized", &boost::optional<double>::is_initialized)
      ;

    class_<openstudio::Point3d>("Point3d")
      .constructor<double, double, double>()
      .function("x", &openstudio::Point3d::x)
      .function("y", &openstudio::Point3d::y)
      .function("z", &openstudio::Point3d::z)
      ;
    register_vector<openstudio::Point3d>("Point3dVector");

    class_<openstudio::Vector3d>("Vector3d")
      .constructor<double, double, double>()
      .function("x", &openstudio::Vector3d::x)
      .function("y", &openstudio::Vector3d::y)
      .function("z", &openstudio::Vector3d::z)
      ;
    register_vector<openstudio::Vector3d>("Vector3dVector");

    function("floorplanToThreeJS", &openstudio::floorplanToThreeJS);

    function("getArea", &openstudio::getArea);

  }

#endif