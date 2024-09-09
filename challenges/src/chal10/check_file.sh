#!/bin/bash
CHK="/home/chal10/secret"
if [ -d "$CHK" ]; then
  echo "$CHK exist, delete it" 1>&2
  exit 1
fi
MD5=`echo -n "$CHK" | md5sum`
if [ "${MD5:0:32}" = "0132ee2decefdf2a7e45b75fad88c09f" ]; then
  MD5=`echo -n "${CHK}X_X" | md5sum`
  PAS=`echo "${MD5:0:32}2020" | xxd -r -p | base64`
  echo "Correct, your password is $PAS"
else
  echo "Nope"
fi
