#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/********************************************************/
/***   Go DATA      *************************************/
/********************************************************/
static bool goDataInitialized = false;
static LanguageData go_keywords;
static LanguageData go_types;
static LanguageData go_literals;
static LanguageData go_builtin;
static LanguageData go_other;
void initGoData(){
    go_keywords = {
        {('b'), QLatin1String("break")},
        {('c'), QLatin1String("case")},
        {('c'), QLatin1String("chan")},
        {('c'), QLatin1String("const")},
        {('c'), QLatin1String("continue")},
        {('d'), QLatin1String("default")},
        {('d'), QLatin1String("defer")},
        {('e'), QLatin1String("else")},
        {('f'), QLatin1String("fallthrough")},
        {('f'), QLatin1String("for")},
        {('f'), QLatin1String("func")},
        {('g'), QLatin1String("go")},
        {('t'), QLatin1String("to")},
        {('i'), QLatin1String("if")},
        {('i'), QLatin1String("import")},
        {('i'), QLatin1String("interface")},
        {('p'), QLatin1String("package")},
        {('r'), QLatin1String("range")},
        {('r'), QLatin1String("return")},
        {('s'), QLatin1String("select")},
        {('s'), QLatin1String("struct")},
        {('s'), QLatin1String("switch")},
        {('t'), QLatin1String("type")},
    };

    go_types = {
        {('m'), QLatin1String("map")},
        {('s'), QLatin1String("struct")},
        {('v'), QLatin1String("var")},
        {('b'), QLatin1String("bool")},
        {('b'), QLatin1String("byte")},
        {('c'), QLatin1String("complex64")},
        {('c'), QLatin1String("complex128")},
        {('f'), QLatin1String("float32")},
        {('f'), QLatin1String("float64")},
        {('i'), QLatin1String("int8")},
        {('i'), QLatin1String("int16")},
        {('i'), QLatin1String("int32")},
        {('i'), QLatin1String("int64")},
        {('s'), QLatin1String("string")},
        {('u'), QLatin1String("uint8")},
        {('u'), QLatin1String("uint16")},
        {('u'), QLatin1String("uint32")},
        {('u'), QLatin1String("uint64")},
        {('i'), QLatin1String("int")},
        {('u'), QLatin1String("uint")},
        {('u'), QLatin1String("uintptr")},
        {('r'), QLatin1String("rune")}
    };

    go_literals = {
        {('f'), QLatin1String("false")},
        {('t'), QLatin1String("true")},
        {('n'), QLatin1String("nil")},
        {('i'), QLatin1String("iota")}
    };

    go_builtin = {
        {('a'), QLatin1String("append")},
        {('c'), QLatin1String("cap")},
        {('c'), QLatin1String("close")},
        {('c'), QLatin1String("complex")},
        {('c'), QLatin1String("copy")},
        {('i'), QLatin1String("imag")},
        {('l'), QLatin1String("len")},
        {('m'), QLatin1String("make")},
        {('n'), QLatin1String("new")},
        {('p'), QLatin1String("panic")},
        {('p'), QLatin1String("print")},
        {('p'), QLatin1String("println")},
        {('r'), QLatin1String("real")},
        {('r'), QLatin1String("recover")},
        {('d'), QLatin1String("delete")}
    };

    go_other = {

    };
}
void loadGoData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other) {
    if (!goDataInitialized) {
        initGoData();
        goDataInitialized = true;
    }
    types = go_types;
    keywords = go_keywords;
    builtin = go_builtin;
    literals = go_literals;
    other = go_other;
}
