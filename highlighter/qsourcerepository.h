#pragma once

#include <QStringList>
#include <QHash>

#include <qsourcehighliter.h>

class QSourceRepository {
public:
    QSourceRepository() {
        syntaxList.push_back("Asm");
        syntaxList.push_back("Bash");
        syntaxList.push_back("C");
        syntaxList.push_back("C++");
        syntaxList.push_back("CMake");
        syntaxList.push_back("CSharp");
        syntaxList.push_back("Css");
        syntaxList.push_back("Go");
        syntaxList.push_back("Html");
        syntaxList.push_back("Ini");
        syntaxList.push_back("Javascript");
        syntaxList.push_back("Java");
        syntaxList.push_back("Lua");
        syntaxList.push_back("Make");
        syntaxList.push_back("Markdown");
        syntaxList.push_back("Php");
        syntaxList.push_back("Python");
        syntaxList.push_back("Qml");
        syntaxList.push_back("Rust");
        syntaxList.push_back("Sql");
        syntaxList.push_back("Typescript");
        syntaxList.push_back("V");
        syntaxList.push_back("Vex");
        syntaxList.push_back("VHDL");
        syntaxList.push_back("Xml");
        syntaxList.push_back("Yaml");
        
        langMap = QHash<QString, QSourceHighliter::Language> {
            { QLatin1String("Asm"), QSourceHighliter::CodeAsm },
            { QLatin1String("Bash"), QSourceHighliter::CodeBash },
            { QLatin1String("C"), QSourceHighliter::CodeC },
            { QLatin1String("C++"), QSourceHighliter::CodeCpp },
            { QLatin1String("CMake"), QSourceHighliter::CodeCMake },
            { QLatin1String("CSharp"), QSourceHighliter::CodeCSharp },
            { QLatin1String("Css"), QSourceHighliter::CodeCSS },
            { QLatin1String("Go"), QSourceHighliter::CodeGo },
            { QLatin1String("Html"), QSourceHighliter::CodeXML },
            { QLatin1String("Ini"), QSourceHighliter::CodeINI },
            { QLatin1String("Java"), QSourceHighliter::CodeJava },
            { QLatin1String("Javascript"), QSourceHighliter::CodeJava },
            { QLatin1String("Json"), QSourceHighliter::CodeJSON },
            { QLatin1String("Lua"), QSourceHighliter::CodeLua },
            { QLatin1String("Make"), QSourceHighliter::CodeMake },
            { QLatin1String("Markdown"), QSourceHighliter::CodeMarkdown },
            { QLatin1String("Php"), QSourceHighliter::CodePHP },
            { QLatin1String("Python"), QSourceHighliter::CodePython },
            { QLatin1String("Qml"), QSourceHighliter::CodeQML },
            { QLatin1String("Rust"), QSourceHighliter::CodeRust },
            { QLatin1String("Sql"), QSourceHighliter::CodeSQL },
            { QLatin1String("Typescript"), QSourceHighliter::CodeTypeScript },
            { QLatin1String("V"), QSourceHighliter::CodeV },
            { QLatin1String("Vex"), QSourceHighliter::CodeVex },
            { QLatin1String("VHDL"), QSourceHighliter::CodeVHDL },
            { QLatin1String("Xml"), QSourceHighliter::CodeXML },
            { QLatin1String("Yaml"), QSourceHighliter::CodeYAML }
        };
    }
    
    QStringList getSyntaxList() {
        return syntaxList;
    }
    
    QSourceHighliter::Language getLanguage(QString name) {
        return langMap[name];
    }
    
    QString getSyntaxForFile(QString input) {
        if (input.endsWith(".asm") || input.endsWith(".S")) return "Asm";
        else if (input.endsWith(".sh")) return "Bash";
        else if (input.endsWith(".c") || input.endsWith(".h")) return "C";
        else if (input.endsWith(".cpp") || input.endsWith(".cxx") || input.endsWith(".hpp") || input.endsWith(".hh")) return "C++";
        else if (input.endsWith("CMakeLists.txt") || input.endsWith(".cmake")) return "CMake";
        else if (input.endsWith(".cs") || input.endsWith(".csx")) return "CSharp";
        else if (input.endsWith(".css")) return "Css";
        else if (input.endsWith(".go")) return "Go";
        else if (input.endsWith(".html") || input.endsWith(".htm")) return "Html";
        else if (input.endsWith(".ini")) return "Ini";
        else if (input.endsWith(".js")) return "Javascript";
        else if (input.endsWith(".java")) return "Java";
        else if (input.endsWith(".lua")) return "Lua";
        else if (input.endsWith("Makefile")) return "Make";
        else if (input.endsWith(".md")) return "Markdown";
        else if (input.endsWith(".php")) return "Php";
        else if (input.endsWith(".py")) return "Python";
        else if (input.endsWith(".qml")) return "Qml";
        else if (input.endsWith(".rs")) return "Rust";
        else if (input.endsWith(".sql")) return "Sql";
        else if (input.endsWith(".ts") || input.endsWith(".tsx")) return "Typescript";
        else if (input.endsWith(".vhdl") || input.endsWith(".vhd")) return "VHDL";
        else if (input.endsWith(".xml")) return "Xml";
        else if (input.endsWith(".yaml")) return "Yaml";
        return "Plain Text";
    }
private:
    QStringList syntaxList;
    QHash<QString, QSourceHighliter::Language> langMap;
};

