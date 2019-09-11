#include "code/utilities/types/tree/tree_traversal.hpp"
#include "code/tools/hackerrank/bst_swap_solution_sliding_window_two_ptrs.hpp"
#include "code/tools/hackerrank/bst_swap_solution_in_out.hpp"
#include "code/tools/hackerrank/bst_swap_solution_geeks_five_ptrs.hpp"
#include "code/tools/hackerrank/bst_swap_solution_geeks_four_ptrs.hpp"
#include "code/tools/hackerrank/bst_swap_solution_geeks_three_ptrs.hpp"
#include "code/tools/hackerrank/bst_swap_algorithm.hpp"
#include "code/tools/hackerrank/bst_swap_solution.hpp"
#include "code/utilities/data_structures/tree/binary_nodes.hpp"
#include "gtest/gtest.h"
#include <algorithm>
#include <vector>
#include <utility>

void wrong_by_only_two_nodes(std::vector<int> nodes){
  auto sorted = nodes;
  std::sort(sorted.begin(),sorted.end());
  
  int discrepency_count = 0;
  for (size_t i = 0; i < sorted.size(); ++i){
    if (nodes[i] != sorted[i]){
      ++discrepency_count;
    }
  }
  EXPECT_EQ(discrepency_count,2);
}

void check_algorithm_fixes_tree(BinaryNode<int> & root, Bst_Swap_Algorithm const& algo){
  
  //the tree SHOULD NOT be sorted before we start
  auto before = Tree_Traversal::inorder_traversal_as_list(&root);
  EXPECT_FALSE(std::is_sorted(before.begin(),before.end()));
  
  //in fact, it should only be wrong by two nodes
  //we don't accept trees that are already fixed or broken beyond two nodes out of place
  wrong_by_only_two_nodes(before);
  
  //Time to fix the tree, and confirm that we actually fixed it.
  Bst_Swap_Solution::fix_bst(&root,algo);
  auto after = Tree_Traversal::inorder_traversal_as_list(&root);
  EXPECT_TRUE(std::is_sorted(after.begin(),after.end()));
}

void check_every_swap_combination(BinaryNode<int> & root, Bst_Swap_Algorithm const& algo){
    auto ordered = Tree_Traversal::inorder_traversal_as_node_list(&root);
    for (size_t i = 0; i < ordered.size(); ++i){
      for (size_t j = 0; j < ordered.size(); ++j){
        if (ordered[i]->val != ordered[j]->val){
          std::swap(ordered[i]->val,ordered[j]->val);
          //std::cout << "swapped " << ordered[i]->val << " " << ordered[j]->val << std::endl;
          check_algorithm_fixes_tree(root,algo);
        }
      }
    }
}


std::vector<Bst_Swap_Algorithm> algorithms_to_test(){
  std::vector<Bst_Swap_Algorithm> x;
  x.emplace_back(Bst_Swap_Algorithm::HACKERRANK_RECURSIVE_FIVE);
  x.emplace_back(Bst_Swap_Algorithm::HACKERRANK_RECURSIVE_FOUR);
  x.emplace_back(Bst_Swap_Algorithm::HACKERRANK_RECURSIVE_THREE);
  x.emplace_back(Bst_Swap_Algorithm::SLIDING_WINDOW_AND_PAIR);
  x.emplace_back(Bst_Swap_Algorithm::INORDER_OUTORDER_THREE);
  return x;
}

