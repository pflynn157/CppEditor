#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/**********************************************************/
/* Python Data *********************************************/
/**********************************************************/
static bool PyDataInitialized = false;
static LanguageData py_keywords;
static LanguageData py_types;
static LanguageData py_literals;
static LanguageData py_builtin;
static LanguageData py_other;

void initPyData() {
    py_keywords = {
        {('a'), QLatin1String("and")},
        {('e'), QLatin1String("elif")},
        {('i'), QLatin1String("is")},
        {('g'), QLatin1String("global")},
        {('a'), QLatin1String("as")},
        {('i'), QLatin1String("in")},
        {('i'), QLatin1String("if")},
        {('f'), QLatin1String("from")},
        {('r'), QLatin1String("raise")},
        {('f'), QLatin1String("for")},
        {('e'), QLatin1String("except")},
        {('f'), QLatin1String("finally")},
        {('p'), QLatin1String("print")},
        {('p'), QLatin1String("pass")},
        {('r'), QLatin1String("return")},
        {('e'), QLatin1String("exec")},
        {('e'), QLatin1String("else")},
        {('b'), QLatin1String("break")},
        {('n'), QLatin1String("not")},
        {('w'), QLatin1String("with")},
        {('c'), QLatin1String("class")},
        {('a'), QLatin1String("assert")},
        {('y'), QLatin1String("yield")},
        {('t'), QLatin1String("try")},
        {('w'), QLatin1String("while")},
        {('c'), QLatin1String("continue")},
        {('d'), QLatin1String("del")},
        {('o'), QLatin1String("or")},
        {('d'), QLatin1String("def")},
        {('l'), QLatin1String("lambda")},
        {('a'), QLatin1String("async")},
        {('a'), QLatin1String("await")},
        {('n'), QLatin1String("nonlocal")},
    };

    py_types = {

    };

    py_literals = {
        {('F'), QLatin1String("False")},
        {('T'), QLatin1String("True")},
        {('N'), QLatin1String("None")}
    };

    py_builtin = {
        { ('_'), QLatin1String("__import__") },
        { ('a'), QLatin1String("abs") },
        { ('a'), QLatin1String("all") },
        { ('a'), QLatin1String("any") },
        { ('a'), QLatin1String("apply") },
        { ('a'), QLatin1String("ascii") },
        { ('b'), QLatin1String("basestring") },
        { ('b'), QLatin1String("bin") },
        { ('b'), QLatin1String("bool") },
        { ('b'), QLatin1String("buffer") },
        { ('b'), QLatin1String("bytearray") },
        { ('b'), QLatin1String("bytes") },
        { ('c'), QLatin1String("callable") },
        { ('c'), QLatin1String("chr") },
        { ('c'), QLatin1String("classmethod") },
        { ('c'), QLatin1String("cmp") },
        { ('c'), QLatin1String("coerce") },
        { ('c'), QLatin1String("compile") },
        { ('c'), QLatin1String("complex") },
        { ('d'), QLatin1String("delattr") },
        { ('d'), QLatin1String("dict") },
        { ('d'), QLatin1String("dir") },
        { ('d'), QLatin1String("divmod") },
        { ('e'), QLatin1String("enumerate") },
        { ('e'), QLatin1String("eval") },
        { ('e'), QLatin1String("execfile") },
        { ('f'), QLatin1String("file") },
        { ('f'), QLatin1String("filter") },
        { ('f'), QLatin1String("float") },
        { ('f'), QLatin1String("format") },
        { ('f'), QLatin1String("frozenset") },
        { ('g'), QLatin1String("getattr") },
        { ('g'), QLatin1String("globals") },
        { ('h'), QLatin1String("hasattr") },
        { ('h'), QLatin1String("hash") },
        { ('h'), QLatin1String("help") },
        { ('h'), QLatin1String("hex") },
        { ('i'), QLatin1String("id") },
        { ('i'), QLatin1String("input") },
        { ('i'), QLatin1String("int") },
        { ('i'), QLatin1String("intern") },
        { ('i'), QLatin1String("isinstance") },
        { ('i'), QLatin1String("issubclass") },
        { ('i'), QLatin1String("iter") },
        { ('l'), QLatin1String("len") },
        { ('l'), QLatin1String("list") },
        { ('l'), QLatin1String("locals") },
        { ('l'), QLatin1String("long") },
        { ('m'), QLatin1String("map") },
        { ('m'), QLatin1String("max") },
        { ('m'), QLatin1String("memoryview") },
        { ('m'), QLatin1String("min") },
        { ('n'), QLatin1String("next") },
        { ('o'), QLatin1String("object") },
        { ('o'), QLatin1String("oct") },
        { ('o'), QLatin1String("open") },
        { ('o'), QLatin1String("ord") },
        { ('p'), QLatin1String("pow") },
        { ('p'), QLatin1String("property") },
        { ('r'), QLatin1String("range") },
        { ('r'), QLatin1String("raw_input") },
        { ('r'), QLatin1String("reduce") },
        { ('r'), QLatin1String("reload") },
        { ('r'), QLatin1String("repr") },
        { ('r'), QLatin1String("reversed") },
        { ('r'), QLatin1String("round") },
        { ('s'), QLatin1String("set") },
        { ('s'), QLatin1String("setattr") },
        { ('s'), QLatin1String("slice") },
        { ('s'), QLatin1String("sorted") },
        { ('s'), QLatin1String("staticmethod") },
        { ('s'), QLatin1String("str") },
        { ('s'), QLatin1String("sum") },
        { ('s'), QLatin1String("super") },
        { ('t'), QLatin1String("tuple") },
        { ('t'), QLatin1String("type") },
        { ('u'), QLatin1String("unichr") },
        { ('u'), QLatin1String("unicode") },
        { ('v'), QLatin1String("vars") },
        { ('x'), QLatin1String("xrange") },
        { ('z'), QLatin1String("zip") }
    };

    py_other = {
        {('i'), QLatin1String("import")}
    };
}
void loadPythonData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other){
    if (!PyDataInitialized) {
        initPyData();
        PyDataInitialized = true;
    }
    types = py_types;
    keywords = py_keywords;
    builtin = py_builtin;
    literals = py_literals;
    other = py_other;
}
