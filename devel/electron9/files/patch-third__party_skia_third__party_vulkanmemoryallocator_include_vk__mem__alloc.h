--- third_party/skia/third_party/vulkanmemoryallocator/include/vk_mem_alloc.h.orig	2020-05-28 04:23:52 UTC
+++ third_party/skia/third_party/vulkanmemoryallocator/include/vk_mem_alloc.h
@@ -2232,7 +2232,7 @@ remove them if not needed.
 #include <mutex> // for std::mutex
 #include <atomic> // for std::atomic
 
-#if !defined(_WIN32) && !defined(__APPLE__)
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__FreeBSD__)
     #include <malloc.h> // for aligned_alloc()
 #endif
 