BinaryNodes<int> TwoNodesSwapped_NonAdjecent_Example1(){
  
  //     6 
  //    /  \ 
  //   10   2 
  //  /  \ /  \ 
  // 1   3 7  12 
  // 10 and 2 are swapped
  BinaryNodes<int> x;
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(6));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(10));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(2));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(1));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(3));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(7));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(12));
  x.nodes[0]->left = &*x.nodes[1];
  x.nodes[0]->right = &*x.nodes[2];
  x.nodes[0]->left->left = &*x.nodes[3];
  x.nodes[0]->left->right = &*x.nodes[4];
  x.nodes[0]->right->left = &*x.nodes[5];
  x.nodes[0]->right->right = &*x.nodes[6];
  return x;
}
BinaryNodes<int> TwoNodesSwapped_NonAdjecent_Example2(){
  
  //       10
  //      /  \
  //     5    8
  //    / \
  //   2   20
  // 20 and 8 are swapped
  BinaryNodes<int> x;
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(10));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(5));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(8));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(2));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(20));
  x.nodes[0]->left = &*x.nodes[1];
  x.nodes[0]->right = &*x.nodes[2];
  x.nodes[0]->left->left = &*x.nodes[3];
  x.nodes[0]->left->right = &*x.nodes[4];
  return x;
}
BinaryNodes<int> TwoNodesSwapped_NonAdjecent_Example3(){
  //        2
  //      /  \
  //     3    1
  // 3 and 1 are swapped
  BinaryNodes<int> x;
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(2));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(3));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(1));
  x.nodes[0]->left = &*x.nodes[1];
  x.nodes[0]->right = &*x.nodes[2];
  return x;
}
BinaryNodes<int> TwoNodesSwapped_NonAdjecent_Example4(){
    //        2
    //      /  \
    //     1    3
    //    /      \
    //   4        0
    // 4 and 0 are swapped
  BinaryNodes<int> x;
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(2));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(1));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(3));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(4));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(0));
  x.nodes[0]->left = &*x.nodes[1];
  x.nodes[0]->right = &*x.nodes[2];
  x.nodes[0]->left->left = &*x.nodes[3];
  x.nodes[0]->right->right = &*x.nodes[4];
  return x;
}
BinaryNodes<int> TwoNodesSwapped_NonAdjecent_Example5(){
  //       4
  //      /  \
  //     3    5
  //    /      \
  //   2        6
  //  /          \
  // 7            1
  // 7 and 1 are swapped
  BinaryNodes<int> x;
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(4));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(3));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(5));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(2));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(6));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(7));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(1));
  x.nodes[0]->left = &*x.nodes[1];
  x.nodes[0]->right = &*x.nodes[2];
  x.nodes[0]->left->left = &*x.nodes[3];
  x.nodes[0]->right->right = &*x.nodes[4];
  x.nodes[0]->left->left->left = &*x.nodes[5];
  x.nodes[0]->right->right->right = &*x.nodes[6];
  return x;
}
BinaryNodes<int> TwoNodesSwapped_NonAdjecent_Example6(){
  //       7
  //      /  \
  //     3    5
  //    /      \
  //   2        6
  //  /          \
  // 1            4
  // 7 and 4 are swapped
  BinaryNodes<int> x;
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(7));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(3));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(5));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(2));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(6));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(1));
  x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(4));
  x.nodes[0]->left = &*x.nodes[1];
  x.nodes[0]->right = &*x.nodes[2];
  x.nodes[0]->left->left = &*x.nodes[3];
  x.nodes[0]->right->right = &*x.nodes[4];
  x.nodes[0]->left->left->left = &*x.nodes[5];
  x.nodes[0]->right->right->right = &*x.nodes[6];
  return x;
}


