// See the LICENSE file

/* JXcoreProxy allows the native code to invoke the JXCore API JX_CreateThread.
 * JX_CreateThread creates a SpiderMonkey thread to run a second instance of
 * the javascript engine. That second instance can be started and stopped at 
 * will, while the main engine instance can only be created and started once.
 */

#ifndef JXcoreProxy_h
#define JXcoreProxy_h

#include "jx.h"
#include "JXcore.h"

/* The callback passed to JX_CreateThread. It calls the iOS native method that
 * instanciates the child javascript engine.
 */
static void JXcoreProxy_CB(void *arg) {
    NSLog(@"JXcoreProxy: callback invoked.");
    [JXcore startChildEngine];
}

/* Call JX_CreateThread passing the callback to run native iOS code on the thread
 * created by SpiderMonkey.
 */
static void JXcoreProxy_CreateThread() {
    NSLog(@"JXcoreProxy: create thread.");
    JX_CreateThread(JXcoreProxy_CB);
}

#endif /* JXcoreProxy_h */