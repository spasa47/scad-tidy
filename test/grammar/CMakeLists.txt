message(STATUS "Configuring grammar tests")
add_executable(grammar_tests
        function_tests.cpp
        lexer/function_tests.cpp
)
target_link_libraries(grammar_tests PRIVATE scad_tidy::scad_tidy_warnings scad_tidy::scad_tidy_options
        scad_tidy::scad_tidy_grammar)

target_link_system_libraries(
        grammar_tests
        PRIVATE
        antlr4_static
        Catch2::Catch2WithMain
fmt::fmt)

target_include_directories(grammar_tests PRIVATE "${CMAKE_BINARY_DIR}/configured_files/include")
target_include_system_directories(
        grammar_tests
        PRIVATE
        "${antlr4_SOURCE_DIR}/runtime/Cpp/runtime/src"
        ${ANTLR_OpenScadLexer_OUTPUT_DIR}
        ${ANTLR_OpenScadParser_OUTPUT_DIR})

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(
            TARGET grammar_tests
            PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:grammar_tests> $<TARGET_FILE_DIR:grammar_tests>
            COMMAND_EXPAND_LISTS)
endif ()


catch_discover_tests(
        grammar_tests
        TEST_PREFIX
        "grammartests."
        REPORTER
        XML
        OUTPUT_DIR
        .
        OUTPUT_PREFIX
        "grammartests."
        OUTPUT_SUFFIX
        .xml)