TEST(BST_Fix, NonAdjacent_1) {
    
    for (auto algo: algorithms_to_test()){
      auto tree = TwoNodesSwapped_NonAdjecent_Example1();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}

TEST(BST_Fix, NonAdjacent_2) {
    
    for (auto algo: algorithms_to_test()){
      auto tree = TwoNodesSwapped_NonAdjecent_Example2();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}

TEST(BST_Fix, NonAdjacent_3) {
    
    for (auto algo: algorithms_to_test()){
      auto tree = TwoNodesSwapped_NonAdjecent_Example3();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}

TEST(BST_Fix, NonAdjacent_4) {
    
    for (auto algo: algorithms_to_test()){
      auto tree = TwoNodesSwapped_NonAdjecent_Example4();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}

TEST(BST_Fix, NonAdjacent_5) {
    
    for (auto algo: algorithms_to_test()){
      auto tree = TwoNodesSwapped_NonAdjecent_Example5();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}
TEST(BST_Fix, NonAdjacent_6) {
    
    for (auto algo: algorithms_to_test()){
      auto tree = TwoNodesSwapped_NonAdjecent_Example6();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}

TEST(BST_Fix, NonAdjacent_7) {
        
     //     6 
     //    /  \ 
     //   2    10 
     //  /  \ /  \ 
     // 12   3 7  1 
     // 12 and 1 are swapped
     for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(6);
    BinaryNode<int> r1(2);
    BinaryNode<int> r2(10);
    BinaryNode<int> r3(12);
    BinaryNode<int> r4(3);
    BinaryNode<int> r5(7);
    BinaryNode<int> r6(1);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->right = &r4;
    root.right->left = &r5;
    root.right->right = &r6;
    check_algorithm_fixes_tree(root,algo);}
}

TEST(BST_Fix, Adjacent_1) {
    
    //       10
    //      /  \
    //     6    20
    //    / \
    //   2   5
    // 5 and 6 are swapped
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(10);
    BinaryNode<int> r1(6);
    BinaryNode<int> r2(20);
    BinaryNode<int> r3(2);
    BinaryNode<int> r4(5);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->right = &r4;
    check_algorithm_fixes_tree(root,algo);}
}

TEST(BST_Fix, Adjacent_2) {
    
    //       10
    //      /  \
    //     4    20
    //    / \
    //   5   7
    // 4 and 5 are swapped
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(10);
    BinaryNode<int> r1(4);
    BinaryNode<int> r2(20);
    BinaryNode<int> r3(5);
    BinaryNode<int> r4(7);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->right = &r4;
    check_algorithm_fixes_tree(root,algo);}
}

TEST(BST_Fix, Adjacent_3) {
    
    //        5
    //      /  \
    //     10    20
    //    / \
    //   4   7
    // 5 and 10 are swapped
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(5);
    BinaryNode<int> r1(10);
    BinaryNode<int> r2(20);
    BinaryNode<int> r3(4);
    BinaryNode<int> r4(7);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->right = &r4;
    check_algorithm_fixes_tree(root,algo);}
}
TEST(BST_Fix, Adjacent_4) {
    
    //        1
    //      /  \
    //     2    3
    // 2 and 1 are swapped
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(1);
    BinaryNode<int> r1(2);
    BinaryNode<int> r2(3);
    root.left = &r1;
    root.right = &r2;
    check_algorithm_fixes_tree(root,algo);}
}
TEST(BST_Fix, Adjacent_5) {
    
    //        1
    //      /  \
    //     2    3
    //    /
    //   0
    // 2 and 1 are swapped
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(1);
    BinaryNode<int> r1(2);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(0);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    check_algorithm_fixes_tree(root,algo);}
}
TEST(BST_Fix, Adjacent_6) {
    
    //        1
    //      /  \
    //     2    3
    //           \
    //            4
    // 2 and 1 are swapped
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(1);
    BinaryNode<int> r1(2);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(4);
    root.left = &r1;
    root.right = &r2;
    root.right->right = &r3;
    check_algorithm_fixes_tree(root,algo);}
}
TEST(BST_Fix, Adjacent_7) {
    
    //        1
    //      /  \
    //     2    3
    //   /       \
    //  0         4
    // 2 and 1 are swapped
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(1);
    BinaryNode<int> r1(2);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(0);
    BinaryNode<int> r4(4);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.right->right = &r4;
    check_algorithm_fixes_tree(root,algo);}
}
TEST(BST_Fix, Adjacent_8) {
    
 //           20
 //         /
 //        19
 //      /
 //     18
 //    /
 //   5
 //  / \
 // 6   7
   
 //    6 and 5 are swapped
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(20);
    BinaryNode<int> r1(19);
    BinaryNode<int> r2(18);
    BinaryNode<int> r3(5);
    BinaryNode<int> r4(6);
    BinaryNode<int> r5(7);
    root.left = &r1;
    root.left->left = &r2;
    root.left->left->left = &r3;
    root.left->left->left->left = &r4;
    root.left->left->left->right = &r5;
    check_algorithm_fixes_tree(root,algo);}
}
TEST(BST_Fix, Adjacent_9) {
    
 //           20
 //         /
 //        19
 //      /
 //     18
 //    /
 //   7
 //  / \
 // 5   6
   
 //    7 and 6 are swapped
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(20);
    BinaryNode<int> r1(19);
    BinaryNode<int> r2(18);
    BinaryNode<int> r3(7);
    BinaryNode<int> r4(5);
    BinaryNode<int> r5(6);
    root.left = &r1;
    root.left->left = &r2;
    root.left->left->left = &r3;
    root.left->left->left->left = &r4;
    root.left->left->left->right = &r5;
    check_algorithm_fixes_tree(root,algo);}
}
TEST(BST_Fix, Adjacent_10) {
    
    //        3
    //      /  \
    //     1    2
    // 3 and 2 are swapped
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(3);
    BinaryNode<int> r1(1);
    BinaryNode<int> r2(2);
    root.left = &r1;
    root.right = &r2;
    check_algorithm_fixes_tree(root,algo);}
}
TEST(BST_Fix, Adjacent_11) {
  
  // 2
  //  \
  //   1
  //   1 and 2 are swapped
  for (auto algo: algorithms_to_test()){
  BinaryNode<int> root(2);
  BinaryNode<int> r1(1);
  root.right = &r1;
  check_algorithm_fixes_tree(root,algo);}
}
TEST(BST_Fix, Adjacent_12) {
  
  //  1
  // /
  // 2
  //   2 and 1 are swapped
  for (auto algo: algorithms_to_test()){
  BinaryNode<int> root(1);
  BinaryNode<int> r1(2);
  root.left = &r1;
  check_algorithm_fixes_tree(root,algo);}
}


