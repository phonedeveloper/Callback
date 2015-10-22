#line 2 "CallbackTest.ino"
#include <ArduinoUnit.h>

/*
 * CallbackTest - test the Callback library
 * 
 * Uses arduinounit from https://github.com/mmurdoch/arduinounit
 * 
 * Executed on an Arduino Mega ADK.
 * 
 * Author: PhoneDeveloper, LLC
 * Date: 10/22/2015
 *
 * Copyright (c) 2015, PhoneDeveloper, LLC
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <Callback.h>

/*
 * Change this each build and ensure that the version number is reflected
 * in the serial output at the start of the tests.
 */
static const char* VERSION = "0.0.2";
static const char* VERSION_STRING = "CallbackTest sketch version ";

/*
 * Variables that will be set by callback functions during test.
 */
boolean callbackCalled;
boolean booleanParameter;
char* charPointerParameter;
String stringParameter;
char charParameter;
unsigned char unsignedCharParameter;
int intParameter;
unsigned int unsignedIntParameter;
long longParameter;
unsigned long unsignedLongParameter;
float floatParameter;
double doubleParameter;
void* voidPointerParameter;

/*
 * A class that can be called back
 */
class MyTest : public Callable {
private:
  void* pointerValue = (void*) 0;
public:
  void callback(void* pointer);
  void* getPointerValue();
};

void MyTest::callback(void* pointer) {
  pointerValue = pointer;
}

void* MyTest::getPointerValue() {
  return pointerValue;
}

/*
 * Initializes above variables.
 */
void initializeTest() {
  callbackCalled = false;
  booleanParameter = false;
  charPointerParameter = (char*) 0;
  stringParameter = "";
  charParameter = 0;
  unsignedCharParameter = 0;
  intParameter = 0;
  unsignedIntParameter = 0;
  longParameter = 0l;
  unsignedLongParameter = 0ul;
  floatParameter = 0.0;
  doubleParameter = 0.0;
  voidPointerParameter = (void*) 0;
}

/*
 * Functions that will be called back during test.
 * Each sets a global variable that the caller can later check.
 */
void callback() {
  callbackCalled = true;
}

void callbackTakesBool(boolean value) {
  booleanParameter = value;
}

void callbackTakesCharPointer(char* value) {
  charPointerParameter = value;
}

void callbackTakesString(String value) {
  stringParameter = value;
}

void callbackTakesChar(char value) {
  charParameter = value;
}

void callbackTakesUnsignedChar(unsigned char value) {
  unsignedCharParameter = value;
}

void callbackTakesInt(int value) {
  intParameter = value;
}

void callbackTakesUnsignedInt(unsigned int value) {
  unsignedIntParameter = value;
}

void callbackTakesLong(long value) {
  longParameter = value;
}

void callbackTakesUnsignedLong(unsigned long value) {
  unsignedLongParameter = value;
}

void callbackTakesFloat(float value) {
  floatParameter = value;
}

void callbackTakesDouble(double value) {
  doubleParameter = value;
}

void callbackTakesVoidPointer(void* value) {
  voidPointerParameter = value;
}

/*
 * The tests.
 */
test(Callback) {
  initializeTest();
  assertFalse(callbackCalled);
  Callback function = callback;
  function();
  assertTrue(callbackCalled);
}

test(CallbackTakesBool) {
  initializeTest();
  assertFalse(booleanParameter);
  CallbackTakesBool function = callbackTakesBool;
  function(true);
  assertTrue(booleanParameter);
}

test(CallbackTakesCharPointer) {
  initializeTest();
  assertEqual(charPointerParameter, (char*) 0);
  CallbackTakesCharPointer function = callbackTakesCharPointer;
  char* c = "a";
  function(c);
  assertEqual(*charPointerParameter, 'a');
}

test(CallbackTakesString) {
  initializeTest();
  if (stringParameter == "") {
    assertTrue(true);
  } else {
    assertTrue(false);
  }
  CallbackTakesString function = callbackTakesString;
  function("hi");
  if (stringParameter == "hi") {
    assertTrue(true); 
  } else {
    assertTrue(false);
  }
}

test(CallbackTakesChar) {
  initializeTest();
  assertEqual(charParameter, 0);
  CallbackTakesChar function = callbackTakesChar;
  function('a');
  assertEqual(charParameter, 'a');
}

test(CallbackTakesUnsignedChar) {
  initializeTest();
  assertEqual(unsignedCharParameter, 0);
  CallbackTakesUnsignedChar function = callbackTakesUnsignedChar;
  function('a');
  assertEqual(unsignedCharParameter, 'a');
}

test(CallbackTakesInt) {
  initializeTest();
  assertEqual(intParameter, 0);
  CallbackTakesInt function = callbackTakesInt;
  function('a');
  assertEqual(intParameter, 'a');
}

test(CallbackTakesUnsignedInt) {
  initializeTest();
  assertEqual(unsignedIntParameter, 0);
  CallbackTakesUnsignedInt function = callbackTakesUnsignedInt;
  function('a');
  assertEqual(unsignedIntParameter, 'a');
}

test(CallbackTakesLong) {
  initializeTest();
  assertEqual(longParameter, 0);
  CallbackTakesLong function = callbackTakesLong;
  function('a');
  assertEqual(longParameter, 'a');
}

test(CallbackTakesUnsignedLong) {
  initializeTest();
  assertEqual(unsignedLongParameter, 0);
  CallbackTakesUnsignedLong function = callbackTakesUnsignedLong;
  function('a');
  assertEqual(unsignedLongParameter, 'a');
}

test(CallbackTakesFloat) {
  initializeTest();
  assertEqual(floatParameter, 0);
  CallbackTakesFloat function = callbackTakesFloat;
  function('a');
  assertEqual(floatParameter, 'a');
}

test(CallbackTakesDouble) {
  initializeTest();
  assertEqual(doubleParameter, 0);
  CallbackTakesDouble function = callbackTakesDouble;
  function('a');
  assertEqual(doubleParameter, 'a');
}

test(CallbackTakesVoidPointer) {
  initializeTest();
  assertEqual((unsigned long)voidPointerParameter, 0);
  CallbackTakesVoidPointer function = callbackTakesVoidPointer;
  function((void*) 0xffff);
  assertEqual((unsigned long)voidPointerParameter, 0xffff);
}

test(CallbackMethod) {
  MyTest testInstance;
  assertEqual((unsigned long)testInstance.getPointerValue(), 0);

  Callable* caller = &testInstance;
  caller->callback((void*) 0xffff);
  
  assertEqual((unsigned long)testInstance.getPointerValue(), 0xffff);
}


/*
 * The rest is for arduinounit.
 */
void setup() {
  Serial.begin(9600);
  Serial.print(VERSION_STRING);
  Serial.println(VERSION);
}

void loop() {
  Test::run();
}
