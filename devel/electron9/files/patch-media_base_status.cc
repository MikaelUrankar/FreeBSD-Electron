--- media/base/status.cc.orig	2020-05-26 07:48:30 UTC
+++ media/base/status.cc
@@ -66,7 +66,9 @@ Status&& Status::AddCause(Status&& cause) && {
 
 void Status::AddFrame(const base::Location& location) {
   DCHECK(data_);
+#if SUPPORTS_LOCATION_BUILTINS
   data_->frames.push_back(MediaSerialize(location));
+#endif
 }
 
 Status OkStatus() {
