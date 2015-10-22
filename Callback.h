#ifndef Callback_h
#define Callback_h

/**
 * @file Callback.h
 * @author PhoneDeveloper, LLC
 * @date 10/20/2015
 * @brief Header file for Callback library
 * 
 * This is the header file for the Callback library for Arduino.
 * 
 * The Callback library provides typedefs for function pointers that
 * take different data types, and an interface class that defines a
 * method signature.
 * 
 * More information about Callback can be found in the README.md file of
 * the Callback GitHub project at https://github.com/PhoneDeveloper/Callback.
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
#include "Arduino.h"

/*
 * These typedefs define pointers to functions that take different data types as parameters.
 */
typedef void (*Callback)(void);
typedef void (*CallbackTakesBool)(bool);
typedef void (*CallbackTakesCharPointer)(char*);
typedef void (*CallbackTakesString)(String);
typedef void (*CallbackTakesChar)(char);
typedef void (*CallbackTakesUnsignedChar)(unsigned char);
typedef void (*CallbackTakesInt)(int);
typedef void (*CallbackTakesUnsignedInt)(unsigned int);
typedef void (*CallbackTakesLong)(long);
typedef void (*CallbackTakesUnsignedLong)(unsigned long);
typedef void (*CallbackTakesFloat)(float);
typedef void (*CallbackTakesDouble)(double);
typedef void (*CallbackTakesVoidPointer)(void*);

/**
 * @class Callable
 * @author Sean Sheedy
 * @date 10/10/2015
 * @file Callback.h
 * @brief Provides a callback method for class instances wishing to be called back
 * 
 * 
 */
class Callable
{
public:
    virtual void callback(void* pointer);
};

#endif