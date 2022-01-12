#include <QMultiHash>
#include <QLatin1String>
#include <languagedata.h>

/**********************************************************/
/* Shell Data *********************************************/
/**********************************************************/

static bool shellDataInitialized = false;
static LanguageData shell_keywords;
static LanguageData shell_types;
static LanguageData shell_literals;
static LanguageData shell_builtin;
static LanguageData shell_other;
void initShellData() {
    shell_keywords = {
        {('i'), QLatin1String("if")},
        {('t'), QLatin1String("then")},
        {('e'), QLatin1String("else")},
        {('e'), QLatin1String("elif")},
        {('f'), QLatin1String("fi")},
        {('f'), QLatin1String("for")},
        {('w'), QLatin1String("while")},
        {('i'), QLatin1String("in")},
        {('d'), QLatin1String("do")},
        {('d'), QLatin1String("done")},
        {('c'), QLatin1String("case")},
        {('e'), QLatin1String("esac")},
        {('f'), QLatin1String("function")}
    };

    shell_types = {};

    shell_literals = {
        {('f'), QLatin1String("false")},
        {('t'), QLatin1String("true")}
    };

    shell_builtin = {
        {('b'), QLatin1String("break")},
        {('c'), QLatin1String("cd")},
        {('c'), QLatin1String("continue")},
        {('e'), QLatin1String("eval")},
        {('e'), QLatin1String("exec")},
        {('e'), QLatin1String("exit")},
        {('e'), QLatin1String("export")},
        {('g'), QLatin1String("getopts")},
        {('h'), QLatin1String("hash")},
        {('p'), QLatin1String("pwd")},
        {('r'), QLatin1String("readonly")},
        {('r'), QLatin1String("return")},
        {('s'), QLatin1String("shift")},
        {('t'), QLatin1String("test")},
        {('t'), QLatin1String("timestrap")},
        {('u'), QLatin1String("umask")},
        {('u'), QLatin1String("unset")},
        {('B'), QLatin1String("Bash")},
        {('a'), QLatin1String("alias")},
        {('b'), QLatin1String("bind")},
        {('b'), QLatin1String("builtin")},
        {('c'), QLatin1String("caller")},
        {('c'), QLatin1String("command")},
        {('d'), QLatin1String("declare")},
        {('e'), QLatin1String("echo")},
        {('e'), QLatin1String("enable")},
        {('h'), QLatin1String("help")},
        {('l'), QLatin1String("let")},
        {('l'), QLatin1String("local")},
        {('l'), QLatin1String("logout")},
        {('m'), QLatin1String("mapfile")},
        {('p'), QLatin1String("printfread")},
        {('r'), QLatin1String("readarray")},
        {('s'), QLatin1String("source")},
        {('t'), QLatin1String("type")},
        {('t'), QLatin1String("typeset")},
        {('u'), QLatin1String("ulimit")},
        {('u'), QLatin1String("unalias")},
        {('m'), QLatin1String("modifiers")},
        {('s'), QLatin1String("set")},
        {('s'), QLatin1String("shopt")},
        {('a'), QLatin1String("autoload")},
        {('b'), QLatin1String("bg")},
        {('b'), QLatin1String("bindkey")},
        {('b'), QLatin1String("bye")},
        {('c'), QLatin1String("cap")},
        {('c'), QLatin1String("chdir")},
        {('c'), QLatin1String("clone")},
        {('c'), QLatin1String("comparguments")},
        {('c'), QLatin1String("compcall")},
        {('c'), QLatin1String("compctl")},
        {('c'), QLatin1String("compdescribe")},
        {('c'), QLatin1String("compfilescompgroups")},
        {('c'), QLatin1String("compquote")},
        {('c'), QLatin1String("comptags")},
        {('c'), QLatin1String("comptry")},
        {('c'), QLatin1String("compvalues")},
        {('d'), QLatin1String("dirs")},
        {('d'), QLatin1String("disable")},
        {('d'), QLatin1String("disown")},
        {('e'), QLatin1String("echotc")},
        {('e'), QLatin1String("echoti")},
        {('e'), QLatin1String("emulatefc")},
        {('f'), QLatin1String("fg")},
        {('f'), QLatin1String("float")},
        {('f'), QLatin1String("functions")},
        {('g'), QLatin1String("getcap")},
        {('g'), QLatin1String("getln")},
        {('h'), QLatin1String("history")},
        {('i'), QLatin1String("integer")},
        {('j'), QLatin1String("jobs")},
        {('k'), QLatin1String("kill")},
        {('l'), QLatin1String("limit")},
        {('l'), QLatin1String("log")},
        {('n'), QLatin1String("noglob")},
        {('p'), QLatin1String("popd")},
        {('p'), QLatin1String("printpushd")},
        {('p'), QLatin1String("pushln")},
        {('r'), QLatin1String("rehash")},
        {('s'), QLatin1String("sched")},
        {('s'), QLatin1String("setcap")},
        {('s'), QLatin1String("setopt")},
        {('s'), QLatin1String("stat")},
        {('s'), QLatin1String("suspend")},
        {('t'), QLatin1String("ttyctl")},
        {('u'), QLatin1String("unfunction")},
        {('u'), QLatin1String("unhash")},
        {('u'), QLatin1String("unlimitunsetopt")},
        {('v'), QLatin1String("vared")},
        {('w'), QLatin1String("wait")},
        {('w'), QLatin1String("whence")},
        {('w'), QLatin1String("where")},
        {('w'), QLatin1String("which")},
        {('z'), QLatin1String("zcompile")},
        {('z'), QLatin1String("zformat")},
        {('z'), QLatin1String("zftp")},
        {('z'), QLatin1String("zle")},
        {('z'), QLatin1String("zmodload")},
        {('z'), QLatin1String("zparseopts")},
        {('z'), QLatin1String("zprof")},
        {('z'), QLatin1String("zpty")},
        {('z'), QLatin1String("zregexparse")},
        {('z'), QLatin1String("zsocket")},
        {('z'), QLatin1String("zstyle")},
        {('z'), QLatin1String("ztcp")},
        {('g'), QLatin1String("git")},
        {('r'), QLatin1String("rm")},
        {('s'), QLatin1String("sudo")},
        {('f'), QLatin1String("fdisk")},
        {('a'), QLatin1String("apt")},
        {('s'), QLatin1String("snap")},
        {('f'), QLatin1String("flatpak")},
        {('s'), QLatin1String("snapcraft")},
        {('y'), QLatin1String("yaourt")},
        {('n'), QLatin1String("nmcli")},
        {('p'), QLatin1String("pacman")},
        {('p'), QLatin1String("pamac")},
        {('f'), QLatin1String("fsck")},
        {('m'), QLatin1String("mount")},
        {('m'), QLatin1String("mkdir")},
        {('m'), QLatin1String("mkswap")},
        {('s'), QLatin1String("sleep")},
        {('l'), QLatin1String("ls")},
        {('w'), QLatin1String("wget")},
        {('k'), QLatin1String("kill")},
        {('k'), QLatin1String("killall")},
        {('g'), QLatin1String("gdb")},
        {('Q'), QLatin1String("QOwnNotes")},
        {('q'), QLatin1String("qownnotes")},
        {('d'), QLatin1String("docker")},
        {('o'), QLatin1String("openssl")},
        {('p'), QLatin1String("php")},
        {('p'), QLatin1String("python")},
        {('p'), QLatin1String("perl")},
        {('g'), QLatin1String("go")},
        {('c'), QLatin1String("curl")}
    };

    shell_other = {};
}

void loadShellData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other) {
    if (!shellDataInitialized) {
        initShellData();
        shellDataInitialized = true;
    }
    types = shell_types;
    keywords = shell_keywords;
    builtin = shell_builtin;
    literals = shell_literals;
    other = shell_other;

}
