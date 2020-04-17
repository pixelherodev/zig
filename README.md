![ZIG](https://ziglang.org/zig-logo.svg)

## This repository

This repository contains backported fixes from upstream, and is otherwise
identical to the 0.6 release.

I am doing this for my own benefit. There is no guarantee that I will
continue to do this. You're welcome to help, or to ask nicely how it's going,
but don't insist that I put in work on your behalf.

I don't mean to come across rudely, but I'm taking a great deal of work onto
myself and I will almost certainly choose to give up before 0.7, and would
rather make it clear now that I'm not going to continue if that happens.

## Zig

A general-purpose programming language and toolchain for maintaining
**robust**, **optimal**, and **reusable** software.

## Resources

 * [Introduction](https://ziglang.org/#Introduction)
 * [Download & Documentation](https://ziglang.org/download)
 * [Community](https://github.com/ziglang/zig/wiki/Community)
 * [Contributing](https://github.com/ziglang/zig/blob/master/CONTRIBUTING.md)
 * [Frequently Asked Questions](https://github.com/ziglang/zig/wiki/FAQ)
 * [Community Projects](https://github.com/ziglang/zig/wiki/Community-Projects)

## Building from Source

[![Build Status](https://dev.azure.com/ziglang/zig/_apis/build/status/ziglang.zig?branchName=master)](https://dev.azure.com/ziglang/zig/_build/latest?definitionId=1&branchName=master)

Note that you can
[download a binary of master branch](https://ziglang.org/download/#release-master).

### Stage 1: Build Zig from C++ Source Code

#### Dependencies

##### POSIX

 * cmake >= 2.8.5
 * gcc >= 5.0.0 or clang >= 3.6.0
 * LLVM, Clang, LLD development libraries == 10.x, compiled with the same gcc or clang version above
   - Use the system package manager, or [build from source](https://github.com/ziglang/zig/wiki/How-to-build-LLVM,-libclang,-and-liblld-from-source#posix).

##### Windows

 * cmake >= 3.15.3
 * Microsoft Visual Studio. Supported versions:
   - 2015 (version 14)
   - 2017 (version 15.8)
   - 2019 (version 16)
 * LLVM, Clang, LLD development libraries == 10.x
   - Use the [pre-built binaries](https://github.com/ziglang/zig/wiki/Building-Zig-on-Windows) or [build from source](https://github.com/ziglang/zig/wiki/How-to-build-LLVM,-libclang,-and-liblld-from-source#windows).

#### Instructions

##### POSIX

```
mkdir build
cd build
cmake ..
make install
```

##### MacOS

```
brew install cmake llvm
brew outdated llvm || brew upgrade llvm
mkdir build
cd build
cmake .. -DCMAKE_PREFIX_PATH=$(brew --prefix llvm)
make install
```

You will now run into this issue:
[homebrew and llvm 10 packages in apt.llvm.org are broken with undefined reference to getPollyPluginInfo](https://github.com/ziglang/zig/issues/4799)

Please help upstream LLVM and Homebrew solve this issue, there is nothing Zig
can do about it. See that issue for a workaround you can do in the meantime.

##### Windows

See https://github.com/ziglang/zig/wiki/Building-Zig-on-Windows

### Stage 2: Build Self-Hosted Zig from Zig Source Code

*Note: Stage 2 compiler is not complete. Beta users of Zig should use the
Stage 1 compiler for now.*

Dependencies are the same as Stage 1, except now you can use stage 1 to compile
Zig code.

```
bin/zig build --prefix $(pwd)/stage2
```

This produces `./stage2/bin/zig` which can be used for testing and development.
Once it is feature complete, it will be used to build stage 3 - the final compiler
binary.

### Stage 3: Rebuild Self-Hosted Zig Using the Self-Hosted Compiler

*Note: Stage 2 compiler is not yet able to build Stage 3. Building Stage 3 is
not yet supported.*

Once the self-hosted compiler can build itself, this will be the actual
compiler binary that we will install to the system. Until then, users should
use stage 1.

#### Debug / Development Build

```
./stage2/bin/zig build --prefix $(pwd)/stage3
```

#### Release / Install Build

```
./stage2/bin/zig build install -Drelease
```
