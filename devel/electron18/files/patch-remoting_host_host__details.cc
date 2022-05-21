--- remoting/host/host_details.cc.orig	2022-05-19 03:45:37 UTC
+++ remoting/host/host_details.cc
@@ -23,7 +23,7 @@ std::string GetHostOperatingSystemName() {
   return "Mac";
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
   return "ChromeOS";
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   return "Linux";
 #elif BUILDFLAG(IS_ANDROID)
   return "Android";
