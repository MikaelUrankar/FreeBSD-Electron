--- third_party/ffmpeg/libavutil/cpu.c.orig	2022-05-11 07:17:29 UTC
+++ third_party/ffmpeg/libavutil/cpu.c
@@ -36,10 +36,7 @@
 #if HAVE_GETPROCESSAFFINITYMASK || HAVE_WINRT
 #include <windows.h>
 #endif
-#if HAVE_SYSCTL
-#if HAVE_SYS_PARAM_H
-#include <sys/param.h>
-#endif
+#if HAVE_SYSCTL && !defined(__OpenBSD__)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
