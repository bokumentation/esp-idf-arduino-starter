#!/bin/bash

# --- ESP-IDF Project Setup Script ---
# This script automates OS detection, links the correct clangd templates and initializes pre-commit hooks.

# Detect Operating System
OS_TYPE="$(uname -s)"
echo "------------------------------------------------"
echo "Detecting OS: $OS_TYPE"
echo "------------------------------------------------"

case "${OS_TYPE}" in
    Linux*)
        # Check if running under WSL
        if grep -q Microsoft /proc/version; then
            echo "[OK] Setting up for Linux (WSL)..."
        else
            echo "[OK] Setting up for Native Linux..."
        fi
        cp tools/clangd-templates/linux.clangd .clangd
        ;;

    Darwin*)
        echo "[OK] Setting up for macOS..."
        cp tools/clangd-templates/macos.clangd .clangd
        ;;

    CYGWIN*|MINGW*|MSYS*)
        echo "[OK] Setting up for Windows (Root Installation)..."
        if [ -f "tools/clangd-templates/windows.clangd" ]; then
            cp tools/clangd-templates/windows.clangd .clangd
        else
            echo "[ERROR] Windows template not found in tools/clangd-templates/"
            exit 1
        fi
        ;;

    *)
        echo "[!] Unknown OS. Please copy the template manually from tools/."
        exit 1
        ;;
esac

# Ensure pre-commit is installed and activated
echo "------------------------------------------------"
if command -v pre-commit > /dev/null; then
    echo "Initializing pre-commit hooks..."
    pre-commit install
    echo "[OK] Pre-commit hooks installed."
else
    echo "[WARN] 'pre-commit' command not found."
    echo "Please install it via: pip install pre-commit"
fi

echo "------------------------------------------------"
echo "Setup complete!"
echo "TIP: Restart the 'Clangd Language Server' in VS Code to apply changes."
echo "------------------------------------------------"
