set -e

g++-11 -std=c++20 B.cpp -o B.out
g++-11 -std=c++20 gen.cpp -o gen.out
g++-11 -std=c++20 B_brute.cpp -o B_brute.out

in_file="input_file.txt"
my_answer="my_answer.txt"
correct_answer="correct_answer.txt"

for ((i = 1; ; ++i)); do
    ./gen.out $i > $in_file
    ./B.out < $in_file > $my_answer
    ./B_brute.out < $in_file > $correct_answer
    diff -Z $my_answer $correct_answer > /dev/null || break
    echo "Passed test: "  $i
done

echo "WB on the following test:"
cat $in_file
echo "Your answer is:"
cat $my_answer
echo "Correct answer is:"
cat $correct_answer
