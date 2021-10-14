g++ src/random_input_gen.cpp -o input
g++ src/solution_using_segment_tree.cpp -o opt
g++ src/solution_using_forloop.cpp -o sol
echo $1 $2 | ./input >> in.txt
echo "Solution 1: For Loop"
cat in.txt | ./sol 
echo ""
echo "Solution 2: Segment Tree"
cat in.txt | ./opt
rm input opt sol in.txt