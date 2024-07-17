add_subdirectory(common)
add_subdirectory(utility)
add_subdirectory(grammar)
add_subdirectory(formatter)
add_subdirectory(linter)
add_subdirectory(cli)

# Need to set this at root level
set(ANTLR_OpenScadLexer_OUTPUT_DIR
    ${ANTLR_OpenScadLexer_OUTPUT_DIR}
    PARENT_SCOPE)
set(ANTLR_OpenScadParser_OUTPUT_DIR
    ${ANTLR_OpenScadParser_OUTPUT_DIR}
    PARENT_SCOPE)
