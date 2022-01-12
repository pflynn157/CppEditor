#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/********************************************************/
/***   V DATA      **************************************/
/********************************************************/
static bool vDataInitialized = false;
static LanguageData v_keywords;
static LanguageData v_types;
static LanguageData v_literals;
static LanguageData v_builtin;
static LanguageData v_other;
void initVData() {
    v_keywords = {
        {('b'), QLatin1String("break")},
        {('c'), QLatin1String("const")},
        {('c'), QLatin1String("continue")},
        {('d'), QLatin1String("defer")},
        {('e'), QLatin1String("else")},
        {('f'), QLatin1String("for")},
        {('f'), QLatin1String("fn")},
        {('g'), QLatin1String("go")},
        {('g'), QLatin1String("goto")},
        {('i'), QLatin1String("if")},
        {('i'), QLatin1String("import")},
        {('i'), QLatin1String("interface")},
        {('r'), QLatin1String("return")},
        {('s'), QLatin1String("struct")},
        {('s'), QLatin1String("switch")},
        {('t'), QLatin1String("type")},
        {('p'), QLatin1String("pub")},
        {('o'), QLatin1String("or")},
        {('n'), QLatin1String("none")}
    };

    v_types = {
        {('m'), QLatin1String("map")},
        {('s'), QLatin1String("struct")},
        {('b'), QLatin1String("bool")},
        {('b'), QLatin1String("byte")},
        {('f'), QLatin1String("f32")},
        {('f'), QLatin1String("f64")},
        {('i'), QLatin1String("i8")},
        {('i'), QLatin1String("i16")},
        {('i'), QLatin1String("int")},
        {('i'), QLatin1String("i64")},
        {('i'), QLatin1String("i128")},
        {('s'), QLatin1String("string")},
        {('u'), QLatin1String("u16")},
        {('u'), QLatin1String("u32")},
        {('u'), QLatin1String("u64")},
        {('u'), QLatin1String("u128")},
        {('u'), QLatin1String("byteptr")},
        {('u'), QLatin1String("voidptr")},
        {('r'), QLatin1String("rune")}
    };

    v_literals = {
        {('f'), QLatin1String("false")},
        {('t'), QLatin1String("true")},
    };

    v_builtin = {
    };

    v_other = {

    };
}
void loadVData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other) {
    if (!vDataInitialized) {
        initVData();
        vDataInitialized = true;
    }
    types = v_types;
    keywords = v_keywords;
    builtin = v_builtin;
    literals = v_literals;
    other = v_other;
}
