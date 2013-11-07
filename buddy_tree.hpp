#pragma once

#pragma pack(1)
struct phys_mem {
	unsigned long long addr;
};

class BuddyTree {
public:
	/*
	Initialise the structure with a size of `memory_size` and a minimum allocation size of `block_size`
	*/
	void init(unsigned long block_size, unsigned long long memory_size);
	
	/*
	Allocate `sz` bytes, return the start address as uint64_t in a phys_addr
	*/
	phys_mem alloc(unsigned long long sz);
	
	
	/*
	Allocate `sz` bytes, but place it at `addr`.
	- addr must be floor aligned to `block_size`
	--- Implies that the end address of the memory block is ceil aligned to `block_size`
	*/
	phys_mem reserve(unsigned long long sz, unsigned long long addr);
	
	/*
	return the memory pointed to by `addr`
	*/
	void free(phys_mem addr);
};

#pragma pack()
