--- node_modules/playwright-core/lib/utils/registry.js.orig	2022-01-08 06:19:19 UTC
+++ node_modules/playwright-core/lib/utils/registry.js
@@ -177,7 +177,7 @@ const registryDirectory = (() => {
     result = envDefined;
   } else {
     let cacheDirectory;
-    if (process.platform === 'linux') cacheDirectory = process.env.XDG_CACHE_HOME || _path.default.join(os.homedir(), '.cache');else if (process.platform === 'darwin') cacheDirectory = _path.default.join(os.homedir(), 'Library', 'Caches');else if (process.platform === 'win32') cacheDirectory = process.env.LOCALAPPDATA || _path.default.join(os.homedir(), 'AppData', 'Local');else throw new Error('Unsupported platform: ' + process.platform);
+    if (process.platform === 'linux' || process.platform === 'freebsd') cacheDirectory = process.env.XDG_CACHE_HOME || _path.default.join(os.homedir(), '.cache');else if (process.platform === 'darwin') cacheDirectory = _path.default.join(os.homedir(), 'Library', 'Caches');else if (process.platform === 'win32') cacheDirectory = process.env.LOCALAPPDATA || _path.default.join(os.homedir(), 'AppData', 'Local');else throw new Error('Unsupported platform: ' + process.platform);
     result = _path.default.join(cacheDirectory, 'ms-playwright');
   }
 
@@ -734,4 +734,4 @@ function findChromiumChannel(sdkLanguage) {
 
 const registry = new Registry(require('../../browsers.json'));
 exports.registry = registry;
-//# sourceMappingURL=registry.js.map
\ No newline at end of file
+//# sourceMappingURL=registry.js.map
