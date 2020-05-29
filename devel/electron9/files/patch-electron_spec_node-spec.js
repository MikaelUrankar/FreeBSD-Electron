--- electron/spec/node-spec.js.orig	2020-05-18 21:17:08 UTC
+++ electron/spec/node-spec.js
@@ -143,7 +143,7 @@ describe('node feature', () => {
     });
 
     describe('child_process.exec', () => {
-      (process.platform === 'linux' ? it : it.skip)('allows executing a setuid binary from non-sandboxed renderer', () => {
+      (process.platform === 'linux' || process.platform === 'freebsd' ? it : it.skip)('allows executing a setuid binary from non-sandboxed renderer', () => {
         // Chrome uses prctl(2) to set the NO_NEW_PRIVILEGES flag on Linux (see
         // https://github.com/torvalds/linux/blob/40fde647cc/Documentation/userspace-api/no_new_privs.rst).
         // We disable this for unsandboxed processes, which the renderer tests
