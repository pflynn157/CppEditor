## CppEditor
CppEditor is an advanced text/code editor written in C++. It has all the features you would except of a modern text editor. CppEditor is designed to run on any platform, and to be easily ported to new platforms with minimal modifications.

#### Licensing
CppEditor is currently licensed under the BSD 3-clause license. The included TinyXML2 source code is licensed under the zlib license. The libsettings library is licensed under the BSD-3 license. The including Oxygen icons, the KDE syntax-highlighting and KDE KDBusAddons library, and the Qt framework are all licensed under LGPL.

#### Supported Platforms
CppEditor is developed mainly on Linux, so if obviously works the best on this platform. It also should also build and run without any issues on BSD-like systems (particularly, FreeBSD). Although the actual source code has Windows support, since I changed the library dependencies, I have not tested it on Windows yet. I do plan on trying to get it to work on Windows later on.

#### Dependencies
The following are needed to build CppEditor:   
1. Qt5 Core
2. Qt5 Widgets
3. Qt5 GUI
4. KDBusAddons
5. libsettings
6. KDE syntax-highlighting

#### Languages
CppEditor has experimental internationalization support. Currently, there is support for the following languages:   
1. Afrikaans
2. German
3. English
4. Spanish
5. Esperanto
6. Italian
7. Dutch
8. Swedish   
These files, as I do not speak all these languages, were created with the help of Google Translate. Therefore, they probably have errors. Feel free to contribute corrections (or new files) if you wish. However, please be aware of two things: 1) the entire program does not have translation support (must does, its just a few of the deep-down areas that don't), and 2) I am thinking about migrating to a different internationalization framework, probably the Qt one (not definite yet, just an idea).


