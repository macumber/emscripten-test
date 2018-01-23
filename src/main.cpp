#include "./utilities/geometry/Point3d.hpp"
#include "./utilities/geometry/Vector3d.hpp"

#include "./utilities/core/UUID.hpp"

using namespace openstudio;

int main(){

  Point3d p(1, 2, 3);
  Vector3d v(4, 5, 6);

  std::cout << p << std::endl;
  std::cout << v << std::endl;

  Point3d p2 = p + v;

  std::cout << p2 << std::endl;

  UUID uuid = createUUID();
  std::string uuidString = toString(uuid);
  UUID uuid2 = toUUID(uuidString);

  return 0;
}