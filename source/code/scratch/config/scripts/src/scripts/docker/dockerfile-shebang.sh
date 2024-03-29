#!/usr/bin/env bash
NAME=$(basename "$1")
docker build -t "$NAME" - < "$1" > /dev/null
shift # Remove script name from arguments
docker run --rm --name "$NAME" "$NAME" "$@"