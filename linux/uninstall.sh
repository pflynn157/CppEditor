#!/bin/bash
echo "Uninstalling..."

rm /usr/local/bin/CppEditor
rm /usr/share/applications/cpp-editor.desktop

update-desktop-database

echo "Done" 
