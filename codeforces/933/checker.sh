set -e

g++-11 -std=c++20 A.cpp -o A.out
g++-11 -std=c++20 gen.cpp -o gen.out
g++-11 -std=c++20 A_brute.cpp -o A_brute.out

in_file="input_file.txt"
my_answer="my_answer.txt"
correct_answer="correct_answer.txt"

for ((i = 1; ; ++i)); do
    ./gen.out $i > $in_file
    ./A.out < $in_file > $my_answer
    ./A_brute.out < $in_file > $correct_answer
    diff -Z $my_answer $correct_answer > /dev/null || break
    echo "Passed test: "  $i
done

echo "WA on the following test:"
cat $in_file
echo "Your answer is:"
cat $my_answer
echo "Correct answer is:"
cat $correct_answer
