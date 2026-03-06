#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tcbase::termin_base" for configuration ""
set_property(TARGET tcbase::termin_base APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(tcbase::termin_base PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libtermin_base.so"
  IMPORTED_SONAME_NOCONFIG "libtermin_base.so"
  )

list(APPEND _cmake_import_check_targets tcbase::termin_base )
list(APPEND _cmake_import_check_files_for_tcbase::termin_base "${_IMPORT_PREFIX}/lib/libtermin_base.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
