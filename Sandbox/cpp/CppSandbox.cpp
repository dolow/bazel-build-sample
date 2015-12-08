#include "CppSandbox.h"
#include <iostream>
#include <android/log.h>

#define LOG_INFO(text)  __android_log_print(ANDROID_LOG_INFO, "sandbox", #text);
#define LOG_INFO_F(...) __android_log_print(ANDROID_LOG_INFO, "sandbox", ##__VA_ARGS__);

static JavaVM* VM  = nullptr;
static JNIEnv* env = nullptr;

extern "C"
{
    jint JNI_OnLoad(JavaVM *vm, void *reserved)
    {
        VM = vm;
        return JNI_VERSION_1_4;
    }

    void Java_jp_do_1low_bazel_sample_AppActivity_jniCallback(JNIEnv* env, jclass cls, jstring val)
    {
        const char* str = env->GetStringUTFChars(val, 0);
        LOG_INFO_F("jni callback %s", str);
        env->ReleaseStringUTFChars(val, str);

        CppSandbox::test();
    }
}

CppSandbox::CppSandbox()  {}
CppSandbox::~CppSandbox() {}
    
void CppSandbox::test()
{
    LOG_INFO("cpp test");
    
    do {
        if (VM == nullptr) {
            LOG_INFO("VM is nullptr");
            break;
        }
    
        if (env == nullptr) {
            int status;
            status = VM->GetEnv((void **)&env, JNI_VERSION_1_4);
            if (status < 0) {
                LOG_INFO("couldn't get env");
                break;
            }
        
            status = VM->AttachCurrentThread(&env, 0);
            if (status < 0) {
                LOG_INFO("couldn't attach thread");
                break;
            }
        }
        
        jclass javaClass = env->FindClass("jp/do_low/bazel/sample/AppActivity");
        if (!javaClass) {
            LOG_INFO("java class not found.");
            break;
        }
        
        jmethodID method = env->GetStaticMethodID(javaClass, "jniCall", "(Ljava/lang/String;)V");
        if (!method) {
            LOG_INFO("java method not found.");
            break;
        }
        
        jstring arg = env->NewStringUTF("string from cpp");
        env->CallStaticVoidMethod(javaClass, method, arg);
    } while(0);
}
