## Parser Template

### What is it?

This is a template for building a parser using Flex and Bison in C or C++. While you could adapt it to any build system, I've found that CMake makes it really easy. I've included patterns for some common lexical elements, including types. The entry is the grammar file; the function is called "parse(const char *path)". Note that if you specify an invalid path, it will simply take input from stdin.

### License

This template is in the public domain. Hope its helpful.
