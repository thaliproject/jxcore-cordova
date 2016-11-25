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

/* The callback passed to JX_CreateRIThread. It calls the iOS native method that
 * instanciates the restart-able instance engine.
 */
static void JXcoreProxy_RI_CB(void *arg) {
    NSLog(@"JXcoreProxy: RI thread callback invoked.");
    [JXcore startRIChildEngine];
}

/* Call JX_CreateRIThread passing the callback to run native iOS code on the
 * restart-able instance thread created by SpiderMonkey.
 */
static void JXcoreProxy_CreateRIThread() {
    NSLog(@"JXcoreProxy: create RI thread.");
    JX_CreateRIThread(JXcoreProxy_RI_CB);
}

#endif /* JXcoreProxy_h */