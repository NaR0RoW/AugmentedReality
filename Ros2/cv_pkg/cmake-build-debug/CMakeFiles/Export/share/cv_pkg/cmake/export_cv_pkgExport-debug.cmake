#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "cv_pkg::cv_pkg" for configuration "Debug"
set_property(TARGET cv_pkg::cv_pkg APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(cv_pkg::cv_pkg PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/cv_pkg/libcv_pkg.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS cv_pkg::cv_pkg )
list(APPEND _IMPORT_CHECK_FILES_FOR_cv_pkg::cv_pkg "${_IMPORT_PREFIX}/lib/cv_pkg/libcv_pkg.a" )

# Import target "cv_pkg::cv_pkg_emitter" for configuration "Debug"
set_property(TARGET cv_pkg::cv_pkg_emitter APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(cv_pkg::cv_pkg_emitter PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/cv_pkg/cv_pkg_emitter"
  )

list(APPEND _IMPORT_CHECK_TARGETS cv_pkg::cv_pkg_emitter )
list(APPEND _IMPORT_CHECK_FILES_FOR_cv_pkg::cv_pkg_emitter "${_IMPORT_PREFIX}/lib/cv_pkg/cv_pkg_emitter" )

# Import target "cv_pkg::cv_pkg_receiver" for configuration "Debug"
set_property(TARGET cv_pkg::cv_pkg_receiver APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(cv_pkg::cv_pkg_receiver PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/cv_pkg/cv_pkg_receiver"
  )

list(APPEND _IMPORT_CHECK_TARGETS cv_pkg::cv_pkg_receiver )
list(APPEND _IMPORT_CHECK_FILES_FOR_cv_pkg::cv_pkg_receiver "${_IMPORT_PREFIX}/lib/cv_pkg/cv_pkg_receiver" )

# Import target "cv_pkg::cv_pkg_receiver2" for configuration "Debug"
set_property(TARGET cv_pkg::cv_pkg_receiver2 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(cv_pkg::cv_pkg_receiver2 PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/cv_pkg/cv_pkg_receiver2"
  )

list(APPEND _IMPORT_CHECK_TARGETS cv_pkg::cv_pkg_receiver2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_cv_pkg::cv_pkg_receiver2 "${_IMPORT_PREFIX}/lib/cv_pkg/cv_pkg_receiver2" )

# Import target "cv_pkg::cv_pkg_emitter_and_receiver" for configuration "Debug"
set_property(TARGET cv_pkg::cv_pkg_emitter_and_receiver APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(cv_pkg::cv_pkg_emitter_and_receiver PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/cv_pkg/cv_pkg_emitter_and_receiver"
  )

list(APPEND _IMPORT_CHECK_TARGETS cv_pkg::cv_pkg_emitter_and_receiver )
list(APPEND _IMPORT_CHECK_FILES_FOR_cv_pkg::cv_pkg_emitter_and_receiver "${_IMPORT_PREFIX}/lib/cv_pkg/cv_pkg_emitter_and_receiver" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