TEST(BST_Fix, Every_Swap_1) {
        
     //     6 
     //    /  \ 
     //   2    10 
     //  /  \ /  \ 
     // 1   3 7  12 
     for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(6);
    BinaryNode<int> r1(2);
    BinaryNode<int> r2(10);
    BinaryNode<int> r3(1);
    BinaryNode<int> r4(3);
    BinaryNode<int> r5(7);
    BinaryNode<int> r6(12);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->right = &r4;
    root.right->left = &r5;
    root.right->right = &r6;
    check_every_swap_combination(root,algo);}
}
TEST(BST_Fix, Every_Swap_2) {
    
        //    2
        //  /  \
        // 1    3
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(2);
    BinaryNode<int> r1(1);
    BinaryNode<int> r2(3);
    root.left = &r1;
    root.right = &r2;
    check_every_swap_combination(root,algo);}
}
TEST(BST_Fix, Every_Swap_3) {
    
     //       2
     //     /  \
     //    1    3
     //  /       \
     // 0         4
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(2);
    BinaryNode<int> r1(1);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(0);
    BinaryNode<int> r4(4);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.right->right = &r4;
    check_every_swap_combination(root,algo);}
}
TEST(BST_Fix, Every_Swap_4) {
    
     // 1-2-3-4-5-6-7-8-9-10
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(10);
    BinaryNode<int> r1(9);
    BinaryNode<int> r2(8);
    BinaryNode<int> r3(7);
    BinaryNode<int> r4(6);
    BinaryNode<int> r5(5);
    BinaryNode<int> r6(4);
    BinaryNode<int> r7(3);
    BinaryNode<int> r8(2);
    BinaryNode<int> r9(1);
    root.left = &r1;
    root.left->left = &r2;
    root.left->left->left = &r3;
    root.left->left->left->left = &r4;
    root.left->left->left->left->left = &r5;
    root.left->left->left->left->left->left = &r6;
    root.left->left->left->left->left->left->left = &r7;
    root.left->left->left->left->left->left->left->left = &r8;
    root.left->left->left->left->left->left->left->left->left = &r9;
    check_every_swap_combination(root,algo);}
}
TEST(BST_Fix, Every_Swap_5) {
    
     // 1-2-3-4-5-6-7-8-9-10
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(1);
    BinaryNode<int> r1(2);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(4);
    BinaryNode<int> r4(5);
    BinaryNode<int> r5(6);
    BinaryNode<int> r6(7);
    BinaryNode<int> r7(8);
    BinaryNode<int> r8(9);
    BinaryNode<int> r9(10);
    root.right = &r1;
    root.right->right = &r2;
    root.right->right->right = &r3;
    root.right->right->right->right = &r4;
    root.right->right->right->right->right = &r5;
    root.right->right->right->right->right->right = &r6;
    root.right->right->right->right->right->right->right = &r7;
    root.right->right->right->right->right->right->right->right = &r8;
    root.right->right->right->right->right->right->right->right->right = &r9;
    check_every_swap_combination(root,algo);}
}
TEST(BST_Fix, Every_Swap_6) {
    
    //  2
    // /
    // 1
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(2);
    BinaryNode<int> r1(1);
    root.left = &r1;
    check_every_swap_combination(root,algo);}
}
TEST(BST_Fix, Every_Swap_7) {
    
     // 1
     // \
     //  2
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(1);
    BinaryNode<int> r1(2);
    root.right = &r1;
    check_every_swap_combination(root,algo);}
}
TEST(BST_Fix, Every_Swap_8) {
    
        //    2
        //  /  \
        // 1    3
        //       \
        //        5
        //       / \
        //      4   6
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(2);
    BinaryNode<int> r1(1);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(5);
    BinaryNode<int> r4(4);
    BinaryNode<int> r5(6);
    root.left = &r1;
    root.right = &r2;
    root.right->right = &r3;
    root.right->right->left = &r4;
    root.right->right->right = &r5;
    check_every_swap_combination(root,algo);}
}
TEST(BST_Fix, Every_Swap_9) {
    
      //       5
      //      / \
      //     4   6
      //    /
      //   2
      //  / \
      // 1   3
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(5);
    BinaryNode<int> r1(4);
    BinaryNode<int> r2(6);
    BinaryNode<int> r3(2);
    BinaryNode<int> r4(1);
    BinaryNode<int> r5(3);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->left->left = &r4;
    root.left->left->right = &r5;
    check_every_swap_combination(root,algo);}
}

