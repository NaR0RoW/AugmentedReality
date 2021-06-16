#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "cpp::cpp" for configuration ""
set_property(TARGET cpp::cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(cpp::cpp PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libcpp.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS cpp::cpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_cpp::cpp "${_IMPORT_PREFIX}/lib/libcpp.a" )

# Import target "cpp::video_transmitter" for configuration ""
set_property(TARGET cpp::video_transmitter APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(cpp::video_transmitter PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/cpp/video_transmitter"
  )

list(APPEND _IMPORT_CHECK_TARGETS cpp::video_transmitter )
list(APPEND _IMPORT_CHECK_FILES_FOR_cpp::video_transmitter "${_IMPORT_PREFIX}/lib/cpp/video_transmitter" )

# Import target "cpp::video_receiver" for configuration ""
set_property(TARGET cpp::video_receiver APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(cpp::video_receiver PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/cpp/video_receiver"
  )

list(APPEND _IMPORT_CHECK_TARGETS cpp::video_receiver )
list(APPEND _IMPORT_CHECK_FILES_FOR_cpp::video_receiver "${_IMPORT_PREFIX}/lib/cpp/video_receiver" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
