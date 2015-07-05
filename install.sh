#!/usr/bin/env bash
#
# Created by Arthur Asatryan
# Company: BiaCode
# Date: 7/5/15
# Copyright (c) 2015 BiaCode. All rights reserved.

# ./install.sh
#
# Download BiaEngine dependencies and binaries from github releases and extracts from ZIP
#
# Helps prevent repo bloat due to large binary files
#

prefix=https://biacode.com/biaengine/dependencies/nix

filename=dependencies.zip

echo Downloading $filename.zip from $prefix...
curl -# -LO $prefix/$filename.zip
echo Extracting $filename.zip... please standby...
unzip -q $filename.zip
echo Cleaning up...
rm $filename.zip
echo Done.