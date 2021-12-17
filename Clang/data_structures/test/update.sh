#!/usr/bin/bash

for header in $(find ../src -type f -name "*.h"); do
	name=$("$header")
done