TEST(BST_Fix, Every_Swap_10) {
  
  
  // 13
  // /
  // 11
  // \
  //  12
  //  /
  //  9
  //  \
  //   10
  for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(13);
    BinaryNode<int> r1(11);
    BinaryNode<int> r2(12);
    BinaryNode<int> r3(9);
    BinaryNode<int> r4(10);
    root.left = &r1;
    root.left->right = &r2;
    root.left->right->left = &r3;
    root.left->right->left->right = &r4;
    check_every_swap_combination(root,algo);}
}

TEST(BST_Fix, Every_Swap_11) {
  
  
   // 1
   //  \
   //   6
   //  /
   // 3
   //  \
   //   5
   //   /
   //  4
    
  for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(1);
    BinaryNode<int> r1(6);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(5);
    BinaryNode<int> r4(4);
    root.right = &r1;
    root.right->left = &r2;
    root.right->left->right = &r3;
    root.right->left->right->left = &r4;
    check_every_swap_combination(root,algo);}
}
TEST(BST_Fix, Every_Swap_12) {
        
     //     6 
     //    /  \ 
     //   2    10 
     //  /  \ /   \ 
     // 1   3 7     12
     //      \  \   /
     //      4  8  11
     for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(6);
    BinaryNode<int> r1(2);
    BinaryNode<int> r2(10);
    BinaryNode<int> r3(1);
    BinaryNode<int> r4(3);
    BinaryNode<int> r5(7);
    BinaryNode<int> r6(12);
    BinaryNode<int> r7(4);
    BinaryNode<int> r8(8);
    BinaryNode<int> r9(11);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->right = &r4;
    root.right->left = &r5;
    root.right->right = &r6;
    root.left->right->right = &r7;
    root.right->left->right = &r8;
    root.right->right->left = &r9;
    check_every_swap_combination(root,algo);}
}
TEST(BST_Fix, Every_Swap_13) {
    
   //        10
   //       /  \
   //      9    11
   //    /       \
   //   8         12
   //  /           \
   // 0             20
   //  \            /
   //   1          19
   //     \       / 
   //       2   18
   //        \  /
   //        3  17
    
    
    for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(10);
    BinaryNode<int> r1(9);
    BinaryNode<int> r2(11);
    BinaryNode<int> r3(8);
    BinaryNode<int> r4(12);
    BinaryNode<int> r5(0);
    BinaryNode<int> r6(20);
    BinaryNode<int> r7(1);
    BinaryNode<int> r8(19);
    BinaryNode<int> r9(2);
    BinaryNode<int> r10(18);
    BinaryNode<int> r11(3);
    BinaryNode<int> r12(17);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.right->right = &r4;
    root.left->left->left = &r5;
    root.right->right->right = &r6;
    root.left->left->left->right = &r7;
    root.right->right->right->left = &r8;
    root.left->left->left->right->right = &r9;
    root.right->right->right->left->left = &r10;
    root.left->left->left->right->right->right = &r11;
    root.right->right->right->left->left->left = &r12;
    check_every_swap_combination(root,algo);}
}

