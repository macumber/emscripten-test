This repository is for testing [Emscripten](http://kripken.github.io/emscripten-site/) on a portion of the OpenStudio SDK dealing with geometry.

## Usage

Create a folder named `embuild`

Extract the contents of the latest release `libtest_lib_release.zip` into that directory.

Install [Node and npm](https://nodejs.org/en/download/)

Run the test script by running `node test.js` from the root directory

Install [npm serve](https://www.npmjs.com/package/serve)

Serve the test page by running `serve` from the root directory

## Building

docker build -t emscripten_test_builder .
docker run -it --mount src=$(pwd),target=/src,type=bind emscripten_test_builder

