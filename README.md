# color_test

## Building for Xcode

### Prerequisites:
 - Installed CMake with version 3.18.3 or higher.
 - Installed Xcode.

To generate Xcode project run this command sequence in terminal:
```
git clone https://github.com/rokoDev/color_test.git
cd color_test
mkdir build
cd build
cmake -GXcode ..
```

Then run this command to open Xcode project:
```
cmake --open ./
```

In Xcode choose `color_test` target and hit `command+R` to run the `color_test` app.