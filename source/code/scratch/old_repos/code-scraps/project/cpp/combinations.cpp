#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using std::copy;
using std::cout;
using std::endl;
using std::vector;

void combinations_r_recursive(const vector<char> &elems, unsigned long req_len,
			    vector<unsigned long> &pos, unsigned long depth,
			    unsigned long margin)
{
	// Have we selected the number of required elements?
	if (depth >= req_len) {
		for (unsigned long ii = 0; ii < pos.size(); ++ii)
			cout << elems[pos[ii]];
		cout << endl;
		return;
	}

	// Try to select new elements to the right of the last selected one.
	for (unsigned long ii = margin; ii < elems.size(); ++ii) {
		pos[depth] = ii;
		combinations_r_recursive(elems, req_len, pos, depth + 1, ii);
	}
	return;
}

void combinations_r(const vector<char> &elems, unsigned long req_len)
{
	assert(req_len > 0 && req_len <= elems.size());
	vector<unsigned long> positions(req_len, 0);
	combinations_r_recursive(elems, req_len, positions, 0, 0);
}

const unsigned long num_elements = 6;
const unsigned long comb_len = 2;

int main()
{
	vector<char> elements(num_elements);
	char elements_str[num_elements + 1] = "123456";
	copy(elements_str, elements_str + num_elements, elements.begin());

	combinations_r(elements, comb_len);
	return 0;
}
