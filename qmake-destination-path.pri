platform_path = unknown-platform
compiler_path = unknown-compiler
processor_path = unknow-processor
build_path = unknown-build

PLATFORM_WIN {
    platform_path = windows
}
PLATFORM_MACOS {
    platform_path = macos
}
PLATFORM_PATH {
    platform_path = linux
}

COMILER_GCC {
    compiler_path = gcc
}
COMPILER_MSVC2017 {
    compiler_path = msvc2017
}
COMPILER_CLANG {
    compiler_path = clang
}

PROCESSOR_x64 {
    processor_path = x64
}
PROCESSOR_x86 {
    processor_path = x86
}
PROCESSOR_ARM64 {
    processor_path = arm64
}

BUILD_DEBUG {
    build_path = debug
} else {
    build_path = release
}

DESTINATION_PATH = $$platform_path/$$compiler_path/$$processor_path/$$build_path
message(Dest path: $${DESTINATION_PATH})
