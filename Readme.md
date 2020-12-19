## CppEditor
CppEditor is a text/code editor written in C++ using the Qt framework. It has all the features you would expect of a modern text editor.

Originally, this project was hobby/learning project (2017-2018). I actually think it goes back a little further; I had an even older version than what is in this repository, but it became bloated and I didn't like that I had to use the GPL license (because of the libraries I was using at the time). So I stripped it down and started over a while back. The project when dormant again while I moved on to other things, but I recently began development again because I really wanted a text editor that I liked and that I could use across all platforms/desktops. I'm actually really picky about my editors. The ones I like happen to be the ones most closely tied with other desktop environments. The solution? I make my own.

I will be updating this as I encounter bugs and start to use it for my day-to-day work. The biggest thing I will see happening with this in the near future is the project panel will be replaced with a more generic mini-file explorer, like those you encounter in many modern GUI editors. The code in this also isn't the greatest, so I will probably be working over time to clean this up (I've learned a lot about programming the right way in recent times).

#### Licensing
CppEditor is currently licensed under the BSD 3-clause license. The included TinyXML2 source code is licensed under the zlib license. The including Oxygen icons, the KDE syntax-highlighting and KDE KDBusAddons library, and the Qt framework are all licensed under LGPL.

#### Supported Platforms
Linux is my platform of choice for day-to-day work, and my job requires it. That said, Linux will be the main platform I support this on. However, the program is also meant to be very portable- it only uses Qt and a few tier 1 KDE libraries- so it should run on other platforms including Windows without much issue.

Note to Windows users: I had this working on Windows not too long ago, and it probably still does. I don't use Windows at the moment and very much hope I won't need too, but if you want to try to build it, you are welcome to try the DOS scripts I wrote to automate the process. The two KDE libraries I do use work on Windows.

#### Dependencies
The following are needed to build CppEditor:   
1. Qt5 Core
2. Qt5 Widgets
3. Qt5 GUI
4. KDBusAddons
6. KDE syntax-highlighting

These are the packages you need across different Linux distros:   
- Ubuntu/Linux Mint: `qt5-default qtbase5-dev libkf5syntaxhighlighting5 libkf5syntaxhighlighting-dev libkf5dbusaddons5 libkf5dbusaddons-dev`   
- Fedora: `qt5-qtbase qt5-qtbase-devel kf5-syntax-highlighting kf5-syntax-highlighting-devel kf5-kdbusaddons kf5-kdbusaddons-devel`   
- Manjaro/Arch Linux: `qt5-base syntax-highlighting kdbusaddons`   

In addition, you will need a C++ compiler and CMake. I generally use G++, but I don't think it matters.

#### Ubuntu Fixes

I recently switched one of my computers to Ubuntu, which as you know uses the Gnome desktop. In order to get it to look like the rest of the applications, you need a few additional packages/fixes:   
* `sudo apt install qt5-style-plugins` -> Installs additional Qt styles (including the Gtk one we want)
* `echo "export QT_QPA_PLATFORMTHEME=gtk2" >> ~/.profile` -> Enable the theme. Make sure to log out and back in when you're done
* `sudo apt install appmenu-gtk2-module` -> If you have a delay launching, installing this will fix it.


