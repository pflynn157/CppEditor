#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/********************************************************/
/***   JSON DATA      ***********************************/
/********************************************************/
static bool jsonDataInitialized = false;
static LanguageData json_keywords;
static LanguageData json_types;
static LanguageData json_literals;
static LanguageData json_builtin;
static LanguageData json_other;
void initJSONData() {
    json_keywords = {
    };

    json_types = {
    };

    json_literals = {
        {('f'), QLatin1String("false")},
        {('t'), QLatin1String("true")},
        {('n'), QLatin1String("null")}
    };

    json_builtin = {
    };

    json_other = {
};
}
void loadJSONData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other) {
    if (!jsonDataInitialized) {
        initJSONData();
        jsonDataInitialized = true;
    }
    types = json_types;
    keywords = json_keywords;
    builtin = json_builtin;
    literals = json_literals;
    other = json_other;
}
