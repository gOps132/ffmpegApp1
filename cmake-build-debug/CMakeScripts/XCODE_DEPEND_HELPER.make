# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.ffmpegApp1.Debug:
PostBuild.glfw.Debug: /Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/Debug/ffmpegApp1
/Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/Debug/ffmpegApp1:\
	/Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/lib/glfw/src/Debug/libglfw3.a\
	/usr/local/lib/libavcodec.dylib\
	/usr/local/lib/libavformat.dylib\
	/usr/local/lib/libavutil.dylib
	/bin/rm -f /Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/Debug/ffmpegApp1


PostBuild.glfw.Debug:
/Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/lib/glfw/src/Debug/libglfw3.a:
	/bin/rm -f /Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/lib/glfw/src/Debug/libglfw3.a


PostBuild.ffmpegApp1.Release:
PostBuild.glfw.Release: /Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/Release/ffmpegApp1
/Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/Release/ffmpegApp1:\
	/Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/lib/glfw/src/Release/libglfw3.a\
	/usr/local/lib/libavcodec.dylib\
	/usr/local/lib/libavformat.dylib\
	/usr/local/lib/libavutil.dylib
	/bin/rm -f /Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/Release/ffmpegApp1


PostBuild.glfw.Release:
/Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/lib/glfw/src/Release/libglfw3.a:
	/bin/rm -f /Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/lib/glfw/src/Release/libglfw3.a


PostBuild.ffmpegApp1.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/MinSizeRel/ffmpegApp1
/Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/MinSizeRel/ffmpegApp1:\
	/Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/lib/glfw/src/MinSizeRel/libglfw3.a\
	/usr/local/lib/libavcodec.dylib\
	/usr/local/lib/libavformat.dylib\
	/usr/local/lib/libavutil.dylib
	/bin/rm -f /Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/MinSizeRel/ffmpegApp1


PostBuild.glfw.MinSizeRel:
/Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/lib/glfw/src/MinSizeRel/libglfw3.a:
	/bin/rm -f /Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/lib/glfw/src/MinSizeRel/libglfw3.a


PostBuild.ffmpegApp1.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/RelWithDebInfo/ffmpegApp1
/Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/RelWithDebInfo/ffmpegApp1:\
	/Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/lib/glfw/src/RelWithDebInfo/libglfw3.a\
	/usr/local/lib/libavcodec.dylib\
	/usr/local/lib/libavformat.dylib\
	/usr/local/lib/libavutil.dylib
	/bin/rm -f /Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/RelWithDebInfo/ffmpegApp1


PostBuild.glfw.RelWithDebInfo:
/Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/lib/glfw/src/RelWithDebInfo/libglfw3.a:
	/bin/rm -f /Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/lib/glfw/src/RelWithDebInfo/libglfw3.a




# For each target create a dummy ruleso the target does not have to exist
/Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/lib/glfw/src/Debug/libglfw3.a:
/Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/lib/glfw/src/MinSizeRel/libglfw3.a:
/Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/lib/glfw/src/RelWithDebInfo/libglfw3.a:
/Users/giancedrickepilan/Documents/programmingProjects/real\ projects/ffmpegApp1/cmake-build-debug/lib/glfw/src/Release/libglfw3.a:
/usr/local/lib/libavcodec.dylib:
/usr/local/lib/libavformat.dylib:
/usr/local/lib/libavutil.dylib:
