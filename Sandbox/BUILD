# cpp library
cc_library (
    name = "android_app_cpp",
    srcs = glob(["cpp/*.cpp"]),
    hdrs = glob(["cpp/*.h"]),
    copts = ["-std=c++11"],
    linkopts = ["-llog"],
)

# java project
android_binary (
    name = "android_app",
    srcs = glob(["java/**/*.java"]),
    custom_package = "jp.do_low.bazel.sample",
    manifest = "android/AndroidManifest.xml",
    resource_files = glob(["res/**"]),
    deps = ["//external:android/appcompat_v4", ":android_app_cpp"],
    legacy_native_support = 0,
)


objc_binary (
    name = "ios_app_binary",
    #srcs = ["objc/main.m"],
    srcs = glob(["objc/*.m"]),
    hdrs = glob(["objc/*.h"]),
    #deps = [":ios_app_library"],
)

# ios project
ios_application (
    name      = "ios_app",
    bundle_id = "jp.do_low.bazel.sample",
    binary    = ":ios_app_binary",
    infoplist = "ios/Info.plist",
)
