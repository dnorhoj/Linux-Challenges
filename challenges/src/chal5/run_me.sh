#!/bin/bash
CHK="hardcoded string"
MD5=`echo -n "$CHK" | md5sum`
#echo "$MD5"
if [ "${MD5:0:32}" = "a95764050f8ced2a0392f34955c56c18" ]; then
  MD5=`echo -n "${CHK}X_X" | md5sum`
  PAS=`echo "${MD5:0:32}2020" | xxd -r -p | base64`
  echo "Correct, your password is $PAS"
else
  echo "Nope"
fi
