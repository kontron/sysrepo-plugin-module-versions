CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")
set(PLUGINS_DIR "${CMAKE_INSTALL_PREFIX}/${LIB_INSTALL_DIR}/sysrepo/plugins/" CACHE PATH "Sysrepo plugins directory.")

PROJECT(sysrepo-plugin-module-versions)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
#set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
#set(CMAKE_C_FLAGS_DEBUG   "-g -O0 -DDEBUG")

set(SOURCES
	src/module-versions-plugin.c)

if(CMAKE_BUILD_TYPE MATCHES "debug")
  add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
  target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE DEBUG=1)
  install(TARGETS ${CMAKE_PROJECT_NAME}
	  DESTINATION lib/sysrepo/plugins)
else()
  add_library(${CMAKE_PROJECT_NAME} MODULE ${SOURCES})
  install(TARGETS ${CMAKE_PROJECT_NAME} LIBRARY
	  DESTINATION lib/sysrepo/plugins)
endif()

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES OUTPUT_NAME ${CMAKE_PROJECT_NAME} PREFIX "")

find_package(PkgConfig REQUIRED)

include_directories(${SYSREPO_INCLUDE_DIRS})

find_package(SYSREPO REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} ${SYSREPO_LIBRARIES})
include_directories(${SYSREPO_INCLUDE_DIRS})

# find programs
if (NOT SYSREPOCTL_EXECUTABLE)
    find_program(SYSREPOCTL_EXECUTABLE sysrepoctl)
endif()
if (NOT SYSREPOCTL_EXECUTABLE)
    message(FATAL_ERROR "Unable to find sysrepoctl, set SYSREPOCTL_EXECUTABLE manually.")
endif()

if (NOT SYSREPOCFG_EXECUTABLE)
    find_program(SYSREPOCFG_EXECUTABLE sysrepocfg)
endif()
if (NOT SYSREPOCFG_EXECUTABLE)
    message(FATAL_ERROR "Unable to find sysrepocfg, set SYSREPOCFG_EXECUTABLE manually.")
endif()

# Command line options to be passed to `sysrepoctl` when working with modules
# which should only be accessible by an administrator
if (NOT SYSREPOCTL_ROOT_PERMS)
    set(SYSREPOCTL_ROOT_PERMS "-p 600")
endif()

## get sysrepo plugins directory
#if (NOT SR_PLUGINS_DIR)
#    if (PKG_CONFIG_FOUND)
#        execute_process(COMMAND ${PKG_CONFIG_EXECUTABLE} "--variable=SR_PLUGINS_DIR" "libsysrepo" OUTPUT_VARIABLE SR_PLUGINS_DIR)
#        string(STRIP ${SR_PLUGINS_DIR} SR_PLUGINS_DIR)
#    endif()
#endif()
#if (NOT SR_PLUGINS_DIR)
#    message(FATAL_ERROR "Cannot get sysrepo plugins directory due to missing pkg-config, set SR_PLUGINS_DIR manually.")
#endif()

option(MODEL_INSTALL "Enable yang model installation" ON)
if (MODEL_INSTALL)
    install(CODE "
        message(STATUS \"Installing sysrepo modules...\")
        execute_process(COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/scripts/model-install.sh ${SYSREPOCTL_EXECUTABLE} \"${SYSREPOCTL_ROOT_PERMS}\" RESULT_VARIABLE RET ERROR_VARIABLE ERR)
        if(\${RET})
             message(FATAL_ERROR \"sysrepoctl failed: \${ERR}\")
        endif()
    ")
endif()
