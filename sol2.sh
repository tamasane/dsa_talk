g++ src/random_input_gen.cpp -o input
g++ src/solution_using_segment_tree.cpp -o sol
echo $1 $2 | ./input >> in.txt
rm input
cat in.txt | ./sol
rm in.txt sol