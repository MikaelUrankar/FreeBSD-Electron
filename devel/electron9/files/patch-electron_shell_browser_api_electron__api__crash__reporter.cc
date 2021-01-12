--- electron/shell/browser/api/electron_api_crash_reporter.cc.orig	2020-12-11 21:16:23 UTC
+++ electron/shell/browser/api/electron_api_crash_reporter.cc
@@ -30,7 +30,7 @@
 #include "shell/common/gin_helper/dictionary.h"
 #include "shell/common/node_includes.h"
 
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !defined(OS_BSD)
 #include "chrome/browser/crash_upload_list/crash_upload_list_crashpad.h"
 #include "components/crash/core/app/crashpad.h"  // nogncheck
 #include "components/crash/core/common/crash_key.h"
@@ -69,7 +69,7 @@ namespace api {
 
 namespace crash_reporter {
 
-#if defined(MAS_BUILD)
+#if defined(MAS_BUILD) || defined(OS_BSD)
 namespace {
 
 void NoOp() {}
@@ -135,7 +135,7 @@ void Start(const std::string& submit_url,
            const std::map<std::string, std::string>& global_extra,
            const std::map<std::string, std::string>& extra,
            bool is_node_process) {
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !defined(OS_BSD)
   if (g_crash_reporter_initialized)
     return;
   g_crash_reporter_initialized = true;
@@ -232,13 +232,13 @@ v8::Local<v8::Value> GetUploadedReports(v8::Isolate* i
 #endif
 
 void SetUploadToServer(bool upload) {
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !defined(OS_BSD)
   ElectronCrashReporterClient::Get()->SetCollectStatsConsent(upload);
 #endif
 }
 
 bool GetUploadToServer() {
-#if defined(MAS_BUILD)
+#if defined(MAS_BUILD) || defined(OS_BSD)
   return false;
 #else
   return ElectronCrashReporterClient::Get()->GetCollectStatsConsent();
@@ -247,7 +247,7 @@ bool GetUploadToServer() {
 
 v8::Local<v8::Value> GetParameters(v8::Isolate* isolate) {
   std::map<std::string, std::string> keys;
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !defined(OS_BSD)
   electron::crash_keys::GetCrashKeys(&keys);
 #endif
   return gin::ConvertToV8(isolate, keys);
@@ -259,7 +259,7 @@ void Initialize(v8::Local<v8::Object> exports,
                 void* priv) {
   gin_helper::Dictionary dict(context->GetIsolate(), exports);
   dict.SetMethod("start", &electron::api::crash_reporter::Start);
-#if defined(MAS_BUILD)
+#if defined(MAS_BUILD) || defined(OS_BSD)
   dict.SetMethod("addExtraParameter", &electron::api::crash_reporter::NoOp);
   dict.SetMethod("removeExtraParameter", &electron::api::crash_reporter::NoOp);
 #else
