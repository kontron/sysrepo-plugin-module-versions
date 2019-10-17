find_package(PkgConfig)
pkg_check_modules(PC_LIBNL QUIET libnl3)

find_path(LIBNL_INCLUDE_DIR netlink/version.h
	HINTS ${PC_LIBNL_INCLUDEDIR} ${PC_LIBNL_NF_INCLUDE_DIRS} PATH_SUFFIXES libnl3)

find_library(LIBNL_LIBRARY NAMES nl-3 nl
	HINTS ${PC_LIBNL_LIBDIR} ${PC_LIBNL_LIBRARY_DIRS})

set(LIBNL_LIBRARIES ${LIBNL_LIBRARY})
set(LIBNL_INCLUDE_DIRS ${LIBNL_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(LIBNL DEFAULT_MSG LIBNL_LIBRARY LIBNL_INCLUDE_DIR)

mark_as_advanced(LIBNL_INCLUDE_DIR LIBNL_LIBRARY)

