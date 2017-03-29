LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := holamundondk
LOCAL_SRC_FILES := com_holamundondk_HolaMundoNDK.c
include $(BUILD_SHARED_LIBRARY)