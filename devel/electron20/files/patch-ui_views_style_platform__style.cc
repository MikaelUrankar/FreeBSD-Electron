--- ui/views/style/platform_style.cc.orig	2022-08-01 19:04:54 UTC
+++ ui/views/style/platform_style.cc
@@ -52,7 +52,7 @@ const View::FocusBehavior PlatformStyle::kDefaultFocus
 const bool PlatformStyle::kAdjustBubbleIfOffscreen =
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     false;
 #else
     true;
