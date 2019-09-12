#include "code/utilities/types/tree/tree_traversal.hpp"
#include "code/utilities/data_structures/tree/binary_node.hpp"
#include "code/utilities/types/tree/bst/annotated_bst_fix.hpp"
#include "code/utilities/types/tree/bst/annotated_bst_state.hpp"
#include "code/utilities/data_structures/tree/binary_nodes.hpp"
#include "gtest/gtest.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>

TEST(bst_inorder_throw_discrepancy, NonAdjacent_1) {
    
    //setup state
    // Annotated_Bst_State state;
    // state.a = &root;
    // state.b = nullptr;
    // state.root = &root;
    // state.current_photo = 0;
    // state.all_nodes = Tree_Traversal::inorder_traversal_as_node_list(state.root);
    // state.val_heights = Tree_Traversal::get_binary_node_levels(&root);
    // state.original_connections = Tree_Traversal::get_all_directed_relationships(&root);
    
    
    
    //setup state
    auto real_root = *x.nodes[0];
    Annotated_Bst_State state;
    state.a = &real_root;
    state.b = nullptr;
    state.root = &real_root;
    state.current_photo = 0;
    state.all_nodes = Tree_Traversal::inorder_traversal_as_node_list(state.root);
    state.val_heights = Tree_Traversal::get_binary_node_levels(&real_root);
    state.original_connections = Tree_Traversal::get_all_directed_relationships(&real_root);
    
    Annotated_Bst_Fix::fix(state);
    
    
}





