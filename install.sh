#!/bin/bash

# The directory where the repository has been cloned
REPO_DIR=$(pwd)
REPO_NAME=$(basename "$REPO_DIR")

# The user's home directory
HOME_DIR="$HOME"

# Check if the repo is already in the home directory
if [[ "$REPO_DIR" != "$HOME_DIR/$REPO_NAME" ]]; then
  # Move the repository to the user's home directory
  mv "$REPO_DIR" "$HOME_DIR/"
fi

# Rename the repository to .starter
mv "$HOME_DIR/$REPO_NAME" "$HOME_DIR/.starter"

# Change into the .starter directory
cd "$HOME_DIR/.starter"

# Create the starter script
cat > starter.sh << 'EOL'
#!/bin/bash

if [[ "$#" -lt 1 ]]; then
    echo "Usage: starter <language> | -help"
    echo "Available languages: c, cpp, haskell, python"
    exit 1
fi

if [ "$1" = "-help" ]; then
    echo "Usage: starter <language>"
    echo "The starter command creates a new project in the specified language by copying the corresponding starter template."
    echo "Available languages: c, cpp, haskell, python"
    exit 0
fi

cp -r "$HOME/.starter/${1}_starter"/* ./

EOL

# Set execute permission and move the script to a location in PATH
chmod +x "$HOME_DIR/.starter/starter.sh"
sudo mv "$HOME_DIR/.starter/starter.sh" "/usr/local/bin/starter"
echo "Installation successful. You can now use the starter script from anywhere."
