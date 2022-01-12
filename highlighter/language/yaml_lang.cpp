#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/********************************************************/
/***   YAML DATA  ***************************************/
/********************************************************/
static bool YAMLDataInitialized = false;
static LanguageData YAML_keywords;
static LanguageData YAML_types;
static LanguageData YAML_literals;
static LanguageData YAML_builtin;
static LanguageData YAML_other;
void initYAMLData() {
    YAML_keywords = {};
    YAML_types = {};
    YAML_literals = {
        {('f'), QLatin1String("false")},
        {('t'), QLatin1String("true")},
        {('n'), QLatin1String("null")},
    };

    YAML_builtin = {};
    YAML_other = {};
}
void loadYAMLData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other) {
    if (!YAMLDataInitialized) {
        initYAMLData();
        YAMLDataInitialized = true;
    }
    types = YAML_types;
    keywords = YAML_keywords;
    builtin = YAML_builtin;
    literals = YAML_literals;
    other = YAML_other;
}
