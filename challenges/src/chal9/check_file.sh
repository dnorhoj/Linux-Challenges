#!/bin/bash
CHK="/home/chal9/secret"
if [ -d "$CHK" ]; then
  echo "$CHK exist, delete it" 1>&2
  exit 1
fi
MD5=`echo -n "$CHK" | md5sum`
if [ "${MD5:0:32}" = "bdfb2053465459bebed771c5760854e3" ]; then
  MD5=`echo -n "${CHK}X_X" | md5sum`
  PAS=`echo "${MD5:0:32}2020" | xxd -r -p | base64`
  echo "Correct, your password is $PAS"
else
  echo "Nope"
fi
