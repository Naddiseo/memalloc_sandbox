#include "buddy_tree.hpp"

/*
	Implementation here.
*/

/*
Initialise the structure with a size of `memory_size` and a minimum allocation size of `block_size`
*/
void 
BuddyTree::init(unsigned long block_size, unsigned long long memory_size) {
}

/*
Allocate `sz` bytes, return the start address as uint64_t in a phys_addr
*/
phys_mem 
BuddyTree::alloc(unsigned long long sz) {
	return {static_cast<unsigned long long>(-1)};
}


/*
Allocate `sz` bytes, but place it at `addr`.
- addr must be floor aligned to `block_size`
--- Implies that the end address of the memory block is ceil aligned to `block_size`
*/
phys_mem 
BuddyTree::reserve(unsigned long long sz, unsigned long long addr) {
	return {static_cast<unsigned long long>(-1)};
}

/*
return the memory pointed to by `addr`
*/
void 
BuddyTree::free(phys_mem addr) {

}
