set -e

g++-11 -std=c++20 code.cpp -o code.out
g++-11 -std=c++20 gen.cpp -o gen.out
g++-11 -std=c++20 brute.cpp -o brute.out

in_file="input_file.txt"
my_file="my_answer.txt"
correct_file="correct_answer.txt"

for ((i = 1; ; ++i)); do
    ./gen.out $i > $in_file
    ./code.out < $in_file > my_answer.txt
    ./brute.out < $in_file > correct_answer.txt
    diff -Z my_answer.txt correct_answer.txt > /dev/null || break
    echo "Passed test: "  $i
done

echo "WA on the following test:"
cat $in_file
echo "Your answer is:"
cat $my_file
echo ""
echo "Correct answer is:"
cat $correct_file
echo ""
