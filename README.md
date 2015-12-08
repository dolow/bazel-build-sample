# What is this ?

This is a sample project for [Bazel](http://bazel.io/) build.

# Environment

- Android NDK r10e
- Android SDK 22
- Bazel 0.1.1

# How to build

add path to _android\_sdk\_repository_ and _android\_ndk\_repository_ in _WORKSPACE_ .

then run;

```
$ bazel build //Sandbox:app --crosstool_top=@androidndk//:toolchain --host_crosstool_top=//tools/cpp:toolchain
```

apk will be created in the directory below

```
bazel-bin/Sandbox/app.apk
```
