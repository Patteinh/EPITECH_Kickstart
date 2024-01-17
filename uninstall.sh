#!/bin/bash

# The user's home directory
HOME_DIR="$HOME"

# Remove the .starter directory
rm -rf "$HOME_DIR/.starter"

# Remove the starter script
sudo rm "/usr/local/bin/starter.sh" 2>/dev/null

echo "Uninstallation successful. Starter script and repo directorie have been removed."
