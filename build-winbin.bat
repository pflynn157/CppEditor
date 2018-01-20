@echo off
:: Copyright 2017 Patrick Flynn
::
:: Redistribution and use in source and binary forms, with or without modification, 
:: are permitted provided that the following conditions are met:
::
:: 1. Redistributions of source code must retain the above copyright notice, 
::	this list of conditions and the following disclaimer.
::
:: 2. Redistributions in binary form must reproduce the above copyright notice, this 
::	list of conditions and the following disclaimer in the documentation and/or 
::	other materials provided with the distribution.
::
:: 3. Neither the name of the copyright holder nor the names of its contributors may 
::	be used to endorse or promote products derived from this software 
::	without specific prior written permission.
::
:: THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
:: ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
:: WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
:: IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
:: INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
:: NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
:: PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
:: WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
:: ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
:: EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

::Builds a winbin folder
::This folder contains all the files needed to build a distributable CppEditor
::You must do this before building the setup.iss script.
cls
echo You must enter the path to where the Qt DLLs are.
echo For example, if you built CppEditor using Qt 5.10.0 with the minw53_32 toolkit,
echo your path will look like this: C:\Qt\5.10.0\mingw53_32
echo.
echo Warning:
echo DO NOT include "bin" in the name, even though the DLLs are in that folder.
echo DO NOT include the ending slash.
echo.
set /p qtpath="Enter the complete path to the folder: "
echo %qtpath%

cls
if not exist %qtpath% (
	echo Error
	echo Unknown path.
	echo Exiting...
	exit /B
)

cls
echo Checking for folders...
if exist ".\winbin" rmdir .\winbin
md winbin

echo Copying executable...
if exist ".\build\src\CppEditor.exe" (
	copy .\build\src\CppEditor.exe .\winbin\CppEditor.exe
) else (
	echo Program executable not found.
	echo Please make sure the program is built.
	exit /B
)

echo Copying libraries...
cd winbin

md platforms
cd platforms
copy "%qtpath%\plugins\platforms\qwindows.dll" .\
cd ..

copy "%qtpath%\bin\libEGL.dll" .\
copy "%qtpath%\bin\libgcc_s_dw2-1.dll" .\
copy "%qtpath%\bin\libstdc++-6.dll" .\
copy "%qtpath%\bin\libwinpthread-1.dll" .\
copy "%qtpath%\bin\Qt5Core.dll" .\
copy "%qtpath%\bin\Qt5Gui.dll" .\
copy "%qtpath%\bin\Qt5Widgets.dll" .\

copy "C:\Unix\bin\libKF5DBusAddons.dll" .\
copy "C:\Unix\bin\libKF5SyntaxHighlighting.dll" .\
copy "C:\Unix\bin\libsettings.dll" .\

cd ..

echo Done
