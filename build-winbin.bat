@echo off

cd build

md winbin
copy src\CppEditor.exe .\winbin

cd winbin

windeployqt --release --compiler-runtime CppEditor.exe

copy C:\Unix\bin\libKF5DBusAddons.dll .\
copy C:\Unix\bin\libKF5SyntaxHighlighting.dll .\

windeployqt --release --compiler-runtime libKF5DBusAddons.dll
windeployqt --release --compiler-runtime libKF5SyntaxHighlighting.dll

cd ..\..
