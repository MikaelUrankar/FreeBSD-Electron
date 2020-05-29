--- electron/script/lib/utils.js.orig	2020-05-18 21:17:08 UTC
+++ electron/script/lib/utils.js
@@ -18,7 +18,7 @@ function getElectronExec () {
       return `out/${OUT_DIR}/Electron.app/Contents/MacOS/Electron`;
     case 'win32':
       return `out/${OUT_DIR}/electron.exe`;
-    case 'linux':
+    case 'linux': case 'freebsd':
       return `out/${OUT_DIR}/electron`;
     default:
       throw new Error('Unknown platform');
