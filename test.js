var em_module = require('./embuild/libtest_lib.js');

var result = em_module.my_function(1,2,3);
console.log(result);
console.log(result.x());
console.log(result.y());
console.log(result.z());

var instance = new em_module.Point3d(1, 2, 3);
console.log(instance);
console.log(instance.x());
console.log(instance.y());
console.log(instance.z());