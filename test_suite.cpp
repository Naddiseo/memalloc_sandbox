#include <cppunit/extensions/HelperMacros.h>
#include <buddy_tree.hpp>
#include <string>
#include <iostream>

class BuddyTreeTest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(BuddyTreeTest);
	CPPUNIT_TEST(testBuddyTree);
	CPPUNIT_TEST(testBuddyTreeFree);
	CPPUNIT_TEST(testBuddyReserve);
	CPPUNIT_TEST_SUITE_END();
public:
	
	void testBuddyTree() {
		BuddyTree t;
		
		t.init(1, 8);
		auto phys = t.alloc(1);
		CPPUNIT_ASSERT_EQUAL(0ull, phys.addr);
		
		phys = t.alloc(2);
		CPPUNIT_ASSERT_EQUAL(2ull, phys.addr);
		
		phys = t.alloc(1);
		CPPUNIT_ASSERT_EQUAL(1ull, phys.addr);
		
		phys = t.alloc(4);
		CPPUNIT_ASSERT_EQUAL(4ull, phys.addr);
	}
	
	void testBuddyTreeFree() {
		BuddyTree t, d;
		
		t.init(1, 8);
		d.init(1, 8);
		
		auto phys1 = t.alloc(1);
		auto phys2 = t.alloc(2);
		auto phys3 = t.alloc(1);
		auto phys4 = t.alloc(4);
		
		CPPUNIT_ASSERT_EQUAL(0ull, phys1.addr);
		CPPUNIT_ASSERT_EQUAL(2ull, phys2.addr);
		CPPUNIT_ASSERT_EQUAL(1ull, phys3.addr);
		CPPUNIT_ASSERT_EQUAL(4ull, phys4.addr);
		
		t.free(phys4);
		auto phys5 = t.alloc(2);
		CPPUNIT_ASSERT_EQUAL(4ull, phys5.addr);
		
		t.free(phys1);
		t.free(phys2);
		t.free(phys3);
		auto phys6 = t.alloc(1);
		CPPUNIT_ASSERT_EQUAL(0ull, phys6.addr);
		
		d.alloc(1);
		auto phys7 = d.alloc(3);
		CPPUNIT_ASSERT_EQUAL(4ull, phys7.addr);
	}
	
	void testBuddyReserve() {
		BuddyTree t, d;
		t.init(1, 8);
		t.init(2, 32);
		
		auto phys1 = t.reserve(2, 3);
		CPPUNIT_ASSERT_EQUAL(3ull, phys1.addr);
		
		auto phys2 = d.reserve(3, 3);
		CPPUNIT_ASSERT_EQUAL(2ull, phys2.addr);
		
		// allocate the first block
		CPPUNIT_ASSERT_EQUAL(0ull, d.alloc(1).addr);
		
		/*
		 *  the first reserve should reserve 2-6, which means the next block
		 *  of 4 bytes is located at 8.
		 */
		CPPUNIT_ASSERT_EQUAL(8ull, d.alloc(4).addr);
		
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION(BuddyTreeTest);

