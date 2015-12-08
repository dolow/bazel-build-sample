# cpp library
cc_library (
    name = "sandbox_cpp",
    srcs = glob(["cpp/*.cpp"]),
    hdrs = glob(["cpp/*.h"]),
    copts = ["-std=c++11"],
    linkopts = ["-llog"],
)

# java project
android_binary (
    name = "app",
    srcs = glob(["java/**/*.java"]),
    custom_package = "jp.do_low.bazel.sample",
    manifest = "AndroidManifest.xml",
    resource_files = glob(["res/**"]),
    deps = ["//external:android/appcompat_v4", ":sandbox_cpp"],
    legacy_native_support = 0,
)

