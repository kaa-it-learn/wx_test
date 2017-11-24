cmake_minimum_required(VERSION 3.0)

project(wx_test)

if(VCPKG_TOOLCHAIN)
    add_definitions(-D_UNICODE -DUNICODE -DWXUSINGDLL -DwxUSE_GUI=1 -D__WXMSW__ -DWINVER=0x0500)
    find_path(wxWidgets_INCLUDE_DIR wx/wx.h)
    include_directories(${wxWidgets_INCLUDE_DIR})
    set(vcpkg_lib_path ${_VCPKG_INSTALLED_DIR}/_target_/_mode_/lib)
    string(REGEX REPLACE "_target_" "${VCPKG_TARGET_TRIPLET}" vcpkg_lib_path ${vcpkg_lib_path})

    if("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
        #debug lib
        string(REGEX REPLACE "_mode_" "debug" vcpkg_lib_path ${vcpkg_lib_path})
        link_libraries(
                ${vcpkg_lib_path}/wxmsw31ud_core.lib
                ${vcpkg_lib_path}/wxbase31ud.lib)
    else()
        #release lib
        string(REGEX REPLACE "_mode_/" "" vcpkg_lib_path ${vcpkg_lib_path})
        link_libraries(
                ${vcpkg_lib_path}/wxmsw31u_core.lib
                ${vcpkg_lib_path}/wxmsw31u_adv.lib
                ${vcpkg_lib_path}/wxbase31u.lib)
    endif()
endif()

if (MSVC)
    #add_definitions(-D_USING_V110_SDK71_ -D_WIN32_WINNT=0x0501)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS,5.01")

endif()

#find_package(wxwidgets REQUIRED net gl core base)

#find_path(wxWidgets_INCLUDE_DIR wx/wx.h)
#find_library(wxWidgets_wxbase31u_LIBRARY wxbase31u  wxmsw31u_adv)
#find_library(wxWidgets_wxmsw31u_core_LIBRARY wxmsw31u_core)
#find_library(wxWidgets_wxmsw31u_adv_LIBRARY wxmsw31u_adv)

#include_directories(${wxWidgets_INCLUDE_DIR})

set(SOURCE_FILES MainFrame.h MainFrame.cpp App.h App.cpp)

add_executable(wx_test WIN32 ${SOURCE_FILES})

# and for each of your dependent executable/library targets:
#target_link_libraries(wx_test ${wxWidgets_wxbase31u_LIBRARY} ${wxWidgets_wxmsw31u_core_LIBRARY} ${wxWidgets_wxmsw31u_adv_LIBRARY})