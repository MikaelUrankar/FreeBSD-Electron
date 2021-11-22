--- components/safe_browsing/core/common/features.cc.orig	2021-09-14 01:51:55 UTC
+++ components/safe_browsing/core/common/features.cc
@@ -106,7 +106,7 @@ const base::Feature
 
 const base::Feature kSafeBrowsingSeparateNetworkContexts {
   "SafeBrowsingSeparateNetworkContexts",
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -115,7 +115,7 @@ const base::Feature kSafeBrowsingSeparateNetworkContex
 
 const base::Feature kSafeBrowsingRemoveCookies {
   "SafeBrowsingRemoveCookies",
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
