--- chrome/browser/renderer_context_menu/render_view_context_menu.h.orig	2021-09-14 01:51:50 UTC
+++ chrome/browser/renderer_context_menu/render_view_context_menu.h
@@ -31,7 +31,7 @@
 #include "ui/base/window_open_disposition.h"
 #include "ui/gfx/geometry/vector2d.h"
 
-#if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/lens/region_search/lens_region_search_controller.h"
 #endif
 
@@ -353,7 +353,7 @@ class RenderViewContextMenu : public RenderViewContext
   // The type of system app (if any) associated with the WebContents we're in.
   absl::optional<web_app::SystemAppType> system_app_type_;
 
-#if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
   // Controller for Lens Region Search feature. This controller will be
   // destroyed as soon as the RenderViewContextMenu object is destroyed. The
   // RenderViewContextMenu is reset every time it is shown, but persists between
