#ifndef __CONSOLE_LOG_H__
#define __CONSOLE_LOG_H__

#include <android/log.h>

#define ALOG_TAG "jxcore-cordova-jni"
#define LogD(...) \
  __android_log_print(ANDROID_LOG_DEBUG, ALOG_TAG, __VA_ARGS__)
#define LogW(...) \
  __android_log_print(ANDROID_LOG_WARN, ALOG_TAG, __VA_ARGS__)
#define LogE(...) \
  __android_log_print(ANDROID_LOG_ERROR, ALOG_TAG, __VA_ARGS__)

#endif // __CONSOLE_LOG_H__