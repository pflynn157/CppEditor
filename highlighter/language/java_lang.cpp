#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/********************************************************/
/***   Java DATA      ***********************************/
/********************************************************/
static bool javaDataInitialized = false;
static LanguageData java_keywords;
static LanguageData java_types;
static LanguageData java_literals;
static LanguageData java_builtin;
static LanguageData java_other;
void initJavaData() {
    java_keywords = {
        {('a'), QLatin1String("abstract")},
        {('a'), QLatin1String("assert")},
        {('b'), QLatin1String("break")},
        {('c'), QLatin1String("case")},
        {('c'), QLatin1String("catch")},
        {('c'), QLatin1String("const")},
        {('c'), QLatin1String("continue")},
        {('d'), QLatin1String("default")},
        {('d'), QLatin1String("do")},
        {('e'), QLatin1String("else")},
        {('e'), QLatin1String("exports")},
        {('e'), QLatin1String("extends")},
        {('f'), QLatin1String("final")},
        {('f'), QLatin1String("finally")},
        {('f'), QLatin1String("for")},
        {('g'), QLatin1String("goto")},
        {('i'), QLatin1String("if")},
        {('i'), QLatin1String("implements")},
        {('i'), QLatin1String("import")},
        {('i'), QLatin1String("instanceof")},
        {('i'), QLatin1String("interface")},
        {('l'), QLatin1String("long")},
        {('m'), QLatin1String("module")},
        {('n'), QLatin1String("native")},
        {('n'), QLatin1String("new")},
        {('n'), QLatin1String("null")},
        {('o'), QLatin1String("open")},
        {('o'), QLatin1String("opens")},
        {('p'), QLatin1String("package")},
        {('p'), QLatin1String("private")},
        {('p'), QLatin1String("protected")},
        {('p'), QLatin1String("provides")},
        {('p'), QLatin1String("public")},
        {('r'), QLatin1String("requires")},
        {('r'), QLatin1String("return")},
        {('s'), QLatin1String("static")},
        {('s'), QLatin1String("strictfp")},
        {('s'), QLatin1String("super")},
        {('s'), QLatin1String("switch")},
        {('s'), QLatin1String("synchronized")},
        {('t'), QLatin1String("this")},
        {('t'), QLatin1String("throw")},
        {('t'), QLatin1String("throws")},
        {('t'), QLatin1String("to")},
        {('t'), QLatin1String("transient")},
        {('t'), QLatin1String("transitive")},
        {('t'), QLatin1String("try")},
        {('u'), QLatin1String("uses")},
        {('v'), QLatin1String("var")},
        {('v'), QLatin1String("volatile")},
        {('w'), QLatin1String("while")},
        {('w'), QLatin1String("with")},
        {('y'), QLatin1String("yield")}
    };

    java_types = {
        {('v'), QLatin1String("void")},
        {('f'), QLatin1String("float")},
        {('b'), QLatin1String("boolean")},
        {('b'), QLatin1String("byte")},
        {('i'), QLatin1String("int")},
        {('c'), QLatin1String("char")},
        {('c'), QLatin1String("class")},
        {('d'), QLatin1String("double")},
        {('e'), QLatin1String("enum")},
        {('s'), QLatin1String("short")},

    };

    java_literals = {
        {('f'), QLatin1String("false")},
        {('t'), QLatin1String("true")}
    };

    java_builtin = {

    };

    java_other = {

    };
}
void loadJavaData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other) {
    if (!javaDataInitialized) {
        initJavaData();
        javaDataInitialized = true;
    }
    types = java_types;
    keywords = java_keywords;
    builtin = java_builtin;
    literals = java_literals;
    other = java_other;
}
