# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.ffmpegApp1.Debug:
PostBuild.glfw.Debug: /Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/Debug/ffmpegApp1
/Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/Debug/ffmpegApp1:\
	/Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/lib/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/Debug/ffmpegApp1


PostBuild.glfw.Debug:
/Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/lib/glfw/src/Debug/libglfw3.a:
	/bin/rm -f /Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/lib/glfw/src/Debug/libglfw3.a


PostBuild.ffmpegApp1.Release:
PostBuild.glfw.Release: /Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/Release/ffmpegApp1
/Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/Release/ffmpegApp1:\
	/Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/lib/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/Release/ffmpegApp1


PostBuild.glfw.Release:
/Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/lib/glfw/src/Release/libglfw3.a:
	/bin/rm -f /Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/lib/glfw/src/Release/libglfw3.a


PostBuild.ffmpegApp1.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/MinSizeRel/ffmpegApp1
/Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/MinSizeRel/ffmpegApp1:\
	/Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/lib/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/MinSizeRel/ffmpegApp1


PostBuild.glfw.MinSizeRel:
/Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/lib/glfw/src/MinSizeRel/libglfw3.a:
	/bin/rm -f /Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/lib/glfw/src/MinSizeRel/libglfw3.a


PostBuild.ffmpegApp1.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/RelWithDebInfo/ffmpegApp1
/Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/RelWithDebInfo/ffmpegApp1:\
	/Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/lib/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/RelWithDebInfo/ffmpegApp1


PostBuild.glfw.RelWithDebInfo:
/Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/lib/glfw/src/RelWithDebInfo/libglfw3.a:
	/bin/rm -f /Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/lib/glfw/src/RelWithDebInfo/libglfw3.a




# For each target create a dummy ruleso the target does not have to exist
/Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/lib/glfw/src/Debug/libglfw3.a:
/Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/lib/glfw/src/MinSizeRel/libglfw3.a:
/Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/lib/glfw/src/RelWithDebInfo/libglfw3.a:
/Users/giancedrickepilan/dev/native/ffmpegApp1/xcode/lib/glfw/src/Release/libglfw3.a:
