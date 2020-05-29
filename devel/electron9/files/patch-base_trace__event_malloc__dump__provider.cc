--- base/trace_event/malloc_dump_provider.cc.orig	2020-05-26 07:48:14 UTC
+++ base/trace_event/malloc_dump_provider.cc
@@ -17,6 +17,8 @@
 
 #if defined(OS_MACOSX)
 #include <malloc/malloc.h>
+#elif defined(OS_BSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -132,6 +134,9 @@ bool MallocDumpProvider::OnMemoryDump(const MemoryDump
   }
 #elif defined(OS_FUCHSIA)
 // TODO(fuchsia): Port, see https://crbug.com/706592.
+#elif defined(OS_BSD)
+  total_virtual_size = 0;
+  allocated_objects_size = 0;
 #else
   struct mallinfo info = mallinfo();
   // In case of Android's jemalloc |arena| is 0 and the outer pages size is
