#!/usr/bin/env bash
set -euo pipefail
mkdir -p site build
# Compile the ORIGINAL client unchanged (except one spelling correction),
# renaming its main so the separate web bridge can initialize it.
em++ -std=c++17 -O2 -Dmain=original_main -c cpp/client.cpp -o build/client.o
em++ -std=c++17 -O2 cpp/travelplanner.cpp cpp/web_bridge.cpp build/client.o \
  -o site/travelplanner.js \
  --no-entry -sMODULARIZE=1 -sEXPORT_NAME=createTravelPlannerModule \
  -sENVIRONMENT=web -sALLOW_MEMORY_GROWTH=1 -sNO_EXIT_RUNTIME=1 \
  -sEXPORTED_FUNCTIONS=_tp_init,_tp_route_text \
  -sEXPORTED_RUNTIME_METHODS=UTF8ToString
ls -lh site/travelplanner.js site/travelplanner.wasm
