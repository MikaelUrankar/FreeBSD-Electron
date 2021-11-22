--- headless/lib/browser/headless_browser_main_parts.h.orig	2021-09-14 01:51:58 UTC
+++ headless/lib/browser/headless_browser_main_parts.h
@@ -44,7 +44,7 @@ class HeadlessBrowserMainParts : public content::Brows
 #if defined(OS_MAC)
   void PreCreateMainMessageLoop() override;
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   void PostCreateMainMessageLoop() override;
 #endif
   void QuitMainMessageLoop();
