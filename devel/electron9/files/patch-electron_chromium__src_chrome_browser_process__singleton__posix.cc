--- electron/chromium_src/chrome/browser/process_singleton_posix.cc.orig	2020-05-18 21:17:08 UTC
+++ electron/chromium_src/chrome/browser/process_singleton_posix.cc
@@ -94,7 +94,7 @@
 #include "content/public/browser/browser_thread.h"
 #include "net/base/network_interfaces.h"
 
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(TOOLKIT_VIEWS) && ((defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD))
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -861,7 +861,7 @@ ProcessSingleton::NotifyResult ProcessSingleton::Notif
     // The other process is shutting down, it's safe to start a new process.
     return PROCESS_NONE;
   } else if (strncmp(buf, kACKToken, base::size(kACKToken) - 1) == 0) {
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(TOOLKIT_VIEWS) && ((defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD))
     // Likely NULL in unit tests.
     views::LinuxUI* linux_ui = views::LinuxUI::instance();
     if (linux_ui)
