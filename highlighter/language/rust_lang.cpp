#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/********************************************************/
/***   Rust DATA      ***********************************/
/********************************************************/
static bool rustDataInitialized = false;
static LanguageData rust_keywords;
static LanguageData rust_types;
static LanguageData rust_literals;
static LanguageData rust_builtin;
static LanguageData rust_other;
void initRustData() {
rust_keywords = {
    {('a'), QLatin1String("abstract")},
    {('a'), QLatin1String("alignof")},
    {('a'), QLatin1String("as")},
    {('a'), QLatin1String("async")},
    {('a'), QLatin1String("await")},
    {('b'), QLatin1String("be")},
    {('b'), QLatin1String("box")},
    {('b'), QLatin1String("break")},
    {('c'), QLatin1String("const")},
    {('c'), QLatin1String("continue")},
    {('c'), QLatin1String("crate")},
    {('d'), QLatin1String("do")},
    {('d'), QLatin1String("dyn")},
    {('e'), QLatin1String("else")},
    {('e'), QLatin1String("extern")},
    {('f'), QLatin1String("final")},
    {('f'), QLatin1String("fn")},
    {('f'), QLatin1String("for")},
    {('i'), QLatin1String("if")},
    {('i'), QLatin1String("impl")},
    {('i'), QLatin1String("in")},
    {('l'), QLatin1String("let")},
    {('l'), QLatin1String("loop")},
    {('m'), QLatin1String("match")},
    {('m'), QLatin1String("mod")},
    {('m'), QLatin1String("move")},
    {('m'), QLatin1String("mut")},
    {('o'), QLatin1String("offsetof")},
    {('o'), QLatin1String("once")},
    {('o'), QLatin1String("override")},
    {('p'), QLatin1String("priv")},
    {('p'), QLatin1String("pub")},
    {('p'), QLatin1String("pure")},
    {('r'), QLatin1String("ref")},
    {('r'), QLatin1String("return")},
    {('s'), QLatin1String("sizeof")},
    {('s'), QLatin1String("static")},
    {('s'), QLatin1String("self")},
    {('S'), QLatin1String("Self")},
    {('s'), QLatin1String("super")},
    {('t'), QLatin1String("trait")},
    {('t'), QLatin1String("type")},
    {('t'), QLatin1String("typeof")},
    {('u'), QLatin1String("unsafe")},
    {('u'), QLatin1String("unsized")},
    {('u'), QLatin1String("use")},
    {('v'), QLatin1String("virtual")},
    {('w'), QLatin1String("where")},
    {('w'), QLatin1String("while")},
    {('y'), QLatin1String("yield")},
};

rust_types = {
    {('u'), QLatin1String("union")},
    {('e'), QLatin1String("enum")},
    {('s'), QLatin1String("struct")},

    {('i'), QLatin1String("i8")},
    {('i'), QLatin1String("i16")},
    {('i'), QLatin1String("i32")},
    {('i'), QLatin1String("i64")},
    {('i'), QLatin1String("i128")},
    {('i'), QLatin1String("isize")},
    {('u'), QLatin1String("u8")},
    {('u'), QLatin1String("u16")},
    {('u'), QLatin1String("u32")},
    {('u'), QLatin1String("u64")},
    {('u'), QLatin1String("u128")},
    {('u'), QLatin1String("usize")},
    {('f'), QLatin1String("f32")},
    {('f'), QLatin1String("f64")},
    {('s'), QLatin1String("str")},
    {('c'), QLatin1String("char")},
    {('b'), QLatin1String("bool")},
    {('B'), QLatin1String("Box")},
    {('O'), QLatin1String("Option")},
    {('R'), QLatin1String("Result")},
    {('S'), QLatin1String("String")},
    {('V'), QLatin1String("Vec")}
};

rust_literals = {
    {('f'), QLatin1String("false")},
    {('t'), QLatin1String("true")}
};

rust_builtin = {

};

rust_other = {
    {('a'), QLatin1String("assert!")},
    {('a'), QLatin1String("assert_eq!")},
    {('b'), QLatin1String("bitflags!")},
    {('b'), QLatin1String("bytes!")},
    {('c'), QLatin1String("cfg!")},
    {('c'), QLatin1String("col!")},
    {('c'), QLatin1String("concat!")},
    {('c'), QLatin1String("concat_idents!")},
    {('d'), QLatin1String("debug_assert!")},
    {('d'), QLatin1String("debug_assert_eq!")},
    {('e'), QLatin1String("env!")},
    {('p'), QLatin1String("panic!")},
    {('f'), QLatin1String("file!")},
    {('f'), QLatin1String("format!")},
    {('f'), QLatin1String("format_args!")},
    {('i'), QLatin1String("include_bin!")},
    {('i'), QLatin1String("include_str!")},
    {('l'), QLatin1String("line!")},
    {('l'), QLatin1String("local_data_key!")},
    {('m'), QLatin1String("module_path!")},
    {('o'), QLatin1String("option_env!")},
    {('p'), QLatin1String("print!")},
    {('p'), QLatin1String("println!")},
    {('s'), QLatin1String("select!")},
    {('s'), QLatin1String("stringify!")},
    {('t'), QLatin1String("try!")},
    {('u'), QLatin1String("unimplemented!")},
    {('u'), QLatin1String("unreachable!")},
    {('v'), QLatin1String("vec!")},
    {('w'), QLatin1String("write!")},
    {('w'), QLatin1String("writeln!")},
    {('m'), QLatin1String("macro_rules!")},
    {('a'), QLatin1String("assert_ne!")},
    {('d'), QLatin1String("debug_assert_ne!")}
};
}
void loadRustData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other) {
    if (!rustDataInitialized) {
        initRustData();
        rustDataInitialized = true;
    }
    types = rust_types;
    keywords = rust_keywords;
    builtin = rust_builtin;
    literals = rust_literals;
    other = rust_other;
}
