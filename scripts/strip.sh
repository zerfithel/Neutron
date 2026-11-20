OUTPUT_DIR="${1:-build}"
find "$OUTPUT_DIR" -type f -executable -exec strip {} +
