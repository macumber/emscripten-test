var em_module = require('./embuild/libtest_lib.js');

var instance = new em_module.Point3d(1, 2, 3);
console.log(instance);
console.log(instance.x());
console.log(instance.y());
console.log(instance.z());