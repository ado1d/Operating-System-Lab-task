#!/bin/bash

# Create a file
create_file() {
    read -p "Enter new file name: " file
    if [ -f "$file" ]; then
        echo "File already exists."
    else
        touch "$file"
        echo "File created: $file"
    fi
}

# Write to a file (overwrite)
write_file() {
    read -p "Enter file name to write to: " file
    if [ -f "$file" ]; then
        read -p "Enter content to write: " content
        echo "$content" > "$file"
        echo "Written to file."
    else
        echo "File not found."
    fi
}

# Append to a file
append_file() {
    read -p "Enter file name to append to: " file
    if [ -f "$file" ]; then
        read -p "Enter content to append: " content
        echo "$content" >> "$file"
        echo "Content appended."
    else
        echo "File not found."
    fi
}

# Read file
read_file() {
    read -p "Enter file name to read: " file
    if [ -f "$file" ]; then
        echo "Content of $file:"
        cat "$file"
    else
        echo "File not found."
    fi
}

# Delete a file
delete_file() {
    read -p "Enter file name to delete: " file
    if [ -f "$file" ]; then
        rm "$file"
        echo "File deleted."
    else
        echo "File not found."
    fi
}

# Menu
while true; do
    echo ""
    echo "FILE MANAGER MENU"
    echo "1. Create File"
    echo "2. Write to File"
    echo "3. Append to File"
    echo "4. Read File"
    echo "5. Delete File"
    echo "6. Exit"
    read -p "Choose an option [1-6]: " opt

    case $opt in
        1) create_file ;;
        2) write_file ;;
        3) append_file ;;
        4) read_file ;;
        5) delete_file ;;
        6) echo "Exiting..."; break ;;
        *) echo "Invalid option. Try again." ;;
    esac
done
