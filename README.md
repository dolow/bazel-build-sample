# What is this ?

This is a sample project for [Bazel](http://bazel.io/) build.

# Environment

- Android NDK r12b
- Android SDK 23
- Bazel 0.4.3

# How to build

## Android

add path to _android\_sdk\_repository_ and _android\_ndk\_repository_ in _WORKSPACE_ .

then run;

```
$ bazel build //Sandbox:android_app --crosstool_top=//external:android/crosstool --host_crosstool_top=@bazel_tools//tools/cpp:toolchain --cpu=x86_64
```

apk will be created in the directory below

```
bazel-bin/Sandbox/android_app.apk
```


## iOS

run

```
$ bazel build //Sandbox:ios_app --ios_sdk_version=9.0
```

ios_sdk_version must be the one installed in your environment.

Xcode project will be generated in the directory below

```
bazel-bin/Sandbox/ios_app.xcodeproj
```
