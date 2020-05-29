--- ui/gl/gl_bindings_api_autogen_glx.h.orig	2020-05-26 07:49:14 UTC
+++ ui/gl/gl_bindings_api_autogen_glx.h
@@ -88,6 +88,7 @@ bool glXGetMscRateOMLFn(Display* dpy,
                         GLXDrawable drawable,
                         int32_t* numerator,
                         int32_t* denominator) override;
+__GLXextFuncPtr glXGetProcAddressARBFn(const GLubyte* procName) override;
 void glXGetSelectedEventFn(Display* dpy,
                            GLXDrawable drawable,
                            unsigned long* mask) override;
