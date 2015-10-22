# Callback

For Arduino, a header file that provides data types for callback functions, and an interface for classes that need to be called back.

I use callbacks in other libraries and wanted the definitions to be separate and in one place.

### Installation

If you're not using one of my other libraries, you might just want to cut and paste the code you need from `Callback.h` into your sketch.

If you want to make `Callback.h` accessible by the Arduino IDE as a library, just create a folder in your Arduino `libraries` folder named `Callback` and put these files and folders in it. `libraries` is located where your sketches are stored. Apparently, older Arduino versions did not keep libraries there, so YMMV.

### Tests & Usage

A sketch that tests the definitions, `CallbackTest`, is found in the `examples` folder. From it, you can glean examples of how to use `Callback.h`. If you run the test sketch, look for its output in the serial terminal at 9600 baud.

## License
(c) 2015, PhoneDeveloper LLC

Licensed under the BSD license. See the LICENSE file.

## Author
Sean Sheedy, PhoneDeveloper LLC