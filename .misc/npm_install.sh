#!/bin/bash
set -e

npm install -g $(grep -vE "^\s*#" npm-requirements.txt  | tr "\n" " ")
