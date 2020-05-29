--- remoting/host/host_attributes.cc.orig	2020-05-26 08:03:25 UTC
+++ remoting/host/host_attributes.cc
@@ -120,7 +120,7 @@ std::string GetHostAttributes() {
       media::InitializeMediaFoundation()) {
     result.push_back("HWEncoder");
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   result.push_back("HWEncoder");
 #endif
 