TEST(BST_Fix, Every_Swap_14) {
       //    12
       //  /    \
       // 1      23
       //  \    /
       //   11 13
       //  /    \
       // 2      22
       //  \    /
       //   10 14
       //  /    \
       // 3      21
       //  \    /
       //   9  15
       //  /    \
       // 4      20
       //  \    /
       //   8  16
       //  /    \
       // 5      19
       //  \    /
       //   7  17
       //  /    \
       // 6      18
  for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(12);
    BinaryNode<int> r1(1);
    BinaryNode<int> r2(23);
    BinaryNode<int> r3(11);
    BinaryNode<int> r4(13);
    BinaryNode<int> r5(2);
    BinaryNode<int> r6(22);
    BinaryNode<int> r7(10);
    BinaryNode<int> r8(14);
    BinaryNode<int> r9(3);
    BinaryNode<int> r10(21);
    BinaryNode<int> r11(9);
    BinaryNode<int> r12(15);
    BinaryNode<int> r13(4);
    BinaryNode<int> r14(20);
    BinaryNode<int> r15(8);
    BinaryNode<int> r16(16);
    BinaryNode<int> r17(5);
    BinaryNode<int> r18(19);
    BinaryNode<int> r19(7);
    BinaryNode<int> r20(17);
    BinaryNode<int> r21(6);
    BinaryNode<int> r22(18);
    root.left = &r1;
    root.right = &r2;
    root.left->right = &r3;
    root.right->left = &r4;
    root.left->right->left = &r5;
    root.right->left->right = &r6;
    root.left->right->left->right = &r7;
    root.right->left->right->left = &r8;
    root.left->right->left->right->left = &r9;
    root.right->left->right->left->right = &r10;
    root.left->right->left->right->left->right = &r11;
    root.right->left->right->left->right->left = &r12;
    root.left->right->left->right->left->right->left = &r13;
    root.right->left->right->left->right->left->right = &r14;
    root.left->right->left->right->left->right->left->right = &r15;
    root.right->left->right->left->right->left->right->left = &r16;
    root.left->right->left->right->left->right->left->right->left = &r17;
    root.right->left->right->left->right->left->right->left->right = &r18;
    root.left->right->left->right->left->right->left->right->left->right = &r19;
    root.right->left->right->left->right->left->right->left->right->left = &r20;
    root.left->right->left->right->left->right->left->right->left->right->left = &r21;
    root.right->left->right->left->right->left->right->left->right->left->right = &r22;
    check_every_swap_combination(root,algo);}
}

