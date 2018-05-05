LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE:= libtermux-helper
LOCAL_SRC_FILES:= termux-helper.c
include $(BUILD_SHARED_LIBRARY)
