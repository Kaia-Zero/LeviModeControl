cmake_minimum_required(VERSION 3.22)
project(LeviModeControl LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(MOD_ID "levimodecontrol" CACHE STRING "Mod id")
set(MOD_NAME "LeviModeControl" CACHE STRING "Mod name")
set(MOD_AUTHOR "Kaia-Zero" CACHE STRING "Mod author")
set(MOD_VERSION "0.1.0" CACHE STRING "Mod version")
set(MOD_LIBRARY_NAME "levimodecontrol" CACHE STRING "Library name")
set(MOD_MINECRAFT_VERSIONS "[\"1.26.*\"]" CACHE STRING "Minecraft versions")
set(MOD_ICON "" CACHE STRING "Optional icon")

include(FetchContent)
FetchContent_Declare(preloader_android
  GIT_REPOSITORY https://github.com/LiteLDev/preloader-android.git
  GIT_TAG 0.2.2)
FetchContent_MakeAvailable(preloader_android)

add_library(${MOD_LIBRARY_NAME} SHARED src/main.cpp src/Mod.cpp)
target_include_directories(${MOD_LIBRARY_NAME} PRIVATE src)
target_link_libraries(${MOD_LIBRARY_NAME} PRIVATE preloader)
target_compile_options(${MOD_LIBRARY_NAME} PRIVATE -fvisibility=hidden -fvisibility-inlines-hidden)
target_link_options(${MOD_LIBRARY_NAME} PRIVATE "-Wl,-z,max-page-size=16384")

configure_file(manifest.json.in manifest.json @ONLY)
set(PKG_DIR "${CMAKE_CURRENT_BINARY_DIR}/package/${MOD_ID}")
set(PKG_FILE "${CMAKE_CURRENT_BINARY_DIR}/${MOD_ID}-${MOD_VERSION}-${ANDROID_ABI}.levipack")
add_custom_target(levi_package
  COMMAND ${CMAKE_COMMAND} -E rm -rf "${CMAKE_CURRENT_BINARY_DIR}/package"
  COMMAND ${CMAKE_COMMAND} -E make_directory "${PKG_DIR}"
  COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:${MOD_LIBRARY_NAME}>" "${PKG_DIR}/lib${MOD_LIBRARY_NAME}.so"
  COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/manifest.json" "${PKG_DIR}/manifest.json"
  COMMAND ${CMAKE_COMMAND} -E chdir "${CMAKE_CURRENT_BINARY_DIR}/package" ${CMAKE_COMMAND} -E tar cf "${PKG_FILE}" --format=zip "${MOD_ID}"
  DEPENDS ${MOD_LIBRARY_NAME}
  VERBATIM)