TEST(BST_Fix, Every_Swap_15) {
       //    12
       //  /    \
       // 1      23
       //  \    /  \
       //   11 13   24
       //  /    \    \
       // 2      22   25
       //  \    /      \
       //   10 14       26
       //  /    \        \
       // 3      21      27
       //  \    /         \
       //   9  15         28
       //  /    \
       // 4      20
       //  \    /
       //   8  16
       //  /    \
       // 5      19
       //  \    /
       //   7  17
       //  /    \
       // 6      18
  for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(12);
    BinaryNode<int> r1(1);
    BinaryNode<int> r2(23);
    BinaryNode<int> r3(11);
    BinaryNode<int> r4(13);
    BinaryNode<int> r5(2);
    BinaryNode<int> r6(22);
    BinaryNode<int> r7(10);
    BinaryNode<int> r8(14);
    BinaryNode<int> r9(3);
    BinaryNode<int> r10(21);
    BinaryNode<int> r11(9);
    BinaryNode<int> r12(15);
    BinaryNode<int> r13(4);
    BinaryNode<int> r14(20);
    BinaryNode<int> r15(8);
    BinaryNode<int> r16(16);
    BinaryNode<int> r17(5);
    BinaryNode<int> r18(19);
    BinaryNode<int> r19(7);
    BinaryNode<int> r20(17);
    BinaryNode<int> r21(6);
    BinaryNode<int> r22(18);
    
    BinaryNode<int> r23(24);
    BinaryNode<int> r24(25);
    BinaryNode<int> r25(26);
    BinaryNode<int> r26(27);
    BinaryNode<int> r27(28);
    root.left = &r1;
    root.right = &r2;
    root.left->right = &r3;
    root.right->left = &r4;
    root.left->right->left = &r5;
    root.right->left->right = &r6;
    root.left->right->left->right = &r7;
    root.right->left->right->left = &r8;
    root.left->right->left->right->left = &r9;
    root.right->left->right->left->right = &r10;
    root.left->right->left->right->left->right = &r11;
    root.right->left->right->left->right->left = &r12;
    root.left->right->left->right->left->right->left = &r13;
    root.right->left->right->left->right->left->right = &r14;
    root.left->right->left->right->left->right->left->right = &r15;
    root.right->left->right->left->right->left->right->left = &r16;
    root.left->right->left->right->left->right->left->right->left = &r17;
    root.right->left->right->left->right->left->right->left->right = &r18;
    root.left->right->left->right->left->right->left->right->left->right = &r19;
    root.right->left->right->left->right->left->right->left->right->left = &r20;
    root.left->right->left->right->left->right->left->right->left->right->left = &r21;
    root.right->left->right->left->right->left->right->left->right->left->right = &r22;
    
    root.right->right = &r23;
    root.right->right->right = &r24;
    root.right->right->right->right = &r25;
    root.right->right->right->right->right = &r26;
    root.right->right->right->right->right->right = &r27;
    check_every_swap_combination(root,algo);}
}

