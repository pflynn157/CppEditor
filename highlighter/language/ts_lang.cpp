#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/********************************************************/
/***   Typescript DATA  *********************************/
/********************************************************/
static bool typescriptDataInitialized = false;
static LanguageData typescript_keywords;
static LanguageData typescript_types;
static LanguageData typescript_literals;
static LanguageData typescript_builtin;
static LanguageData typescript_other;
void initTypescriptData() {
    typescript_keywords = {
        {'i', QLatin1String("in")},
        {'i', QLatin1String("if")},
        {'f', QLatin1String("for")},
        {'w', QLatin1String("while")},
        {'f', QLatin1String("finally")},
        {'n', QLatin1String("new")},
        {'f', QLatin1String("function")},
        {'d', QLatin1String("do")},
        {'r', QLatin1String("return")},
        {'v', QLatin1String("void")},
        {'e', QLatin1String("else")},
        {'b', QLatin1String("break")},
        {'c', QLatin1String("catch")},
        {'i', QLatin1String("instanceof")},
        {'w', QLatin1String("with")},
        {'t', QLatin1String("throw")},
        {'c', QLatin1String("case")},
        {'d', QLatin1String("default")},
        {'t', QLatin1String("try")},
        {'t', QLatin1String("this")},
        {'s', QLatin1String("switch")},
        {'c', QLatin1String("continue")},
        {'t', QLatin1String("typeof")},
        {'d', QLatin1String("delete")},
        {'l', QLatin1String("let")},
        {'y', QLatin1String("yield")},
        {'c', QLatin1String("const")},
        {'p', QLatin1String("public")},
        {'p', QLatin1String("private")},
        {'p', QLatin1String("protected")},
        {'g', QLatin1String("get")},
        {'s', QLatin1String("set")},
        {'s', QLatin1String("super")},
        {'s', QLatin1String("static")},
        {'i', QLatin1String("implements")},
        {'e', QLatin1String("export")},
        {'i', QLatin1String("import")},
        {'d', QLatin1String("declare")},
        {'t', QLatin1String("type")},
        {'n', QLatin1String("namespace")},
        {'a', QLatin1String("abstract")},
        {'a', QLatin1String("as")},
        {'f', QLatin1String("from")},
        {'e', QLatin1String("extends")},
        {'a', QLatin1String("async")},
        {'a', QLatin1String("await")}
    };

    typescript_types = {
        {'v', QLatin1String("var")},
        {'c', QLatin1String("class")},
        {'e', QLatin1String("enum")}
    };

    typescript_literals = {
        {('f'), QLatin1String("false")},
        {('n'), QLatin1String("null")},
        {('t'), QLatin1String("true")},
        {('u'), QLatin1String("undefined")},
        {('N'), QLatin1String("NaN")},
        {('I'), QLatin1String("Infinity")}
    };

    typescript_builtin = {
        {'e', QLatin1String("eval")},
        {'i', QLatin1String("isFinite")},
        {'i', QLatin1String("isNaN")},
        {'p', QLatin1String("parseFloat")},
        {'p', QLatin1String("parseInt")},
        {'d', QLatin1String("decodeURI")},
        {'d', QLatin1String("decodeURIComponent")},
        {'e', QLatin1String("encodeURI")},
        {'e', QLatin1String("encodeURIComponent")},
        {'e', QLatin1String("escape")},
        {'u', QLatin1String("unescape")},
        {'O', QLatin1String("Object")},
        {'F', QLatin1String("Function")},
        {'B', QLatin1String("Boolean")},
        {'E', QLatin1String("Error")},
        {'E', QLatin1String("EvalError")},
        {'I', QLatin1String("InternalError")},
        {'R', QLatin1String("RangeError")},
        {'R', QLatin1String("ReferenceError")},
        {'S', QLatin1String("StopIteration")},
        {'S', QLatin1String("SyntaxError")},
        {'T', QLatin1String("TypeError")},
        {'U', QLatin1String("URIError")},
        {'N', QLatin1String("Number")},
        {'M', QLatin1String("Math")},
        {'D', QLatin1String("Date")},
        {'S', QLatin1String("String")},
        {'R', QLatin1String("RegExp")},
        {'A', QLatin1String("Array")},
        {'F', QLatin1String("Float32Array")},
        {'F', QLatin1String("Float64Array")},
        {'I', QLatin1String("Int16Array")},
        {'I', QLatin1String("Int32Array")},
        {'I', QLatin1String("Int8Array")},
        {'U', QLatin1String("Uint16Array")},
        {'U', QLatin1String("Uint32Array")},
        {'U', QLatin1String("Uint8Array")},
        {'U', QLatin1String("Uint8ClampedArray")},
        {'A', QLatin1String("ArrayBuffer")},
        {'D', QLatin1String("DataView")},
        {'J', QLatin1String("JSON")},
        {'I', QLatin1String("Intl")},
        {'a', QLatin1String("arguments")},
        {'r', QLatin1String("require")},
        {'m', QLatin1String("module")},
        {'c', QLatin1String("console")},
        {'w', QLatin1String("window")},
        {'d', QLatin1String("document")},
        {'a', QLatin1String("any")},
        {'n', QLatin1String("number")},
        {'b', QLatin1String("boolean")},
        {'s', QLatin1String("string")},
        {'v', QLatin1String("void")},
        {'P', QLatin1String("Promise")}
    };

    typescript_other = {
};
}
void loadTypescriptData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other) {
    if (!typescriptDataInitialized) {
        initTypescriptData();
        typescriptDataInitialized = true;
    }
    types = typescript_types;
    keywords = typescript_keywords;
    builtin = typescript_builtin;
    literals = typescript_literals;
    other = typescript_other;
}
