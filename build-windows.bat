@echo off
cls

echo Cloning dependencies...
cd ..
if not exist extra-cmake-modules (
	git clone https://github.com/KDE/extra-cmake-modules.git)
if not exist kdbusaddons (
	git clone https://github.com/KDE/kdbusaddons.git)
if not exist syntax-highlighting (
	git clone https://github.com/KDE/syntax-highlighting.git)

echo Checking for C:\Unix
if not exist C:\Unix md C:\Unix

::Build extra-cmake-modules
echo Building extra-cmake-modules
cd extra-cmake-modules
if not exist build md build
cd build

cmake -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX=C:/Unix ..
mingw32-make
mingw32-make install

cd ../..
echo Done
::Done building extra-cmake-modules

::Build KDusAddons
echo Building KDBusAddons
cd kdbusaddons
if not exist build md build
cd build

cmake -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH=C:/Unix/share/ECM -DCMAKE_INSTALL_PREFIX=C:/Unix ..
mingw32-make
mingw32-make install

cd ../..
echo Done
::Done building KDBusAddons

::Build KDE syntax-highlighting
echo Build KDE Syntax Highlighting
cd syntax-highlighting
if not exist build md build
cd build

cmake -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH=C:/Unix/share/ECM -DCMAKE_INSTALL_PREFIX=C:/Unix ..
mingw32-make
mingw32-make install

cd ../..
echo Done
::Done building KDE Syntax-Highlighting

::Build CppEditor
echo Building CppEditor
cd CppEditor
if not exist build md build
cd build

cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=C:/Unix/share/ECM -DCMAKE_INSTALL_PREFIX=C:/Unix -DCMAKE_CXX_FLAGS="-IC:/Unix/include -LC:/Unix/lib" ..
mingw32-make

cd ../..
echo Done
::Done building CppEditor
