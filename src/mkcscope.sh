#!/bin/sh
rm -rf cscope.files cscope.files

find ./ -name '*.[cCsShH]' -print > cscope.files

cscope -i cscope.files
