#!/usr/bin/env bash
set -euo pipefail
EXPECTED="Hello, World!"
OUTPUT=$(./source/code/hello_world/sh/hello_world)

if [ "$OUTPUT" != "$EXPECTED" ]; then
    echo "$OUTPUT != $EXPECTED"
    exit 1
fi
