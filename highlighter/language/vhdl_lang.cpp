#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/**********************************************************/
/* VHDL Data *********************************************/
/**********************************************************/

static bool vhdlDataInitialized = false;
static LanguageData vhdl_keywords;
static LanguageData vhdl_types;
static LanguageData vhdl_builtin;
static LanguageData vhdl_literals;
static LanguageData vhdl_other;
void initVHDLData() {
    vhdl_keywords = LanguageData{
        {('a'), QLatin1String("access")},
        {('a'), QLatin1String("after")},
        {('a'), QLatin1String("alias")},
        {('a'), QLatin1String("all")},
        {('a'), QLatin1String("architecture")},
        {('a'), QLatin1String("array")},
        {('a'), QLatin1String("assert")},
        {('a'), QLatin1String("attribute")},
        {('a'), QLatin1String("and")},
        {('a'), QLatin1String("abs")},
        {('b'), QLatin1String("begin")},
        {('b'), QLatin1String("block")},
        {('b'), QLatin1String("body")},
        {('b'), QLatin1String("buffer")},
        {('b'), QLatin1String("bus")},
        {('c'), QLatin1String("case")},
        {('c'), QLatin1String("component")},
        {('c'), QLatin1String("configuration")},
        {('c'), QLatin1String("constant")},
        {('d'), QLatin1String("disconnect")},
        {('d'), QLatin1String("downto")},
        {('e'), QLatin1String("else")},
        {('e'), QLatin1String("elsif")},
        {('e'), QLatin1String("end")},
        {('e'), QLatin1String("entity")},
        {('e'), QLatin1String("eixt")},
        {('e'), QLatin1String("error")},
        {('f'), QLatin1String("file")},
        {('f'), QLatin1String("for")},
        {('f'), QLatin1String("function")},
        {('f'), QLatin1String("failure")},
        {('g'), QLatin1String("generate")},
        {('g'), QLatin1String("generic")},
        {('g'), QLatin1String("group")},
        {('g'), QLatin1String("guarded")},
        {('i'), QLatin1String("if")},
        {('i'), QLatin1String("impure")},
        {('i'), QLatin1String("in")},
        {('i'), QLatin1String("inertial")},
        {('i'), QLatin1String("inout")},
        {('i'), QLatin1String("is")},
        {('l'), QLatin1String("label")},
        {('l'), QLatin1String("library")},
        {('l'), QLatin1String("linkage")},
        {('l'), QLatin1String("literal")},
        {('l'), QLatin1String("loop")},
        {('m'), QLatin1String("map")},
        {('m'), QLatin1String("mod")},
        {('n'), QLatin1String("new")},
        {('n'), QLatin1String("next")},
        {('n'), QLatin1String("null")},
        {('n'), QLatin1String("note")},
        {('n'), QLatin1String("nand")},
        {('n'), QLatin1String("nor")},
        {('n'), QLatin1String("not")},
        {('o'), QLatin1String("of")},
        {('o'), QLatin1String("on")},
        {('o'), QLatin1String("open")},
        {('o'), QLatin1String("others")},
        {('o'), QLatin1String("out")},
        {('o'), QLatin1String("or")},
        {('p'), QLatin1String("package")},
        {('p'), QLatin1String("port")},
        {('p'), QLatin1String("postponed")},
        {('p'), QLatin1String("procedure")},
        {('p'), QLatin1String("process")},
        {('p'), QLatin1String("pure")},
        {('r'), QLatin1String("range")},
        {('r'), QLatin1String("record")},
        {('r'), QLatin1String("register")},
        {('r'), QLatin1String("reject")},
        {('r'), QLatin1String("report")},
        {('r'), QLatin1String("return")},
        {('r'), QLatin1String("rol")},
        {('r'), QLatin1String("ror")},
        {('r'), QLatin1String("rem")},
        {('s'), QLatin1String("select")},
        {('s'), QLatin1String("severity")},
        {('s'), QLatin1String("signal")},
        {('s'), QLatin1String("shared")},
        {('s'), QLatin1String("subtype")},
        {('s'), QLatin1String("sla")},
        {('s'), QLatin1String("sll")},
        {('s'), QLatin1String("sra")},
        {('s'), QLatin1String("srl")},
        {('t'), QLatin1String("then")},
        {('t'), QLatin1String("to")},
        {('t'), QLatin1String("transport")},
        {('t'), QLatin1String("type")},
        {('u'), QLatin1String("unaffected")},
        {('u'), QLatin1String("units")},
        {('u'), QLatin1String("until")},
        {('u'), QLatin1String("use")},
        {('v'), QLatin1String("variable")},
        {('w'), QLatin1String("wait")},
        {('w'), QLatin1String("when")},
        {('w'), QLatin1String("while")},
        {('w'), QLatin1String("with")},
        {('w'), QLatin1String("warning")},
        {('x'), QLatin1String("xor")},
        {('x'), QLatin1String("xnor")}
    };

    vhdl_types = {
        {('b'), QLatin1String("bit")},
        {('b'), QLatin1String("bit_vector")},
        {('b'), QLatin1String("boolean")},
        {('c'), QLatin1String("character")},
        {('i'), QLatin1String("integer")},
        {('r'), QLatin1String("real")},
        {('t'), QLatin1String("time")},
        {('t'), QLatin1String("text")},
        {('s'), QLatin1String("string")},
        {('s'), QLatin1String("severity_level")},
        {('s'), QLatin1String("signed")},
        {('s'), QLatin1String("std_logic")},
        {('s'), QLatin1String("std_logic_vector")},
        {('s'), QLatin1String("std_ulogic")},
        {('s'), QLatin1String("std_ulogic_vector")},
        {('p'), QLatin1String("positive")},
        {('n'), QLatin1String("natural")},
        {('u'), QLatin1String("unsigned")},
        {('l'), QLatin1String("line")},
        {('q'), QLatin1String("qsim_state")},
        {('q'), QLatin1String("qsim_state_vector")},
        {('q'), QLatin1String("qsim_12state")},
        {('q'), QLatin1String("qsim_12state_vector")},
        {('q'), QLatin1String("qsim_strength")},
        {('m'), QLatin1String("mux_bit")},
        {('m'), QLatin1String("mux_vector")},
        {('r'), QLatin1String("reg_bit")},
        {('r'), QLatin1String("reg_vector")},
        {('w'), QLatin1String("wor_bit")},
        {('w'), QLatin1String("wor_vector")}
    };

    vhdl_literals = {
        {('f'), QLatin1String("false")},
        {('t'), QLatin1String("true")}
    };

    vhdl_builtin = {
    };

    vhdl_other = {
    };
}
void loadVHDLData(LanguageData &typess,
             LanguageData &keywordss,
             LanguageData &builtins,
             LanguageData &literalss,
             LanguageData &others){
    if (!vhdlDataInitialized) {
        initVHDLData();
        vhdlDataInitialized = true;
    }

    typess = vhdl_types;
    keywordss = vhdl_keywords;
    builtins = vhdl_builtin;
    literalss = vhdl_literals;
    others = vhdl_other;

}
