REM https://stackoverflow.com/questions/45260216/emscripten-cmake-pass-emscripten-options-in-cmakelist-file

mkdir embuild
cd embuild
..\cmake-3.10.2-win64-x64\bin\cmake -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE="../../emsdk/emscripten/1.37.26/cmake/Modules/Platform/Emscripten.cmake"  ..
make
cd ..