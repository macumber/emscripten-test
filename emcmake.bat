REM https://github.com/juj/emsdk.git
REM https://stackoverflow.com/questions/45260216/emscripten-cmake-pass-emscripten-options-in-cmakelist-file
REM https://stackoverflow.com/questions/32099307/run-java-script-file-created-by-emscripten-from-another-java-script-file

mkdir embuild
cd embuild

..\cmake-3.10.2-win64-x64\bin\cmake -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE="..\..\emsdk\emscripten\1.37.26\cmake\Modules\Platform\Emscripten.cmake" -DEMSCRIPTEN_GENERATE_BITCODE_STATIC_LIBRARIES=ON ..

REM make clean
make

call ..\..\emsdk\emscripten\1.37.26\emcc --bind -s DEMANGLE_SUPPORT=1 libtest_lib.bc -o libtest_lib.js
REM call ..\..\emsdk\emscripten\1.37.26\emcc --bind -s DEMANGLE_SUPPORT=1 -s LINKABLE=1 -s EXPORT_ALL=1 libtest_lib.bc -o libtest_lib.js

cd ..