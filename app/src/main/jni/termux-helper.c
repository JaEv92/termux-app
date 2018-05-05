#include <jni.h>
#include <sys/stat.h>
#include <unistd.h>

#define TERMUX_UNUSED(x) x __attribute__((__unused__))

JNIEXPORT int JNICALL Java_com_termux_app_TermuxHelper_getFileUID(JNIEnv* env, jclass TERMUX_UNUSED(clazz), jstring path)
{
    struct stat st;
    
    if (path) {
        const char *file_path = (*env)->GetStringUTFChars(env, path, NULL);
        if(stat(file_path, &st) == 0) {
            return st.st_uid;
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

JNIEXPORT int JNICALL Java_com_termux_app_TermuxHelper_getAppUID(JNIEnv* TERMUX_UNUSED(env), jclass TERMUX_UNUSED(clazz))
{
    return getuid();
}
