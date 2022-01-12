#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/**********************************************************/
/* PHP Data *********************************************/
/**********************************************************/
static bool PHPDataInitialized = false;
static LanguageData php_keywords;
static LanguageData php_types;
static LanguageData php_literals;
static LanguageData php_builtin;
static LanguageData php_other;
void initPHPData() {
    php_keywords = {
        {('a'), QLatin1String("and")},
        {('l'), QLatin1String("list")},
        {('a'), QLatin1String("abstract")},
        {('g'), QLatin1String("global")},
        {('p'), QLatin1String("private")},
        {('e'), QLatin1String("echo")},
        {('i'), QLatin1String("interface")},
        {('a'), QLatin1String("as")},
        {('s'), QLatin1String("static")},
        {('e'), QLatin1String("endswitch")},
        {('i'), QLatin1String("if")},
        {('e'), QLatin1String("endwhile")},
        {('o'), QLatin1String("or")},
        {('c'), QLatin1String("const")},
        {('f'), QLatin1String("for")},
        {('e'), QLatin1String("endforeach")},
        {('s'), QLatin1String("self")},
        {('w'), QLatin1String("while")},
        {('i'), QLatin1String("isset")},
        {('p'), QLatin1String("public")},
        {('p'), QLatin1String("protected")},
        {('e'), QLatin1String("exit")},
        {('f'), QLatin1String("foreach")},
        {('t'), QLatin1String("throw")},
        {('e'), QLatin1String("elseif")},
        {('e'), QLatin1String("empty")},
        {('d'), QLatin1String("do")},
        {('x'), QLatin1String("xor")},
        {('r'), QLatin1String("return")},
        {('p'), QLatin1String("parent")},
        {('c'), QLatin1String("clone")},
        {('u'), QLatin1String("use")},
        {('e'), QLatin1String("else")},
        {('b'), QLatin1String("break")},
        {('p'), QLatin1String("print")},
        {('e'), QLatin1String("eval")},
        {('n'), QLatin1String("new")},
        {('c'), QLatin1String("catch")},
        {('c'), QLatin1String("case")},
        {('e'), QLatin1String("exception")},
        {('d'), QLatin1String("default")},
        {('d'), QLatin1String("die")},
        {('e'), QLatin1String("enddeclare")},
        {('f'), QLatin1String("final")},
        {('t'), QLatin1String("try")},
        {('s'), QLatin1String("switch")},
        {('c'), QLatin1String("continue")},
        {('e'), QLatin1String("endfor")},
        {('e'), QLatin1String("endif")},
        {('d'), QLatin1String("declare")},
        {('u'), QLatin1String("unset")},
        {('t'), QLatin1String("trait")},
        {('g'), QLatin1String("goto")},
        {('i'), QLatin1String("instanceof")},
        {('i'), QLatin1String("insteadof")},
        {('y'), QLatin1String("yield")},
        {('f'), QLatin1String("finally")}
    };

    php_types = {
        {('v'), QLatin1String("var")},
        {('c'), QLatin1String("class")},
        {('e'), QLatin1String("enum")},
        {('a'), QLatin1String("array")}
    };

    php_literals = {
        {('f'), QLatin1String("false")},
        {('t'), QLatin1String("true")},
        {('n'), QLatin1String("null")}
    };

    php_builtin = {


    };

    php_other = {
    {('i'), QLatin1String("include_once")},
    {('i'), QLatin1String("include")},
    {('_'), QLatin1String("__FILE__")},
    {('r'), QLatin1String("require")},
    {('r'), QLatin1String("require_once")},
    {('_'), QLatin1String("__CLASS__")},
    {('_'), QLatin1String("__LINE__")},
    {('_'), QLatin1String("__METHOD__")},
    {('_'), QLatin1String("__FUNCTION__")},
    {('_'), QLatin1String("__DIR__")},
    {('_'), QLatin1String("__NAMESPACE__")},

    {('S'), QLatin1String("SERVER")},
    {('G'), QLatin1String("GET")},
    {('P'), QLatin1String("POST")},
    {('F'), QLatin1String("FILES")},
    {('R'), QLatin1String("REQUEST")},
    {('S'), QLatin1String("SESSION")},
    {('E'), QLatin1String("ENV")},
    {('C'), QLatin1String("COOKIE")},
    {('G'), QLatin1String("GLOBALS")},
    {('H'), QLatin1String("HTTP_RAW_POST_DATA")},
    {('a'), QLatin1String("argc")},
    {('a'), QLatin1String("argv")},
    {('p'), QLatin1String("php_errormsg")},
    {('h'), QLatin1String("http_response_header")}
};
}
void loadPHPData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other) {
    if (!PHPDataInitialized) {
        initPHPData();
        PHPDataInitialized = true;
    }
    types = php_types;
    keywords = php_keywords;
    builtin = php_builtin;
    literals = php_literals;
    other = php_other;
}
