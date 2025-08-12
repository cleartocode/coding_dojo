#!/bin/bash
# Uso: ./new_kata.sh <python|cpp|rust|c> <nombre_ejercicio>

set -euo pipefail

if [ $# -ne 2 ]; then
  echo "Uso: $0 <python|cpp|rust|c> <nombre_ejercicio>"
  exit 1
fi

LANG=$1
NAME=$2
ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"

case "$LANG" in
  python)
    DEST="$ROOT_DIR/python/$NAME"
    [ -e "$DEST" ] && { echo "Ya existe: $DEST"; exit 1; }
    mkdir -p "$DEST"
    cp "$ROOT_DIR/python/template.py" "$DEST/test_${NAME}.py"
    echo "✅ Python en: $DEST"
    echo "   cd \"$DEST\" && pytest -q"
    ;;
  cpp)
    DEST="$ROOT_DIR/cpp/$NAME"
    [ -e "$DEST" ] && { echo "Ya existe: $DEST"; exit 1; }
    mkdir -p "$DEST"
    cp "$ROOT_DIR/cpp/template.cpp" "$DEST/$NAME.cpp"
    echo "✅ C++ en: $DEST"
    echo "   g++ -std=c++20 -O2 \"$DEST/$NAME.cpp\" -o \"$DEST/$NAME\" && \"$DEST/$NAME\""
    ;;
  rust)
    BASE="$ROOT_DIR/rust"
    DEST="$BASE/$NAME"
    [ -e "$DEST" ] && { echo "Ya existe: $DEST"; exit 1; }
    (cd "$BASE" && cargo new --lib "$NAME" >/dev/null)
    cp "$ROOT_DIR/rust/template.rs" "$DEST/src/lib.rs"
    echo "✅ Rust (cargo) en: $DEST"
    echo "   cd \"$DEST\" && cargo test"
    ;;
  c)
    DEST="$ROOT_DIR/c/$NAME"
    [ -e "$DEST" ] && { echo "Ya existe: $DEST"; exit 1; }
    mkdir -p "$DEST"
    cp "$ROOT_DIR/c/template.c" "$DEST/$NAME.c"
    echo "✅ C en: $DEST"
    echo "   gcc -std=c11 -O2 \"$DEST/$NAME.c\" -o \"$DEST/$NAME\" && \"$DEST/$NAME\""
    ;;
  *)
    echo "Lenguaje no soportado: $LANG"
    exit 1
    ;;
esac
