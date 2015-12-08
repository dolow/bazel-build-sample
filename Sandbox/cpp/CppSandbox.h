#include <jni.h>

extern "C"
{
    jint JNI_OnLoad(JavaVM *vm, void *reserved);

    void Java_jp_do_1low_bazel_sample_AppActivity_jniCallback(JNIEnv* env, jclass cls, jstring val);
}

class CppSandbox
{
public:
    CppSandbox();
    ~CppSandbox();
    
    static void test();
};
