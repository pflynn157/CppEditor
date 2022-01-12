#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/**********************************************************/
/* QML Data *********************************************/
/**********************************************************/
static bool QMLDataInitialized = false;
static LanguageData qml_keywords;
static LanguageData qml_types;
static LanguageData qml_literals;
static LanguageData qml_builtin;
static LanguageData qml_other;

void initQMLData() {
    qml_keywords = {
    {('d'), QLatin1String("default")},
    {('p'), QLatin1String("property")},
    {('i'), QLatin1String("int")},
    {('v'), QLatin1String("var")},
    {('s'), QLatin1String("string")},
    {('f'), QLatin1String("function")},
    {('r'), QLatin1String("readonly")},
    {('M'), QLatin1String("MouseArea")},
    {('d'), QLatin1String("delegate")},
    {('i'), QLatin1String("if")},
    {('e'), QLatin1String("else")},

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
    {('B'), QLatin1String("Behavior")},
    {('c'), QLatin1String("color")},
    {('c'), QLatin1String("coordinate")},
    {('d'), QLatin1String("date")},
    {('e'), QLatin1String("enumeration")},
    {('f'), QLatin1String("font")},
    {('g'), QLatin1String("geocircle")},
    {('g'), QLatin1String("georectangle")},
    {('g'), QLatin1String("geoshape")},
    {('l'), QLatin1String("list")},
    {('m'), QLatin1String("matrix4x4")},
    {('p'), QLatin1String("parent")},
    {('p'), QLatin1String("point")},
    {('q'), QLatin1String("quaternion")},
    {('r'), QLatin1String("real")},
    {('s'), QLatin1String("size")},
    {('s'), QLatin1String("string")},
    {('v'), QLatin1String("variant")},
    {('v'), QLatin1String("vector2d")},
    {('v'), QLatin1String("vector3d")},
    {('v'), QLatin1String("vector4d")},
    {('P'), QLatin1String("Promise")}
};

    qml_types = {
    {('R'), QLatin1String("Rectangle")},
    {('T'), QLatin1String("Text")},
    {('c'), QLatin1String("color")},
    {('I'), QLatin1String("Item")},
    {('u'), QLatin1String("url")},
    {('C'), QLatin1String("Component")},
    {('B'), QLatin1String("Button")},
    {('T'), QLatin1String("TextInput")},
    {('L'), QLatin1String("ListView")},


};

    qml_literals = {
    {('f'), QLatin1String("false")},
    {('t'), QLatin1String("true")}
};

    qml_builtin = {

};

    qml_other = {
    {('i'), QLatin1String("import")}
};
}
void loadQMLData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other){
    if (!QMLDataInitialized) {
        initQMLData();
        QMLDataInitialized = true;
    }
    types = qml_types;
    keywords = qml_keywords;
    builtin = qml_builtin;
    literals = qml_literals;
    other = qml_other;
}
