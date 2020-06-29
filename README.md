# scope-lite - C++ standard libraries extensions, version 3: Generic scope and RAII Wrapper.

[![Language](https://img.shields.io/badge/C%2B%2B-98/11/14/17/20-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization) [![License](https://img.shields.io/badge/license-BSL-blue.svg)](https://opensource.org/licenses/BSL-1.0) [![Build Status](https://travis-ci.org/martinmoene/scope-lite.svg?branch=master)](https://travis-ci.org/martinmoene/scope-lite) [![Build status](https://ci.appveyor.com/api/projects/status/gpmw4gt271itoy2n?svg=true)](https://ci.appveyor.com/project/martinmoene/scope-lite) [![Version](https://badge.fury.io/gh/martinmoene%2Fscope-lite.svg)](https://github.com/martinmoene/scope-lite/releases) [![download](https://img.shields.io/badge/latest-download-blue.svg)](https://raw.githubusercontent.com/martinmoene/scope-lite/master/include/nonstd/scope.hpp) [![Conan](https://img.shields.io/badge/on-conan-blue.svg)](https://bintray.com/martinmoene/nonstd-lite/scope-lite%3Anonstd-lite/_latestVersion) [![Try it online](https://img.shields.io/badge/on-wandbox-blue.svg)](https://wandbox.org/) [![Try it on godbolt online](https://img.shields.io/badge/on-godbolt-blue.svg)](https://godbolt.org/)

**Contents**  

- [Example usage](#example-usage)
- [In a nutshell](#in-a-nutshell)
- [License](#license)
- [Dependencies](#dependencies)
- [Installation](#installation)
- [Synopsis](#synopsis)
- [Features](#features)
- [Reported to work with](#reported-to-work-with)
- [Building the tests](#building-the-tests)
- [Other implementations of scope](#other-implementations-of-scope)
- [Notes and references](#notes-and-references)
- [Appendix](#appendix)

## Example usage

```Cpp
#include "nonstd/scope.hpp"
#include <iostream>

using namespace nonstd;

int main()
{
    // TBD
}
```

### Compile and run

```Text
prompt> g++ -Wall -I../include -o 01-basic.exe 01-basic.cpp && 01-basic.exe
...
```

## In a nutshell

**scope lite** is a single-file header-only library to provide [C++ standard libraries extensions, version 3](https://en.cppreference.com/w/cpp/experimental/lib_extensions_3) for use with C++98 and later. If available, the standard library is used, unless [configured](#configuration) otherwise.

**Features and properties of scope lite** are ease of installation (single header), freedom of dependencies other than the standard library.

**Limitations of scope lite** are ... .

## License

*scope lite* is distributed under the [Boost Software License](https://github.com/martinmoene/scope-lite/blob/master/LICENSE.txt).


## Dependencies

*scope lite* has no other dependencies than the [C++ standard library](http://en.cppreference.com/w/cpp/header).


## Installation

*scope lite* is a single-file header-only library. Put `scope.hpp` in the [include](include) folder directly into the project source tree or somewhere reachable from your project.

## Synopsis

**Contents**  

[Documentation of C++ standard libraries extensions, version 3](#documentation-of-C-standard-libraries-extensions-version-3)
[Configuration](#configuration)  

### Documentation of C++ standard libraries extensions, version 3

Depending on the compiler and C++ standard used, *scope lite* behaves less or more like the standard's version. To get an idea of the capabilities of *scope lite* with your configuration, look at the output of the [tests](test/scope.t.cpp), issuing `scope-main.t --pass @`. For the standard's documentation, see [C++ standard libraries extensions, version 3](https://en.cppreference.com/w/cpp/experimental/lib_extensions_3).  

### Configuration

\-D<b>nssg\_CPLUSPLUS</b>=199711L  
Define this macro to override the auto-detection of the supported C++ standard, if your compiler does not set the `__cplusplus` macro correctly.

### Select standard library version or *scope lite*

At default, *scope lite* uses the standard library's version if it is available and lets you use it via namespace `nonstd`. You can however override this default and explicitly request to use the standard's version or *scope lite*'s header via the following macros.

-D<b>nssg\_CONFIG\_SELECT\_SCOPE</b>=scope_SCOPE_DEFAULT  
Define this to `scope_SCOPE_STD` to select standard's version. Define this to `scope_SCOPE_NONSTD` to select *scope lite*. Default is undefined, which has the same effect as defining to `scope_SCOPE_DEFAULT`.

## Reported to work with

TBD

## Building the tests

TBD

## Other implementations of scope

- [Example implementation](https://github.com/PeterSommerlad/SC22WG21_Papers/tree/master/workspace/P0052_scope_exit/src). Peter Sommerlad. 2018.

## Notes and references

*Interface and specification*

- Cppreference. [C++ standard libraries extensions, version 3](https://en.cppreference.com/w/cpp/experimental/lib_extensions_3)

*Proposals*

- [p0052 - Generic scope and RAII Wrapper for the Standard Library](wg21.link/p0052). Peter Sommerlad and Andrew L. Sandoval with contributions by Eric Niebler and Daniel Krügler

## Appendix

The [test program](test/scope.t.cpp) provides information on the compiler, the C++ language and library capabilities and the tests performed.

### A.1 Compile-time information

The version of *scope lite* is available via tag `[.version]`. The following tags are available for information on the compiler and on the C++ standard library used: `[.compiler]`, `[.stdc++]`, `[.stdlanguage]` and `[.stdlibrary]`.

### A.2 scope lite test specification

```Text
scope_exit: exit function is called at end of scope
scope_exit: exit function is called when an exception occurs
scope_exit: exit function is not called at end of scope when released
scope_fail: exit function is called when an exception occurs
scope_fail: exit function is not called when no exception occurs
scope_fail: exit function is not called when released
scope_success: exit function is called when no exception occurs
scope_success: exit function is not called when an exception occurs
scope_success: exit function is not called when released
```