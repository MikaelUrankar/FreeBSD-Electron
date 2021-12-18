--- electron/shell/browser/net/system_network_context_manager.cc.orig	2021-12-03 01:46:05 UTC
+++ electron/shell/browser/net/system_network_context_manager.cc
@@ -45,7 +45,7 @@
 #include "components/os_crypt/keychain_password_mac.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/os_crypt/key_storage_config_linux.h"
 #endif
 
@@ -311,7 +311,7 @@ void SystemNetworkContextManager::OnNetworkServiceCrea
   KeychainPassword::GetServiceName() = app_name + " Safe Storage";
   KeychainPassword::GetAccountName() = app_name;
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // c.f.
   // https://source.chromium.org/chromium/chromium/src/+/master:chrome/browser/net/system_network_context_manager.cc;l=515;drc=9d82515060b9b75fa941986f5db7390299669ef1;bpv=1;bpt=1
   const base::CommandLine& command_line =
@@ -333,7 +333,7 @@ void SystemNetworkContextManager::OnNetworkServiceCrea
   // process, send it the required key.
   if (content::IsOutOfProcessNetworkService() &&
       electron::fuses::IsCookieEncryptionEnabled()) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     network::mojom::CryptConfigPtr network_crypt_config =
         network::mojom::CryptConfig::New();
     network_crypt_config->application_name = config->application_name;
@@ -349,7 +349,7 @@ void SystemNetworkContextManager::OnNetworkServiceCrea
 #endif
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   OSCrypt::SetConfig(std::move(config));
 #endif
 
