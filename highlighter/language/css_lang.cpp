#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/********************************************************/
/***   CSS DATA      ***********************************/
/********************************************************/
static bool cssDataInitialized = false;
static LanguageData css_keywords;
static LanguageData css_types;
static LanguageData css_literals;
static LanguageData css_builtin;
static LanguageData css_other;
void initCSSData() {
    css_keywords = {
        {'i', QLatin1String("important")},
        {'p', QLatin1String("px")},
        {'e', QLatin1String("em")}
    };

    css_types = {
        {'a', QLatin1String("align")},
        {'c', QLatin1String("content")},
        {'i', QLatin1String("items")},
        {'s', QLatin1String("self")},
        {'a', QLatin1String("all")},
        {'a', QLatin1String("animation")},
        {'d', QLatin1String("delay")},
        {'d', QLatin1String("direction")},
        {'d', QLatin1String("duration")},
        {'f', QLatin1String("fill")},
        {'m', QLatin1String("mode")},
        {'i', QLatin1String("iteration")},
        {'c', QLatin1String("count")},
        {'n', QLatin1String("name")},
        {'p', QLatin1String("play")},
        {'s', QLatin1String("state")},
        {'t', QLatin1String("timing")},
        {'f', QLatin1String("function")},
        {'a', QLatin1String("azimuth")},
        {'b', QLatin1String("backface")},
        {'v', QLatin1String("visibility")},
        {'a', QLatin1String("attachment")},
        {'b', QLatin1String("blend")},
        {'m', QLatin1String("mode")},
        {'c', QLatin1String("clip")},
        {'c', QLatin1String("color")},
        {'i', QLatin1String("image")},
        {'o', QLatin1String("origin")},
        {'p', QLatin1String("position")},
        {'r', QLatin1String("repeat")},
        {'s', QLatin1String("size")},
        {'b', QLatin1String("background")},
        {'b', QLatin1String("bleed")},
        {'c', QLatin1String("color")},
        {'r', QLatin1String("radius")},
        {'r', QLatin1String("radius")},
        {'s', QLatin1String("style")},
        {'w', QLatin1String("width")},
        {'b', QLatin1String("bottom")},
        {'c', QLatin1String("collapse")},
        {'c', QLatin1String("color")},
        {'i', QLatin1String("image")},
        {'o', QLatin1String("outset")},
        {'r', QLatin1String("repeat")},
        {'s', QLatin1String("source")},
        {'s', QLatin1String("slice")},
        {'w', QLatin1String("width")},
        {'c', QLatin1String("color")},
        {'s', QLatin1String("style")},
        {'w', QLatin1String("width")},
        {'l', QLatin1String("left")},
        {'r', QLatin1String("radius")},
        {'c', QLatin1String("color")},
        {'s', QLatin1String("style")},
        {'w', QLatin1String("width")},
        {'r', QLatin1String("right")},
        {'s', QLatin1String("spacing")},
        {'s', QLatin1String("style")},
        {'c', QLatin1String("color")},
        {'l', QLatin1String("left")},
        {'r', QLatin1String("radius")},
        {'r', QLatin1String("radius")},
        {'s', QLatin1String("style")},
        {'w', QLatin1String("width")},
        {'t', QLatin1String("top")},
        {'w', QLatin1String("width")},
        {'b', QLatin1String("border")},
        {'b', QLatin1String("bottom")},
        {'b', QLatin1String("break")},
        {'b', QLatin1String("box")},
        {'s', QLatin1String("shadow")},
        {'b', QLatin1String("box")},
        {'s', QLatin1String("sizing")},
        {'a', QLatin1String("after")},
        {'b', QLatin1String("before")},
        {'b', QLatin1String("break")},
        {'i', QLatin1String("inside")},
        {'c', QLatin1String("caption")},
        {'s', QLatin1String("side")},
        {'c', QLatin1String("caret")},
        {'c', QLatin1String("color")},
        {'c', QLatin1String("clear")},
        {'c', QLatin1String("clip")},
        {'c', QLatin1String("color")},
        {'c', QLatin1String("columns")},
        {'c', QLatin1String("column")},
        {'c', QLatin1String("count")},
        {'f', QLatin1String("fill")},
        {'g', QLatin1String("gap")},
        {'r', QLatin1String("rule")},
        {'c', QLatin1String("color")},
        {'s', QLatin1String("style")},
        {'w', QLatin1String("width")},
        {'s', QLatin1String("span")},
        {'w', QLatin1String("width")},
        {'c', QLatin1String("content")},
        {'i', QLatin1String("increment")},
        {'c', QLatin1String("counter")},
        {'r', QLatin1String("reset")},
        {'a', QLatin1String("after")},
        {'b', QLatin1String("before")},
        {'c', QLatin1String("cue")},
        {'c', QLatin1String("cursor")},
        {'d', QLatin1String("direction")},
        {'d', QLatin1String("display")},
        {'e', QLatin1String("elevation")},
        {'e', QLatin1String("empty")},
        {'c', QLatin1String("cells")},
        {'f', QLatin1String("filter")},
        {'f', QLatin1String("flex")},
        {'b', QLatin1String("basis")},
        {'d', QLatin1String("direction")},
        {'f', QLatin1String("feature")},
        {'s', QLatin1String("settings")},
        {'f', QLatin1String("flex")},
        {'f', QLatin1String("flow")},
        {'g', QLatin1String("grow")},
        {'s', QLatin1String("shrink")},
        {'w', QLatin1String("wrap")},
        {'f', QLatin1String("float")},
        {'f', QLatin1String("family")},
        {'k', QLatin1String("kerning")},
        {'l', QLatin1String("language")},
        {'o', QLatin1String("override")},
        {'a', QLatin1String("adjust")},
        {'s', QLatin1String("size")},
        {'s', QLatin1String("stretch")},
        {'s', QLatin1String("style")},
        {'s', QLatin1String("synthesis")},
        {'v', QLatin1String("variant")},
        {'a', QLatin1String("alternates")},
        {'c', QLatin1String("caps")},
        {'e', QLatin1String("east")},
        {'a', QLatin1String("asian")},
        {'l', QLatin1String("ligatures")},
        {'n', QLatin1String("numeric")},
        {'p', QLatin1String("position")},
        {'w', QLatin1String("weight")},
        {'f', QLatin1String("font")},
        {'a', QLatin1String("area")},
        {'a', QLatin1String("auto")},
        {'c', QLatin1String("columns")},
        {'f', QLatin1String("flow")},
        {'r', QLatin1String("rows")},
        {'e', QLatin1String("end")},
        {'g', QLatin1String("gap")},
        {'s', QLatin1String("start")},
        {'c', QLatin1String("column")},
        {'g', QLatin1String("gap")},
        {'e', QLatin1String("end")},
        {'g', QLatin1String("gap")},
        {'s', QLatin1String("start")},
        {'r', QLatin1String("row")},
        {'a', QLatin1String("areas")},
        {'c', QLatin1String("columns")},
        {'r', QLatin1String("rows")},
        {'t', QLatin1String("template")},
        {'g', QLatin1String("grid")},
        {'h', QLatin1String("hanging")},
        {'p', QLatin1String("punctuation")},
        {'h', QLatin1String("height")},
        {'h', QLatin1String("hyphens")},
        {'i', QLatin1String("isolation")},
        {'j', QLatin1String("justify")},
        {'c', QLatin1String("content")},
        {'i', QLatin1String("items")},
        {'s', QLatin1String("self")},
        {'l', QLatin1String("leftimage")},
        {'l', QLatin1String("letter")},
        {'s', QLatin1String("spacing")},
        {'b', QLatin1String("break")},
        {'l', QLatin1String("line")},
        {'s', QLatin1String("style")},
        {'i', QLatin1String("image")},
        {'s', QLatin1String("style")},
        {'p', QLatin1String("position")},
        {'t', QLatin1String("type")},
        {'l', QLatin1String("list")},
        {'s', QLatin1String("style")},
        {'b', QLatin1String("bottom")},
        {'l', QLatin1String("left")},
        {'r', QLatin1String("right")},
        {'t', QLatin1String("top")},
        {'m', QLatin1String("margin")},
        {'m', QLatin1String("marker")},
        {'o', QLatin1String("offset")},
        {'m', QLatin1String("marks")},
        {'m', QLatin1String("max")},
        {'h', QLatin1String("height")},
        {'w', QLatin1String("width")},
        {'m', QLatin1String("min")},
        {'m', QLatin1String("mix")},
        {'b', QLatin1String("blend")},
        {'m', QLatin1String("mode")},
        {'n', QLatin1String("nav")},
        {'u', QLatin1String("up")},
        {'d', QLatin1String("down")},
        {'l', QLatin1String("left")},
        {'r', QLatin1String("right")},
        {'o', QLatin1String("opacity")},
        {'o', QLatin1String("order")},
        {'o', QLatin1String("orphans")},
        {'c', QLatin1String("color")},
        {'o', QLatin1String("offset")},
        {'s', QLatin1String("style")},
        {'w', QLatin1String("width")},
        {'o', QLatin1String("outline")},
        {'w', QLatin1String("wrap")},
        {'o', QLatin1String("overflow")},
        {'b', QLatin1String("bottom")},
        {'l', QLatin1String("left")},
        {'r', QLatin1String("right")},
        {'t', QLatin1String("top")},
        {'p', QLatin1String("padding")},
        {'b', QLatin1String("break")},
        {'a', QLatin1String("after")},
        {'b', QLatin1String("before")},
        {'i', QLatin1String("inside")},
        {'p', QLatin1String("page")},
        {'a', QLatin1String("after")},
        {'b', QLatin1String("before")},
        {'p', QLatin1String("pause")},
        {'p', QLatin1String("perspective")},
        {'o', QLatin1String("origin")},
        {'r', QLatin1String("range")},
        {'p', QLatin1String("pitch")},
        {'c', QLatin1String("content")},
        {'i', QLatin1String("items")},
        {'p', QLatin1String("place")},
        {'s', QLatin1String("self")},
        {'p', QLatin1String("play")},
        {'d', QLatin1String("during")},
        {'p', QLatin1String("position")},
        {'q', QLatin1String("quotes")},
        {'r', QLatin1String("resize")},
        {'r', QLatin1String("rest")},
        {'a', QLatin1String("after")},
        {'b', QLatin1String("before")},
        {'r', QLatin1String("rest")},
        {'r', QLatin1String("richness")},
        {'r', QLatin1String("right")},
        {'s', QLatin1String("size")},
        {'h', QLatin1String("header")},
        {'n', QLatin1String("numeral")},
        {'s', QLatin1String("speak")},
        {'p', QLatin1String("punctuation")},
        {'s', QLatin1String("speak")},
        {'s', QLatin1String("speech")},
        {'r', QLatin1String("rate")},
        {'s', QLatin1String("stress")},
        {'t', QLatin1String("tab")},
        {'s', QLatin1String("size")},
        {'t', QLatin1String("table")},
        {'l', QLatin1String("layout")},
        {'t', QLatin1String("text")},
        {'a', QLatin1String("align")},
        {'l', QLatin1String("last")},
        {'d', QLatin1String("decoration")},
        {'c', QLatin1String("color")},
        {'l', QLatin1String("line")},
        {'s', QLatin1String("skip")},
        {'s', QLatin1String("style")},
        {'i', QLatin1String("indent")},
        {'o', QLatin1String("overflow")},
        {'s', QLatin1String("shadow")},
        {'t', QLatin1String("transform")},
        {'u', QLatin1String("underline")},
        {'p', QLatin1String("position")},
        {'t', QLatin1String("top")},
        {'t', QLatin1String("transform")},
        {'o', QLatin1String("origin")},
        {'s', QLatin1String("style")},
        {'t', QLatin1String("transition")},
        {'d', QLatin1String("delay")},
        {'d', QLatin1String("duration")},
        {'p', QLatin1String("property")},
        {'t', QLatin1String("timing")},
        {'f', QLatin1String("function")},
        {'u', QLatin1String("unicode")},
        {'b', QLatin1String("bidi")},
        {'v', QLatin1String("vertical")},
        {'a', QLatin1String("align")},
        {'v', QLatin1String("visibility")},
        {'b', QLatin1String("balance")},
        {'d', QLatin1String("duration")},
        {'f', QLatin1String("family")},
        {'p', QLatin1String("pitch")},
        {'r', QLatin1String("range")},
        {'r', QLatin1String("rate")},
        {'s', QLatin1String("stress")},
        {'v', QLatin1String("volume")},
        {'v', QLatin1String("voice")},
        {'v', QLatin1String("volume")},
        {'w', QLatin1String("white")},
        {'s', QLatin1String("space")},
        {'w', QLatin1String("widows")},
        {'w', QLatin1String("width")},
        {'w', QLatin1String("will")},
        {'c', QLatin1String("change")},
        {'w', QLatin1String("word")},
        {'b', QLatin1String("break")},
        {'s', QLatin1String("spacing")},
        {'w', QLatin1String("wrap")},
        {'x', QLatin1String("x")},
        {'y', QLatin1String("y")},
        {'z', QLatin1String("z")},
        {'i', QLatin1String("index")},
        {'r', QLatin1String("rgb")},
        {'s', QLatin1String("sans")},
        {'s', QLatin1String("serif")},
        {'n', QLatin1String("normal")}
    };

    css_literals = {
    };

    css_builtin = {
    };

    css_other = {
    };
}
void loadCSSData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other) {
    if (!cssDataInitialized) {
        initCSSData();
        cssDataInitialized = true;
    }
    types = css_types;
    keywords = css_keywords;
    builtin = css_builtin;
    literals = css_literals;
    other = css_other;
}