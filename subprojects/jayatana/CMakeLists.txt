cmake_minimum_required (VERSION 3.6 FATAL_ERROR)
cmake_policy (VERSION 3.6)
project (jayatana C)
cmake_policy(SET CMP0054 NEW)
enable_testing ()
include(GNUInstallDirs)
include(CMakeDependentOption)
find_package (PkgConfig QUIET)
find_package(Java)
find_package(JNI)
pkg_check_modules(XKBCOMMON
    xkbcommon
    IMPORTED_TARGET)
pkg_check_modules(DBUSMENU
    dbusmenu-glib-0.4>=16.04.0
    IMPORTED_TARGET)

cmake_dependent_option(STANDALONE "Build jayatana STANDALONE" ON
        "NOT CORE_FOUND;JAVA_FOUND;JNI_FOUND;XKBCOMMON_FOUND;DBUSMENU_FOUND" OFF)
cmake_dependent_option(ENABLE_JAYATANA "Build jayatana fork" OFF
    "JAVA_FOUND;JNI_FOUND;XKBCOMMON_FOUND;DBUSMENU_FOUND" OFF)

if(STANDALONE)
	set (CPACK_SOURCE_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}")
	set (CPACK_SOURCE_IGNORE_FILES "/build/;/.gitmodules;/.git;/.gitignore;~$;${CPACK_SOURCE_IGNORE_FILES}")
	include (CPack)
	add_custom_target (dist COMMAND ${CMAKE_MAKE_PROGRAM} package_source)
endif()

if (ENABLE_JAYATANA OR STANDALONE)
    add_subdirectory(lib)
    add_subdirectory(java)
endif()
