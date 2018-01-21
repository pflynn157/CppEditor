## CppEditor
CppEditor is an advanced text/code editor written in C++. It has all the features you would except of a modern text editor. CppEditor is designed to run on any platform, and to be easily ported to new platforms with minimal modifications.

#### Licensing
CppEditor is currently licensed under the BSD 3-clause license. The included TinyXML2 source code is licensed under the zlib license. The libsettings library is licensed under the BSD-3 license. The including Oxygen icons, the KDE syntax-highlighting and KDE KDBusAddons library, and the Qt framework are all licensed under LGPL.

#### Supported Platforms
CppEditor is fully supported on Linux and mostly supported on Windows. Additionally, it should run with no issues on FreeBSD. For more information, see this link: https://sites.google.com/site/patrick4664tech/cppeditor

#### Dependencies
The following are needed to build CppEditor:   
1. Qt5 Core
2. Qt5 Widgets
3. Qt5 GUI
4. KDBusAddons
5. libsettings
6. KDE syntax-highlighting

### Icons
On Linux, CppEditor pulls icons from the current theme. However, on desktops (like Fluxbox) or systems (like Windows) without this support, an included icon is used instead. All icons are from the Oxygen icon theme. Don't want to use the theme icons at all? You don't have to. Open the settings file by clicking Settings (in the menubar)-> Open settings file. Change the value of the "sysicons" node to "false" and restart the program. To resume using theme icons if they are available, change the "sysicons" node back to true. You can also use different icons if you do not like the theme or Oxygen icons. Simply swap out the Oxygen icon for what you want in the {source root}/src/icons folder. Important: you must rename your new icon to the same name that the previous icon had, or it will not work. Also, this cannot be done at runtime; you must rebuild the program after swapping your icons.


