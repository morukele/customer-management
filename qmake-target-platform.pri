win32 {
    CONFIG += PLATFORM_WIN
    message(PLATFORM_WIN)
    win32-g++ {
        CONFIG += COMPILER_GCC
        message(COMPILER_GCC)
    }
    win32-msvc2017 {
        CONFIG += COMPILER_MSVC2017
        message(COMPILER_MSVC2017)
        win32-msvc2017:QMAKE_TARGET.arcg = x86_64
    }
}

linux {
    CONFIG += PLATFORM_LINUX
    message(PLATFORM_LINUX)
    # Make QMAKE_TARGET arch available for Linux
    !contains(QT_ARCH, x86_64) {
        QMAKE_TARGET.arch = x86
    } else {
        QMAKE_TARGET.arch = x86_64
    }
    linux-g++{
        CONFIG += COMPILER_GCC
        message(COMPILER_GCC)
    }
}

macos {
    CONFIG += PLATFORM_MACOS
    message(PLATFORM_MACOS)
    contains(QMAKE_HOST.arch, arm64){
        CONFIG += COMPILER_CLANG
        message(COMPILER_CLANG on ARM64)
        QMAKE_TARGET.arch = arm64
    }

    contains(QMAKE_HOST.arch, x86_64){
        CONFIG += COMPILER_CLANG
        message(COMPILER_CLANG on X86_64)
        QMAKE_TARGET.arch = x86_64
    }
}

contains(QMAKE_TARGET.arch, x86_64) {
    CONFIG += PROCESSOR_x64
    message(PROCESSOR_x64)
}else {
    contains(QMAKE_TARGET.arch, arm64) {
        CONFIG += PROCESSOR_ARM64
        message(ARM64)
    } else {
        CONFIG += PROCESSOR_x86
        message(PROCESSOR_x86)
    }
}

CONFIG(debug, release|debug) {
    CONFIG += BUILD_DEBUG
    message(BUILD_DEBUG)
} else {
    CONFIG += BUILD_RELEASE
    message(BUILD_RELEASE)
}
