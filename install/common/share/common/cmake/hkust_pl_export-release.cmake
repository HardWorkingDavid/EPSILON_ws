#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "hkust_pl_common" for configuration "Release"
set_property(TARGET hkust_pl_common APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(hkust_pl_common PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libhkust_pl_common.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS hkust_pl_common )
list(APPEND _IMPORT_CHECK_FILES_FOR_hkust_pl_common "${_IMPORT_PREFIX}/lib/libhkust_pl_common.a" )

# Import target "hkust_pl_ooqp_itf" for configuration "Release"
set_property(TARGET hkust_pl_ooqp_itf APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(hkust_pl_ooqp_itf PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libhkust_pl_ooqp_itf.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS hkust_pl_ooqp_itf )
list(APPEND _IMPORT_CHECK_FILES_FOR_hkust_pl_ooqp_itf "${_IMPORT_PREFIX}/lib/libhkust_pl_ooqp_itf.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
