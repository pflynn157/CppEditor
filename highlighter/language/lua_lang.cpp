#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/**********************************************************/
/* LuaData ************************************************/
/**********************************************************/

static bool luaDataInitialized = false;
static LanguageData lua_keywords;
static LanguageData lua_types;
static LanguageData lua_builtin;
static LanguageData lua_literals;
static LanguageData lua_other;

void initLuaData() {
    lua_keywords = LanguageData{
        {('a'), QLatin1String("and")},
        {('b'), QLatin1String("break")},
        {('d'), QLatin1String("do")},
        {('e'), QLatin1String("else")},
        {('e'), QLatin1String("elseif")},
        {('e'), QLatin1String("end")},
        {('f'), QLatin1String("for")},
        {('f'), QLatin1String("function")},
        {('i'), QLatin1String("if")},
        {('i'), QLatin1String("in")},
        {('l'), QLatin1String("local")},
        {('n'), QLatin1String("not")},
        {('o'), QLatin1String("or")},
        {('r'), QLatin1String("repeat")},
        {('r'), QLatin1String("require")},
        {('r'), QLatin1String("return")},
        {('t'), QLatin1String("then")},
        {('u'), QLatin1String("until")},
        {('w'), QLatin1String("while")}};

    lua_literals = LanguageData{
        {('f'), QLatin1String("false")},
        {('n'), QLatin1String("nil")},
        {('t'), QLatin1String("true")}};

    lua_other = LanguageData{
        {('_'), QLatin1String("_G")},
        {('_'), QLatin1String("__add")},
        {('_'), QLatin1String("__call")},
        {('_'), QLatin1String("__contact")},
        {('_'), QLatin1String("__div")},
        {('_'), QLatin1String("__eq")},
        {('_'), QLatin1String("__index")},
        {('_'), QLatin1String("__le")},
        {('_'), QLatin1String("__lt")},
        {('_'), QLatin1String("__mod")},
        {('_'), QLatin1String("__mul")},
        {('_'), QLatin1String("__newindex")},
        {('_'), QLatin1String("__sub")},
        {('_'), QLatin1String("__tostring")},
        {('_'), QLatin1String("__unm")}
    };

    lua_builtin = LanguageData{
        {('d'), QLatin1String("debug")},
        {('d'), QLatin1String("dofile")},
        {('g'), QLatin1String("getfenv")},
        {('g'), QLatin1String("gethook")},
        {('g'), QLatin1String("getinfo")},
        {('g'), QLatin1String("getlocal")},
        {('g'), QLatin1String("getmetatable")},
        {('g'), QLatin1String("getregistry")},
        {('g'), QLatin1String("getupvalue")},
        {('i'), QLatin1String("ipairs")},
        {('l'), QLatin1String("load")},
        {('l'), QLatin1String("loadfile")},
        {('l'), QLatin1String("loadstring")},
        {('n'), QLatin1String("next")},
        {('p'), QLatin1String("pairs")},
        {('p'), QLatin1String("print")},
        {('r'), QLatin1String("rawequal")},
        {('r'), QLatin1String("rawget")},
        {('r'), QLatin1String("rawset")},
        {('s'), QLatin1String("select")},
        {('s'), QLatin1String("setfenv")},
        {('s'), QLatin1String("sethook")},
        {('s'), QLatin1String("setlocal")},
        {('s'), QLatin1String("setmetatable")},
        {('s'), QLatin1String("setupvalue")},
        {('t'), QLatin1String("tonumber")},
        {('t'), QLatin1String("tostring")},
        {('t'), QLatin1String("traceback")},
        {('t'), QLatin1String("type")},
        {('u'), QLatin1String("unpack")}
    };

}

void loadLuaData(LanguageData &typess,
                 LanguageData &keywordss,
                 LanguageData &builtins,
                 LanguageData &literalss,
                 LanguageData &others){
    if (!luaDataInitialized) {
        initLuaData();
        luaDataInitialized = true;
    }
    typess    = lua_types;
    keywordss = lua_keywords;
    builtins  = lua_builtin;
    literalss = lua_literals;
    others    = lua_other;
}
