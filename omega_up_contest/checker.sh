set -e

g++-11 -std=c++20 code.cpp -o code.out
g++-11 -std=c++20 gen.cpp -o gen.out
g++-11 -std=c++20 brute.cpp -o brute.out

in_file="input_file.txt"
my_file="input_file.txt"
correct_file="input_file.txt"

for ((i = 1; ; ++i)); do
    ./gen.out $i > $in_file
    ./code.out < $in_file > myAnswer
    ./brute.out < $in_file > correctAnswer
    diff -Z myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done

echo "WA on the following test:"
cat $in_file
echo "Your answer is:"
cat $my_file
echo "Correct answer is:"
cat $correct_answer
