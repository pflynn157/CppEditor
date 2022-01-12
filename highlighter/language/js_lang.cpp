#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/**********************************************************/
/* JS Data *********************************************/
/**********************************************************/
static bool JSDataInitialized = false;
static LanguageData js_keywords;
static LanguageData js_types;
static LanguageData js_literals;
static LanguageData js_builtin;
static LanguageData js_other;
void initJSData() {
    js_keywords = {
        {('i'), QLatin1String("in")},
        {('o'), QLatin1String("of")},
        {('i'), QLatin1String("if")},
        {('f'), QLatin1String("for")},
        {('w'), QLatin1String("while")},
        {('f'), QLatin1String("finally")},
        {('n'), QLatin1String("new")},
        {('f'), QLatin1String("function")},
        {('d'), QLatin1String("do")},
        {('r'), QLatin1String("return")},
        {('v'), QLatin1String("void")},
        {('e'), QLatin1String("else")},
        {('b'), QLatin1String("break")},
        {('c'), QLatin1String("catch")},
        {('i'), QLatin1String("instanceof")},
        {('w'), QLatin1String("with")},
        {('t'), QLatin1String("throw")},
        {('c'), QLatin1String("case")},
        {('d'), QLatin1String("default")},
        {('t'), QLatin1String("try")},
        {('t'), QLatin1String("this")},
        {('s'), QLatin1String("switch")},
        {('c'), QLatin1String("continue")},
        {('t'), QLatin1String("typeof")},
        {('d'), QLatin1String("delete")},
        {('l'), QLatin1String("let")},
        {('y'), QLatin1String("yield")},
        {('c'), QLatin1String("const")},
        {('e'), QLatin1String("export")},
        {('s'), QLatin1String("super")},
        {('d'), QLatin1String("debugger")},
        {('a'), QLatin1String("as")},
        {('a'), QLatin1String("async")},
        {('a'), QLatin1String("await")},
        {('s'), QLatin1String("static")},
        {('i'), QLatin1String("import")},
        {('f'), QLatin1String("from")},
        {('a'), QLatin1String("as")}
    };

    js_types = {
        {('v'), QLatin1String("var")},
        {('c'), QLatin1String("class")},
        {('b'), QLatin1String("byte")},
        {('e'), QLatin1String("enum")},
        {('f'), QLatin1String("float")},
        {('s'), QLatin1String("short")},
        {('l'), QLatin1String("long")},
        {('i'), QLatin1String("int")},
        {('v'), QLatin1String("void")},
        {('b'), QLatin1String("boolean")},
        {('d'), QLatin1String("double")}
    };

    js_literals = {
        {('f'), QLatin1String("false")},
        {('n'), QLatin1String("null")},
        {('t'), QLatin1String("true")},
        {('u'), QLatin1String("undefined")},
        {('N'), QLatin1String("NaN")},
        {('I'), QLatin1String("Infinity")}
    };

    js_builtin = {
        {('e'), QLatin1String("eval")},
        {('i'), QLatin1String("isFinite")},
        {('i'), QLatin1String("isNaN")},
        {('p'), QLatin1String("parseFloat")},
        {('p'), QLatin1String("parseInt")},
        {('d'), QLatin1String("decodeURI")},
        {('d'), QLatin1String("decodeURIComponent")},
        {('e'), QLatin1String("encodeURI")},
        {('e'), QLatin1String("encodeURIComponent")},
        {('e'), QLatin1String("escape")},
        {('u'), QLatin1String("unescape")},
        {('O'), QLatin1String("Object")},
        {('F'), QLatin1String("Function")},
        {('B'), QLatin1String("Boolean")},
        {('E'), QLatin1String("Error")},
        {('E'), QLatin1String("EvalError")},
        {('I'), QLatin1String("InternalError")},
        {('R'), QLatin1String("RangeError")},
        {('R'), QLatin1String("ReferenceError")},
        {('S'), QLatin1String("StopIteration")},
        {('S'), QLatin1String("SyntaxError")},
        {('T'), QLatin1String("TypeError")},
        {('U'), QLatin1String("URIError")},
        {('N'), QLatin1String("Number")},
        {('M'), QLatin1String("Math")},
        {('D'), QLatin1String("Date")},
        {('S'), QLatin1String("String")},
        {('R'), QLatin1String("RegExp")},
        {('A'), QLatin1String("Array")},
        {('F'), QLatin1String("Float32Array")},
        {('F'), QLatin1String("Float64Array")},
        {('I'), QLatin1String("Int16Array")},
        {('I'), QLatin1String("Int32Array")},
        {('I'), QLatin1String("Int8Array")},
        {('U'), QLatin1String("Uint16Array")},
        {('U'), QLatin1String("Uint32Array")},
        {('U'), QLatin1String("Uint8Array")},
        {('U'), QLatin1String("Uint8ClampedArray")},
        {('A'), QLatin1String("ArrayBuffer")},
        {('D'), QLatin1String("DataView")},
        {('J'), QLatin1String("JSON")},
        {('I'), QLatin1String("Intl")},
        {('a'), QLatin1String("arguments")},
        {('r'), QLatin1String("require")},
        {('m'), QLatin1String("module")},
        {('c'), QLatin1String("console")},
        {('w'), QLatin1String("window")},
        {('d'), QLatin1String("document")},
        {('S'), QLatin1String("Symbol")},
        {('S'), QLatin1String("Set")},
        {('M'), QLatin1String("Map")},
        {('W'), QLatin1String("WeakSet")},
        {('W'), QLatin1String("WeakMap")},
        {('P'), QLatin1String("Proxy")},
        {('R'), QLatin1String("Reflect")},
        {('P'), QLatin1String("Promise")}
    };

    js_other = {};
}

void loadJSData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other) {
    if (!JSDataInitialized) {
        initJSData();
        JSDataInitialized = true;
    }
    types = js_types;
    keywords = js_keywords;
    builtin = js_builtin;
    literals = js_literals;
    other = js_other;
}
