--- base/allocator/partition_allocator/partition_address_space.cc.orig	2022-08-01 19:04:19 UTC
+++ base/allocator/partition_allocator/partition_address_space.cc
@@ -234,7 +234,7 @@ void PartitionAddressSpace::UninitConfigurablePoolForT
   setup_.configurable_pool_ = 0;
 }
 
-#if BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
 
 PageCharacteristics page_characteristics;
 
