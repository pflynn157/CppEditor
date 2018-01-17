#!/bin/bash
if [ ! -f ./build/src/CppEditor ] ; then
    echo "Error: You must build the program first!"
    exit 1
fi
cp ./build/src/CppEditor /usr/local/bin
cp ./share/cpp-editor.desktop /usr/share/applications

mkdir -p /usr/share/CppEditor/themes
cp ./themes/*.css /usr/share/CppEditor/themes

update-desktop-database
ldconfig

echo "Done"
