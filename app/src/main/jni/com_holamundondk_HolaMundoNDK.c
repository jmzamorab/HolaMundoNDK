#include "com_holamundondk_HolaMundoNDK.h"
JNIEXPORT jstring Java_com_holamundondk_HolaMundoNDK_dameDatos (JNIEnv * env, jobject this) {
    return (*env)->NewStringUTF(env,"App nativa");
}