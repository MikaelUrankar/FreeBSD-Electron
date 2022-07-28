--- third_party/skia/src/core/SkCpu.cpp.orig	2022-06-10 05:40:07 UTC
+++ third_party/skia/src/core/SkCpu.cpp
@@ -73,6 +73,42 @@
         return features;
     }
 
+#elif defined(SK_CPU_ARM64) && defined(__OpenBSD__)
+    #include <sys/sysctl.h>
+    #include <machine/cpu.h>
+    #include <machine/armreg.h>
+
+    static uint32_t read_cpu_features() {
+      int isar0_mib[] = { CTL_MACHDEP, CPU_ID_AA64ISAR0 };
+      size_t len = sizeof(uint64_t);
+      uint64_t cpu_id = 0;
+      uint32_t features = 0;
+
+      if (sysctl(isar0_mib, 2, &cpu_id, &len, NULL, 0) == 0) {
+        if (ID_AA64ISAR0_CRC32(cpu_id) >= ID_AA64ISAR0_CRC32_BASE)
+          features |= SkCpu::CRC32;
+      }
+
+      return features;
+    }
+
+#elif defined(SK_CPU_ARM64) && defined(__FreeBSD__)
+    #include <machine/armreg.h>
+    #ifndef ID_AA64ISAR0_CRC32_VAL
+    #define ID_AA64ISAR0_CRC32_VAL ID_AA64ISAR0_CRC32
+    #endif
+
+    static uint32_t read_cpu_features() {
+      uint32_t features = 0;
+      uint64_t id_aa64isar0;
+
+      id_aa64isar0 = READ_SPECIALREG(id_aa64isar0_el1);
+      if (ID_AA64ISAR0_CRC32_VAL(id_aa64isar0) == ID_AA64ISAR0_CRC32_BASE) {
+        features |= SkCpu::CRC32;
+      }
+      return features;
+    }
+
 #elif defined(SK_CPU_ARM64) && __has_include(<sys/auxv.h>)
     #include <sys/auxv.h>
 
@@ -115,6 +151,22 @@
         return features;
     }
 
+#elif defined(SK_CPU_ARM32) && defined(__FreeBSD__)
+    #include <sys/auxv.h>
+
+    static uint32_t read_cpu_features() {
+        unsigned long hwcaps = 0;
+        uint32_t features = 0;
+
+        elf_aux_info(AT_HWCAP, (void *)&hwcaps, sizeof hwcaps);
+        if (hwcaps & HWCAP_NEON) {
+            features |= SkCpu::NEON;
+            if (hwcaps & HWCAP_VFPv4) {
+                features |= SkCpu::NEON_FMA|SkCpu::VFP_FP16;
+            }
+        }
+        return features;
+    }
 #elif defined(SK_CPU_ARM32) && __has_include(<sys/auxv.h>) && \
     (!defined(__ANDROID_API__) || __ANDROID_API__ >= 18)
     // sys/auxv.h will always be present in the Android NDK due to unified
