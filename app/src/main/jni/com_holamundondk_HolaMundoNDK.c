#include "com_holamundondk_HolaMundoNDK.h"
#include <android/log.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LOG_TAG "HolaMundoNDK"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

JNIEXPORT jstring Java_com_holamundondk_HolaMundoNDK_dameDatos (JNIEnv * env, jobject this) {
    return (*env)->NewStringUTF(env,"App nativa");
}
jstring Java_com_holamundondk_HolaMundoNDK_funcion1(JNIEnv* env,
jobject thiz, jstring message) {
const char *nativeString = (*env)->GetStringUTFChars(env, message, 0);
LOGI("funcion1 llamada! Parametro entrante: %s", nativeString);
(*env)->ReleaseStringUTFChars(env, message, nativeString);
return (*env)->NewStringUTF(env, "Llamada nativa JNI realizada!");
}
void Java_com_holamundondk_HolaMundoNDK_funcion2(JNIEnv* env,
jobject thiz) {
LOGI("funcion2 llamada!");
jclass clazz = (*env)->GetObjectClass(env, thiz);
if (!clazz) {
LOGE("callback_handler: FALLO object Class");
goto failure;
}
jmethodID method = (*env)->GetMethodID(env, clazz, "funcion3Callback", "()V");
if (!method) {
LOGE("callback_hand ler: FALLO metodo ID");
goto failure;
}
(*env)->CallVoidMethod(env, thiz, method);
failure: return;
}