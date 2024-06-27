antlr_target( OpenScadLexer $ { CMAKE_CURRENT_LIST_DIR } / src
              / ScadLexer.g4 LEXER PACKAGE
                    scad_tidy ) antlr_target( OpenScadParser $ { CMAKE_CURRENT_LIST_DIR } / src
                                                  / ScadParser.g4 PARSER VISITOR PACKAGE parser
                                                        DEPENDS_ANTLR OpenScadLexer COMPILE_FLAGS
                                              - lib $ { ANTLR_OpenScadLexer_OUTPUT_DIR } )

    add_library( scad_tidy_grammar $ { ANTLR_OpenScadLexer_CXX_OUTPUTS } $ {
        ANTLR_OpenScadParser_CXX_OUTPUTS } )
        add_library( scad_tidy::scad_tidy_grammar ALIAS scad_tidy_grammar ) set_target_properties(
            scad_tidy_grammar PROPERTIES CXX_CLANG_TIDY "" CXX_CPPCHECK "" )

            set( ANTLR_OpenScadLexer_OUTPUT_DIR $ { ANTLR_OpenScadLexer_OUTPUT_DIR } PARENT_SCOPE )
                set( ANTLR_OpenScadParser_OUTPUT_DIR $ {
                    ANTLR_OpenScadParser_OUTPUT_DIR } PARENT_SCOPE )
                    target_include_system_directories(
                        scad_tidy_grammar PRIVATE "${antlr4_SOURCE_DIR}/runtime/Cpp/runtime/src" $ {
                            ANTLR_OpenScadLexer_OUTPUT_DIR } $ { ANTLR_OpenScadParser_OUTPUT_DIR } )