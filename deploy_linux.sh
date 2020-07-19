#!/bin/bash
cd build
mkdir linux_bin

cp src/CppEditor linux_bin
cp ../share/cpp-editor.desktop linux_bin
cp ../linux/* linux_bin
cp ../COPYING* linux_bin

tar -czvf CppEditor_bin_linux.tar.gz linux_bin/*
