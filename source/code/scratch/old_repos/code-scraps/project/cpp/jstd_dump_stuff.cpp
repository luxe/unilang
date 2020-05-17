# 1 "jstd.hpp"
# 1 "<command-line>"
# 1 "jstd.hpp"
       
namespace jstd{
# 1 "jstd/fundamental.hpp" 1
       
namespace fundamental{
# 1 "jstd/fundamental/boolean.hpp" 1
       
namespace boolean{
# 1 "jstd/fundamental/boolean/observers.hpp" 1
       
namespace observers{
}
# 4 "jstd/fundamental/boolean.hpp" 2
using namespace observers;
# 1 "jstd/fundamental/boolean/transformers.hpp" 1
       
namespace transformers{
}
# 6 "jstd/fundamental/boolean.hpp" 2
using namespace transformers;
}
# 4 "jstd/fundamental.hpp" 2
using namespace boolean;
# 1 "jstd/fundamental/enumeration.hpp" 1
       
namespace enumeration{

using namespace observers;

using namespace transformers;
}
# 6 "jstd/fundamental.hpp" 2
using namespace enumeration;
# 1 "jstd/fundamental/cstring.hpp" 1
       
namespace cstring{

using namespace observers;

using namespace transformers;
}
# 8 "jstd/fundamental.hpp" 2
using namespace cstring;
# 1 "jstd/fundamental/character.hpp" 1
       
namespace character{

using namespace observers;

using namespace transformers;
}
# 10 "jstd/fundamental.hpp" 2
using namespace character;
# 1 "jstd/fundamental/floating.hpp" 1
       
namespace floating{

using namespace observers;

using namespace transformers;
}
# 12 "jstd/fundamental.hpp" 2
using namespace floating;
# 1 "jstd/fundamental/array.hpp" 1
       
namespace array{

using namespace observers;

using namespace transformers;
}
# 14 "jstd/fundamental.hpp" 2
using namespace array;
# 1 "jstd/fundamental/integral.hpp" 1
       
namespace integral{

using namespace observers;

using namespace transformers;
}
# 16 "jstd/fundamental.hpp" 2
using namespace integral;
}
# 4 "jstd.hpp" 2
using namespace fundamental;
# 1 "jstd/udt.hpp" 1
       
namespace udt{
}
# 6 "jstd.hpp" 2
using namespace udt;
# 1 "jstd/container.hpp" 1
       
namespace container{
# 1 "jstd/container/adaptors.hpp" 1
       
namespace adaptors{
# 1 "jstd/container/adaptors/queue.hpp" 1
       
namespace queue{

using namespace observers;

using namespace transformers;
}
# 4 "jstd/container/adaptors.hpp" 2
using namespace queue;
# 1 "jstd/container/adaptors/priority_queue.hpp" 1
       
namespace priority_queue{

using namespace observers;

using namespace transformers;
}
# 6 "jstd/container/adaptors.hpp" 2
using namespace priority_queue;
# 1 "jstd/container/adaptors/stack.hpp" 1
       
namespace stack{

using namespace observers;

using namespace transformers;
}
# 8 "jstd/container/adaptors.hpp" 2
using namespace stack;
}
# 4 "jstd/container.hpp" 2
using namespace adaptors;
# 1 "jstd/container/sequence.hpp" 1
       
namespace sequence{
# 1 "jstd/container/sequence/forward_list.hpp" 1
       
namespace forward_list{

using namespace observers;

using namespace transformers;
}
# 4 "jstd/container/sequence.hpp" 2
using namespace forward_list;
# 1 "jstd/container/sequence/vector.hpp" 1
       
namespace vector{

using namespace observers;

using namespace transformers;
}
# 6 "jstd/container/sequence.hpp" 2
using namespace vector;
# 1 "jstd/container/sequence/dynarray.hpp" 1
       
namespace dynarray{

using namespace observers;

using namespace transformers;
}
# 8 "jstd/container/sequence.hpp" 2
using namespace dynarray;
# 1 "jstd/container/sequence/deque.hpp" 1
       
namespace deque{

using namespace observers;

using namespace transformers;
}
# 10 "jstd/container/sequence.hpp" 2
using namespace deque;
# 1 "jstd/container/sequence/list.hpp" 1
       
namespace list{

using namespace observers;

using namespace transformers;
}
# 12 "jstd/container/sequence.hpp" 2
using namespace list;
# 1 "jstd/container/sequence/string.hpp" 1
       
namespace string{
# 1 "jstd/container/sequence/string/observers.hpp" 1
       
namespace observers{
# 1 "jstd/container/sequence/string/observers/casing.hpp" 1
       
namespace casing{
}
# 4 "jstd/container/sequence/string/observers.hpp" 2
using namespace casing;
}
# 4 "jstd/container/sequence/string.hpp" 2
using namespace observers;
# 1 "jstd/container/sequence/string/transformers.hpp" 1
       
namespace transformers{

using namespace casing;
}
# 6 "jstd/container/sequence/string.hpp" 2
using namespace transformers;
}
# 14 "jstd/container/sequence.hpp" 2
using namespace string;

using namespace array;
}
# 6 "jstd/container.hpp" 2
using namespace sequence;
# 1 "jstd/container/unordered_associative.hpp" 1
       
namespace unordered_associative{
# 1 "jstd/container/unordered_associative/unordered_map.hpp" 1
       
namespace unordered_map{
# 1 "jstd/container/unordered_associative/unordered_map/observers.hpp" 1
       
namespace observers{
}
# 4 "jstd/container/unordered_associative/unordered_map.hpp" 2
using namespace observers;
# 1 "jstd/container/unordered_associative/unordered_map/transformers.hpp" 1
       
namespace transformers{
}
# 6 "jstd/container/unordered_associative/unordered_map.hpp" 2
using namespace transformers;
}
# 4 "jstd/container/unordered_associative.hpp" 2
using namespace unordered_map;
# 1 "jstd/container/unordered_associative/unordered_set.hpp" 1
       
namespace unordered_set{

using namespace observers;

using namespace transformers;
}
# 6 "jstd/container/unordered_associative.hpp" 2
using namespace unordered_set;
# 1 "jstd/container/unordered_associative/unordered_multiset.hpp" 1
       
namespace unordered_multiset{

using namespace observers;

using namespace transformers;
}
# 8 "jstd/container/unordered_associative.hpp" 2
using namespace unordered_multiset;
# 1 "jstd/container/unordered_associative/unordered_multimap.hpp" 1
       
namespace unordered_multimap{

using namespace observers;

using namespace transformers;
}
# 10 "jstd/container/unordered_associative.hpp" 2
using namespace unordered_multimap;
}
# 8 "jstd/container.hpp" 2
using namespace unordered_associative;
# 1 "jstd/container/associative.hpp" 1
       
namespace associative{
# 1 "jstd/container/associative/set.hpp" 1
       
namespace set{

using namespace observers;

using namespace transformers;
}
# 4 "jstd/container/associative.hpp" 2
using namespace set;
# 1 "jstd/container/associative/multimap.hpp" 1
       
namespace multimap{

using namespace observers;

using namespace transformers;
}
# 6 "jstd/container/associative.hpp" 2
using namespace multimap;
# 1 "jstd/container/associative/map.hpp" 1
       
namespace map{

using namespace observers;

using namespace transformers;
}
# 8 "jstd/container/associative.hpp" 2
using namespace map;
# 1 "jstd/container/associative/multiset.hpp" 1
       
namespace multiset{

using namespace observers;

using namespace transformers;
}
# 10 "jstd/container/associative.hpp" 2
using namespace multiset;
}
# 10 "jstd/container.hpp" 2
using namespace associative;
}
# 8 "jstd.hpp" 2
using namespace container;
}

int main(){}