TEST(BST_Fix, Every_Swap_16) {
       //    12
       //  /    \
       // 1      23
       //  \    /  \
       //   11 13   24
       //  /    \    \
       // 2      22   25
       //  \    /      \
       //   10 14       26
       //  /    \        \
       // 3      21      27
       //  \    /         \
       //   9  15         31
       //  /    \        /
       // 4      20     28
       //  \    /        \
       //   8  16         30
       //  /    \        /
       // 5      19     29
       //  \    /
       //   7  17
       //  /    \
       // 6      18
  for (auto algo: algorithms_to_test()){
    BinaryNode<int> root(12);
    BinaryNode<int> r1(1);
    BinaryNode<int> r2(23);
    BinaryNode<int> r3(11);
    BinaryNode<int> r4(13);
    BinaryNode<int> r5(2);
    BinaryNode<int> r6(22);
    BinaryNode<int> r7(10);
    BinaryNode<int> r8(14);
    BinaryNode<int> r9(3);
    BinaryNode<int> r10(21);
    BinaryNode<int> r11(9);
    BinaryNode<int> r12(15);
    BinaryNode<int> r13(4);
    BinaryNode<int> r14(20);
    BinaryNode<int> r15(8);
    BinaryNode<int> r16(16);
    BinaryNode<int> r17(5);
    BinaryNode<int> r18(19);
    BinaryNode<int> r19(7);
    BinaryNode<int> r20(17);
    BinaryNode<int> r21(6);
    BinaryNode<int> r22(18);
    
    BinaryNode<int> r23(24);
    BinaryNode<int> r24(25);
    BinaryNode<int> r25(26);
    BinaryNode<int> r26(27);
    BinaryNode<int> r27(31);
    BinaryNode<int> r28(28);
    BinaryNode<int> r29(30);
    BinaryNode<int> r30(29);
    root.left = &r1;
    root.right = &r2;
    root.left->right = &r3;
    root.right->left = &r4;
    root.left->right->left = &r5;
    root.right->left->right = &r6;
    root.left->right->left->right = &r7;
    root.right->left->right->left = &r8;
    root.left->right->left->right->left = &r9;
    root.right->left->right->left->right = &r10;
    root.left->right->left->right->left->right = &r11;
    root.right->left->right->left->right->left = &r12;
    root.left->right->left->right->left->right->left = &r13;
    root.right->left->right->left->right->left->right = &r14;
    root.left->right->left->right->left->right->left->right = &r15;
    root.right->left->right->left->right->left->right->left = &r16;
    root.left->right->left->right->left->right->left->right->left = &r17;
    root.right->left->right->left->right->left->right->left->right = &r18;
    root.left->right->left->right->left->right->left->right->left->right = &r19;
    root.right->left->right->left->right->left->right->left->right->left = &r20;
    root.left->right->left->right->left->right->left->right->left->right->left = &r21;
    root.right->left->right->left->right->left->right->left->right->left->right = &r22;
    
    root.right->right = &r23;
    root.right->right->right = &r24;
    root.right->right->right->right = &r25;
    root.right->right->right->right->right = &r26;
    root.right->right->right->right->right->right = &r27;
    root.right->right->right->right->right->right->left = &r28;
    root.right->right->right->right->right->right->left->right = &r29;
    root.right->right->right->right->right->right->left->right->left = &r30;
    check_every_swap_combination(root,algo);}
}

TEST(BST_Fix, Example_Hickey_Shuffle_Easy) {
        //    2
        //  /  \
        // 1    4
        //     / \
        //    3   5
  for (auto algo: algorithms_to_test()){
    
    BinaryNode<int> root(2);
    BinaryNode<int> r1(1);
    BinaryNode<int> r2(4);
    BinaryNode<int> r3(3);
    BinaryNode<int> r4(5);
    
    root.left = &r1;
    root.right = &r2;
    root.right->left = &r3;
    root.right->right = &r4;
    
    check_every_swap_combination(root,algo);
  }
}

TEST(BST_Fix, Example_Hickey_Shuffle_Hard) {

        //    2
        //  /  \
        // 1    3
        //       \
        //        11
        //       /
        //      5
        //     / \
        //    4   7
        //       / \
        //      6   10
        //         /
        //        8
        //         \
        //          9
  for (auto algo: algorithms_to_test()){
    
    BinaryNode<int> root(2);
    BinaryNode<int> r1(1);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(11);
    BinaryNode<int> r4(5);
    BinaryNode<int> r5(4);
    BinaryNode<int> r6(7);
    BinaryNode<int> r7(6);
    BinaryNode<int> r8(10);
    BinaryNode<int> r9(8);
    BinaryNode<int> r10(9);
    
    root.left = &r1;
    root.right = &r2;
    root.right->right = &r3;
    root.right->right->left = &r4;
    root.right->right->left->left = &r5;
    root.right->right->left->right = &r6;
    root.right->right->left->right->left = &r7;
    root.right->right->left->right->right = &r8;
    root.right->right->left->right->right->left = &r9;
    root.right->right->left->right->right->left->right = &r10;
    
    check_every_swap_combination(root,algo);
  }
}







