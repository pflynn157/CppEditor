#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/********************************************************/
/***   Markdown DATA*************************************/
/********************************************************/
static bool MarkdownDataInitialized = false;
static LanguageData MD_keywords;
static LanguageData MD_types;
static LanguageData MD_literals;
static LanguageData MD_builtin;
static LanguageData MD_other;
void initMarkdownData() {
    MD_keywords = {
        {('#'), QLatin1String("#")},
        {('#'), QLatin1String("##")},
        {('#'), QLatin1String("###")},
        {('#'), QLatin1String("####")},
        {('#'), QLatin1String("#####")},
        {('#'), QLatin1String("######")},
    };
    
    MD_types = {};
    MD_literals = {
        {('f'), QLatin1String("false")},
        {('t'), QLatin1String("true")},
        {('n'), QLatin1String("null")},
    };

    MD_builtin = {};
    MD_other = {};
}
void loadMarkdownData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other) {
    if (!MarkdownDataInitialized) {
        initMarkdownData();
        MarkdownDataInitialized = true;
    }
    types = MD_types;
    keywords = MD_keywords;
    builtin = MD_builtin;
    literals = MD_literals;
    other = MD_other;
}
