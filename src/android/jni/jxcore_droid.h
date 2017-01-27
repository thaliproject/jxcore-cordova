// License information is available from LICENSE file

#ifndef __JXCORE_H__
#define __JXCORE_H__
#include "JniHelper.h"
#include "../jxcore-binaries/jx.h"
#include "console_log.h"

namespace jxcore {

void Callback(long id) {
  JniMethodInfo t;
  if (JniHelper::getStaticMethodInfo(t, "io/jxcore/node/jxcore",
                                     "callback", "(J)V")) {
    jvalue jv;
    jv.j = id;
    t.env->CallStaticVoidMethod(t.classID, t.methodID, jv);
    t.env->DeleteLocalRef(t.classID);
  }
}

void CallJava(jobject arr) {
  JniMethodInfo t;
  if (JniHelper::getStaticMethodInfo(t, "io/jxcore/node/jxcore",
                                  "javaCall", "(Ljava/util/ArrayList;)V")) {

    t.env->CallStaticVoidMethod(t.classID, t.methodID, arr);
    t.env->DeleteLocalRef(t.classID);
  }
}

void OnThread(const int attached) {
  if (attached == 0) {
    JniHelper::getEnv();  // attach current thread
  } else {
    JniHelper::getJavaVM()->DetachCurrentThread();
  }
}

int Initialize(JavaVM *vm) {
  JniHelper::setJavaVM(vm);

  return JNI_VERSION_1_4;
}
}

#endif  // __JXCORE_H__
