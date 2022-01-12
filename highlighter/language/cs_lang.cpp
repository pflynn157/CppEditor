#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/********************************************************/
/***   C# DATA      *************************************/
/********************************************************/
static bool csharpDataInitialized = false;
static LanguageData csharp_keywords;
static LanguageData csharp_types;
static LanguageData csharp_literals;
static LanguageData csharp_builtin;
static LanguageData csharp_other;
void initCSharpData() {
    csharp_keywords = {
        {('a'), QLatin1String("abstract")},
        {('a'), QLatin1String("add")},
        {('a'), QLatin1String("alias")},
        {('a'), QLatin1String("as")},
        {('a'), QLatin1String("ascending")},
        {('a'), QLatin1String("async")},
        {('a'), QLatin1String("await")},
        {('b'), QLatin1String("base")},
        {('b'), QLatin1String("break")},
        {('c'), QLatin1String("case")},
        {('c'), QLatin1String("catch")},
        {('c'), QLatin1String("checked")},
        {('c'), QLatin1String("const")},
        {('c'), QLatin1String("continue")},
        {('d'), QLatin1String("decimal")},
        {('d'), QLatin1String("default")},
        {('d'), QLatin1String("delegate")},
        {('d'), QLatin1String("descending")},
        {('d'), QLatin1String("do")},
        {('d'), QLatin1String("dynamic")},
        {('e'), QLatin1String("else")},
        {('e'), QLatin1String("event")},
        {('e'), QLatin1String("explicit")},
        {('e'), QLatin1String("extern")},
        {('f'), QLatin1String("finally")},
        {('f'), QLatin1String("fixed")},
        {('f'), QLatin1String("for")},
        {('f'), QLatin1String("foreach")},
        {('f'), QLatin1String("from")},
        {('g'), QLatin1String("get")},
        {('g'), QLatin1String("global")},
        {('g'), QLatin1String("goto")},
        {('g'), QLatin1String("group")},
        {('i'), QLatin1String("if")},
        {('i'), QLatin1String("implicit")},
        {('i'), QLatin1String("in")},
        {('i'), QLatin1String("interface")},
        {('i'), QLatin1String("internal")},
        {('i'), QLatin1String("into")},
        {('i'), QLatin1String("is")},
        {('j'), QLatin1String("join")},
        {('l'), QLatin1String("let")},
        {('l'), QLatin1String("lock")},
        {('l'), QLatin1String("long")},
        {('n'), QLatin1String("namespace")},
        {('n'), QLatin1String("new")},
        {('o'), QLatin1String("object")},
        {('o'), QLatin1String("operator")},
        {('o'), QLatin1String("orderby")},
        {('o'), QLatin1String("out")},
        {('o'), QLatin1String("override")},
        {('p'), QLatin1String("params")},
        {('p'), QLatin1String("partial")},
        {('p'), QLatin1String("private")},
        {('p'), QLatin1String("protected")},
        {('p'), QLatin1String("public")},
        {('r'), QLatin1String("readonly")},
        {('r'), QLatin1String("ref")},
        {('r'), QLatin1String("remove")},
        {('r'), QLatin1String("return")},
        {('s'), QLatin1String("sealed")},
        {('s'), QLatin1String("select")},
        {('s'), QLatin1String("set")},
        {('s'), QLatin1String("sizeof")},
        {('s'), QLatin1String("stackalloc")},
        {('s'), QLatin1String("static")},
        {('s'), QLatin1String("switch")},
        {('t'), QLatin1String("this")},
        {('t'), QLatin1String("throw")},
        {('t'), QLatin1String("try")},
        {('t'), QLatin1String("typeof")},
        {('u'), QLatin1String("unchecked")},
        {('u'), QLatin1String("unsafe")},
        {('u'), QLatin1String("using")},
        {('v'), QLatin1String("value")},
        {('v'), QLatin1String("virtual")},
        {('v'), QLatin1String("volatile")},
        {('w'), QLatin1String("where")},
        {('w'), QLatin1String("while")},
        {('y'), QLatin1String("yield")}
    };

    csharp_types = {
        {('b'), QLatin1String("bool")},
        {('b'), QLatin1String("byte")},
        {('c'), QLatin1String("char")},
        {('c'), QLatin1String("class")},
        {('d'), QLatin1String("double")},
        {('e'), QLatin1String("enum")},
        {('f'), QLatin1String("float")},
        {('i'), QLatin1String("int")},
        {('s'), QLatin1String("sbyte")},
        {('s'), QLatin1String("short")},
        {('s'), QLatin1String("string")},
        {('s'), QLatin1String("struct")},
        {('u'), QLatin1String("uint")},
        {('u'), QLatin1String("ulong")},
        {('u'), QLatin1String("ushort")},
        {('v'), QLatin1String("var")},
        {('v'), QLatin1String("void")},
    };

    csharp_literals = {
        {('f'), QLatin1String("false")},
        {('t'), QLatin1String("true")},
        {('n'), QLatin1String("null")}
    };

    csharp_builtin = {

    };

    csharp_other = {
        {('d'), QLatin1String("define")},
        {('e'), QLatin1String("elif")},
        {('e'), QLatin1String("else")},
        {('e'), QLatin1String("endif")},
        {('e'), QLatin1String("endregion")},
        {('e'), QLatin1String("error")},
        {('i'), QLatin1String("if")},
        {('l'), QLatin1String("line")},
        {('p'), QLatin1String("pragma")},
        {('r'), QLatin1String("region")},
        {('u'), QLatin1String("undef")},
        {('w'), QLatin1String("warning")}
    };
}
void loadCSharpData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other){
    if (!csharpDataInitialized) {
        initCSharpData();
        csharpDataInitialized = true;
    }
    types = csharp_types;
    keywords = csharp_keywords;
    builtin = csharp_builtin;
    literals = csharp_literals;
    other = csharp_other;
}
