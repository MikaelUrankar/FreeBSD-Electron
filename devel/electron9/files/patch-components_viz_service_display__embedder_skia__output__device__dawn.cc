--- components/viz/service/display_embedder/skia_output_device_dawn.cc.orig	2020-05-26 08:03:23 UTC
+++ components/viz/service/display_embedder/skia_output_device_dawn.cc
@@ -10,7 +10,7 @@
 
 #if defined(OS_WIN)
 #include <dawn_native/D3D12Backend.h>
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include <dawn_native/VulkanBackend.h>
 #endif
 
