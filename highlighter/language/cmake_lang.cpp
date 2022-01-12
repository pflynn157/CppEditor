#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

namespace QSourceHighlite {

/********************************************************/
/***   CMAKE DATA   ***************************************/
/********************************************************/
static bool cmakeDataInitialized = false;
static QMultiHash<char, QLatin1String> cmake_keywords;
static QMultiHash<char, QLatin1String> cmake_types;
static QMultiHash<char, QLatin1String> cmake_literals;
static QMultiHash<char, QLatin1String> cmake_builtin;
static QMultiHash<char, QLatin1String> cmake_other;
void initCMakeData() {
    cmake_keywords = {
        {'b', QLatin1String("break")},
        {'c', QLatin1String("cmake_host_system_information")},
        {'c', QLatin1String("cmake_minimum_required")},
        {'c', QLatin1String("cmake_parse_arguments")},
        {'c', QLatin1String("cmake_policy")},
        {'c', QLatin1String("configure_file")},
        {'c', QLatin1String("continue")},
        {'e', QLatin1String("elseif")},
        {'e', QLatin1String("else")},
        {'e', QLatin1String("endforeach")},
        {'e', QLatin1String("endfunction")},
        {'e', QLatin1String("endif")},
        {'e', QLatin1String("endmacro")},
        {'e', QLatin1String("endwhile")},
        {'e', QLatin1String("execute_process")},
        {'f', QLatin1String("file")},
        {'f', QLatin1String("find_file")},
        {'f', QLatin1String("find_library")},
        {'f', QLatin1String("find_package")},
        {'f', QLatin1String("find_path")},
        {'f', QLatin1String("find_program")},
        {'f', QLatin1String("foreach")},
        {'f', QLatin1String("function")},
        {'g', QLatin1String("get_cmake_property")},
        {'g', QLatin1String("get_directory_property")},
        {'g', QLatin1String("get_filename_component")},
        {'g', QLatin1String("get_property")},
        {'i', QLatin1String("if")},
        {'i', QLatin1String("include")},
        {'i', QLatin1String("include_guard")},
        {'l', QLatin1String("list")},
        {'m', QLatin1String("macro")},
        {'m', QLatin1String("mark_as_advanced")},
        {'m', QLatin1String("math")},
        {'m', QLatin1String("message")},
        {'o', QLatin1String("option")},
        {'r', QLatin1String("return")},
        {'s', QLatin1String("separate_arguments")},
        {'s', QLatin1String("set_directory_properties")},
        {'s', QLatin1String("set")},
        {'s', QLatin1String("set_property")},
        {'s', QLatin1String("site_name")},
        {'s', QLatin1String("string")},
        {'u', QLatin1String("unset")},
        {'v', QLatin1String("variable_watch")},
        {'w', QLatin1String("while")},
        {'a', QLatin1String("add_compile_definitions")},
        {'a', QLatin1String("add_compile_options")},
        {'A', QLatin1String("ADD_COMPILE_OPTIONS")},
        {'a', QLatin1String("add_custom_command")},
        {'a', QLatin1String("add_custom_target")},
        {'a', QLatin1String("add_definitions")},
        {'a', QLatin1String("add_dependencies")},
        {'a', QLatin1String("add_executable")},
        {'a', QLatin1String("add_library")},
        {'a', QLatin1String("add_link_options")},
        {'a', QLatin1String("add_subdirectory")},
        {'a', QLatin1String("add_test")},
        {'a', QLatin1String("aux_source_directory")},
        {'b', QLatin1String("build_command")},
        {'c', QLatin1String("create_test_sourcelist")},
        {'d', QLatin1String("define_property")},
        {'e', QLatin1String("enable_language")},
        {'e', QLatin1String("enable_testing")},
        {'e', QLatin1String("export")},
        {'f', QLatin1String("fltk_wrap_ui")},
        {'g', QLatin1String("get_source_file_property")},
        {'g', QLatin1String("get_target_property")},
        {'g', QLatin1String("get_test_property")},
        {'i', QLatin1String("include_directories")},
        {'i', QLatin1String("include_external_msproject")},
        {'i', QLatin1String("include_regular_expression")},
        {'i', QLatin1String("install")},
        {'l', QLatin1String("link_directories")},
        {'l', QLatin1String("link_libraries")},
        {'l', QLatin1String("load_cache")},
        {'p', QLatin1String("project")},
        {'q', QLatin1String("qt_wrap_cpp")},
        {'q', QLatin1String("qt_wrap_ui")},
        {'r', QLatin1String("remove_definitions")},
        {'s', QLatin1String("set_source_files_properties")},
        {'s', QLatin1String("set_target_properties")},
        {'s', QLatin1String("set_tests_properties")},
        {'s', QLatin1String("source_group")},
        {'t', QLatin1String("target_compile_definitions")},
        {'t', QLatin1String("target_compile_features")},
        {'t', QLatin1String("target_compile_options")},
        {'t', QLatin1String("target_include_directories")},
        {'t', QLatin1String("target_link_directories")},
        {'t', QLatin1String("target_link_libraries")},
        {'t', QLatin1String("target_link_options")},
        {'t', QLatin1String("target_sources")},
        {'t', QLatin1String("try_compile")},
        {'t', QLatin1String("try_run")},
        {'c', QLatin1String("ctest_build")},
        {'c', QLatin1String("ctest_configure")},
        {'c', QLatin1String("ctest_coverage")},
        {'c', QLatin1String("ctest_empty_binary_directory")},
        {'c', QLatin1String("ctest_memcheck")},
        {'c', QLatin1String("ctest_read_custom_files")},
        {'c', QLatin1String("ctest_run_script")},
        {'c', QLatin1String("ctest_sleep")},
        {'c', QLatin1String("ctest_start")},
        {'c', QLatin1String("ctest_submit")},
        {'c', QLatin1String("ctest_test")},
        {'c', QLatin1String("ctest_update")},
        {'c', QLatin1String("ctest_upload")},
        {'b', QLatin1String("build_name")},
        {'e', QLatin1String("exec_program")},
        {'e', QLatin1String("export_library_dependencies")},
        {'i', QLatin1String("install_files")},
        {'i', QLatin1String("install_programs")},
        {'i', QLatin1String("install_targets")},
        {'l', QLatin1String("load_command")},
        {'m', QLatin1String("make_directory")},
        {'o', QLatin1String("output_required_files")},
        {'r', QLatin1String("remove")},
        {'s', QLatin1String("subdir_depends")},
        {'s', QLatin1String("subdirs")},
        {'u', QLatin1String("use_mangled_mesa")},
        {'u', QLatin1String("utility_source")},
        {'v', QLatin1String("variable_requires")},
        {'w', QLatin1String("write_file")},
        {'q', QLatin1String("qt5_use_modules")},
        {'q', QLatin1String("qt5_use_package")},
        {'q', QLatin1String("qt5_wrap_cpp")},
        {'a', QLatin1String("and")},
        {'o', QLatin1String("or")},
        {'n', QLatin1String("not")},
        {'c', QLatin1String("command")},
        {'p', QLatin1String("policy")},
        {'t', QLatin1String("target")},
        {'t', QLatin1String("test")},
        {'e', QLatin1String("exists")},
        {'i', QLatin1String("is_newer_than")},
        {'i', QLatin1String("is_directory")},
        {'i', QLatin1String("is_symlink")},
        {'i', QLatin1String("is_absolute")},
        {'m', QLatin1String("matches")},
        {'l', QLatin1String("less")},
        {'g', QLatin1String("greater")},
        {'e', QLatin1String("equal")},
        {'l', QLatin1String("less_equal")},
        {'g', QLatin1String("greater_equal")},
        {'s', QLatin1String("strless")},
        {'s', QLatin1String("strgreater")},
        {'s', QLatin1String("strequal")},
        {'s', QLatin1String("strless_equal")},
        {'s', QLatin1String("strgreater_equal")},
        {'v', QLatin1String("version_less")},
        {'v', QLatin1String("version_greater")},
        {'v', QLatin1String("version_equal")},
        {'v', QLatin1String("version_less_equal")},
        {'v', QLatin1String("version_greater_equal")},
        {'i', QLatin1String("in_list")},
        {'d', QLatin1String("defined")}
    };
    cmake_types = {};
    cmake_literals = {
        {'o', QLatin1String("on")},
        {'o', QLatin1String("off")},
        {'O', QLatin1String("ON")},
        {'O', QLatin1String("OFF")},
        {'t', QLatin1String("true")},
        {'f', QLatin1String("false")},
        {'T', QLatin1String("TRUE")},
        {'F', QLatin1String("FALSE")}
    };
    cmake_builtin = {
        {'A', QLatin1String("ALLOW_DUPLICATE_CUSTOM_TARGETS")},
        {'A', QLatin1String("AUTOGEN_TARGETS_FOLDER")},
        {'A', QLatin1String("AUTOMOC_TARGETS_FOLDER")},
        {'D', QLatin1String("DEBUG_CONFIGURATIONS")},
        {'D', QLatin1String("DISABLED_FEATURES")},
        {'E', QLatin1String("ENABLED_FEATURES")},
        {'E', QLatin1String("ENABLED_LANGUAGES")},
        {'F', QLatin1String("FIND_LIBRARY_USE_LIB64_PATHS")},
        {'F', QLatin1String("FIND_LIBRARY_USE_OPENBSD_VERSIONING")},
        {'G', QLatin1String("GLOBAL_DEPENDS_DEBUG_MODE")},
        {'G', QLatin1String("GLOBAL_DEPENDS_NO_CYCLES")},
        {'I', QLatin1String("IN_TRY_COMPILE")},
        {'P', QLatin1String("PACKAGES_FOUND")},
        {'P', QLatin1String("PACKAGES_NOT_FOUND")},
        {'J', QLatin1String("JOB_POOLS")},
        {'P', QLatin1String("PREDEFINED_TARGETS_FOLDER")},
        {'E', QLatin1String("ECLIPSE_EXTRA_NATURES")},
        {'R', QLatin1String("REPORT_UNDEFINED_PROPERTIES")},
        {'R', QLatin1String("RULE_LAUNCH_COMPILE")},
        {'R', QLatin1String("RULE_LAUNCH_CUSTOM")},
        {'R', QLatin1String("RULE_LAUNCH_LINK")},
        {'R', QLatin1String("RULE_MESSAGES")},
        {'T', QLatin1String("TARGET_ARCHIVES_MAY_BE_SHARED_LIBS")},
        {'T', QLatin1String("TARGET_SUPPORTS_SHARED_LIBS")},
        {'U', QLatin1String("USE_FOLDERS")},
        {'A', QLatin1String("ADDITIONAL_MAKE_CLEAN_FILES")},
        {'C', QLatin1String("CACHE_VARIABLES")},
        {'C', QLatin1String("CLEAN_NO_CUSTOM")},
        {'C', QLatin1String("CMAKE_CONFIGURE_DEPENDS")},
        {'C', QLatin1String("COMPILE_DEFINITIONS")},
        {'C', QLatin1String("COMPILE_OPTIONS")},
        {'D', QLatin1String("DEFINITIONS")},
        {'E', QLatin1String("EXCLUDE_FROM_ALL")},
        {'I', QLatin1String("IMPLICIT_DEPENDS_INCLUDE_TRANSFORM")},
        {'I', QLatin1String("INCLUDE_DIRECTORIES")},
        {'I', QLatin1String("INCLUDE_REGULAR_EXPRESSION")},
        {'I', QLatin1String("INTERPROCEDURAL_OPTIMIZATION")},
        {'L', QLatin1String("LINK_DIRECTORIES")},
        {'L', QLatin1String("LISTFILE_STACK")},
        {'M', QLatin1String("MACROS")},
        {'P', QLatin1String("PARENT_DIRECTORY")},
        {'R', QLatin1String("RULE_LAUNCH_COMPILE")},
        {'R', QLatin1String("RULE_LAUNCH_CUSTOM")},
        {'R', QLatin1String("RULE_LAUNCH_LINK")},
        {'T', QLatin1String("TEST_INCLUDE_FILE")},
        {'V', QLatin1String("VARIABLES")},
        {'A', QLatin1String("ALIASED_TARGET")},
        {'A', QLatin1String("ARCHIVE_OUTPUT_DIRECTORY")},
        {'A', QLatin1String("ARCHIVE_OUTPUT_NAME")},
        {'A', QLatin1String("AUTOGEN_TARGET_DEPENDS")},
        {'A', QLatin1String("AUTOMOC_MOC_OPTIONS")},
        {'A', QLatin1String("AUTOMOC")},
        {'A', QLatin1String("AUTOUIC")},
        {'A', QLatin1String("AUTOUIC_OPTIONS")},
        {'A', QLatin1String("AUTORCC")},
        {'A', QLatin1String("AUTORCC_OPTIONS")},
        {'B', QLatin1String("BUILD_WITH_INSTALL_RPATH")},
        {'B', QLatin1String("BUNDLE_EXTENSION")},
        {'B', QLatin1String("BUNDLE")},
        {'C', QLatin1String("COMPATIBLE_INTERFACE_BOOL")},
        {'C', QLatin1String("COMPATIBLE_INTERFACE_NUMBER_MAX")},
        {'C', QLatin1String("COMPATIBLE_INTERFACE_NUMBER_MIN")},
        {'C', QLatin1String("COMPATIBLE_INTERFACE_STRING")},
        {'C', QLatin1String("COMPILE_DEFINITIONS")},
        {'C', QLatin1String("COMPILE_FLAGS")},
        {'C', QLatin1String("COMPILE_OPTIONS")},
        {'D', QLatin1String("DEBUG_POSTFIX")},
        {'D', QLatin1String("DEFINE_SYMBOL")},
        {'E', QLatin1String("EchoString")},
        {'E', QLatin1String("ENABLE_EXPORTS")},
        {'E', QLatin1String("EXCLUDE_FROM_ALL")},
        {'E', QLatin1String("EXCLUDE_FROM_DEFAULT_BUILD")},
        {'E', QLatin1String("EXPORT_NAME")},
        {'F', QLatin1String("FOLDER")},
        {'F', QLatin1String("Fortran_FORMAT")},
        {'F', QLatin1String("Fortran_MODULE_DIRECTORY")},
        {'F', QLatin1String("FRAMEWORK")},
        {'G', QLatin1String("GENERATOR_FILE_NAME")},
        {'G', QLatin1String("GNUtoMS")},
        {'H', QLatin1String("HAS_CXX")},
        {'I', QLatin1String("IMPLICIT_DEPENDS_INCLUDE_TRANSFORM")},
        {'I', QLatin1String("IMPORTED_CONFIGURATIONS")},
        {'I', QLatin1String("IMPORTED_IMPLIB")},
        {'I', QLatin1String("IMPORTED_LINK_DEPENDENT_LIBRARIES")},
        {'I', QLatin1String("IMPORTED_LINK_INTERFACE_LANGUAGES")},
        {'I', QLatin1String("IMPORTED_LINK_INTERFACE_LIBRARIES")},
        {'I', QLatin1String("IMPORTED_LINK_INTERFACE_MULTIPLICITY")},
        {'I', QLatin1String("IMPORTED_LOCATION")},
        {'I', QLatin1String("IMPORTED_NO_SONAME")},
        {'I', QLatin1String("IMPORTED")},
        {'I', QLatin1String("IMPORTED_SONAME")},
        {'I', QLatin1String("IMPORT_PREFIX")},
        {'I', QLatin1String("IMPORT_SUFFIX")},
        {'I', QLatin1String("INCLUDE_DIRECTORIES")},
        {'I', QLatin1String("INSTALL_NAME_DIR")},
        {'I', QLatin1String("INSTALL_RPATH")},
        {'I', QLatin1String("INSTALL_RPATH_USE_LINK_PATH")},
        {'I', QLatin1String("INTERFACE_AUTOUIC_OPTIONS")},
        {'I', QLatin1String("INTERFACE_COMPILE_DEFINITIONS")},
        {'I', QLatin1String("INTERFACE_COMPILE_OPTIONS")},
        {'I', QLatin1String("INTERFACE_INCLUDE_DIRECTORIES")},
        {'I', QLatin1String("INTERFACE_LINK_LIBRARIES")},
        {'I', QLatin1String("INTERFACE_POSITION_INDEPENDENT_CODE")},
        {'I', QLatin1String("INTERFACE_SYSTEM_INCLUDE_DIRECTORIES")},
        {'I', QLatin1String("INTERPROCEDURAL_OPTIMIZATION")},
        {'J', QLatin1String("JOB_POOL_COMPILE")},
        {'J', QLatin1String("JOB_POOL_LINK")},
        {'L', QLatin1String("LABELS")},
        {'L', QLatin1String("LIBRARY_OUTPUT_DIRECTORY")},
        {'L', QLatin1String("LIBRARY_OUTPUT_NAME")},
        {'L', QLatin1String("LINK_DEPENDS_NO_SHARED")},
        {'L', QLatin1String("LINK_DEPENDS")},
        {'L', QLatin1String("LINKER_LANGUAGE")},
        {'L', QLatin1String("LINK_FLAGS")},
        {'L', QLatin1String("LINK_INTERFACE_LIBRARIES")},
        {'L', QLatin1String("LINK_INTERFACE_MULTIPLICITY")},
        {'L', QLatin1String("LINK_LIBRARIES")},
        {'L', QLatin1String("LINK_SEARCH_END_STATIC")},
        {'L', QLatin1String("LINK_SEARCH_START_STATIC")},
        {'L', QLatin1String("LOCATION")},
        {'M', QLatin1String("MACOSX_BUNDLE_INFO_PLIST")},
        {'M', QLatin1String("MACOSX_BUNDLE")},
        {'M', QLatin1String("MACOSX_FRAMEWORK_INFO_PLIST")},
        {'M', QLatin1String("MACOSX_RPATH")},
//        {'N', QLatin1String("NAME")},
        {'N', QLatin1String("NO_SONAME")},
        {'N', QLatin1String("NO_SYSTEM_FROM_IMPORTED")},
        {'O', QLatin1String("OSX_ARCHITECTURES")},
        {'O', QLatin1String("OUTPUT_NAME")},
        {'P', QLatin1String("PDB_NAME")},
        {'P', QLatin1String("PDB_OUTPUT_DIRECTORY")},
        {'P', QLatin1String("POSITION_INDEPENDENT_CODE")},
        {'P', QLatin1String("POST_INSTALL_SCRIPT")},
        {'P', QLatin1String("PREFIX")},
        {'P', QLatin1String("PROPERTY")},
        {'P', QLatin1String("PRE_INSTALL_SCRIPT")},
        {'P', QLatin1String("PRIVATE_HEADER")},
        {'P', QLatin1String("PROJECT_LABEL")},
        {'P', QLatin1String("PUBLIC_HEADER")},
        {'R', QLatin1String("RESOURCE")},
        {'R', QLatin1String("RULE_LAUNCH_COMPILE")},
        {'R', QLatin1String("RULE_LAUNCH_CUSTOM")},
        {'R', QLatin1String("RULE_LAUNCH_LINK")},
        {'R', QLatin1String("RUNTIME_OUTPUT_DIRECTORY")},
        {'R', QLatin1String("RUNTIME_OUTPUT_NAME")},
        {'S', QLatin1String("SKIP_BUILD_RPATH")},
        {'S', QLatin1String("SOURCES")},
        {'S', QLatin1String("SOVERSION")},
        {'S', QLatin1String("STATIC_LIBRARY_FLAGS")},
        {'S', QLatin1String("SUFFIX")},
        {'T', QLatin1String("TARGET")},
        {'T', QLatin1String("TYPE")},
        {'V', QLatin1String("VERSION")},
        {'V', QLatin1String("VISIBILITY_INLINES_HIDDEN")},
        {'V', QLatin1String("VS_DOTNET_REFERENCES")},
        {'V', QLatin1String("VS_DOTNET_TARGET_FRAMEWORK_VERSION")},
        {'V', QLatin1String("VS_GLOBAL_KEYWORD")},
        {'V', QLatin1String("VS_GLOBAL_PROJECT_TYPES")},
        {'V', QLatin1String("VS_GLOBAL_ROOTNAMESPACE")},
        {'V', QLatin1String("VS_KEYWORD")},
        {'V', QLatin1String("VS_SCC_AUXPATH")},
        {'V', QLatin1String("VS_SCC_LOCALPATH")},
        {'V', QLatin1String("VS_SCC_PROJECTNAME")},
        {'V', QLatin1String("VS_SCC_PROVIDER")},
        {'V', QLatin1String("VS_WINRT_EXTENSIONS")},
        {'V', QLatin1String("VS_WINRT_REFERENCES")},
        {'W', QLatin1String("WIN32_EXECUTABLE")},
        {'A', QLatin1String("ATTACHED_FILES_ON_FAIL")},
        {'A', QLatin1String("ATTACHED_FILES")},
        {'C', QLatin1String("COST")},
        {'D', QLatin1String("DEPENDS")},
        {'E', QLatin1String("ENVIRONMENT")},
        {'F', QLatin1String("FAIL_REGULAR_EXPRESSION")},
        {'L', QLatin1String("LABELS")},
        {'M', QLatin1String("MEASUREMENT")},
        {'P', QLatin1String("PASS_REGULAR_EXPRESSION")},
        {'P', QLatin1String("PROCESSORS")},
        {'R', QLatin1String("REQUIRED_FILES")},
        {'R', QLatin1String("RESOURCE_LOCK")},
        {'R', QLatin1String("RUN_SERIAL")},
        {'S', QLatin1String("SKIP_RETURN_CODE")},
        {'T', QLatin1String("TIMEOUT")},
        {'W', QLatin1String("WILL_FAIL")},
        {'W', QLatin1String("WORKING_DIRECTORY")},
        {'A', QLatin1String("ABSTRACT")},
        {'A', QLatin1String("AUTOUIC_OPTIONS")},
        {'A', QLatin1String("AUTORCC_OPTIONS")},
        {'C', QLatin1String("COMPILE_DEFINITIONS")},
        {'C', QLatin1String("COMPILE_FLAGS")},
        {'E', QLatin1String("EXTERNAL_OBJECT")},
        {'F', QLatin1String("Fortran_FORMAT")},
        {'G', QLatin1String("GENERATED")},
        {'H', QLatin1String("HEADER_FILE_ONLY")},
        {'K', QLatin1String("KEEP_EXTENSION")},
        {'L', QLatin1String("LABELS")},
//        {'L', QLatin1String("LANGUAGE")},
        {'L', QLatin1String("LOCATION")},
        {'M', QLatin1String("MACOSX_PACKAGE_LOCATION")},
        {'O', QLatin1String("OBJECT_DEPENDS")},
        {'O', QLatin1String("OBJECT_OUTPUTS")},
        {'S', QLatin1String("SYMBOLIC")},
        {'W', QLatin1String("WRAP_EXCLUDE")},
        {'A', QLatin1String("ADVANCED")},
        {'H', QLatin1String("HELPSTRING")},
        {'M', QLatin1String("MODIFIED")},
        {'S', QLatin1String("STRINGS")},
        {'T', QLatin1String("TYPE")},
        {'V', QLatin1String("VALUE")}
    };
    cmake_other = {
        {'C', QLatin1String("CMAKE_ARGC")},
        {'C', QLatin1String("CMAKE_ARGV0")},
        {'C', QLatin1String("CMAKE_AR")},
        {'C', QLatin1String("CMAKE_BINARY_DIR")},
        {'C', QLatin1String("CMAKE_BUILD_TOOL")},
        {'C', QLatin1String("CMAKE_CACHEFILE_DIR")},
        {'C', QLatin1String("CMAKE_CACHE_MAJOR_VERSION")},
        {'C', QLatin1String("CMAKE_CACHE_MINOR_VERSION")},
        {'C', QLatin1String("CMAKE_CACHE_PATCH_VERSION")},
        {'C', QLatin1String("CMAKE_CFG_INTDIR")},
        {'C', QLatin1String("CMAKE_COMMAND")},
        {'C', QLatin1String("CMAKE_CROSSCOMPILING")},
        {'C', QLatin1String("CMAKE_CTEST_COMMAND")},
        {'C', QLatin1String("CMAKE_CURRENT_BINARY_DIR")},
        {'C', QLatin1String("CMAKE_CURRENT_LIST_DIR")},
        {'C', QLatin1String("CMAKE_CURRENT_LIST_FILE")},
        {'C', QLatin1String("CMAKE_CURRENT_LIST_LINE")},
        {'C', QLatin1String("CMAKE_CURRENT_SOURCE_DIR")},
        {'C', QLatin1String("CMAKE_DL_LIBS")},
        {'C', QLatin1String("CMAKE_EDIT_COMMAND")},
        {'C', QLatin1String("CMAKE_EXECUTABLE_SUFFIX")},
        {'C', QLatin1String("CMAKE_EXTRA_GENERATOR")},
        {'C', QLatin1String("CMAKE_EXTRA_SHARED_LIBRARY_SUFFIXES")},
        {'C', QLatin1String("CMAKE_GENERATOR")},
        {'C', QLatin1String("CMAKE_GENERATOR_TOOLSET")},
        {'C', QLatin1String("CMAKE_HOME_DIRECTORY")},
        {'C', QLatin1String("CMAKE_IMPORT_LIBRARY_PREFIX")},
        {'C', QLatin1String("CMAKE_IMPORT_LIBRARY_SUFFIX")},
        {'C', QLatin1String("CMAKE_JOB_POOL_COMPILE")},
        {'C', QLatin1String("CMAKE_JOB_POOL_LINK")},
        {'C', QLatin1String("CMAKE_LINK_LIBRARY_SUFFIX")},
        {'C', QLatin1String("CMAKE_MAJOR_VERSION")},
        {'C', QLatin1String("CMAKE_MAKE_PROGRAM")},
        {'C', QLatin1String("CMAKE_MINIMUM_REQUIRED_VERSION")},
        {'C', QLatin1String("CMAKE_MINOR_VERSION")},
        {'C', QLatin1String("CMAKE_PARENT_LIST_FILE")},
        {'C', QLatin1String("CMAKE_PATCH_VERSION")},
        {'C', QLatin1String("CMAKE_PROJECT_NAME")},
        {'C', QLatin1String("CMAKE_RANLIB")},
        {'C', QLatin1String("CMAKE_ROOT")},
        {'C', QLatin1String("CMAKE_SCRIPT_MODE_FILE")},
        {'C', QLatin1String("CMAKE_SHARED_LIBRARY_PREFIX")},
        {'C', QLatin1String("CMAKE_SHARED_LIBRARY_SUFFIX")},
        {'C', QLatin1String("CMAKE_SHARED_MODULE_PREFIX")},
        {'C', QLatin1String("CMAKE_SHARED_MODULE_SUFFIX")},
        {'C', QLatin1String("CMAKE_SIZEOF_VOID_P")},
        {'C', QLatin1String("CMAKE_SKIP_INSTALL_RULES")},
        {'C', QLatin1String("CMAKE_SKIP_RPATH")},
        {'C', QLatin1String("CMAKE_SOURCE_DIR")},
        {'C', QLatin1String("CMAKE_STANDARD_LIBRARIES")},
        {'C', QLatin1String("CMAKE_STATIC_LIBRARY_PREFIX")},
        {'C', QLatin1String("CMAKE_STATIC_LIBRARY_SUFFIX")},
        {'C', QLatin1String("CMAKE_TOOLCHAIN_FILE")},
        {'C', QLatin1String("CMAKE_TWEAK_VERSION")},
        {'C', QLatin1String("CMAKE_VERBOSE_MAKEFILE")},
        {'C', QLatin1String("CMAKE_VERSION")},
        {'C', QLatin1String("CMAKE_VS_DEVENV_COMMAND")},
        {'C', QLatin1String("CMAKE_VS_INTEL_Fortran_PROJECT_VERSION")},
        {'C', QLatin1String("CMAKE_VS_MSBUILD_COMMAND")},
        {'C', QLatin1String("CMAKE_VS_MSDEV_COMMAND")},
        {'C', QLatin1String("CMAKE_VS_PLATFORM_TOOLSET")},
        {'C', QLatin1String("CMAKE_XCODE_PLATFORM_TOOLSET")},
        {'P', QLatin1String("PROJECT_BINARY_DIR")},
//        {'P', QLatin1String("PROJECT_NAME")},
        {'P', QLatin1String("PROJECT_SOURCE_DIR")},
        {'P', QLatin1String("PROJECT_VERSION")},
        {'P', QLatin1String("PROJECT_VERSION_MAJOR")},
        {'P', QLatin1String("PROJECT_VERSION_MINOR")},
        {'P', QLatin1String("PROJECT_VERSION_PATCH")},
        {'P', QLatin1String("PROJECT_VERSION_TWEAK")},
        {'B', QLatin1String("BUILD_SHARED_LIBS")},
        {'C', QLatin1String("CMAKE_ABSOLUTE_DESTINATION_FILES")},
        {'C', QLatin1String("CMAKE_APPBUNDLE_PATH")},
        {'C', QLatin1String("CMAKE_AUTOMOC_RELAXED_MODE")},
        {'C', QLatin1String("CMAKE_BACKWARDS_COMPATIBILITY")},
        {'C', QLatin1String("CMAKE_BUILD_TYPE")},
        {'C', QLatin1String("CMAKE_COLOR_MAKEFILE")},
        {'C', QLatin1String("CMAKE_CONFIGURATION_TYPES")},
        {'C', QLatin1String("CMAKE_DEBUG_TARGET_PROPERTIES")},
        {'C', QLatin1String("CMAKE_ERROR_DEPRECATED")},
        {'C', QLatin1String("CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION")},
        {'C', QLatin1String("CMAKE_SYSROOT")},
        {'C', QLatin1String("CMAKE_FIND_LIBRARY_PREFIXES")},
        {'C', QLatin1String("CMAKE_FIND_LIBRARY_SUFFIXES")},
        {'C', QLatin1String("CMAKE_FIND_NO_INSTALL_PREFIX")},
        {'C', QLatin1String("CMAKE_FIND_PACKAGE_WARN_NO_MODULE")},
        {'C', QLatin1String("CMAKE_FIND_ROOT_PATH")},
        {'C', QLatin1String("CMAKE_FIND_ROOT_PATH_MODE_INCLUDE")},
        {'C', QLatin1String("CMAKE_FIND_ROOT_PATH_MODE_LIBRARY")},
        {'C', QLatin1String("CMAKE_FIND_ROOT_PATH_MODE_PACKAGE")},
        {'C', QLatin1String("CMAKE_FIND_ROOT_PATH_MODE_PROGRAM")},
        {'C', QLatin1String("CMAKE_FRAMEWORK_PATH")},
        {'C', QLatin1String("CMAKE_IGNORE_PATH")},
        {'C', QLatin1String("CMAKE_INCLUDE_PATH")},
        {'C', QLatin1String("CMAKE_INCLUDE_DIRECTORIES_BEFORE")},
        {'C', QLatin1String("CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE")},
        {'C', QLatin1String("CMAKE_INSTALL_DEFAULT_COMPONENT_NAME")},
        {'C', QLatin1String("CMAKE_INSTALL_PREFIX")},
        {'C', QLatin1String("CMAKE_LIBRARY_PATH")},
        {'C', QLatin1String("CMAKE_MFC_FLAG")},
        {'C', QLatin1String("CMAKE_MODULE_PATH")},
        {'C', QLatin1String("CMAKE_NOT_USING_CONFIG_FLAGS")},
        {'C', QLatin1String("CMAKE_PREFIX_PATH")},
        {'C', QLatin1String("CMAKE_PROGRAM_PATH")},
        {'C', QLatin1String("CMAKE_SKIP_INSTALL_ALL_DEPENDENCY")},
        {'C', QLatin1String("CMAKE_STAGING_PREFIX")},
        {'C', QLatin1String("CMAKE_SYSTEM_IGNORE_PATH")},
        {'C', QLatin1String("CMAKE_SYSTEM_INCLUDE_PATH")},
        {'C', QLatin1String("CMAKE_SYSTEM_LIBRARY_PATH")},
        {'C', QLatin1String("CMAKE_SYSTEM_PREFIX_PATH")},
        {'C', QLatin1String("CMAKE_SYSTEM_PROGRAM_PATH")},
        {'C', QLatin1String("CMAKE_USER_MAKE_RULES_OVERRIDE")},
        {'C', QLatin1String("CMAKE_WARN_DEPRECATED")},
        {'C', QLatin1String("CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION")},
        {'A', QLatin1String("APPLE")},
        {'B', QLatin1String("BORLAND")},
        {'C', QLatin1String("CMAKE_CL_64")},
        {'C', QLatin1String("CMAKE_COMPILER_2005")},
        {'C', QLatin1String("CMAKE_HOST_APPLE")},
        {'C', QLatin1String("CMAKE_HOST_SYSTEM_NAME")},
        {'C', QLatin1String("CMAKE_HOST_SYSTEM_PROCESSOR")},
        {'C', QLatin1String("CMAKE_HOST_SYSTEM")},
        {'C', QLatin1String("CMAKE_HOST_SYSTEM_VERSION")},
        {'C', QLatin1String("CMAKE_HOST_UNIX")},
        {'C', QLatin1String("CMAKE_HOST_WIN32")},
        {'C', QLatin1String("CMAKE_LIBRARY_ARCHITECTURE_REGEX")},
        {'C', QLatin1String("CMAKE_LIBRARY_ARCHITECTURE")},
        {'C', QLatin1String("CMAKE_OBJECT_PATH_MAX")},
        {'C', QLatin1String("CMAKE_SYSTEM_NAME")},
        {'C', QLatin1String("CMAKE_SYSTEM_PROCESSOR")},
        {'C', QLatin1String("CMAKE_SYSTEM")},
        {'C', QLatin1String("CMAKE_SYSTEM_VERSION")},
        {'C', QLatin1String("CYGWIN")},
        {'E', QLatin1String("ENV")},
        {'M', QLatin1String("MSVC10")},
        {'M', QLatin1String("MSVC11")},
        {'M', QLatin1String("MSVC12")},
        {'M', QLatin1String("MSVC60")},
        {'M', QLatin1String("MSVC70")},
        {'M', QLatin1String("MSVC71")},
        {'M', QLatin1String("MSVC80")},
        {'M', QLatin1String("MSVC90")},
        {'M', QLatin1String("MSVC_IDE")},
        {'M', QLatin1String("MSVC")},
        {'M', QLatin1String("MSVC_VERSION")},
        {'U', QLatin1String("UNIX")},
        {'W', QLatin1String("WIN32")},
        {'X', QLatin1String("XCODE_VERSION")},
        {'C', QLatin1String("CMAKE_ARCHIVE_OUTPUT_DIRECTORY")},
        {'C', QLatin1String("CMAKE_AUTOMOC_MOC_OPTIONS")},
        {'C', QLatin1String("CMAKE_AUTOMOC")},
        {'C', QLatin1String("CMAKE_AUTORCC")},
        {'C', QLatin1String("CMAKE_AUTORCC_OPTIONS")},
        {'C', QLatin1String("CMAKE_AUTOUIC")},
        {'C', QLatin1String("CMAKE_AUTOUIC_OPTIONS")},
        {'C', QLatin1String("CMAKE_BUILD_WITH_INSTALL_RPATH")},
        {'C', QLatin1String("CMAKE_DEBUG_POSTFIX")},
        {'C', QLatin1String("CMAKE_EXE_LINKER_FLAGS")},
        {'C', QLatin1String("CMAKE_Fortran_FORMAT")},
        {'C', QLatin1String("CMAKE_Fortran_MODULE_DIRECTORY")},
        {'C', QLatin1String("CMAKE_GNUtoMS")},
        {'C', QLatin1String("CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE")},
        {'C', QLatin1String("CMAKE_INCLUDE_CURRENT_DIR")},
        {'C', QLatin1String("CMAKE_INSTALL_NAME_DIR")},
        {'C', QLatin1String("CMAKE_INSTALL_RPATH")},
        {'C', QLatin1String("CMAKE_INSTALL_RPATH_USE_LINK_PATH")},
        {'C', QLatin1String("CMAKE_LIBRARY_OUTPUT_DIRECTORY")},
        {'C', QLatin1String("CMAKE_LIBRARY_PATH_FLAG")},
        {'C', QLatin1String("CMAKE_LINK_DEF_FILE_FLAG")},
        {'C', QLatin1String("CMAKE_LINK_DEPENDS_NO_SHARED")},
        {'C', QLatin1String("CMAKE_LINK_INTERFACE_LIBRARIES")},
        {'C', QLatin1String("CMAKE_LINK_LIBRARY_FILE_FLAG")},
        {'C', QLatin1String("CMAKE_LINK_LIBRARY_FLAG")},
        {'C', QLatin1String("CMAKE_MACOSX_BUNDLE")},
        {'C', QLatin1String("CMAKE_MACOSX_RPATH")},
        {'C', QLatin1String("CMAKE_MODULE_LINKER_FLAGS")},
        {'C', QLatin1String("CMAKE_NO_BUILTIN_CHRPATH")},
        {'C', QLatin1String("CMAKE_NO_SYSTEM_FROM_IMPORTED")},
        {'C', QLatin1String("CMAKE_OSX_ARCHITECTURES")},
        {'C', QLatin1String("CMAKE_OSX_DEPLOYMENT_TARGET")},
        {'C', QLatin1String("CMAKE_OSX_SYSROOT")},
        {'C', QLatin1String("CMAKE_PDB_OUTPUT_DIRECTORY")},
        {'C', QLatin1String("CMAKE_POSITION_INDEPENDENT_CODE")},
        {'C', QLatin1String("CMAKE_RUNTIME_OUTPUT_DIRECTORY")},
        {'C', QLatin1String("CMAKE_SHARED_LINKER_FLAGS")},
        {'C', QLatin1String("CMAKE_SKIP_BUILD_RPATH")},
        {'C', QLatin1String("CMAKE_SKIP_INSTALL_RPATH")},
        {'C', QLatin1String("CMAKE_STATIC_LINKER_FLAGS")},
        {'C', QLatin1String("CMAKE_TRY_COMPILE_CONFIGURATION")},
        {'C', QLatin1String("CMAKE_USE_RELATIVE_PATHS")},
        {'C', QLatin1String("CMAKE_VISIBILITY_INLINES_HIDDEN")},
        {'C', QLatin1String("CMAKE_WIN32_EXECUTABLE")},
        {'E', QLatin1String("EXECUTABLE_OUTPUT_PATH")},
        {'L', QLatin1String("LIBRARY_OUTPUT_PATH")},
        {'C', QLatin1String("CMAKE_Fortran_MODDIR_DEFAULT")},
        {'C', QLatin1String("CMAKE_Fortran_MODDIR_FLAG")},
        {'C', QLatin1String("CMAKE_Fortran_MODOUT_FLAG")},
        {'C', QLatin1String("CMAKE_INTERNAL_PLATFORM_ABI")},
        {'C', QLatin1String("CPACK_ABSOLUTE_DESTINATION_FILES")},
        {'C', QLatin1String("CPACK_COMPONENT_INCLUDE_TOPLEVEL_DIRECTORY")},
        {'C', QLatin1String("CPACK_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION")},
        {'C', QLatin1String("CPACK_INCLUDE_TOPLEVEL_DIRECTORY")},
        {'C', QLatin1String("CPACK_INSTALL_SCRIPT")},
        {'C', QLatin1String("CPACK_PACKAGING_INSTALL_PREFIX")},
        {'C', QLatin1String("CPACK_SET_DESTDIR")},
        {'C', QLatin1String("CPACK_WARN_ON_ABSOLUTE_INSTALL_DESTINATION")}
    };
}

void loadCMakeData(QMultiHash<char, QLatin1String> &types, QMultiHash<char, QLatin1String> &keywords, QMultiHash<char, QLatin1String> &builtin, QMultiHash<char, QLatin1String> &literals, QMultiHash<char, QLatin1String> &other)
{
    if (!cmakeDataInitialized) {
        initCMakeData();
        cmakeDataInitialized = true;
    }
    types = cmake_types;
    keywords = cmake_keywords;
    builtin = cmake_builtin;
    literals = cmake_literals;
    other = cmake_other;
}

}