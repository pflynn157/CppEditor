## CppEditor
CppEditor is a text/code editor written in C++ using the Qt framework. It has all the features you would expect of a modern text editor.

Originally, this project was hobby/learning project (2017-2018). I actually think it goes back a little further; I had an even older version than what is in this repository, but it became bloated and I didn't like that I had to use the GPL license (because of the libraries I was using at the time). So I stripped it down and started over a while back. The project when dormant again while I moved on to other things, but I recently began development again because I really wanted a text editor that I liked and that I could use across all platforms/desktops. I'm actually really picky about my editors. The ones I like happen to be the ones most closely tied with other desktop environments. The solution? I make my own.

I will be updating this as I encounter bugs and start to use it for my day-to-day work. The biggest thing I will see happening with this in the near future is the project panel will be replaced with a more generic mini-file explorer, like those you encounter in many modern GUI editors. The code in this also isn't the greatest, so I will probably be working over time to clean this up (I've learned a lot about programming the right way in recent times).

### Update- Version 3
You are currently on the development branch, which contains the in-progress version 3.

Version 3 contains significant changes from version 2, the biggest being the removal of the KDE library dependencies. I was tired of dealing with those, and recently I noticed that the KDE syntax highlighter looks different on each version, so I decided to just use my own highlighter. While I made one in the past, it wasn't great, so I found a different one on Github. Thanks to the simple design and liberal licensing, I simply forked it and added it directly into the repository. I also removed the KDBus-based IPC. I've made IPC controllers in the past, so if I really need it, I will add it back. I'm not going to publish version 3 for a few months until I've had time to test these changes.

Many thanks to Waqar Ahmed (Waqar144) for his amazing QSourceHighlite library and for licensing the way he chose. Because I made several additions and modifications, you can find the original version here: [https://github.com/Waqar144/QSourceHighlite](https://github.com/Waqar144/QSourceHighlite).

### Licensing
CppEditor is currently licensed under the BSD 3-clause license. The included Oxygen icons and the Qt framework are all licensed under LGPL. The included QSourceHighlite fork is licensed under the MIT License.

### Supported Platforms
Linux is my platform of choice for day-to-day work, and my job requires it. That said, Linux will be the main platform I support this on. However, the program is also meant to be very portable- it only uses Qt, so any other platform including Windows that supports Qt5 should support this.

### Dependencies
The following are needed to build CppEditor:   
1. Qt5 Core
2. Qt5 Widgets
3. Qt5 GUI

These are the packages you need across different Linux distros:   
- Ubuntu/Linux Mint: `qt5-default qtbase5-dev`   
- Fedora: `qt5-qtbase qt5-qtbase-devel`   
- Manjaro/Arch Linux: `qt5-base`   

In addition, you will need a C++ compiler and CMake. I generally use G++, but I don't think it matters.

### Theme Fixes

On Gtk-based desktops such as Gnome and Cinnamon (the latter of which I use on all my systems), you may have issues with Qt applications such as this not looking like the rest of the system. If that's the case, follow these instructions to fix that:

* `sudo apt install qt5-style-plugins` -> Installs additional Qt styles (including the Gtk one we want) (Ubuntu/Linux Mint/Debian)
* `sudo dnf install qt5-qtstyleplugins` -> Same as above, except for Fedora
* `echo "export QT_QPA_PLATFORMTHEME=gtk2" >> ~/.profile` -> Enable the theme. Make sure to log out and back in when you're done
* `sudo apt install appmenu-gtk2-module` -> If you have a delay launching, installing this will fix it.


