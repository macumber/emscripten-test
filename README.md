This repository is for testing [Emscripten](http://kripken.github.io/emscripten-site/) on a portion of the OpenStudio SDK dealing with geometry.

## Usage

Create a folder named `embuild`

Extract the contents of the latest release `libtest_lib_release.zip` into that directory.

Copy the file `libtest_lib.js.mem` into the project's root directory (this is a temporary step).

Install [Node and npm](https://nodejs.org/en/download/)

Run the test script by running `node test.js` from the root directory

Install [npm serve](https://www.npmjs.com/package/serve)

Serve the test page by running `serve` from the root directory

## Building

Install the [Emscripten SDK](https://github.com/juj/emsdk)

Run the commands in the `emcmakebuild.bat` file

