cmake_minimum_required(VERSION 3.0.0)
project(parser_template)

find_package(BISON)
find_package(FLEX)

add_compile_options(-std=c++11)

BISON_TARGET(parser grammar.y ${CMAKE_CURRENT_BINARY_DIR}/parser.yy.cpp)
FLEX_TARGET(scanner scanner.ll ${CMAKE_CURRENT_BINARY_DIR}/parser.lex.cpp)
ADD_FLEX_BISON_DEPENDENCY(scanner parser)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(PARSER_SRC
	${BISON_parser_OUTPUTS}
	${FLEX_scanner_OUTPUTS}
	main.cpp
)

add_executable(simple_parser ${PARSER_SRC})
