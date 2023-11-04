
# Replace 'source_file.txt' with the actual name of your source file.
source_file="./t.cpp"

# Loop to create copies of the file with names from A to D.
for ((i=0; i<4; i++)); do
    new_file_name=$(printf "copy_%s.cpp" $(printf \\$(printf '%03o' $((65+i)))))
    cp "$source_file" "$new_file_name"
done
