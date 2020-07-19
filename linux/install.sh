#!/bin/bash
echo "Installing..."

install CppEditor /usr/local/bin
install cpp-editor.desktop /usr/share/applications

update-desktop-database

echo "Done" 
