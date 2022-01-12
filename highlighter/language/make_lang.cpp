#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/********************************************************/
/***   MAKE DATA   ***************************************/
/********************************************************/
static bool makeDataInitialized = false;
static QMultiHash<char, QLatin1String> make_keywords;
static QMultiHash<char, QLatin1String> make_types;
static QMultiHash<char, QLatin1String> make_literals;
static QMultiHash<char, QLatin1String> make_builtin;
static QMultiHash<char, QLatin1String> make_other;
void initMakeData() {
    make_keywords = {
        {'i', QLatin1String("include")},
        {'d', QLatin1String("define")},
        {'e', QLatin1String("else")},
        {'e', QLatin1String("endef")},
        {'e', QLatin1String("endif")},
        {'e', QLatin1String("export")},
        {'i', QLatin1String("ifn?def")},
        {'i', QLatin1String("ifn?eq")},
        {'i', QLatin1String("include")},
        {'o', QLatin1String("override")},
        {'p', QLatin1String("private")},
        {'s', QLatin1String("sinclude")},
        {'u', QLatin1String("undefine")},
        {'u', QLatin1String("unexport")},
        {'v', QLatin1String("vpath")}
    };
    make_types = {
        {'a', QLatin1String("addsuffix")},
        {'a', QLatin1String("abspath")},
        {'a', QLatin1String("and")},
        {'a', QLatin1String("ar")},
        {'b', QLatin1String("basename")},
        {'c', QLatin1String("call")},
        {'d', QLatin1String("dir")},
        {'e', QLatin1String("error")},
        {'e', QLatin1String("eval")},
        {'f', QLatin1String("file")},
        {'f', QLatin1String("filter")},
        {'f', QLatin1String("find")},
        {'f', QLatin1String("findstring")},
        {'f', QLatin1String("firstword")},
        {'f', QLatin1String("flavor")},
        {'f', QLatin1String("foreach")},
        {'g', QLatin1String("guile")},
        {'i', QLatin1String("if")},
        {'i', QLatin1String("info")},
        {'i', QLatin1String("install")},
        {'j', QLatin1String("join")},
        {'l', QLatin1String("lastword")},
        {'l', QLatin1String("load")},
        {'n', QLatin1String("notdir")},
        {'o', QLatin1String("or")},
        {'o', QLatin1String("origin")},
        {'p', QLatin1String("patsubst")},
        {'r', QLatin1String("ranlib")},
        {'r', QLatin1String("realpath")},
        {'r', QLatin1String("rm")},
        {'s', QLatin1String("shell")},
        {'s', QLatin1String("sort")},
        {'s', QLatin1String("strip")},
        {'s', QLatin1String("subst")},
        {'s', QLatin1String("suffix")},
        {'v', QLatin1String("value")},
        {'w', QLatin1String("warning")},
        {'w', QLatin1String("wildcard")},
        {'w', QLatin1String("word")}
    };
    make_literals = {
        {'t', QLatin1String("true")},
        {'f', QLatin1String("false")},
    };
    make_builtin = {
    };
    make_other = {
        {'C', QLatin1String("CFLAGS")},
        {'L', QLatin1String("LIBS")},
        {'P', QLatin1String("PREFIX")},
    };
}

void loadMakeData(QMultiHash<char, QLatin1String> &types, QMultiHash<char, QLatin1String> &keywords, QMultiHash<char, QLatin1String> &builtin, QMultiHash<char, QLatin1String> &literals, QMultiHash<char, QLatin1String> &other)
{
    if (!makeDataInitialized) {
        initMakeData();
        makeDataInitialized = true;
    }
    types = make_types;
    keywords = make_keywords;
    builtin = make_builtin;
    literals = make_literals;
    other = make_other;
}
