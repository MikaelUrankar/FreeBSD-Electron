--- third_party/crashpad/crashpad/util/misc/uuid.cc.orig	2020-05-26 07:49:00 UTC
+++ third_party/crashpad/crashpad/util/misc/uuid.cc
@@ -95,7 +95,7 @@ bool UUID::InitializeWithNew() {
   InitializeFromBytes(uuid);
   return true;
 #elif defined(OS_WIN) || defined(OS_LINUX) || defined(OS_ANDROID) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
   // Linux, Android, and Fuchsia do not provide a UUID generator in a
   // widely-available system library. On Linux and Android, uuid_generate()
   // from libuuid is not available everywhere.
